/* -*- c++ -*- */
/*
 * Copyright 2019 gr-timingsync author.
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "wrap_fft_index_ss_impl.h"

namespace gr {
	namespace timingsync {

		wrap_fft_index_ss::sptr
		wrap_fft_index_ss::make(int fft_size, float log_per)
		{
			return gnuradio::get_initial_sptr
				(new wrap_fft_index_ss_impl(fft_size, log_per));
		}


		/*
		 * The private constructor
		 */
		wrap_fft_index_ss_impl::wrap_fft_index_ss_impl(int fft_size, float log_per)
			: gr::sync_block("wrap_fft_index_ss",
			                 gr::io_signature::make(1, 1, sizeof(short)),
			                 gr::io_signature::make(1, 1, sizeof(short))),
			d_fft_size(fft_size),
			d_log_period(log_per),
			d_avg_peak_index(0),
			d_n_avg_samples(0),
			d_last_print(std::chrono::system_clock::now())
		{}

		/*
		 * Our virtual destructor.
		 */
		wrap_fft_index_ss_impl::~wrap_fft_index_ss_impl()
		{
		}

		int
		wrap_fft_index_ss_impl::work(int noutput_items,
		                             gr_vector_const_void_star &input_items,
		                             gr_vector_void_star &output_items)
		{
			const short *in = (const short *) input_items[0];
			short *out = (short *) output_items[0];

			// Do <+signal processing+>
			for(int i = 0; i < noutput_items; i++)
			{
				if (in[i] >= (d_fft_size/2)) {
					out[i] = in[i] - d_fft_size;
				} else {
					out[i] = in[i];
				}

				/* Track average index */
				d_avg_peak_index += (double) out[i];
				d_n_avg_samples++;
			}

			/* Print wrapped index periodically if so desired */
			std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = now - d_last_print;
			if (d_log_period > 0 && elapsed_seconds.count() > d_log_period) {
				d_avg_peak_index /= d_n_avg_samples;
				printf("Cross-corr peak index: %f\r\n", d_avg_peak_index);
				fflush(stdout);
				d_last_print = now;
				/* Reset average */
				d_avg_peak_index = 0;
				d_n_avg_samples  = 0;
			}

			// Tell runtime system how many output items we produced.
			return noutput_items;
		}

	} /* namespace timingsync */
} /* namespace gr */


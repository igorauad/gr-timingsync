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

#ifndef INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_IMPL_H
#define INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_IMPL_H

#include <chrono>
#include <timingsync/wrap_fft_index_ss.h>

namespace gr {
	namespace timingsync {

		class wrap_fft_index_ss_impl : public wrap_fft_index_ss
		{
		private:
			// Nothing to declare in this block.
			int d_fft_size;
			float d_log_period;
			double d_avg_peak_index;
			unsigned int d_n_avg_samples;
			std::chrono::time_point<std::chrono::system_clock> d_last_print;

		public:
			wrap_fft_index_ss_impl(int fft_size, float log_per);
			~wrap_fft_index_ss_impl();

			// Where all the action really happens
			int work(
				int noutput_items,
				gr_vector_const_void_star &input_items,
				gr_vector_void_star &output_items
				);
		};

	} // namespace timingsync
} // namespace gr

#endif /* INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_IMPL_H */


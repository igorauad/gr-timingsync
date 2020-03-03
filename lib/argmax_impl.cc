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
#include <volk/volk.h>
#include "argmax_impl.h"


namespace gr {
	namespace timingsync {

		argmax::sptr
		argmax::make(int vlen)
		{
			return gnuradio::get_initial_sptr
				(new argmax_impl(vlen));
		}


		/*
		 * The private constructor
		 */
		argmax_impl::argmax_impl(int vlen)
			: gr::sync_block("argmax",
			                 gr::io_signature::make(1, 1, vlen * sizeof(float)),
			                 gr::io_signature::make(1, 1, sizeof(short))),
			d_vlen(vlen)
		{}

		/*
		 * Our virtual destructor.
		 */
		argmax_impl::~argmax_impl()
		{
		}

		int
		argmax_impl::work(int noutput_items,
		                  gr_vector_const_void_star &input_items,
		                  gr_vector_void_star &output_items)
		{
			const float *in = (const float *) input_items[0];
			short *idx_out = (short *) output_items[0];
			uint32_t out;

			for (int i = 0; i < noutput_items; i++) {
				volk_32f_index_max_32u(&out, in + (i*d_vlen), d_vlen);
				idx_out[i] = (short) out;
			}

			return noutput_items;
		}
	} /* namespace timingsync */
} /* namespace gr */


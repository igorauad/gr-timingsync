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

#ifndef INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_H
#define INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_H

#include <timingsync/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
	namespace timingsync {

		/*!
		 * \brief <+description of block+>
		 * \ingroup timingsync
		 *
		 */
		class TIMINGSYNC_API wrap_fft_index_ss : virtual public gr::sync_block
		{
		public:
			typedef boost::shared_ptr<wrap_fft_index_ss> sptr;

			/*!
			 * \brief Wrap FFT index into [-N/2, N/2) range
			 * \param fft_size FFT size
			 * \param log_per Debug log period in secs
			 */
			static sptr make(int fft_size, float log_per);
		};
	} // namespace timingsync
} // namespace gr

#endif /* INCLUDED_TIMINGSYNC_WRAP_FFT_INDEX_SS_H */


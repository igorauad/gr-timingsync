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

#ifndef INCLUDED_TIMINGSYNC_ARGMAX_H
#define INCLUDED_TIMINGSYNC_ARGMAX_H

#include <timingsync/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
	namespace timingsync {

		/*!
		 * \brief <+description of block+>
		 * \ingroup timingsync
		 *
		 */
		class TIMINGSYNC_API argmax : virtual public gr::sync_block
		{
		public:
			typedef boost::shared_ptr<argmax> sptr;

			/*!
			 * \brief Returns the maximum of a float vector
			 * \param vlen Vector length
			 */
			static sptr make(int vlen);
		};

	} // namespace timingsync
} // namespace gr

#endif /* INCLUDED_TIMINGSYNC_ARGMAX_H */


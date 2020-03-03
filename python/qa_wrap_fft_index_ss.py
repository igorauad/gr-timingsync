#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Copyright 2019 gr-timingsync author.
#
# This is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3, or (at your option)
# any later version.
#
# This software is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this software; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
#

from gnuradio import gr, gr_unittest
from gnuradio import blocks
import timingsync_swig as timingsync

class qa_wrap_fft_index_ss(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        # set up fg
        Nfft    = 8192
        in_vec       = (4096, 0, 4095, 1, 8191, 10, 8182)
        expected_out = (-4096, 0, 4095, 1, -1, 10, -10)
        src     = blocks.vector_source_s(in_vec)
        wrapper = timingsync.wrap_fft_index_ss(Nfft, 0.0)
        snk     = blocks.vector_sink_s()
        self.tb.connect(src, wrapper, snk)
        self.tb.run()
        wrapped_index = snk.data()
        self.assertEqual(wrapped_index, expected_out)
        # check data

if __name__ == '__main__':
    gr_unittest.run(qa_wrap_fft_index_ss)

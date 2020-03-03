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

class qa_argmax(gr_unittest.TestCase):

    def setUp(self):
        self.tb = gr.top_block()

    def tearDown(self):
        self.tb = None

    def test_001_t(self):
        """Test two consecutive vectors"""
        vlen         = 4
        in_vec       = (0.0,1.0,2.0,3.0,1.5,3.5,0.5,2.5)
        expected_out = (3,1)
        src     = blocks.vector_source_f(in_vec)
        srcv    = blocks.stream_to_vector(gr.sizeof_float, vlen)
        argmax  = timingsync.argmax(vlen)
        snk     = blocks.vector_sink_s()
        self.tb.connect(src, srcv, argmax, snk)
        self.tb.run()
        peak_index = snk.data()
        print(peak_index)
        self.assertEqual(peak_index, expected_out)

    def test_002_t(self):
        """Test silence period"""
        vlen         = 4
        in_vec       = (0.0,1.0,2.0,3.0,0.0,0.0,0.0,0.0,1.5,3.5,0.5,2.5)
        expected_out = (3,0,1)
        src     = blocks.vector_source_f(in_vec)
        srcv    = blocks.stream_to_vector(gr.sizeof_float, vlen)
        argmax  = timingsync.argmax(vlen)
        snk     = blocks.vector_sink_s()
        self.tb.connect(src, srcv, argmax, snk)
        self.tb.run()
        peak_index = snk.data()
        print(peak_index)
        self.assertEqual(peak_index, expected_out)


if __name__ == '__main__':
    gr_unittest.run(qa_argmax)

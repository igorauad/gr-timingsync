/* -*- c++ -*- */

#define TIMINGSYNC_API

%include "gnuradio.i"           // the common stuff

//load generated python docstrings
%include "timingsync_swig_doc.i"

%{
#include "timingsync/wrap_fft_index_ss.h"
#include "timingsync/argmax.h"
%}

%include "timingsync/wrap_fft_index_ss.h"
GR_SWIG_BLOCK_MAGIC2(timingsync, wrap_fft_index_ss);
%include "timingsync/argmax.h"
GR_SWIG_BLOCK_MAGIC2(timingsync, argmax);

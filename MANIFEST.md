title: The TIMINGSYNC OOT Module
brief: Tools to assess the timing alignment between two input signals
tags:
  - synchronization
  - signal analysis
author:
  - Igor Freire <igorfreire@ufpa.br>
copyright_owner:
  - Copyright Owner 1
license:
repo: https://github.com/igorauad/gr-timingsync
gr_supported_version: v3.8
#website: <module_website> # If you have a separate project website, put it here
#icon: <icon_url> # Put a URL to a square image here that will be used as an icon on CGRAN
---
gr-timingsync is an OOT module containing flowgraphs and helper blocks to
evaluate the alignment of the timing between two input signals. For example, it
can be used with a two-channel USRP while receiving from two distinct radios
whose transmissions are supposed to be aligned/coordinated in time, such as the
case of LTE/5G TDD radios. The flowgraphs compute the cross-correlation between
the two input signals and, based on the correlation's peak, output the alignment
(in terms of sample intervals) between the two input signals.

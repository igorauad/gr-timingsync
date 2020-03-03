# gr-timingsync

An OOT module containing flowgraphs and helper blocks to evaluate the timing
alignment error between two input signals.

It can be used in the scenario that follows: two independent transmitters (**Tx
1** and **Tx 2**) are supposed to execute time-aligned transmissions on the air
interface. For example, a pair of LTE/5G time division duplexing (TDD) radios
transmitting on the same frequency band with overlapping coverage areas. To
evaluate the alignment in time of their air interface transmissions, the two
transmitters are connected to an SDR interface with two receive channels (**Rx
Ch1** and **Rx Ch2**). In the host PC, `gr-timingsync` applications can be used
to measure the timing alignment of the two transmissions.

```
Tx 1 ------
           \              ------      -------------
            \---- RX Ch1 |      |    |             |
                         | SDR  |----|gr-timingsync|
             /--- RX Ch2 |      |    |             |
            /             ------      -------------
Tx 2 ------/
```

The flowgraphs that are available in this repository compute the
cross-correlation between the two input signals using frequency-domain
approach. Then, based on the correlation's peak, they infer the time alignment
(in terms of sample intervals) of the two input signals.

Available applications:

- `apps/timing_analyzer.grc`: Prints the timing alignment (in sample intervals)
  between two input signals of an USRP to the console.
- `apps/timing_analyzer_gui.grc`: Same purpose, but displays the information in
  QT GUI plots.
- `examples/sim_timing_analyzer.grc`: Similar application, but instead of using
  the real input of an SDR interface, generates two time-displaced signals in
  simulation and verifies the functionality of the timing analyzer tools.

## Build Instructions

The module works with GNU Radio version v3.8 or higher. To build, run the
following:

```
mkdir build
cd build/
cmake ..
make
```

> NOTE: in case your GNU Radio installation is on a specific prefix, run the
> `cmake` step like so:
>
> ```
> cmake -DCMAKE_INSTALL_PREFIX=$PREFIX ..
> ```

Then install with:
```
make install
```
or
```
sudo make install
```

To build the applications that are located in the `apps` directory, run from the
root directory:
```
make
```

## Running

Change to the `apps/` directory and execute one of the two available application
for timing alignment analysis.

For example, to print periodically to the console on every second, run:

```
./timing_analyzer.py -l 1 -a serial=30E8A70
```

where `-l` determines the log periodicity and argument `-a` specified the USRP
address, in this example `serial=30E8A70`.


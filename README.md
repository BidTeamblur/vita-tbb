# VitaTBB
An experimental C++14-compatible subset of oneAPI Threading Building Blocks adapted for PlayStation Vita.

This is a hobby port done mostly by reading upstream TBB source and trial and error. Pull requests and fixes are very welcome.
It is not complete, not optimized, definitely not a full TBB replacement.
The goal is to get at least some algorithms working on real Vita hardware (personal goal is parallel_for.h).

## Currently implemented:

- tbb::blocked_range
- tbb::blocked_range2d
- tbb::blocked_range3d
- tbb::blocked_nd_range
- tbb::split / tbb::proportional_split

## What's in progress / TODO

- Thread pool (2 workers + main thread)
- `parallel_for` (some headers needed beforehand)

## Building tests

Tests are plain `.cpp` files. Build them however you want, i made them just to check whether they compile with my headers.

## License

Apache 2.0. oneTBB is also Apache 2.0. See LICENSE.

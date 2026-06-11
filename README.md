# llfio - Low-level file i/o and filesystem C++ library

This is a `build2` package repository for
[`llfio`](https://github.com/ned14/llfio), a zero whole machine memory copy
low-level file i/o and filesystem C++ library (proposed for future C++
standardisation).

This file contains setup instructions and other details that are more
appropriate for development rather than consumption. If you want to use
`llfio` in your `build2`-based project, then instead see the accompanying
[`PACKAGE-README.md`](libllfio/PACKAGE-README.md) file.

The repository contains two packages: `libllfio` (the library, built in the
compiled configuration matching the upstream `llfio_sl`/`llfio_dl` targets)
and `libllfio-tests` (the upstream test suite, packaged separately because
it requires the KernelTest framework).

Note that upstream does not make versioned releases (only continuously
tested snapshots of the develop branch). The packages follow these snapshots
using pre-release snapshot versions of the upstream `2.0` API version
(`2.0.0-a.0.z`).

The development setup for libllfio uses the standard bdep-based workflow. For example:

```
git clone --recurse-submodules .../llfio.git
cd llfio

bdep init -C @gcc cc config.cxx=g++
bdep update
bdep test
```

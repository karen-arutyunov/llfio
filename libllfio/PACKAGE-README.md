# libllfio - Low-level file i/o and filesystem C++ library

This is a `build2` package for the [`llfio`](https://github.com/ned14/llfio)
C++ library. It provides a zero whole machine memory copy low-level file i/o
and filesystem abstraction (proposed for future C++ standardisation), with
particularly strong support for writing portable filesystem algorithms and
for storage with microsecond-level transfer latencies.


## Usage

To start using `libllfio` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libllfio >= 2.0.0-a.0.1
```

Then import the library in your `buildfile`:

```
import libs = libllfio%lib{llfio}
```

And include its headers as:

```c++
#include <llfio/llfio.hpp>
```

Note that the library is built in the compiled configuration (matching the
upstream `llfio_sl`/`llfio_dl` CMake targets): consumers automatically get
`LLFIO_HEADERS_ONLY=0` plus `LLFIO_STATIC_LINK=1` or `LLFIO_DYN_LINK=1`
depending on the linkage variant.


## Importable targets

This package provides the following importable targets:

```
lib{llfio}
```


## Configuration variables

This package does not provide any configuration variables. Note that the
optional upstream features that are enabled (or disabled) by default are
matched: the storage profile support is compiled in and the experimental
SG14 `status_code` mode (`LLFIO_EXPERIMENTAL_STATUS_CODE`) is not used.

# libllfio-tests

This package contains the upstream [`llfio`](https://github.com/ned14/llfio)
test suite (which requires the KernelTest framework and is therefore
packaged separately from `libllfio`).

The test layout mirrors the upstream `test/tests/` directory: most tests are
self-contained executables, while the `*_create_close`/`*_enumerate`
kernel-runner tests additionally use on-disk workspace templates which
KernelTest's filesystem workspace hook locates via the
`KERNELTEST_LLFIO_HOME` environment variable (set by the accompanying
testscript).

Known limitations:

* The `extended_attributes` and `utils` tests are built but not run: the
  former expects newly-created files to carry no extended attributes (not
  true on SELinux-enabled systems), and the latter checks process memory
  accounting against exact page counts which varies with the kernel
  version/configuration.

* The `symlink_handle_create_close` workspace template contains a symlink
  (`existing1/testlink`) which `b dist` materializes as a regular file, so
  this test only works when the package is consumed from the git repository
  (where the symlink is preserved) rather than from a source distribution.

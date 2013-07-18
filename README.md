go-prism
========

Capture CS:GO gameplay data for analysis

## Building

### Prerequisites

If you're on a 64-bit machine, you'll need to install the proper libc includes for 32-bit builds, as well as the C/C++ compilers with multilib support:

Debian/Ubuntu:

```
sudo apt-get install libc6-dev-i386 gcc-4.7-multilib g++-4.7-multilib
```

### Compiling

In the root of the repo, run `make`.

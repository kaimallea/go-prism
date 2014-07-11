go-prism
========

Capture CS:GO gameplay data for analysis

## Building

If you're on a 64-bit machine you'll need to install C/C++ compilers with multilib support.

#### Debian/Ubuntu:

```
$ sudo apt-get install build-essential gcc-multilib g++-multilib
```

You might also need to install the libc includes for 32-bit builds: `libc6-dev-i386`.

#### Vagrant:

Use the included `Vagrantfile` to build a VM with the build tools necessary for compiling go-prism.

```
$ vagrant up
```

Then you can easily access the VM and compile the code:

```
$ vagrant ssh
$ cd /vagrant
$ make
```

### Compiling

In the root of the repo, run `make`.

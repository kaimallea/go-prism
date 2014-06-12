go-prism
========

Capture CS:GO gameplay data for analysis

## Building

If you're on a 64-bit machine, you'll need to install the proper libc includes for 32-bit builds, as well as the C/C++ compilers with multilib support.

#### Debian/Ubuntu:

```
sudo apt-get install build-essential libc6-dev-i386 gcc-4.8-multilib g++-4.8-multilib
```

#### Docker:

Use the included `Dockerfile` to build a docker image with the build tools necessary for compiling go-prism.

```
docker build -t <username>/<imagename> .
```

Then you can easily create a container to test compilation. The example below also makes the source code (assuming working dir) available in the container at `/src`:

```
docker run -i -t -v $(pwd):/src <username>/<imagename>
```

### Compiling

In the root of the repo, run `make`.

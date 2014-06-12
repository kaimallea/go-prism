FROM ubuntu:14.04

MAINTAINER Kai Mallea <kmallea@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update

RUN apt-get install -y build-essential libc6-dev-i386 gcc-4.8-multilib g++-4.8-multilib git

RUN adduser \
        --disabled-password \
        --shell /bin/bash \
        --gecos "" \
        developer

USER developer

ENTRYPOINT ['/bin/bash']
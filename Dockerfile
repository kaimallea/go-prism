FROM ubuntu:14.04

MAINTAINER Kai Mallea <kmallea@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update -qq
RUN apt-get install -qqy \
  build-essential \
  libc6-dev-i386 \
  gcc-4.8-multilib \
  g++-4.8-multilib \
  git

RUN mkdir /src

WORKDIR /src

CMD ["/bin/bash"]

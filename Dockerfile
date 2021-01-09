FROM ubuntu:20.04

RUN apt update \
 && DEBIAN_FRONTEND=noninteractive apt install -y \
  make \
  cmake \
  cppcheck \
  g++ \
  doxygen \
  graphviz \
  git \
&& rm -rf /var/lib/apt/lists/*
FROM ubuntu:20.04

RUN apt-get update && apt-get install --no-install-recommends -y \
  make \
  cppcheck \
  g++ \
  doxygen \
  graphviz \
&& rm -rf /var/lib/apt/lists/*
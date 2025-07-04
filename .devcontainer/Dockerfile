FROM alpine:latest

# Install essential C/C++ build tools, CMake and libs for running IDE in the container
RUN apk update && apk add --no-cache \
    build-base \
    cmake \
    make \
    gcc \
    g++ \
    musl \
    musl-dev \
    linux-headers \
    sudo \
    libxext \
    libxrender \
    libxtst \
    libxi \
    freetype \
    procps \
    gcompat \
    unzip \
    curl \
    wget \
    procps \
    && rm -rf /var/cache/apk/*

# Copy source files to container
COPY CMakeLists.txt wrapper64_glibc.c wrapper64_glibc.h /tmp/build/

# Build the libwrapper64 library
WORKDIR /tmp/build
RUN cmake . && make

# Copy the built library to /root
RUN cp libwrapper64_glibc.so /root/

# Set LD_PRELOAD
RUN echo "export LD_PRELOAD=/root/libwrapper64_glibc.so" >> /etc/profile

# Cleanup build files
RUN rm -rf /tmp/build

USER $USERNAME
WORKDIR /root

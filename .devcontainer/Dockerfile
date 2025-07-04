FROM alpine:latest

# Install essential C/C++ build tools and CMake
RUN apk update && apk add --no-cache \
    build-base \
    cmake \
    make \
    gcc \
    g++ \
    musl-dev \
    linux-headers \
    sudo \
    && rm -rf /var/cache/apk/*

# Create non-root user
ARG USERNAME=developer
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN addgroup -g $USER_GID $USERNAME \
    && adduser -D -u $USER_UID -G $USERNAME $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Copy source files to container
COPY CMakeLists.txt wrapper64_glibc.c wrapper64_glibc.h /tmp/build/

# Build the project
WORKDIR /tmp/build
RUN cmake . && make

# Copy the built library to /root
RUN cp libwrapper64_glibc.so /root/

# Set LD_PRELOAD
RUN echo "export LD_PRELOAD=/root/libwrapper64_glibc.so" >> /etc/profile

# Cleanup build files
RUN rm -rf /tmp/build

USER $USERNAME
WORKDIR /workspace

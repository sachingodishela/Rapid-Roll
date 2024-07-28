FROM ubuntu:22.04
RUN apt update -y

# setup display
RUN apt install libxmu-dev libxi-dev libgl-dev libxinerama-dev libxcursor-dev libxrandr-dev libglu1-mesa-dev pkg-config -y

# setup build tools
RUN apt install git -y
RUN apt install g++ -y
RUN apt install gdb -y
RUN apt install cmake -y

# setup package manager
RUN apt install curl zip unzip tar -y
RUN apt install ninja-build -y
RUN cd / && git clone https://github.com/microsoft/vcpkg.git && cd vcpkg && ./bootstrap-vcpkg.sh
RUN echo "export VCPKG_ROOT=/vcpkg" >> ~/.profile
RUN echo "export PATH=\"\$VCPKG_ROOT:\$PATH\"" >> ~/.profile

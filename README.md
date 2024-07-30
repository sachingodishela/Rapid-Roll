# Rapid-Roll
This a cross-platform 2 dimensional arcade game. The goal is to juggle the ball between steps (for as long as you can) that keep coming from down and move upwards. If the ball touches the top of the screen or fall down in the bottom, you are lost.
Currently supports only Windows and Linux.
#### 3rd Party Libraries Used:
1. GLFW for windowing
2. GLEW for accessing OpenGL
#### Development Roadmap:
|Feature|Start Date|End Date|
|-|-|-|
|Side Boundaries|||
|Thorns at the top|||
|Scoreboard|||
|Lives|||
|Sound FX|||
|Increasing velocities over time|||
## Setup & Run Instructions:
1. Install the pre-requisites:
	- Git
	- C++ compiler
	- CMake (3.3 or above)
	- Ninja
	- VCPKG (Make sure to set VCPKG_ROOT environment variable)
2. Clone the repository
```
git clone git@github.com:sachingodishela/Rapid-Roll.git && cd Rapid-Roll

```
3. Configure cmake cache (linux) & build the source:
```
cmake --preset=linux-config && cmake --build --preset=linux-build
```

4. Configure cmake cache (windows) & build the source:

```
cmake --preset=windows-config && cmake --build --preset=windows-build
```
5. Run the executable generated in the `build` directory.

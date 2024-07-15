# Rapid-Roll
This a 2 dimensional arcade game. The goal is to juggle the ball between steps (for as long as you can) that keep coming from down and move upwards. If the ball touches the top of the screen or fall down in the bottom, you are lost.
#### Libraries Used:
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
## Setup Instructions:
1. Install [Docker Engine](https://docs.docker.com/engine/install/ubuntu/)
2. Install [VS Code](https://code.visualstudio.com/download). After that install the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) extension
3. Checkout this repository:
```
git clone git@github.com:sachingodishela/Rapid-Roll.git
cd Rapid-Roll
code .
```
4. Run this command to enable GUI for your containerized applications.
```
xhost local:root
```
5. Open the folder in dev container.

## Build & Run Instructions:
1. To build and run the game, run the default build task by pressing `Ctrl + Shift + B`
2. To debug the game, press `F5`

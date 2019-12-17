# mm1y-queue-simulation
C++ simulator of mm1y computer network queues
## Features
* Simulation of a specific network queue
* Simulation of a group of network queues with the same capacity
## Prerequisites
To clone and run this application, you'll need Git and C++ compiler.

From your command line:
```bash
# Install Git
$ sudo apt install git
# Install C++ compiler
$ sudo apt install g++
```
## How to Use
### Simulation of a specific network queue
```bash
# Clone this repository
$ git clone https://github.com/vittoboa/mm1y-queue-simulation.git

# Go into the repository
$ cd mm1y-queue-simulation

# Compile the app
$ make

# Run the simulation in mode 1
$ ./simulation 1
```
<a href="https://imgur.com/NdpZB2b"><img src="https://i.imgur.com/NdpZB2b.gif" width="640" title="How to run a simulation of a specific network queue" /></a>

### Simulation of a group of network queues with the same capacity
```bash
# Clone this repository
$ git clone https://github.com/vittoboa/mm1y-queue-simulation.git

# Go into the repository
$ cd mm1y-queue-simulation

# Compile the app
$ make

# Run the simulation in mode 2
$ ./simulation 2
```
<a href="https://imgur.com/TGKu5do"><img src="https://i.imgur.com/TGKu5do.gif" width="640" title="How to run a simulation of a group of network queues with the same capacity"/></a>

<a href="https://imgur.com/8r96BPe"><img src="https://i.imgur.com/8r96BPe.png" width="640" title="Graph of a group of network queues with the same capacity"/></a>
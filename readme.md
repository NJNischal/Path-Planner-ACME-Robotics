# A* Path Planner and Iksolver for 6 DOF Manipulator
[![Build Status](https://travis-ci.org/NJNischal/Path-Planner-ACME-Robotics.svg?branch=master)](https://travis-ci.org/NJNischal/Path-Planner-ACME-Robotics)
[![Coverage Status](https://coveralls.io/repos/github/NJNischal/Path-Planner-ACME-Robotics/badge.svg?branch=master)](https://coveralls.io/github/NJNischal/Path-Planner-ACME-Robotics?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---

## Overview

This is the project implements the path planner Module for Acme Robotics. In this project, inverse kinematics problem of a robotic manipulator with 6 degrees of freedom is addressed.For this,two points which forms the start and end positions of the end effector of the robot manipulator are given to Astar algorithm which in turn gives the shortest path avoiding obstacles.Using inverse kinematics,for each point on the path, 6 joint angles are calculated.

## Implementation salient points

1) The environment where the robot operates is represented as binary map '1' represents obstacles '0' represents valid position.

2) Given a start and goal position in this map, the shortest path between these two points is found by using A* algorithm.

3) The points on the path thus obtained are transformed into robots base frame.

4) Inverse kinematics is then applied to these points to obtain a set of 6 joint angles for each point on this path.

5) The final ouput is this set of 6 joint angles obtained for each point, when sent as input to the robot traces the path.

## Install Eigen3

In this project, we have used Eigen version 3.3.7. For download instructions, please visit http://eigen.tuxfamily.org/index.php?title=Main_Page#Download  

## Dependencies

Eigen3: Eigen3 is a c++ template library for algebra. This library is used in this project for representation of 2D map of robot and other matrix calculations which are used profoundly in our source code. This library is preferred because it is very lightweight and involves integrating only header files. The header files already exists in usr/include folder on the ubuntu machine. This directory can be included into project by adding the following line in Cmakelists.txt file in the 'app' sub-directory of the project.

In the include_directories add /usr/include/eigen3

Accordingly in the travis.yml the following line is added so that eigen3 is recognised by travisCI.
Add the following line in the before_install: section of travis.yml
- wget http://bitbucket.org/eigen/eigen/get/3.3.4.tar.gz && tar xzf 3.3.4.tar.gz && sudo cp -Rp eigen-eigen-5a0156e40feb /usr/local/include/eigen3

## Standard install via command-line
```
git clone --recursive https://github.com/NJNischal/Path-Planner-ACME-Robotics.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Shareable Links for Sprint notes and AIP template:

Sprint notes: 
https://docs.google.com/document/d/12OItDMsqb8h6DQTVezA4NGi-M5xf9JzFdQqQbvPX68Q/edit?ts=5d9f4c66

AIP Template:
https://docs.google.com/spreadsheets/d/1fC9TYi5srTVPyc5ghDMLPsvgVkAj7jlxIm-aA8zec2o/edit?ts=5d9f4b72#gid=0

## License
MIT License

Copyright (c) 2019 RAJA SRINIVAS, JAGADESH NISCHAL NAGIREDDI, VAMSHI KUMAR

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Doxygen

To install doxygen 

sudo apt install doxygen

To create Doxygen documentation

doxygen -g Creates a Doxyfile, edit the configuration of the doxyfile and run: doxygen ./Doxyfile

## Known issues and Bugs

There were segmentation faults with the indexing of eigen matrix. 
There were some bugs with Eclipse IDE where it doesn't build the changes after changes were made.




# C++ Boilerplate
[![Build Status](https://travis-ci.org/NJNischal/Path-Planner-ACME-Robotics.svg?branch=iteration_development)](https://travis-ci.org/NJNischal/Path-Planner-ACME-Robotics)
[![Coverage Status](https://coveralls.io/repos/github/NJNischal/Path-Planner-ACME-Robotics/badge.svg?branch=iteration_development)](https://coveralls.io/github/NJNischal/Path-Planner-ACME-Robotics?branch=master)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
---

## Overview

This is the project  developed using c++ for Acme Robotics path planning department.In this project, inverse kinematics problem of a robotic manipulator with 6 degrees of freedom is addressed.For this,two points which forms the start and end points of end effector of manipulator are given to Astar algorithm which in turn gives the shortest path avoiding obstacles.Using inverse kinematics,for each point the joint angles are calculated.

##Eigen3

Eigen3 library is used in this project,which already exists in usr/include folder of the local.Accordingly travis.yml is edited so that eigen3 is recognised.Eigen is used for calculations on the matrix,which are used profoundly in our source code.

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




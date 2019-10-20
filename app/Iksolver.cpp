/*
 * @copyright 2019
 * @copyright MIT License
 * @file Iksolver.cpp
 * Design
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @version 1.0
 * @date 11/10/2019
 * @brief File to compute Inverse kinematics for each point in the path obtained from A star algorithm.
 */

#include "Iksolver.h"

Iksolver::Iksolver() {
}

Iksolver::~Iksolver() {
}

std::vector<JointAngles> Iksolver::ikSolver(std::vector<Eigen::Vector2d> path) {
  (void) path;
  JointAngles angles;
  std::vector<JointAngles> solution;
  solution.emplace_back(angles);
  return solution;
}


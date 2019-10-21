/*
 * @copyright 2019
 * @copyright MIT License
 * @file Iksolver.cpp
 * Design (Phase 1)
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 13/10/2019
 * Implementation (Phase 2)
 * @author Nischal NJ - Driver
 * @author Vamshi - Design Keeper
 * @author Raja - Navigator
 * @version 1.0
 * @date 21/10/2019
 * @brief File to compute Inverse kinematics for each point in the path obtained from A star algorithm.
 */

#include "Iksolver.h"
#include <iostream>

Iksolver::Iksolver() {
}

Iksolver::~Iksolver() {
}

std::vector<JointAngles> Iksolver::ikSolver(std::vector<Eigen::Vector2d> path) {
  // that stores six angles
  JointAngles angles;
  std::vector<JointAngles> solution;

  // Rotation matrix that represents orientation of end-effector with reference
  // to base frame.
  Eigen::Matrix3i R;
  R << 1, 0, 0, 0, 0, 1, 0, -1, 0;

  int d = 0;
  int r13 = R(0, 2);
  int r23 = R(1, 2);
  int r33 = R(2, 2);
  int r11 = R(0, 0);
  int r21 = R(1, 0);
  int r12 = R(0, 1);
  int r22 = R(1, 1);
  int d6 = a5 + a6;
  Eigen::Vector2d point;

  for (auto position : path) {
    point = position;
    int ox = 0;
    int oy = 1;
    int oz = 1 - point[0];
    int xc, yc, zc, D;
    double c1, c3, c23, s1, s2, s23;
    //  Wrist center
    xc = ox - d6 * r13;
    yc = oy - d6 * r23;
    zc = oz - d6 * r33;

    // joint angles in degrees
    angles.thetha1 = (atan2(yc, xc)) * (180 / M_PI);

    D = ((pow(xc, 2) + pow(yc, 2) - pow(d, 2) + pow((zc - d1), 2) - pow(a2, 2)
        - pow(a3, 2)) / (2 * a2 * a3));

    angles.thetha3 = (atan2(sqrt(1 - pow(D, 2)), D)) * (180 / M_PI);

    c1 = cos(angles.thetha1);
    c3 = cos(angles.thetha3);
    c23 = cos(angles.thetha2 + angles.thetha3);
    s1 = sin(angles.thetha1);
    s2 = sin(angles.thetha2);
    s23 = sin(angles.thetha2 + angles.thetha3);

    angles.thetha2 = (atan2(zc - d1, sqrt(pow(xc, 2) + pow(yc, 2) - pow(d, 2)))
        - atan2(a3 * s2, a2 + a3 * c3)) * (180 / M_PI);

    angles.thetha4 = (atan2(-c1 * s23 * r13 - s1 * s23 * r23 + c23 * r33,
                            c1 * c23 * r13 + s1 * c23 * r23 + s23 * r33))
        * (180 / M_PI);

    angles.thetha5 = (atan2(sqrt(1 - pow(s1 * r13 - c1 * r23, 2)),
                            s1 * r13 - c1 * r23)) * (180 / M_PI);

    angles.thetha6 = (atan2(s1 * r12 - c1 * r22, -s1 * r11 + c1 * r21))
        * (180 / M_PI);

    solution.emplace_back(angles);
  }
  return solution;
}

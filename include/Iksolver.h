/*
 * @copyright 2019
 * @copyright MIT License
 * @file Iksolver.h
 * Design
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @version 1.0
 * @date 11/10/2019
 * @brief Header file for Inverse Kinematics solver
 */

#ifndef IKSOLVER_H_
#define IKSOLVER_H_
#include <vector>
#include <eigen3/Eigen/Dense>

struct JointAngles {
  double thetha1 = 10;
  double thetha2 = 10;
  double thetha3 = 10;
  double thetha4 = 10;
  double thetha5 = 10;
  double thetha6 = 10;
};

class Iksolver {
 public:
  Iksolver();
  ~Iksolver();

  /**
   * @brief This function is used to display the set of 6 joint angles of manipulator(6 dof arm) for every point in the path
   * computed from the A star algorithm
   * @param path,which is the output from A*star algorithm i.e. the shortest path between start and goal points
   * @return a vector containing struct of joint angles.
   */
  std::vector<JointAngles> ikSolver(std::vector<Eigen::Vector2d> path);

 private:
  /**
   * @brief Following are the lengths of each link of manipulator
   */
  int d1 = 1;
  int a2 = 1;
  int a3 = 1;
  int a4 = 1;
  int a5 = 1;
  int a6 = 1;
};

#endif /* IKSOLVER_H_ */


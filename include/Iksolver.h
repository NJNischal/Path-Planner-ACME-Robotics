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

class Iksolver {
 public:
  Iksolver();
  ~Iksolver();

  /**
   * @brief This function is used to display the set of 6 joint angles of manipulator(6 dof arm) for every point in the path
   * computed from the A star algorithm
   * @param path,which is the output from A*star algorithm i.e. the shortest path between start and goal points
   * @return None
   */
  void ikSolver(std::vector<Eigen::Vector2d> path);

 private:
  /**
   * @brief Following are the lengths of each link of manipulator
   */
  int link1 = 1;
  int link2 = 1;
  int link3 = 1;
  int link4 = 1;
  int link5 = 1;
  int link6 = 1;
};

#endif /* IKSOLVER_H_ */


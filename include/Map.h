/*
 * @copyright 2019
 * @copyright MIT License
 * @file Map.h
 * Design (Phase 1)
 * @author Nischal NJ - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design keeper
 * @version 1.0
 * @date 11/10/2019
 * @brief Class definition of Map of environment
 */

#include <eigen3/Eigen/Dense>
#include <iostream>
#include <vector>
#include "NodesManager.h"

#ifndef INCLUDE_MAP_H_
#define INCLUDE_MAP_H_

/**
 * @brief Map class is used to generate the map with obstacles for the A* Algorithm
 * and check validity of given locations
 */

class Map {
 public:
  Map();
  ~Map();

  /**
   * @brief Checks presence of obstacle at the given location
   * where obstacle is represented by '1' and workspace is represented by '0' in the map.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return Boolean returns true if there is obstacle, false otherwise.
   */
  bool obstacleCheck(const Position& newPos);

  /**
   * @brief Checks validity of the given location
   * i.e. if the point lies within the bounds of the map.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return Boolean returns true if the location is valid, false otherwise.
   */
  bool validityCheck(const Position& newPos);

  /**
   * @brief Displays complete map with obstacles represented by 1,0 for valid points.
   * @param None
   * @return None
   */
  void plotMap();

  /**
   * @brief Creates obstacles on the map
   * @param None
   * @return None
   */
  void createMap();

  /**
   * brief Sets the path traced by the robot by digit 5 in the matrix.
   * @param path is a vector containing the points in the form
   * of eigen vector traced by the robot.
   * @return None
   */
  void setPath(std::vector<Eigen::Vector2d> path);

 private:

  /**
   * @brief This is a matrix initialization for the map using Eigen library
   */
  Eigen::MatrixXd map = Eigen::MatrixXd::Zero(20, 20);
};

#endif /* INCLUDE_MAP_H_ */

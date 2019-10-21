/*
 * @copyright 2019
 * @copyright MIT License
 * @file Astar.h
 * Design (Phase 1)
 * @author Nischal NJ - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design keeper
 * @date 12/10/2019
 * Implementation (Phase 2)
 * @author Nischal Nj - Design keeper
 * @author Vamshi - Navigator
 * @author Raja - Driver
 * @date 20/10/2019
 * @version 1.0
 * @brief header file for Astar class which is used to compute the shortest path between two points avoiding obstacles.
 */

#include "NodesManager.h"
#include "Actions.h"
#include "Map.h"
#include <eigen3/Eigen/Dense>
#include <vector>
#include <math.h>
#include <map>
#include <iterator>

#ifndef INCLUDE_ASTAR_H_
#define INCLUDE_ASTAR_H_

/**
 * @brief Astar class is used to implement the A* algorithm. Euclidean heuristic is used for this algorithm.
 * A star gives the shortest path while avoiding obstacles
 */
class Astar {
 public:
  Astar();
  ~Astar();

  /**
   * @brief In this method, the shortest path will be computed using the A* algorithm
   * @param None
   * @return std::vector<Eigen::Vector2d> returns path obtained from astar algorithm.
   */
  std::vector<Eigen::Vector2d> aStarAlgorithm();

  /**
   * @brief shows the final path which was computed by the A* algorithm (Backtracking)
   * @param None
   * @return None
   */
  void pathBacktracking();

  /**
   * @brief
   * @param struct position that represents current position of the robot
   * on the map.
   * @param struct new position that represents next position of the robot
   * on the map
   * @param double d which specifies cost specific to an action 1 for up
   * down right left. sqrt(2) for remaining four actions.
   * @return None
   */
  void checkAndUpdate(const Position& currentPosition,
                        const Position& newPosition, double d);

  /**
   * @brief Calculates the cost to go for the current position and goal position
   * (Euclidean Distance between the two points)
   * @param current position, stuct Position
   * @return Double Cost to go
   */
  double computeCostToGo(const Position& pos);

  /**
   * @brief Is used to retrieve the start position
   * @param None
   * @return Struct position
   */
  Position getStartPosition();

  /**
   * @brief Is used to retrieve the goal position
   * @param None
   * @return Struct position
   */
  Position getGoalPosition();

  /**
   * @brief Is used to set the start position
   * @param int x and y coordinates for start position
   * @return None
   */
  void setStartPosition(int x, int y);

  /**
   * @brief Is used to set the goal position
   * @param int x and y coordinates for goal position
   * @return None
   */
  void setGoalPosition(int x, int y);

 private:
  Position startPosition;
  Position goalPosition;
  std::vector<Eigen::Vector2d> path;
};

#endif /* INCLUDE_ASTAR_H_ */

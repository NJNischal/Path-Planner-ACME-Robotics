/*
 * @copyright 2019
 * @copyright MIT License
 * @file NodesManager.h
 * Design
 * @author Nischal NJ - Navigator
 * @author Vamshi - Design Keeper
 * @author Raja - Driver
 * @version 1.0
 * @date 11/10/2019
 * @brief Header file for class NodesManager.
 */

#ifndef INCLUDE_NODESMANAGER_H_
#define INCLUDE_NODESMANAGER_H_

#include <eigen3/Eigen/Dense>

/**
 * @brief This is a struct with two attributes x and y.
 */
struct Position {
  int x = 0;
  int y = 0;
};

/**
 * @brief NodesManager class is used to manage and update all the matrices that is required for
 * implementation of A star algorithm
 */
class NodesManager {
 public:
  NodesManager();
  ~NodesManager();

  /**
   * @brief Takes the current node as index for the Visited matrix and updates the status
   * at that index. Status is 1 if visited, else 0.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return None
   */
  void updateVisited(const Position& pos);

  /**
   * @brief Takes the current node as index for the Parent matrix and updates the parent for the node
   * Each parent for current node is associated with unique ID.
   * Ex. For node (1,1), (1,2) as parent.
   * Parent for (1,1) is represented by (x-coordinate*100 + y-coordinate)
   * i.e. (1,2) - id is 102
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return None
   */
  void updateParent(const Position& pos);

  /**
   * @brief Takes the current node as index for the Cost matrix and updates the cost at that index
   * @param Position struct which has x,y value, coordinates of a given location
   * @param double cost, this is the sum of cost to come and cost to go
   * @return None
   */
  void updateCost(const Position& pos, double cost);

  /**
   * @brief Takes the current node as index for the CostToCome matrix and updates the cost
   * Status is 1 if visited, else 0.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @param double cost, this is the cost from start node to the current node (Eucledian distance)
   * @return None
   */
  void updateCostToCome(const Position& pos, double cost);

  /**
   * @brief Takes the current node as index for the CostToGo matrix and updates the status
   * Status is 1 if visited, else 0.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @param double cost, this is the cost from the current node to the goal position (Eucledian distance)
   * @return None
   */
  void updateCostToGo(const Position& pos, double cost);

  /**
   * @brief Returns the parent for the current node taking the current node as index in the Parent matrix
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return int unique parent ID (Parent for (1,1) is represented by (x-coordinate*100 + y-coordinate))
   */
  int getParent(const Position& pos);

  /**
   * @brief Takes the current node as index for the Visited matrix and updates the status
   * Status is 1 if visited, else 0.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return int, this is the visited status, 1 is visited, 0 is unvisited
   */
  int getVisitedStatus(const Position& pos);

  /**
   * @brief Takes the current node as index for the Cost matrix and returns the cost associated.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return double cost, this is the total cost for a particular node
   */
  double getCost(const Position& pos);

  /**
   * @brief Takes the current node as index for the CostToCome matrix and returns the cost associated.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return double cost, this is the cost to come associated with the current node.
   */
  double getCostToCome(const Position& pos);

  /**
   * @brief Takes the current node as index for the CostToGo matrix and returns the cost associated.
   * @param Position struct which has x,y value, coordinates of a given location.
   * @return double cost, this is the cost to come associated with the current node.
   */
  double getCostToGo(const Position& pos);

 private:
  Eigen::MatrixXd visitedMatrix = Eigen::MatrixXd::Zero(20, 20);
  Eigen::MatrixXd parentMatrix = Eigen::MatrixXd::Zero(20, 20);
  Eigen::MatrixXd costMatrix = Eigen::MatrixXd::Zero(20, 20);
  Eigen::MatrixXd costToComeMatrix = Eigen::MatrixXd::Zero(20, 20);
  Eigen::MatrixXd costToGoMatrix = Eigen::MatrixXd::Zero(20, 20);

};

#endif /* INCLUDE_NODESMANAGER_H_ */

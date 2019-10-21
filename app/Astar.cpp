/*
 * @copyright 2019
 * @copyright MIT License
 * @file Astar.cpp
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
 * @brief cpp implementation file for Astar class which is used to compute the shortest path between two points avoiding obstacles.
 */

#include "Astar.h"

Astar::Astar() {
}

Astar::~Astar() {
}

std::vector<Eigen::Vector2d> Astar::aStarAlgorithm() {
  Eigen::Vector2d a(5, 6);
  std::vector<Eigen::Vector2d> p(4, a);
  return p;
}

void Astar::pathBacktracking() {
}

void Astar::checkAndUpdate(const Position& currentPosition,
                           const Position& newPosition, double d) {
  // checks
  bool check1 = workspace.obstacleCheck(newPosition);
  bool check2 = workspace.validityCheck(newPosition);

  if (!check1 && check2) {
    bool status = manageNodes.getVisitedStatus(newPosition);
    if (!status) {
      manageNodes.updateVisited(newPosition);
      int parentId = currentPosition.x * 100 + currentPosition.y;
      manageNodes.updateParent(newPosition, parentId);
      auto costGo = computeCostToGo(newPosition);
      double costCome = manageNodes.getCostToCome(currentPosition) + d;
      double totalCost = costGo + costCome;
      manageNodes.updateCostToGo(newPosition, costGo);
      manageNodes.updateCostToCome(newPosition, costCome);
      manageNodes.updateCost(newPosition, totalCost);
      priority.insert(std::pair<double, Position>(totalCost, newPosition));
    } else {
      if (manageNodes.getCostToCome(newPosition)
          > manageNodes.getCostToCome(currentPosition) + d) {
        auto costGo = computeCostToGo(newPosition);
        double costCome = manageNodes.getCostToCome(currentPosition) + d;
        double totalCost = costGo + costCome;
        manageNodes.updateCostToGo(newPosition, costGo);
        manageNodes.updateCostToCome(newPosition, costCome);
        manageNodes.updateCost(newPosition, totalCost);
        int parentId = currentPosition.x * 100 + currentPosition.y;
        manageNodes.updateParent(newPosition, parentId);
      }
    }
  }

}

double Astar::computeCostToGo(const Position& pos) {
  double cost = sqrt(
      pow((goalPosition.x - pos.x), 2) + pow((goalPosition.y - pos.y), 2));
  return cost;
}

Position Astar::getStartPosition() {
  return startPosition;
}

Position Astar::getGoalPosition() {
  return goalPosition;
}

void Astar::setStartPosition(int x, int y) {
  startPosition.x = x;
  startPosition.y = y;
}

void Astar::setGoalPosition(int x, int y) {
  goalPosition.x = x;
  goalPosition.y = y;
}


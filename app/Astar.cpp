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

Astar::Astar(Map& map)
    : workspace(map) {
}

Astar::~Astar() {
}

std::vector<Eigen::Vector2d> Astar::aStarAlgorithm() {
  Position currentPosition;
  currentPosition.x = startPosition.x;
  currentPosition.y = startPosition.y;

  while (!(currentPosition == goalPosition)) {
    // marking current position as visited
    manageNodes.updateVisited(currentPosition);

    // write all actions
    Position newPosition = action.moveUp(currentPosition);
    checkAndUpdate(currentPosition, newPosition, 1);

    newPosition = action.moveDown(currentPosition);
    checkAndUpdate(currentPosition, newPosition, 1);

    newPosition = action.moveRight(currentPosition);
    checkAndUpdate(currentPosition, newPosition, 1);

    newPosition = action.moveLeft(currentPosition);
    checkAndUpdate(currentPosition, newPosition, 1);

    newPosition = action.moveUpRight(currentPosition);
    checkAndUpdate(currentPosition, newPosition, sqrt(2));

    newPosition = action.moveUpLeft(currentPosition);
    checkAndUpdate(currentPosition, newPosition, sqrt(2));

    newPosition = action.moveDownRight(currentPosition);
    checkAndUpdate(currentPosition, newPosition, sqrt(2));

    newPosition = action.moveDownLeft(currentPosition);
    checkAndUpdate(currentPosition, newPosition, sqrt(2));

    std::multimap<double, Position>::iterator iter;
    iter = priority.begin();
    currentPosition = iter->second;
    priority.erase(iter);
  }

  pathBacktracking();

  for (auto iter = path.begin(); iter != path.end(); ++iter) {
    std::cout << *iter << std::endl;
  }

  workspace.setPath(path);
  return path;
}

void Astar::pathBacktracking() {
  Position currentNode;
  currentNode.x = goalPosition.x;
  currentNode.y = goalPosition.y;
  Eigen::Vector2d v(currentNode.x, currentNode.y);
  path.push_back(v);
  while (!(currentNode == startPosition)) {
    int px, py, p;
    p = manageNodes.getParent(currentNode);
    px = p / 100;
    py = p % 100;
    v[0] = px;
    v[1] = py;
    path.push_back(v);
    currentNode.x = px;
    currentNode.y = py;
  }
  std::reverse(path.begin(), path.end());
}

void Astar::checkAndUpdate(const Position& currentPosition,
                           const Position& newPosition, double d) {
  // checks
  bool check2 = workspace.validityCheck(newPosition);
  bool check1 = true;
  if (check2) {
    check1 = workspace.obstacleCheck(newPosition);
  }

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

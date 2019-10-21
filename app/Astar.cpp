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
  (void) currentPosition;
  (void) newPosition;
  (void) d;

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


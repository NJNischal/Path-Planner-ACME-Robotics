/*
 * @copyright 2019
 * @copyright MIT License
 * @file Astar.cpp
 * Design
 * @author Nischal NJ - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design pattern
 * @version 1.0
 * @date 11/10/2019
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

double Astar::computeCostToGo(const Position& pos, const Position& posi) {
  (void) pos;
  (void) posi;
  return 1.0;
}

double Astar::computeCostToCome(const Position& pos, const Position& posi) {
  (void) pos;
  (void) posi;
  return 1.0;
}

Position Astar::getStartPosition() {
  Position posi;
  posi.x = 5;
  posi.y = 6;
  return posi;
}

Position Astar::getGoalPosition() {
  Position posi;
  posi.x = 5;
  posi.y = 6;
  return posi;
}

void Astar::setStartPosition(int x, int y) {
  (void) x;
  (void) y;
}

void Astar::setGoalPosition(int x, int y) {
  (void) x;
  (void) y;
}

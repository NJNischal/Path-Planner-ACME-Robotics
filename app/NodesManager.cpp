/*
 * @copyright 2019
 * @copyright MIT License
 * @file NodesManager.cpp
 * Design
 * @author Nischal NJ - Navigator
 * @author Vamshi - Design Keeper
 * @author Raja - Driver
 * @date 12/10/2019
 * Implementation (Phase 2)
 * @author Nischal Nj - Navigator
 * @author Vamshi - Driver
 * @author Raja - Design keeper
 * @date 20/10/2019
 * @version 1.0
 * @brief Implementation of NodesManager class.
 */

#include "NodesManager.h"

NodesManager::NodesManager() {
}

NodesManager::~NodesManager() {
}

void NodesManager::updateVisited(const Position& pos) {
  visitedMatrix(pos.x, pos.y) = 1;  // mark as visited
}

void NodesManager::updateParent(const Position& pos, int parentId) {
  parentMatrix(pos.x, pos.y) = parentId;  // store parent id
}

void NodesManager::updateCost(const Position& pos, double cost) {
  costMatrix(pos.x, pos.y) = cost;  // store total cost
}

void NodesManager::updateCostToCome(const Position& pos, double cost) {
  costToComeMatrix(pos.x, pos.y) = cost;  // store cost to come
}

void NodesManager::updateCostToGo(const Position& pos, double cost) {
  costToGoMatrix(pos.x, pos.y) = cost;  // store cost to go
}

int NodesManager::getParent(const Position& pos) {
  int parentId = parentMatrix(pos.x, pos.y);
  return parentId;
}

int NodesManager::getVisitedStatus(const Position& pos) {
  if (visitedMatrix(pos.x, pos.y) == 1) {
    return 1;  // says visited
  }
  return 0;
}

double NodesManager::getCost(const Position& pos) {
  double cost = costMatrix(pos.x, pos.y);
  return cost;
}

double NodesManager::getCostToCome(const Position& pos) {
  double cost = costToComeMatrix(pos.x, pos.y);
  return cost;
}

double NodesManager::getCostToGo(const Position& pos) {
  double cost = costToGoMatrix(pos.x, pos.y);
  return cost;
}

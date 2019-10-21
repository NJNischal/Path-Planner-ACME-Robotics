/*
 * @copyright 2019
 * @copyright MIT License
 * @file NodesManager.cpp
 * Design
 * @author Nischal NJ - Navigator
 * @author Vamshi - Design Keeper
 * @author Raja - Driver
 * @version 1.0
 * @date 11/10/2019
 * @brief Implementation of NodesManager class.
 */

#include "NodesManager.h"

NodesManager::NodesManager() {
}

NodesManager::~NodesManager() {
}

void NodesManager::updateVisited(const Position& pos) {
  (void) pos;
}

void NodesManager::updateParent(const Position& pos, int parentId) {
  (void) pos;
  (void) parentId;
}

void NodesManager::updateCost(const Position& pos, double cost) {
  (void) pos;
  (void) cost;
}

void NodesManager::updateCostToCome(const Position& pos, double cost) {
  (void) pos;
  (void) cost;
}

void NodesManager::updateCostToGo(const Position& pos, double cost) {
  (void) pos;
  (void) cost;
}

int NodesManager::getParent(const Position& pos) {
  (void) pos;
  return 1;
}

int NodesManager::getVisitedStatus(const Position& pos) {
  (void) pos;
  return 2;
}

double NodesManager::getCost(const Position& pos) {
  (void) pos;
  return 2;
}

double NodesManager::getCostToCome(const Position& pos) {
  (void) pos;
  return 2;
}

double NodesManager::getCostToGo(const Position& pos) {
  (void) pos;
  return 2;
}


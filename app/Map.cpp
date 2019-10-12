/*
 * @copyright 2019
 * @copyright MIT License
 * @file Map.cpp
 * Design (Phase 1)
 * @author Nischal Nj - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design keeper
 * @version 1.0
 * @date 11/10/2019
 * @brief implementation of class Map that defines the location of obstacles
 * in the environment in which the robot operates.
 */

#include "Map.h"

Map::Map() {
  createMap();
}

Map::~Map() {
}

void Map::createMap() {
  map.block(2, 2, 4, 4).setOnes();
  map.block(2, 12, 4, 4).setOnes();
  map.block(14, 5, 4, 8).setOnes();
  std::cout << map;
}

bool Map::obstacleCheck(const Position& newPos) {
  (void) newPos;
  return true;
}

bool Map::validityCheck(const Position& newPos) {
  (void) newPos;
  return true;
}

void Map::plotMap() {
  std::cout << "Complete map will be shown.";
}

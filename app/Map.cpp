/*
 * @copyright 2019
 * @copyright MIT License
 * @file Map.cpp
 * Design (Phase 1)
 * @author Nischal Nj - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design keeper
 * @date 11/10/2019
 * Implementation (Phase 2)
 * @author Nischal Nj - Navigator
 * @author Vamshi - Design keeper
 * @author Raja - Driver
 * @date 19/10/2019
 * @version 1.0
 * @brief implementation of class Map that defines the location of obstacles
 * in the environment in which the robot operates.
 */

#include "Map.h"

Map::Map() {
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
  // checks for number 0 or 1
  if (map(newPos.x, newPos.y) == 0) {
    return 0;
  }
  return 1;
}

bool Map::validityCheck(const Position& newPos) {
  // checks boundary conditions of the map
  if (newPos.x >= 0 && newPos.x < 20 && newPos.y >= 0 && newPos.y < 20) {
    return 1;  // returns 1 if position is valid
  }
  return 0;
}

void Map::setPath(std::vector<Eigen::Vector2d> path) {
  // sets number 5 in the map matrix to path obtained.
  for (auto iter = path.begin(); iter != path.end(); ++iter) {
    auto vector = *iter;
    map(vector[0], vector[1]) = 5;
  }
}

void Map::plotMap() {
  std::cout << "Map of the workspace." << std::endl;
  std::cout << map << std::endl;
}

/*
 * @copyright 2019
 * @copyright MIT License
 * @file Actions.cpp
 * Design
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @date 11/10/2019
 * Implementation (Phase 2)
 * @author Nischal Nj - Driver
 * @author Vamshi - Design keeper
 * @author Raja - Navigator
 * @date 19/10/2019
 * @version 1.0
 * @brief Implementation of Actions class which contains the moves the robot can make
 * in the map (Workspace)
 */


#include <Actions.h>

Actions::Actions() {
}

Actions::~Actions() {
}

Position Actions::moveUp(const Position& currentPos) {
  newPosition.x = currentPos.x - 1;
  newPosition.y = currentPos.y;
  return newPosition;
}

Position Actions::moveDown(const Position& currentPos) {
  newPosition.x = currentPos.x + 1;
  newPosition.y = currentPos.y;
  return newPosition;
}

Position Actions::moveLeft(const Position& currentPos) {
  newPosition.x = currentPos.x;
  newPosition.y = currentPos.y - 1;
  return newPosition;
}

Position Actions::moveRight(const Position& currentPos) {
  newPosition.x = currentPos.x;
  newPosition.y = currentPos.y + 1;
  return newPosition;
}

Position Actions::moveUpRight(const Position& currentPos) {
  newPosition.x = currentPos.x - 1;;
  newPosition.y = currentPos.y + 1;
  return newPosition;
}

Position Actions::moveUpLeft(const Position& currentPos) {
  newPosition.x = currentPos.x - 1;
  newPosition.y = currentPos.y - 1;
  return newPosition;
}

Position Actions::moveDownRight(const Position& currentPos) {
  newPosition.x = currentPos.x + 1;
  newPosition.y = currentPos.y + 1;
  return newPosition;
}

Position Actions::moveDownLeft(const Position& currentPos) {
  newPosition.x = currentPos.x + 1;
  newPosition.y = currentPos.y - 1;
  return newPosition;
}



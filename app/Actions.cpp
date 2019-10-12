/*
 * @copyright 2019
 * @copyright MIT License
 * @file Actions.cpp
 * Design
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @version 1.0
 * @date 11/10/2019
 * @brief Implementation of Actions class which contains the moves the robot can make
 * in the map (Workspace)
 */


#include <Actions.h>

Actions::Actions() {
}

Actions::~Actions() {
}

Position Actions::moveUp(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveDown(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveLeft(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveRight(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveUpRight(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveUpLeft(const Position& currentPos) {
  newPosition.x = 10;
  (void) currentPos;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveDownRight(const Position& currentPos) {
  (void) currentPos;
  newPosition.x = 10;
  newPosition.y = 10;
  return newPosition;
}

Position Actions::moveDownLeft(const Position& currentPos) {
  newPosition.x = 10;
  (void) currentPos;
  newPosition.y = 10;
  return newPosition;
}



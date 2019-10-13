/*
 * @copyright 2019
 * @copyright MIT License
 * @file Actions.h
 * Design
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @version 1.0
 * @date 11/10/2019
 * @brief Header file for class Actions
 */


#ifndef INCLUDE_ACTIONS_H_
#define INCLUDE_ACTIONS_H_
#include "NodesManager.h"


class Actions {
 public:
  Actions();
  ~Actions();

  /**
   * @brief Gives the position which is above the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveUp(const Position& currentPos);

  /**
   * @brief Gives the position which is below the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveDown(const Position& currentPos);

  /**
   * @brief Gives the position which is to the left of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position  moveLeft(const Position& currentPos);

  /**
   * @brief Gives the position which is to the right of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveRight(const Position& currentPos);

  /**
   * @brief Gives the position which is to the top-right of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position  moveUpRight(const Position& currentPos);

  /**
   * @brief Gives the position which is to the top-left of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveUpLeft(const Position& currentPos);

  /**
   * @brief Gives the position which is to the down-left of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveDownRight(const Position& currentPos);

  /**
   * @brief Gives the position which is to the bottom right of the current position
   * @param Position struct which has x,y value, coordinates of a given location
   * @return Position struct which has x,y value, coordinates of new position.
   */
  Position moveDownLeft(const Position& currentPos);

 private:

  Position newPosition;

};
#endif /* INCLUDE_ACTIONS_H_ */

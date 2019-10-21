/*
 * @copyright 2019
 * @copyright MIT License
 * @file Actions.h
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
 * @brief Header file for class Actions
 */


#ifndef INCLUDE_ACTIONS_H_
#define INCLUDE_ACTIONS_H_
#include "NodesManager.h"

/**
 * @brief Actions class is used to generate movement for the robot in the action space which is in 8 directions.
 */
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

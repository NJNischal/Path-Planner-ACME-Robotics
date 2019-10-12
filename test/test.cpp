/*
 * @copyright 2019
 * @copyright MIT License
 * @file test.cpp
 * Design (Phase 1)
 * @author Nischal NJ - Design Keeper
 * @author Vamshi - Driver
 * @author Raja - Navigator
 * @version 1.0
 * @date 11/10/2019
 * @brief Unit test cases for testing classes
 * in the environment in which the robot operates.
 */

#include <gtest/gtest.h>
#include "Map.h"
#include "Nodes.h"
#include "Actions.h"

  /**
   * @brief This is a test for methods in Map class
   */
TEST(mapTest, testMapMethod) {
  Map m;
  Position newPos;
  newPos.x = 1;
  newPos.y = 1;

  EXPECT_FALSE(m.obstacleCheck(newPos));
  EXPECT_FALSE(m.validityCheck(newPos));
}

/**
 * @brief This is a test for methods in Actions class
 */
TEST(actionsTest, testActionsMethods) {
  Actions action;
  Position newPos;
  newPos.x = 1;
  newPos.y = 1;
  EXPECT_EQ(0, action.moveUp(newPos).x);
  EXPECT_EQ(1, action.moveUp(newPos).y);
  EXPECT_EQ(2, action.moveDown(newPos).x);
  EXPECT_EQ(1, action.moveDown(newPos).y);
  EXPECT_EQ(1, action.moveLeft(newPos).x);
  EXPECT_EQ(0, action.moveLeft(newPos).y);
  EXPECT_EQ(1, action.moveRight(newPos).x);
  EXPECT_EQ(2, action.moveRight(newPos).y);
  EXPECT_EQ(0, action.moveUpRight(newPos).x);
  EXPECT_EQ(2, action.moveUpRight(newPos).y);
  EXPECT_EQ(0, action.moveUpLeft(newPos).x);
  EXPECT_EQ(0, action.moveUpLeft(newPos).y);
  EXPECT_EQ(2, action.moveDownRight(newPos).x);
  EXPECT_EQ(2, action.moveDownRight(newPos).y);
  EXPECT_EQ(2, action.moveDownLeft(newPos).x);
  EXPECT_EQ(0, action.moveDownLeft(newPos).y);
}

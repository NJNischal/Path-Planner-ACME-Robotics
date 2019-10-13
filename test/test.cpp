/*
 * @copyright 2019
 * @copyright MIT License
 * @file test.cpp
 * Design (Phase 1)
 * @author Nischal NJ - Navigator
 * @author Vamshi - Design Keeper
 * @author Raja - Driver
 * @version 1.0
 * @date 11/10/2019
 * @brief Unit test cases for testing classes
 * in the environment in which the robot operates.
 */

#include <gtest/gtest.h>
#include <math.h>
#include "Map.h"
#include "NodesManager.h"
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

/**
 * @brief This is a test for methods in NodesManager class
 */
TEST(nodesTest, testNodesManagerMethods) {
  Position newPos;
  newPos.x = 1;
  newPos.y = 1;

  Position currentPos;
  currentPos.x = 0;
  currentPos.y = 0;

  Position goalPos;
  goalPos.x = 5;
  goalPos.y = 2;

  NodesManager node;

  node.updateCost(newPos, sqrt(2) + sqrt(17));
  node.updateCostToCome(newPos, sqrt(2));
  node.updateCostToGo(newPos, sqrt(17));

  EXPECT_EQ(2, node.getCost(newPos));
  EXPECT_EQ(1, node.getCostToCome(newPos));
  EXPECT_EQ(1, node.getCostToGo(newPos));

  node.updateParent(newPos);
  node.updateVisited(newPos);
  EXPECT_EQ(00, node.getParent(newPos));
  EXPECT_EQ(1, node.getVisitedStatus(currentPos));
}


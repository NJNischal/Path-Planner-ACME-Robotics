/*
 * @copyright 2019
 * @copyright MIT License
 * @file test.cpp
 * Design (Phase 1)
 * @author Nischal Nj - Driver
 * @author Vamshi - Navigator
 * @author Raja - Design keeper
 * @version 1.0
 * @date 11/10/2019
 * @brief Unit test cases for testing classes
 * in the environment in which the robot operates.
 */

#include <gtest/gtest.h>
#include "Map.h"
#include "Nodes.h"

TEST(mapTest, testMapMethod) {
  Map m;
  Position newPos;
  newPos.x = 1;
  newPos.y = 1;
  EXPECT_FALSE(m.obstacleCheck(newPos));
  EXPECT_FALSE(m.validityCheck(newPos));
}

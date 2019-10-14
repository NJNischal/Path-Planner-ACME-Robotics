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
#include "Astar.h"

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

/**
 * @brief This is a test for methods in Astar class
 */
TEST(astarTest, testAstarMethods) {
	Astar astar;

	Eigen::Vector2d a1(1, 1);
	Eigen::Vector2d b1(1, 2);
	Eigen::Vector2d c1(1, 3);
	Eigen::Vector2d d1(1, 4);
	std::vector<Eigen::Vector2d> p { a1, b1, c1, d1 };
	std::vector<Eigen::Vector2d> path = astar.aStarAlgorithm();
	std::vector<Eigen::Vector2d>::iterator iter2 = path.begin();

	for (std::vector<Eigen::Vector2d>::iterator iter1 = p.begin();
			iter1 != p.end(); iter1++) {
		Eigen::Vector2d a = *iter1;
		Eigen::Vector2d b = *iter2;
		EXPECT_EQ(a[0], b[0]);
		EXPECT_EQ(a[1], b[1]);
		iter2++;
	}

	astar.setStartPosition(1, 1);
	EXPECT_EQ(1, astar.getStartPosition().x);
	EXPECT_EQ(1, astar.getStartPosition().y);

	astar.setGoalPosition(1, 4);
	EXPECT_EQ(1, astar.getGoalPosition().x);
	EXPECT_EQ(4, astar.getGoalPosition().y);

	Position startPos;
	startPos.x = 1;
	startPos.y = 1;

	Position currentPos;
	currentPos.x = 1;
	currentPos.y = 3;

	Position goalPos;
	goalPos.x = 1;
	goalPos.y = 4;

	EXPECT_EQ(2, astar.computeCostToCome(startPos, currentPos));
	EXPECT_EQ(1, astar.computeCostToGo(goalPos, currentPos));
}

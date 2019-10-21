/**
 * @copyright MIT License
 * @file main.cpp
 * Implementation (Phase 2)
 * @author Nischal NJ - Navigator
 * @author Vamshi - Driver 
 * @author Raja - Design Keeper
 * @version 1.0
 * @date 21/10/2019
 * @brief This is the main file for this project.
 */

#include <iostream>
#include "Map.h"
#include "NodesManager.h"
#include "Actions.h"
#include "Astar.h"
#include "Iksolver.h"

int main() {
// create map of environment
  Map map;
  map.createMap();

  Astar algorithm(map);
  bool value = false;

  // To take user input
  std::cout
      << "To enter your own start and goal position"
          " enter 1,to use pre defined values enter 0"<< std::endl;
  std::cin >> value;
  if (value == true) {
    std::cout << "enter start position between (0,0) and (19,19)" << std::endl;
    int x = 0;
    int y = 0;
    std::cin >> x >> y;
    algorithm.setStartPosition(x, y);
    auto startpositioncheck = algorithm.getStartPosition();
    bool startCheck = map.obstacleCheck(startpositioncheck);
    while (startCheck) {
      std::cout << "Obstacle found, enter valid start position" << std::endl;
      std::cin >> x >> y;
      algorithm.setStartPosition(x, y);
      startpositioncheck = algorithm.getStartPosition();
      startCheck = map.obstacleCheck(startpositioncheck);
    }
    int a = 0;
    int b = 0;

    std::cout << "enter goal position" << std::endl;
    std::cin >> a >> b;
    algorithm.setGoalPosition(a, b);
    auto goalpositioncheck = algorithm.getGoalPosition();
    bool goalCheck = map.obstacleCheck(goalpositioncheck);
    while (goalCheck) {
      std::cout << "Obstacle found, enter valid goal position" << std::endl;
      std::cin >> a >> b;
      algorithm.setGoalPosition(a, b);
      goalpositioncheck = algorithm.getGoalPosition();
      goalCheck = map.obstacleCheck(goalpositioncheck);
    }
  } else {
    // setting start (1,1) and goal positions (18,18)
    algorithm.setStartPosition(1, 1);
    algorithm.setGoalPosition(18, 18);
  }

  // calling astar algorithm
  std::vector<Eigen::Vector2d> solution = algorithm.aStarAlgorithm();

  // plotting final map
  map.plotMap();

  // solving inverse kinematics
  Iksolver solve;
  std::vector<JointAngles> jointangles = solve.ikSolver(solution);
  int i = 1;
  std::cout << std::endl << "The Joint angles are: " << std::endl;
  for (auto iter : jointangles) {
    std::cout << "Point " << i << " " << '{' << iter.thetha1 << " "
              << iter.thetha2 << " " << iter.thetha3 << " " << iter.thetha4
              << " " << iter.thetha5 << " " << iter.thetha6 << '}' << std::endl;
    i++;
  }
}


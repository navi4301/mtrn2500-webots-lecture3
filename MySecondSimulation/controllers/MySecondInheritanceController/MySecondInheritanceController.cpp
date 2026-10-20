// File:          MySecondControllerInheritance.cpp
// Date:
// Description:
// Author:
// Modifications:

#include "EPuckRobot.hpp"

int main(int argc, char **argv) {

  EPuckRobot ePuckRobot {};
  ePuckRobot.run();
  // DistanceSensor and Motor are owned and managed by Robot, 
  // so we can use Raw Pointers for these components as we are just observing them
  // and not responsible for freeing them 
  return 0;
}


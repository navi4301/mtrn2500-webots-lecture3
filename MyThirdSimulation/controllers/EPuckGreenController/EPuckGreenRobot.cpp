#include "EPuckGreenRobot.hpp"
#include <iostream>

EPuckGreenRobot::EPuckGreenRobot()
    : mKeyboard {getKeyboard()}
    {
        mKeyboard->enable(TIME_STEP);
}


void EPuckGreenRobot::display() const {
    std::cout << "[EPuckGreenRobot]: Press and hold t/T and I'll turn myself.\n";
    std::cout << "[EPuckGreenRobot]: Click b/B and I'll ask EPuckBlackRobot to move backward.\n";
    std::cout << "[EPuckGreenRobot]: Click r/R and I'll ask EPuckBlackRobot to roam.\n";
}

void EPuckGreenRobot::turn() {
    const double speedScale {0.5};
    //configure speed
    mLeftSpeed  = speedScale * MAX_SPEED;
    mRightSpeed = -speedScale * MAX_SPEED;
    // send speed to motors
    mLeftMotor->setVelocity(mLeftSpeed);
    mRightMotor->setVelocity(mRightSpeed);
}

//we overide the run func 
void EPuckGreenRobot::run() {
// can also put in construction
    display();
    while (step(TIME_STEP) != -1) {
        int k {mKeyboard->getKey()};
        if(k == 'T') {
            //turn right
            turn();
        } else {
            // inherited from epuck robot
            roam();
        }
    }
}
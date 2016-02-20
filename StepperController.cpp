//
//  StepperController.cpp
//  StepperController
//
//  Created by Tiago Santos on 05/02/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#include "StepperController.hpp"

/*  Step Right (1) or Left (-1)
 *  step: {-1,0,1}
 */
void StepperController::step(int step){
    state+=step;
}

/*  Get current motor state
 *  s1= coil 1, s2= coil 2, s3= !s2, s4=!s1
 */
void StepperController::getState(int *s1, int *s2){
    *s1= states[state%4][0];
    *s2= states[state%4][1];
}
 /* Move right or left with the given speed. Time is the current time in millis
  * speed: between [0 , 255]
  * direction: {-1,0,1}
  */
bool StepperController::move(unsigned char speed, char direction, unsigned long time){
    if( lastupdate + (-21*speed+7058) <= time){ 
        step(direction);
        lastupdate= time;
        return true;
    }
    return false;
}

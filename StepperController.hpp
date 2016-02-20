//
//  StepperController.hpp
//  StepperController
//
//  Created by Tiago Santos on 05/02/16.
//  Copyright © 2016 Tiago Santos. All rights reserved.
//

#ifndef StepperController_hpp
#define StepperController_hpp


class StepperController{
public:
    /*  Step Right (1) or Left (-1)
     *  step: {-1,0,1}
     */
    void step(int step);
    
    /*  Get current motor state
     *  s1= coil 1, s2= coil 2, s3= !s2, s4=!s1
     */
    void getState(int* s1, int* s2);
    
    /* Move right or left with the given speed. Time is the current time in millis
     * speed: between [0 , 255]
     * direction: {-1,0,1}
     */
    bool move(unsigned char speed, char direction, unsigned long time);
    
private:
    unsigned char state= 0;
    char states[4][2]={{0,1},{1,1},{1,0},{0,0}};
    unsigned long lastupdate= 0;
};

#endif /* StepperController_hpp */

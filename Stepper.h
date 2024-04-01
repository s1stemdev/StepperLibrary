//
// Created by systemdev on 31.03.24.
//

#ifndef UNTITLED3_STEPPER_H
#define UNTITLED3_STEPPER_H

class Stepper {
public:
    short aPlus;
    short aMinus;
    short bPlus;
    short bMinus;

    bool unsafeMode = false;

    Stepper(short aPlus, short aMinus, short bPlus, short bMinus);

    /**
     * Running your Stepper.
     *
     * @param speed The speed at which the Stepper rotates. Delay between switches.
     * Maximal recommended speed is 65530. (Delay = 65535 - speed)
     *
     * @param side Side of rotating. (Right is 1;   Left is -1;   Stop is 0)
     */
    void run(unsigned short speed, short side) {
        if(side == 1) runRight(speed);
        if(side == -1) runLeft(speed);
        if(side == 0) stop();
    }

    /**
     * Makes the Stepper turn to the RIGHT
     *
     * @param speed The speed at which the Stepper rotates. Delay between switches.
     * Maximal recommended speed is 65530. (Delay = 65535 - speed)
     */
    void runRight(short speed);

    /**
     * Makes the Stepper turn to the LEFT
     *
     * @param speed The speed at which the Stepper rotates. Delay between switches.
     * Maximal recommended speed is 65530. (Delay = 65535 - speed)
     */
    void runLeft(short speed);

    /**
     * Just stopping your Stepper
     */
    void stop();

    /**
     * Entering unsafe mode allows to set speed larger than 65530
     */
    void enterUnsafe();

    /**
     * Default mode. You can't use speed larger than 65530
     */
    void exitUnsafe();
};


#endif //UNTITLED3_STEPPER_H

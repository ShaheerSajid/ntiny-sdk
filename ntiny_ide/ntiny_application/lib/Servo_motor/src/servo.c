
    #include "pwm.h"
    #include "servo.h"

    void init_servo(){
        pwm_init();
        set_period1(360);// resolution of one angle
        set_prescaler(2777); // default frequency of 50 Hz with above resoluion
         
    }

    uint8_t servo_move_angle(uint16_t micro_second)
    {
        if (micro_second >2500 || micro_second <500)
        {
            return -1;
        }
        uint8_t compare = (micro_second*360)/20000;
        set_compare1(compare);
        return 0;
    }
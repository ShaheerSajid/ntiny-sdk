#include"uart.h"
#include<time.h>
#include<stdint.h>
#include"pwm.h"
#include"gpio.h"
#include"ee_printf.h"
//Define Variables we'll be connecting to
float Setpoint, Input, Output;
//Specify the links and initial tuning parameters
float Kp=0.1, Ki=0.001, Kd=0;
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
uint64_t t1 = 0;
uint64_t dt = 20;
double P, I, D;
float error;

float set_speed = 2500;

#define micros() (uint64_t)(clock()/(uint64_t)50)
#define millis() (uint64_t)(clock()/(uint64_t)50000)
#define digitalRead(pin) gpio_read_pin(pin)

unsigned int minutes = 0;



int led = 9;
int pulse = 0;

int main(void)
{
   uart_init(2000000);
   pwm_init();
   set_prescaler(392);
   set_period1(255);
   set_compare1(127);
   pwm1_start();


   gpio_mode (0,0);
   gpio_mode(1,0);
   gpio_mode(2,0);
   gpio_mode(3,0);
   gpio_mode(4,0);


   t1 = millis();


   while (1)
   {
	   Setpoint = 30000000.0/set_speed;
      while(!digitalRead(pulse));
      while(digitalRead(pulse));
      unsigned int edge_time = micros();
      while(!digitalRead(pulse));
      unsigned int time_period = 2*(micros()-edge_time) ;

      if(( millis()-  t1) >=  dt)
      {
    	/* minutes++;
    	  if(minutes >60000/dt)
    	  {
    		  minutes = 0.0;
    		  I = 0;
    	  } */

         __asm("csrrw x0, mcycle, x0");
          __asm("csrrw x0, mcycleh, x0");
          t1 = millis();
         error = Setpoint - time_period;

         P = Kp*error;
         D = Kd*error/dt;
         I += Ki*error*dt;
         Output = -(P+I+D);
       /*  ee_printf(" output: %0.2f",Output);
              uart_putc('\t');
		  ee_printf(" t1: %d",(unsigned int)t1);
			uart_putc('\t');
		ee_printf("millis(): %d",(unsigned int)millis());
			uart_putc('\t');*/
         if(Output > 255) Output = 255;
         if(Output < 0)
		 {
        	 //pwm1_stop();
        	 Output = 0;
		 }

         set_compare1(Output);
      }
          if(gpio_read_pin(1))
    	  set_speed = 1000;
      else if(gpio_read_pin(2))
    	  set_speed=2000;

      else if(gpio_read_pin(3))
    	  set_speed=3000;
      else if(gpio_read_pin(4))
    	  set_speed=4000;
   	  else
   	   	   set_speed = 2500;


     ee_printf("%0.2f",set_speed);
      uart_putc('\t');
      ee_printf("%d\n",30000000/time_period);


   }

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       {author}                                                  */
/*    Created:      {date}                                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
// vex::brain       Brain;
// A global instance of vex::competition
vex::competition Competition;

// define your global instances of motors and other devices here
vex::motor leftFront (vex::PORT2, vex::gearSetting::ratio18_1, false);
vex::motor rightFront (vex::PORT3, vex::gearSetting::ratio18_1, true);
vex::motor leftBack (vex::PORT4, vex::gearSetting::ratio18_1, false);
vex::motor rightBack (vex::PORT5, vex::gearSetting::ratio18_1, true);
vex::controller Controller1 = vex::controller();

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */ 
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void driveforward(int time)
{
  
}

void autonomous( void ) {

  // ..........................................................................
  

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

bool blocksucker = false;

void usercontrol( void ) {
  
  Brain.Screen.print("13444DV1 is running");

  while (1) {    
    leftFront.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    leftBack.spin(vex::directionType::fwd, Controller1.Axis3.position(), vex::velocityUnits::pct);
    rightFront.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);
    rightBack.spin(vex::directionType::fwd, Controller1.Axis2.position(), vex::velocityUnits::pct);

    if(Controller1.ButtonUp.pressing())
    {
      // turn on block-sucker using a bool???
      blocksucker = true;
    }

    else if(Controller1.ButtonDown.pressing())
    {
      // turn off block-sucker using same bool!!!
      blocksucker = false;
    }
    
    if(blocksucker == true)
    {
      // turn on the windmill wheels
    }

    else if(blocksucker == false)
    {
      // turn off the windmill wheels
    }

    if (ButtonA)
    {
      // turn on stacker
    }

    else if (Controller1.ButtonY.pressing())
    {
      // reverse stacker
    }

    else 
  {
      // stacker is off
    }
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
}


// Main will set up the competition functions and callbacks.
//
int main() {
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
    
    //Run the pre-autonomous function. 
    pre_auton();
       
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
}
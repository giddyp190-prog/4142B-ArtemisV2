#include "autons.h"
#include "lemlib/api.hpp" // IWYU pragma: keep


int autonSelection = 0;

void setAutonSelection() {
    autonSelection++;
    if (autonSelection == 4) {
        autonSelection = 0;
    }
}

// lateral PID controller
lemlib::ControllerSettings lateral_controller_settings(5, // proportional gain (kP)
                                              0.25,// integral gain (kI)
                                              0.01, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller_settings(1.8, // proportional gain (kP)
                                              0.15,// integral gain (kI)
                                              0.01, //rivative gain (kD)
                                              3, // anti windup
                                              0.25, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              0.5, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

//Autos
void redLeft() {}
void redRight() {}

void blueLeft() {}
void blueRight() {}

void skills() {}
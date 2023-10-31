#ifndef _DRIVE_MAIN_H
#define _DRIVE_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_1076462213_H
#define TOP_LEVEL_PREAMBLE_1076462213_H
#include <ir_sensors.h>
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <motors.h>
#endif
typedef struct {
    struct self_base_t base;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    interval_t calibration_time;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    interval_t sample_period;
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    int count;
    struct {
        #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line3_t line3;
        #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line2_t line2;
    } _lf_disp;
    int _lf_disp_width;
    struct {
        #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
        _line_calibrate_t calibrate;
        #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
        _line_trigger_t trigger;
        #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
        _line_reflect_t* reflect;
        #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
        trigger_t reflect_trigger;
        #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
        reaction_t* reflect_reactions[2];
    } _lf_line;
    int _lf_line_width;
    struct {
        #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
        _motors_left_power_t left_power;
        #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
        _motors_right_power_t right_power;
    } _lf_motor;
    int _lf_motor_width;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_0;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_1;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_2;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_3;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_4;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_5;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t _lf__reaction_6;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    trigger_t _lf__t;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t* _lf__t_reactions[1];
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    trigger_t _lf__seconds;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t* _lf__seconds_reactions[1];
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    trigger_t _lf__end_calibration;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    trigger_t _lf__backup;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    reaction_t* _lf__backup_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    reactor_mode_t _lf__modes[2];
} _drive_main_main_self_t;
_drive_main_main_self_t* new__drive_main();
#endif // _DRIVE_MAIN_H
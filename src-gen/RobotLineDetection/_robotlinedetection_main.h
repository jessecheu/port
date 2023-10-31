#ifndef _ROBOTLINEDETECTION_MAIN_H
#define _ROBOTLINEDETECTION_MAIN_H
#include "include/core/reactor.h"
#include "_display.h"
#include "_line.h"
#ifndef TOP_LEVEL_PREAMBLE_1269726699_H
#define TOP_LEVEL_PREAMBLE_1269726699_H
#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
#include <ir_sensors.h>
#endif
typedef struct {
    struct self_base_t base;
    #line 17 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    interval_t calibration_time;
    #line 17 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    interval_t sample_period;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    int count;
    struct {
        #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line0_t line0;
        #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line1_t line1;
        #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line2_t line2;
        #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
        _display_line3_t line3;
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
        reaction_t* reflect_reactions[1];
    } _lf_line;
    int _lf_line_width;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t _lf__reaction_0;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t _lf__reaction_1;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t _lf__reaction_2;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t _lf__reaction_3;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t _lf__reaction_4;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    trigger_t _lf__t;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t* _lf__t_reactions[1];
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    trigger_t _lf__seconds;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t* _lf__seconds_reactions[1];
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    trigger_t _lf__end_calibration;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    reaction_t* _lf__end_calibration_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
} _robotlinedetection_main_main_self_t;
_robotlinedetection_main_main_self_t* new__robotlinedetection_main();
#endif // _ROBOTLINEDETECTION_MAIN_H

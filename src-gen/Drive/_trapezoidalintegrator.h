#ifndef _TRAPEZOIDALINTEGRATOR_H
#define _TRAPEZOIDALINTEGRATOR_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1412848169_H
#define TOP_LEVEL_PREAMBLE_1412848169_H
#include <pico/stdlib.h>
#include <imu.h>
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _trapezoidalintegrator_in_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _trapezoidalintegrator_out_t;
typedef struct {
    struct self_base_t base;
    
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    float s;
    #line 98 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    float prev_in;
    #line 99 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    instant_t prev_time;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _trapezoidalintegrator_in_t* _lf_in;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // width of -2 indicates that it is not a multiport.
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_in_width;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Default input (in case it does not get connected)
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _trapezoidalintegrator_in_t _lf_default__in;
    #line 96 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _trapezoidalintegrator_out_t _lf_out;
    #line 96 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_out_width;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    reaction_t _lf__reaction_0;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    trigger_t _lf__in;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    reaction_t* _lf__in_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _trapezoidalintegrator_self_t;
_trapezoidalintegrator_self_t* new__trapezoidalintegrator();
#endif // _TRAPEZOIDALINTEGRATOR_H

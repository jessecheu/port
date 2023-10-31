#ifndef _MOTORS_H
#define _MOTORS_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_910485144_H
#define TOP_LEVEL_PREAMBLE_910485144_H
#include <motors.h>
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
} _motors_left_power_t;
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
} _motors_right_power_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    _motors_left_power_t* _lf_left_power;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    // width of -2 indicates that it is not a multiport.
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    int _lf_left_power_width;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    // Default input (in case it does not get connected)
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    _motors_left_power_t _lf_default__left_power;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    _motors_right_power_t* _lf_right_power;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    // width of -2 indicates that it is not a multiport.
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    int _lf_right_power_width;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    // Default input (in case it does not get connected)
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    _motors_right_power_t _lf_default__right_power;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    reaction_t _lf__reaction_0;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    reaction_t _lf__reaction_1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    reaction_t _lf__reaction_2;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    trigger_t _lf__left_power;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    reaction_t* _lf__left_power_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    trigger_t _lf__right_power;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
    reaction_t* _lf__right_power_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _motors_self_t;
_motors_self_t* new__motors();
#endif // _MOTORS_H

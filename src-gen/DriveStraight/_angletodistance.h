#ifndef _ANGLETODISTANCE_H
#define _ANGLETODISTANCE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_718632702_H
#define TOP_LEVEL_PREAMBLE_718632702_H
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _angletodistance_degrees_t;
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
} _angletodistance_distance_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    _angletodistance_degrees_t* _lf_degrees;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    // width of -2 indicates that it is not a multiport.
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    int _lf_degrees_width;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    // Default input (in case it does not get connected)
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    _angletodistance_degrees_t _lf_default__degrees;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    _angletodistance_distance_t _lf_distance;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    int _lf_distance_width;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_0;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    trigger_t _lf__degrees;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t* _lf__degrees_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _angletodistance_self_t;
_angletodistance_self_t* new__angletodistance();
#endif // _ANGLETODISTANCE_H

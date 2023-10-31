#ifndef _BUMP_H
#define _BUMP_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_1282962550_H
#define TOP_LEVEL_PREAMBLE_1282962550_H
#include <ir_sensors.h>
// others
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bump_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bump_left_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _bump_right_t;
typedef struct {
    struct self_base_t base;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    interval_t sample_period;
    
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    _bump_calibrate_t* _lf_calibrate;
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    // width of -2 indicates that it is not a multiport.
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    int _lf_calibrate_width;
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    // Default input (in case it does not get connected)
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    _bump_calibrate_t _lf_default__calibrate;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    _bump_left_t _lf_left;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    int _lf_left_width;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    _bump_right_t _lf_right;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    int _lf_right_width;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    reaction_t _lf__reaction_0;
    #line 37 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    reaction_t _lf__reaction_1;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    trigger_t _lf__t1;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    reaction_t* _lf__t1_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    trigger_t _lf__calibrate;
    #line 30 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    reaction_t* _lf__calibrate_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _bump_self_t;
_bump_self_t* new__bump();
#endif // _BUMP_H

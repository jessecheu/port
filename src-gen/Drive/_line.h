#ifndef _LINE_H
#define _LINE_H
#include "include/core/reactor.h"
#ifndef TOP_LEVEL_PREAMBLE_2055288499_H
#define TOP_LEVEL_PREAMBLE_2055288499_H
#include <ir_sensors.h>
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
} _line_calibrate_t;
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
} _line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _line_reflect_t;
typedef struct {
    struct self_base_t base;
    
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    bool calibrating;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    bool calibrated;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    _line_calibrate_t* _lf_calibrate;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // width of -2 indicates that it is not a multiport.
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    int _lf_calibrate_width;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Default input (in case it does not get connected)
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    _line_calibrate_t _lf_default__calibrate;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    _line_trigger_t* _lf_trigger;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // width of -2 indicates that it is not a multiport.
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    int _lf_trigger_width;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Default input (in case it does not get connected)
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    _line_trigger_t _lf_default__trigger;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    _line_reflect_t _lf_reflect;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    int _lf_reflect_width;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    reaction_t _lf__reaction_0;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    reaction_t _lf__reaction_1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    trigger_t _lf__calibrate;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    reaction_t* _lf__calibrate_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    trigger_t _lf__trigger;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _line_self_t;
_line_self_t* new__line();
#endif // _LINE_H

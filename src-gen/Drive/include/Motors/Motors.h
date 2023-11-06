#ifndef _motors_H
#define _motors_H
#ifndef TOP_LEVEL_PREAMBLE_367066629_H
#define TOP_LEVEL_PREAMBLE_367066629_H
/*Correspondence: Range: [(18, 2), (18, 21)) -> Range: [(0, 0), (0, 19)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf)*/#include <motors.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct motors_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    int end[0]; // placeholder; MSVC does not compile empty structs
} motors_self_t;
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
} motors_left_power_t;
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
} motors_right_power_t;
#endif

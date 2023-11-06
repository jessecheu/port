#ifndef _trapezoidalintegrator_H
#define _trapezoidalintegrator_H
#ifndef TOP_LEVEL_PREAMBLE_1601702534_H
#define TOP_LEVEL_PREAMBLE_1601702534_H
/*Correspondence: Range: [(22, 2), (23, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct trapezoidalintegrator_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    float s;
    float prev_in;
    instant_t prev_time;
    int end[0]; // placeholder; MSVC does not compile empty structs
} trapezoidalintegrator_self_t;
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
} trapezoidalintegrator_in_t;
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
} trapezoidalintegrator_out_t;
#endif

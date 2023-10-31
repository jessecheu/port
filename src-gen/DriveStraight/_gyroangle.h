#ifndef _GYROANGLE_H
#define _GYROANGLE_H
#include "include/core/reactor.h"
#include "_trapezoidalintegrator.h"
#include "_gyro.h"
#ifndef TOP_LEVEL_PREAMBLE_459407057_H
#define TOP_LEVEL_PREAMBLE_459407057_H
#include <pico/stdlib.h>
#include <imu.h>
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
} _gyroangle_trigger_t;
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
} _gyroangle_x_t;
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
} _gyroangle_y_t;
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
} _gyroangle_z_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyroangle_trigger_t* _lf_trigger;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // width of -2 indicates that it is not a multiport.
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_trigger_width;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Default input (in case it does not get connected)
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyroangle_trigger_t _lf_default__trigger;
    #line 123 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyroangle_x_t _lf_x;
    #line 123 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_x_width;
    #line 124 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyroangle_y_t _lf_y;
    #line 124 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_y_width;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyroangle_z_t _lf_z;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_z_width;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    trigger_t _lf__trigger;
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _gyroangle_self_t;
_gyroangle_self_t* new__gyroangle();
#endif // _GYROANGLE_H

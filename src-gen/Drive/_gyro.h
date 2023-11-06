#ifndef _GYRO_H
#define _GYRO_H
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
    bool value;
    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _gyro_trigger_t;
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
} _gyro_x_t;
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
} _gyro_y_t;
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
} _gyro_z_t;
typedef struct {
    struct self_base_t base;
    
    
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyro_trigger_t* _lf_trigger;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // width of -2 indicates that it is not a multiport.
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_trigger_width;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Default input (in case it does not get connected)
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyro_trigger_t _lf_default__trigger;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyro_x_t _lf_x;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_x_width;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyro_y_t _lf_y;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_y_width;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    _gyro_z_t _lf_z;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    int _lf_z_width;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    reaction_t _lf__reaction_0;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    trigger_t _lf__trigger;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    reaction_t* _lf__trigger_reactions[1];
    #ifdef FEDERATED
    
    #endif // FEDERATED
} _gyro_self_t;
_gyro_self_t* new__gyro();
#endif // _GYRO_H

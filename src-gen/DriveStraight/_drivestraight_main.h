#ifndef _DRIVESTRAIGHT_MAIN_H
#define _DRIVESTRAIGHT_MAIN_H
#include "include/core/reactor.h"
#include "_encoders.h"
#include "_gyroangle.h"
#include "_bump.h"
#include "_angletodistance.h"
#include "_motors.h"
#ifndef TOP_LEVEL_PREAMBLE_718632702_H
#define TOP_LEVEL_PREAMBLE_718632702_H
#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#include <pico/stdlib.h>
#include <imu.h>
#include <motors.h>
#include <ir_sensors.h>
// others
#endif
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_action_internal_t _base;
    self_base_t* parent;
    bool has_value;

    #ifdef FEDERATED
    #ifdef FEDERATED_DECENTRALIZED
    tag_t intended_tag;
    #endif
    interval_t physical_time_of_arrival;
    #endif
} _drivestraight_main_clear_t;
typedef struct {
    struct self_base_t base;
    
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    float distance;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    float angle;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    _drivestraight_main_clear_t _lf_clear;
    struct {
        #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
        _motors_left_power_t left_power;
        #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf"
        _motors_right_power_t right_power;
    } _lf_motors;
    int _lf_motors_width;
    struct {
        #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
        _gyroangle_trigger_t trigger;
        #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
        _gyroangle_z_t* z;
        #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
        trigger_t z_trigger;
        #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
        reaction_t* z_reactions[2];
    } _lf_gyro;
    int _lf_gyro_width;
    struct {
        #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
        _encoders_trigger_t trigger;
        #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
        _encoders_left_t* left;
        #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
        trigger_t left_trigger;
        #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
        reaction_t* left_reactions[1];
    } _lf_encoder;
    int _lf_encoder_width;
    struct {
        #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
        _angletodistance_degrees_t degrees;
        #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
        _angletodistance_distance_t* distance;
        #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
        trigger_t distance_trigger;
        #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
        reaction_t* distance_reactions[2];
    } _lf_angleToDistanceLeft;
    int _lf_angleToDistanceLeft_width;
    struct {
        #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        _bump_left_t* left;
        #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        trigger_t left_trigger;
        #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        reaction_t* left_reactions[1];
        #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        _bump_right_t* right;
        #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        trigger_t right_trigger;
        #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
        reaction_t* right_reactions[1];
    } _lf_bump;
    int _lf_bump_width;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_0;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_1;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_2;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_3;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_4;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_5;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_6;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_7;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_8;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t _lf__reaction_9;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    trigger_t _lf__t;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t* _lf__t_reactions[1];
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    trigger_t _lf__clear;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    reaction_t* _lf__clear_reactions[1];
    reactor_mode_t _lf__modes[2];
} _drivestraight_main_main_self_t;
_drivestraight_main_main_self_t* new__drivestraight_main();
#endif // _DRIVESTRAIGHT_MAIN_H

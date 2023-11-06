#ifndef _drive_main_H
#define _drive_main_H
#ifndef TOP_LEVEL_PREAMBLE_1102097996_H
#define TOP_LEVEL_PREAMBLE_1102097996_H
/*Correspondence: Range: [(33, 2), (33, 25)) -> Range: [(0, 0), (0, 23)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf)*/#include <ir_sensors.h>
/*Correspondence: Range: [(18, 2), (18, 21)) -> Range: [(0, 0), (0, 19)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Motors.lf)*/#include <motors.h>
/*Correspondence: Range: [(18, 2), (19, 68)) -> Range: [(0, 0), (1, 68)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf)*/#include <pico/stdlib.h>
#include <display.h>        // Do not use "display.h". Doesn't work.
/*Correspondence: Range: [(22, 2), (23, 16)) -> Range: [(0, 0), (1, 16)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf)*/#include <pico/stdlib.h>
#include <imu.h>
/*Correspondence: Range: [(19, 2), (27, 17)) -> Range: [(0, 0), (8, 17)) (verbatim=true; src=/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf)*/#include <math.h> 
#include <hardware/pio.h>
#include <quadrature_encoder.pio.h>

// pin defines
#define RIGHT_ENCODER_AB 8
#define LEFT_ENCODER_AB 12
#define RIGHT_SM 0
#define LEFT_SM 1
#endif
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/api/api.h"
#include "../include/core/reactor.h"
#ifdef __cplusplus
}
#endif
typedef struct drive_self_t{
    self_base_t base; // This field is only to be used by the runtime, not the user.
    interval_t calibration_time;
    interval_t sample_period;
    float angle_before_turn;
    float distance;
    int end[0]; // placeholder; MSVC does not compile empty structs
} drive_self_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_calibrate_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} line_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    uint16_t value[5];

} line_reflect_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line0_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line1_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line2_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    string value;

} display_line3_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_left_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} motors_right_power_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} gyroangle_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_x_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_y_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    float value;

} gyroangle_z_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    bool value;

} encoders_trigger_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_right_t;
typedef struct {
    token_type_t type;
    lf_token_t* token;
    size_t length;
    bool is_present;
    lf_port_internal_t _base;
    int32_t value;

} encoders_left_t;
#endif

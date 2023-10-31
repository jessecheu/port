#include "include/api/api.h"
#include "include/DriveStraight/DriveStraight.h"
#include "_drivestraight_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _drivestraight_mainreaction_function_0(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_set(motors.left_power, 0.25);
    lf_set(motors.right_power, 0.25);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_1(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_trigger_t* trigger;
    
    } gyro;
    struct encoder {
        _encoders_trigger_t* trigger;
    
    } encoder;
    gyro.trigger = &(self->_lf_gyro.trigger);
    encoder.trigger = &(self->_lf_encoder.trigger);
    #line 48 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_set(gyro.trigger, true);
    lf_set(encoder.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_2(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct encoder {
        _encoders_left_t* left;
    
    } encoder;
    struct angleToDistanceLeft {
        _angletodistance_degrees_t* degrees;
    
    } angleToDistanceLeft;
    encoder.left = self->_lf_encoder.left;
    angleToDistanceLeft.degrees = &(self->_lf_angleToDistanceLeft.degrees);
    #line 53 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_set(angleToDistanceLeft.degrees, encoder.left->value);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_3(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct angleToDistanceLeft {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceLeft;
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    angleToDistanceLeft.distance = self->_lf_angleToDistanceLeft.distance;
    reactor_mode_t* TURNING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 58 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    if(angleToDistanceLeft.distance->value - self->distance >= 50){
      lf_set_mode(TURNING);
      lf_set(motors.left_power, 0.15);
      lf_set(motors.right_power, 0);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_4(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    gyro.z = self->_lf_gyro.z;
    reactor_mode_t* DRIVING = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 66 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->angle = gyro.z->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_5(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_left_t* left;
    
    } bump;
    bump.left = self->_lf_bump.left;
    _drivestraight_main_clear_t* clear = &self->_lf_clear;
    #line 70 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_schedule(clear, 0);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_6(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct bump {
        _bump_right_t* right;
    
    } bump;
    bump.right = self->_lf_bump.right;
    _drivestraight_main_clear_t* clear = &self->_lf_clear;
    #line 73 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_schedule(clear, 0);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_7(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    // Expose the action struct as a local variable whose name matches the action name.
    _drivestraight_main_clear_t* clear = &self->_lf_clear;
    // Set the fields of the action struct to match the current trigger.
    clear->is_present = (bool)self->_lf__clear.status;
    clear->has_value = ((self->_lf__clear.tmplt.token) != NULL && (self->_lf__clear.tmplt.token)->value != NULL);
    _lf_replace_template_token((token_template_t*)clear, (self->_lf__clear.tmplt.token));
    reactor_mode_t* TURNING = &self->_lf__modes[1];
    lf_mode_change_type_t _lf_TURNING_change_type = reset_transition;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 77 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_set_mode(TURNING);
    lf_set(motors.left_power, -0.1);
    lf_set(motors.right_power, -0.15);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_8(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct angleToDistanceLeft {
        _angletodistance_distance_t* distance;
    
    } angleToDistanceLeft;
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    angleToDistanceLeft.distance = self->_lf_angleToDistanceLeft.distance;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 85 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->distance = angleToDistanceLeft.distance->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drivestraight_mainreaction_function_9(void* instance_args) {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct gyro {
        _gyroangle_z_t* z;
    
    } gyro;
    struct motors {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motors;
    gyro.z = self->_lf_gyro.z;
    reactor_mode_t* DRIVING = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_DRIVING_change_type = reset_transition;
    motors.left_power = &(self->_lf_motors.left_power);
    motors.right_power = &(self->_lf_motors.right_power);
    #line 89 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    if (gyro.z->value - self->angle <= -90) {
      lf_set_mode(DRIVING);
      lf_set(motors.left_power, 0.25);
      lf_set(motors.right_power, 0.25);
    }
}
#include "include/api/set_undef.h"
_drivestraight_main_main_self_t* new__drivestraight_main() {
    _drivestraight_main_main_self_t* self = (_drivestraight_main_main_self_t*)_lf_new_reactor(sizeof(_drivestraight_main_main_self_t));
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_clear._base.trigger = &self->_lf__clear;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_clear.parent = (self_base_t*)self;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motors_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_gyro_width = -2;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_reactions[0] = &self->_lf__reaction_4;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_reactions[1] = &self->_lf__reaction_9;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.reactions = self->_lf_gyro.z_reactions;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.last = NULL;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.number_of_reactions = 2;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_gyro.z_trigger.physical_time_of_arrival = NEVER;
    #line 125 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_encoder_width = -2;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_reactions[0] = &self->_lf__reaction_2;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.reactions = self->_lf_encoder.left_reactions;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.last = NULL;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.number_of_reactions = 1;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_encoder.left_trigger.physical_time_of_arrival = NEVER;
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_angleToDistanceLeft_width = -2;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_reactions[0] = &self->_lf__reaction_3;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_reactions[1] = &self->_lf__reaction_8;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_trigger.reactions = self->_lf_angleToDistanceLeft.distance_reactions;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_trigger.last = NULL;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_trigger.number_of_reactions = 2;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_angleToDistanceLeft.distance_trigger.physical_time_of_arrival = NEVER;
    #line 22 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_bump_width = -2;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_reactions[0] = &self->_lf__reaction_5;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.reactions = self->_lf_bump.left_reactions;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.last = NULL;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.number_of_reactions = 1;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #ifdef FEDERATED
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.left_trigger.physical_time_of_arrival = NEVER;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #endif // FEDERATED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_reactions[0] = &self->_lf__reaction_6;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.reactions = self->_lf_bump.right_reactions;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.last = NULL;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.number_of_reactions = 1;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #ifdef FEDERATED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    self->_lf_bump.right_trigger.physical_time_of_arrival = NEVER;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Bump.lf"
    #endif // FEDERATED
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.number = 0;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.function = _drivestraight_mainreaction_function_0;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.self = self;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.name = "?";
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.number = 1;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.function = _drivestraight_mainreaction_function_1;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.self = self;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.name = "?";
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.number = 2;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.function = _drivestraight_mainreaction_function_2;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.self = self;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.name = "?";
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.number = 3;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.function = _drivestraight_mainreaction_function_3;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.self = self;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.name = "?";
    #line 57 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.number = 4;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.function = _drivestraight_mainreaction_function_4;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.self = self;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.name = "?";
    #line 65 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[0];
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.number = 5;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.function = _drivestraight_mainreaction_function_5;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.self = self;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.name = "?";
    #line 69 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_5.mode = &self->_lf__modes[0];
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.number = 6;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.function = _drivestraight_mainreaction_function_6;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.self = self;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.name = "?";
    #line 72 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_6.mode = &self->_lf__modes[0];
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.number = 7;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.function = _drivestraight_mainreaction_function_7;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.self = self;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.deadline_violation_handler = NULL;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.STP_handler = NULL;
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.name = "?";
    #line 76 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_7.mode = &self->_lf__modes[0];
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.number = 8;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.function = _drivestraight_mainreaction_function_8;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.self = self;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.deadline_violation_handler = NULL;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.STP_handler = NULL;
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.name = "?";
    #line 84 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_8.mode = &self->_lf__modes[1];
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.number = 9;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.function = _drivestraight_mainreaction_function_9;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.self = self;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.deadline_violation_handler = NULL;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.STP_handler = NULL;
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.name = "?";
    #line 88 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_9.mode = &self->_lf__modes[1];
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t.last = NULL;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_1;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear.last = NULL;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear_reactions[0] = &self->_lf__reaction_7;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear.reactions = &self->_lf__clear_reactions[0];
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear.number_of_reactions = 1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__clear.physical_time_of_arrival = NEVER;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED
    self->_lf__clear.is_physical = false;
    
    self->_lf__clear.tmplt.type.element_size = 0;
    self->_lf_clear.type.element_size = 0;
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 56 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 56 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[0].name = "DRIVING";
    #line 56 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 56 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[0].flags = 0;
    #line 83 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 83 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[1].name = "TURNING";
    #line 83 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 83 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}

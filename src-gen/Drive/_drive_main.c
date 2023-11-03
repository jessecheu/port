#include "include/api/api.h"
#include "include/Drive/Drive.h"
#include "_drive_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _drive_mainreaction_function_0(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    disp.line3 = &(self->_lf_disp.line3);
    #line 36 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    static char buf[17];
    snprintf(buf, 17, "time:%8d s", self->count++);
    lf_set(disp.line3, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_1(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    line.calibrate = &(self->_lf_line.calibrate);
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    lf_set(line.calibrate, false);
    lf_set(motor.left_power, 0.1f);
    lf_set(motor.right_power, 0.1f);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_2(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 48 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_3(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    line.reflect = self->_lf_line.reflect;
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 53 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    //Drives using the line on the ground as reference
    
              /* Motor feedback to stay on the correct path */
              //If the left side of the line sensors are detected, we shift the robot right
              if (line.reflect->value[0] >= 1000 || line.reflect->value[1] >= 1000) {
                //Rotating wheels right to adjust to the right
                lf_set(motor.left_power, 0.10);
                lf_set(motor.right_power, 0.05);
              } 
    
              //Motors are correctly in the center
              if (line.reflect->value[2] >= 1000) {
                //Keep the wheels straight
                lf_set(motor.left_power, 0.05);
                lf_set(motor.right_power, 0.05);
              } 
    
              //If the right side of the line sensors are detected, we shift the robot left
              if (line.reflect->value[3] >= 1000 || line.reflect->value[4] >= 1000) {
                //Rotate the wheel left
                lf_set(motor.left_power, 0.05);
                lf_set(motor.right_power, 0.10);
              }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_4(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct motor {
        _motors_left_power_t* left_power;
    _motors_right_power_t* right_power;
    
    } motor;
    reactor_mode_t* DRIVE = &self->_lf__modes[0];
    lf_mode_change_type_t _lf_DRIVE_change_type = reset_transition;
    motor.left_power = &(self->_lf_motor.left_power);
    motor.right_power = &(self->_lf_motor.right_power);
    #line 83 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    lf_set(motor.left_power, 0.0f);
    lf_set(motor.right_power, 0.0f);
    lf_set_mode(DRIVE);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_5(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 91 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _drive_mainreaction_function_6(void* instance_args) {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_reflect_t* reflect;
    
    } line;
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    line.reflect = self->_lf_line.reflect;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 98 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    static char buf0[17];
    static char buf1[17];
    static char buf2[17];
    if (line.reflect->value[0] >= 1000 || line.reflect->value[1] >= 1000) {
      snprintf(buf0, 17, "Adjusting, Turning Right");
    } else {
      snprintf(buf0, 17, " ");
    }
    if (line.reflect->value[2] >= 1000) {
      snprintf(buf1, 17, "Center");
    } else { 
      snprintf(buf1, 17, " ");
    }
    if (line.reflect->value[3] >= 1000 || line.reflect->value[4] >= 1000) {
      snprintf(buf2, 17, "Adjusting, Turning Left.");
    } else { 
      snprintf(buf2, 17, " ");
    }
    lf_set(disp.line0, buf0);
    lf_set(disp.line1, buf1);
    lf_set(disp.line2, buf2);
}
#include "include/api/set_undef.h"
_drive_main_main_self_t* new__drive_main() {
    _drive_main_main_self_t* self = (_drive_main_main_self_t*)_lf_new_reactor(sizeof(_drive_main_main_self_t));
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_disp_width = -2;
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_line_width = -2;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_3;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_reactions[1] = &self->_lf__reaction_6;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.last = NULL;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.number_of_reactions = 2;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED
    // Set the _width variable for all cases. This will be -2
    // if the reactor is not a bank of reactors.
    self->_lf_motor_width = -2;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.number = 0;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.function = _drive_mainreaction_function_0;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.self = self;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.name = "?";
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.number = 1;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.function = _drive_mainreaction_function_1;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.self = self;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.name = "?";
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.number = 2;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.function = _drive_mainreaction_function_2;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.self = self;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.name = "?";
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.number = 3;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.function = _drive_mainreaction_function_3;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.self = self;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.name = "?";
    #line 52 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_3.mode = &self->_lf__modes[0];
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.number = 4;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.function = _drive_mainreaction_function_4;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.self = self;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.name = "?";
    #line 82 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_4.mode = &self->_lf__modes[1];
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.number = 5;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.function = _drive_mainreaction_function_5;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.self = self;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.deadline_violation_handler = NULL;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.STP_handler = NULL;
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.name = "?";
    #line 90 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_5.mode = NULL;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.number = 6;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.function = _drive_mainreaction_function_6;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.self = self;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.deadline_violation_handler = NULL;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.STP_handler = NULL;
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.name = "?";
    #line 97 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__reaction_6.mode = NULL;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t.last = NULL;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_2;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds.last = NULL;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_0;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration.last = NULL;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_1;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 29 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup.last = NULL;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup_reactions[0] = &self->_lf__reaction_4;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup.reactions = &self->_lf__backup_reactions[0];
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup.number_of_reactions = 1;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #ifdef FEDERATED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__backup.physical_time_of_arrival = NEVER;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    #endif // FEDERATED
    self->_lf__backup.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__backup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_5;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    // Initialize modes
    self_base_t* _lf_self_base = (self_base_t*)self;
    #line 51 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[0].state = &_lf_self_base->_lf__mode_state;
    #line 51 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[0].name = "DRIVE";
    #line 51 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[0].deactivation_time = 0;
    #line 51 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[0].flags = 0;
    #line 81 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[1].state = &_lf_self_base->_lf__mode_state;
    #line 81 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[1].name = "STOP_DETECTED";
    #line 81 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[1].deactivation_time = 0;
    #line 81 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/Drive.lf"
    self->_lf__modes[1].flags = 0;
    // Initialize mode state
    _lf_self_base->_lf__mode_state.parent_mode = NULL;
    _lf_self_base->_lf__mode_state.initial_mode = &self->_lf__modes[0];
    _lf_self_base->_lf__mode_state.current_mode = _lf_self_base->_lf__mode_state.initial_mode;
    _lf_self_base->_lf__mode_state.next_mode = NULL;
    _lf_self_base->_lf__mode_state.mode_change = no_transition;
    return self;
}

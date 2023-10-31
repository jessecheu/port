#include "include/api/api.h"
#include "include/RobotLineDetection/RobotLineDetection.h"
#include "_robotlinedetection_main.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _robotlinedetection_mainreaction_function_0(void* instance_args) {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line0_t* line0;
    _display_line1_t* line1;
    _display_line2_t* line2;
    
    } disp;
    disp.line0 = &(self->_lf_disp.line0);
    disp.line1 = &(self->_lf_disp.line1);
    disp.line2 = &(self->_lf_disp.line2);
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    lf_set(disp.line0, "CALIBRATING");
    lf_set(disp.line1, "Roll robot over");
    lf_set(disp.line2, "light and dark.");
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotlinedetection_mainreaction_function_1(void* instance_args) {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct disp {
        _display_line3_t* line3;
    
    } disp;
    disp.line3 = &(self->_lf_disp.line3);
    #line 34 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    static char buf[17];
    snprintf(buf, 17, "time:%8d s", self->count++);
    lf_set(disp.line3, buf);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotlinedetection_mainreaction_function_2(void* instance_args) {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_calibrate_t* calibrate;
    
    } line;
    line.calibrate = &(self->_lf_line.calibrate);
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    lf_set(line.calibrate, false);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotlinedetection_mainreaction_function_3(void* instance_args) {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    struct line {
        _line_trigger_t* trigger;
    
    } line;
    line.trigger = &(self->_lf_line.trigger);
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    lf_set(line.trigger, true);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _robotlinedetection_mainreaction_function_4(void* instance_args) {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
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
    #line 48 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    static char buf0[17];
    static char buf1[17];
    static char buf2[17];
    if (line.reflect->value[0] >= 1000 || line.reflect->value[1] >= 1000) {
      snprintf(buf0, 17, "Left [0]=%d, [1]=%d", line.reflect->value[0], line.reflect->value[1]);
    } else {
      snprintf(buf0, 17, "[0]=%d, [1]=%d", line.reflect->value[0], line.reflect->value[1]);
    }
    if (line.reflect->value[2] >= 1000) {
      snprintf(buf1, 17, "Center [2]=%d", line.reflect->value[2]);
    } else { 
      snprintf(buf1, 17, "[2]=%d", line.reflect->value[2]);
    }
    if (line.reflect->value[3] >= 1000 || line.reflect->value[4] >= 1000) {
      snprintf(buf2, 17, "Right [3]=%d, [4]=%d", line.reflect->value[3], line.reflect->value[4]);
    } else { 
      snprintf(buf2, 17, "Right [3]=%d, [4]=%d", line.reflect->value[3], line.reflect->value[4]);
    }
    lf_set(disp.line0, buf0);
    lf_set(disp.line1, buf1);
    lf_set(disp.line2, buf2);
}
#include "include/api/set_undef.h"
_robotlinedetection_main_main_self_t* new__robotlinedetection_main() {
    _robotlinedetection_main_main_self_t* self = (_robotlinedetection_main_main_self_t*)_lf_new_reactor(sizeof(_robotlinedetection_main_main_self_t));
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
    self->_lf_line.reflect_reactions[0] = &self->_lf__reaction_4;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.reactions = self->_lf_line.reflect_reactions;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.last = NULL;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.number_of_reactions = 1;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_line.reflect_trigger.physical_time_of_arrival = NEVER;
    #line 40 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.number = 0;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.function = _robotlinedetection_mainreaction_function_0;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.self = self;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.name = "?";
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.number = 1;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.function = _robotlinedetection_mainreaction_function_1;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.self = self;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.name = "?";
    #line 33 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.number = 2;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.function = _robotlinedetection_mainreaction_function_2;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.self = self;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.deadline_violation_handler = NULL;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.STP_handler = NULL;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.name = "?";
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_2.mode = NULL;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.number = 3;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.function = _robotlinedetection_mainreaction_function_3;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.self = self;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.deadline_violation_handler = NULL;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.STP_handler = NULL;
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.name = "?";
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_3.mode = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.number = 4;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.function = _robotlinedetection_mainreaction_function_4;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.self = self;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.deadline_violation_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.STP_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.name = "?";
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__reaction_4.mode = NULL;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t.last = NULL;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t_reactions[0] = &self->_lf__reaction_3;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t.reactions = &self->_lf__t_reactions[0];
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t.number_of_reactions = 1;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__t.physical_time_of_arrival = NEVER;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED
    self->_lf__t.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__t.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds.last = NULL;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds_reactions[0] = &self->_lf__reaction_1;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds.reactions = &self->_lf__seconds_reactions[0];
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds.number_of_reactions = 1;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__seconds.physical_time_of_arrival = NEVER;
    #line 23 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED
    self->_lf__seconds.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__seconds.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration.last = NULL;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration_reactions[0] = &self->_lf__reaction_2;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration.reactions = &self->_lf__end_calibration_reactions[0];
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration.number_of_reactions = 1;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #ifdef FEDERATED
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    self->_lf__end_calibration.physical_time_of_arrival = NEVER;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/RobotLineDetection.lf"
    #endif // FEDERATED
    self->_lf__end_calibration.is_timer = true;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__end_calibration.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    return self;
}

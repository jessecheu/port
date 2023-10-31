#include "include/api/api.h"
#include "include/Line/Line.h"
#include "_line.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _linereaction_function_0(void* instance_args) {
    _line_self_t* self = (_line_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _line_calibrate_t* calibrate = self->_lf_calibrate;
    int calibrate_width = self->_lf_calibrate_width; SUPPRESS_UNUSED_WARNING(calibrate_width);
    #line 46 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->calibrating = calibrate->value;
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _linereaction_function_1(void* instance_args) {
    _line_self_t* self = (_line_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _line_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _line_reflect_t* reflect = &self->_lf_reflect;
    #line 48 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    if (self->calibrating) {
      line_sensors_calibrate();
      self->calibrated = true;
    } else {
      if (!self->calibrated) {
        // Calibration has not been performed, so read raw data.
        line_sensors_read();
        for (int i=0; i<5; i++) {
          reflect->value[i] = line_sensors[i];
        }
      } else {
        line_sensors_read_calibrated();
        for (int i=0; i<5; i++) {
          reflect->value[i] = line_sensors_calibrated[i];
        }
      }
      lf_set_present(reflect);
    }
}
#include "include/api/set_undef.h"
_line_self_t* new__line() {
    _line_self_t* self = (_line_self_t*)_lf_new_reactor(sizeof(_line_self_t));
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Set input by default to an always absent default input.
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_calibrate = &self->_lf_default__calibrate;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Set the default source reactor pointer
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_default__calibrate._base.source_reactor = (self_base_t*)self;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Set input by default to an always absent default input.
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    // Set the default source reactor pointer
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.number = 0;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.function = _linereaction_function_0;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.self = self;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.name = "?";
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.number = 1;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.function = _linereaction_function_1;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.self = self;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.name = "?";
    #line 47 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__reaction_1.mode = NULL;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate.last = NULL;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate_reactions[0] = &self->_lf__reaction_0;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate.reactions = &self->_lf__calibrate_reactions[0];
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate.number_of_reactions = 1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__calibrate.physical_time_of_arrival = NEVER;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED
    self->_lf__calibrate.tmplt.type.element_size = sizeof(bool);
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger.last = NULL;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #ifdef FEDERATED
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 39 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Line.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

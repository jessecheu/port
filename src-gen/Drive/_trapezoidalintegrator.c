#include "include/api/api.h"
#include "include/IMU/TrapezoidalIntegrator.h"
#include "_trapezoidalintegrator.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _trapezoidalintegratorreaction_function_0(void* instance_args) {
    _trapezoidalintegrator_self_t* self = (_trapezoidalintegrator_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _trapezoidalintegrator_in_t* in = self->_lf_in;
    int in_width = self->_lf_in_width; SUPPRESS_UNUSED_WARNING(in_width);
    _trapezoidalintegrator_out_t* out = &self->_lf_out;
    #line 101 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    instant_t now = lf_time_logical();
    if (self->prev_time > SEC(0)) {
      float interval = ((now - self->prev_time) * 1e-9);
      self->s += (in->value + self->prev_in) * interval / 2;
    }
    lf_set(out, self->s);
    self->prev_in = in->value;
    self->prev_time = now;
}
#include "include/api/set_undef.h"
_trapezoidalintegrator_self_t* new__trapezoidalintegrator() {
    _trapezoidalintegrator_self_t* self = (_trapezoidalintegrator_self_t*)_lf_new_reactor(sizeof(_trapezoidalintegrator_self_t));
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set input by default to an always absent default input.
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_in = &self->_lf_default__in;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set the default source reactor pointer
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_default__in._base.source_reactor = (self_base_t*)self;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.number = 0;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.function = _trapezoidalintegratorreaction_function_0;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.self = self;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.name = "?";
    #line 100 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in.last = NULL;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in_reactions[0] = &self->_lf__reaction_0;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in.reactions = &self->_lf__in_reactions[0];
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in.number_of_reactions = 1;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__in.physical_time_of_arrival = NEVER;
    #line 95 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED
    self->_lf__in.tmplt.type.element_size = sizeof(float);
    return self;
}

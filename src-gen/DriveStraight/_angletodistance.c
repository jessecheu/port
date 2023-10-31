#include "include/api/api.h"
#include "include/DriveStraight/AngleToDistance.h"
#include "_angletodistance.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _angletodistancereaction_function_0(void* instance_args) {
    _angletodistance_self_t* self = (_angletodistance_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _angletodistance_degrees_t* degrees = self->_lf_degrees;
    int degrees_width = self->_lf_degrees_width; SUPPRESS_UNUSED_WARNING(degrees_width);
    _angletodistance_distance_t* distance = &self->_lf_distance;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    lf_set(distance, degrees->value*(9.975/360));
}
#include "include/api/set_undef.h"
_angletodistance_self_t* new__angletodistance() {
    _angletodistance_self_t* self = (_angletodistance_self_t*)_lf_new_reactor(sizeof(_angletodistance_self_t));
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    // Set input by default to an always absent default input.
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_degrees = &self->_lf_default__degrees;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    // Set the default source reactor pointer
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf_default__degrees._base.source_reactor = (self_base_t*)self;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.number = 0;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.function = _angletodistancereaction_function_0;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.self = self;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.name = "?";
    #line 24 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees.last = NULL;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees_reactions[0] = &self->_lf__reaction_0;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees.reactions = &self->_lf__degrees_reactions[0];
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees.number_of_reactions = 1;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #ifdef FEDERATED
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    self->_lf__degrees.physical_time_of_arrival = NEVER;
    #line 21 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/DriveStraight.lf"
    #endif // FEDERATED
    self->_lf__degrees.tmplt.type.element_size = sizeof(int32_t);
    return self;
}

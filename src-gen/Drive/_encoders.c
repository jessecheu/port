#include "include/api/api.h"
#include "include/Encoders/Encoders.h"
#include "_encoders.h"
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _encodersreaction_function_0(void* instance_args) {
    _encoders_self_t* self = (_encoders_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 36 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    PIO pio = pio0;
    pio_add_program(pio, &quadrature_encoder_program);
    quadrature_encoder_program_init(pio, RIGHT_SM, RIGHT_ENCODER_AB, 0);
    quadrature_encoder_program_init(pio, LEFT_SM, LEFT_ENCODER_AB, 0);
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _encodersreaction_function_1(void* instance_args) {
    _encoders_self_t* self = (_encoders_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _encoders_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _encoders_left_t* left = &self->_lf_left;
    _encoders_right_t* right = &self->_lf_right;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    // Also, the sign is reversed, where reverse increases, so we negate.
    int32_t rcount = -quadrature_encoder_get_count(pio0, RIGHT_SM);
    int32_t lcount = -quadrature_encoder_get_count(pio0, LEFT_SM);
    lf_set(right, rcount);
    lf_set(left, lcount);
}
#include "include/api/set_undef.h"
_encoders_self_t* new__encoders() {
    _encoders_self_t* self = (_encoders_self_t*)_lf_new_reactor(sizeof(_encoders_self_t));
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    // Set input by default to an always absent default input.
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    // Set the default source reactor pointer
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.number = 0;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.function = _encodersreaction_function_0;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.self = self;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.name = "?";
    #line 35 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.number = 1;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.function = _encodersreaction_function_1;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.self = self;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.name = "?";
    #line 41 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger.last = NULL;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #ifdef FEDERATED
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Encoders.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

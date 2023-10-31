#include "include/api/api.h"
#include "include/Display/Display.h"
#include "_display.h"
// *********** From the preamble, verbatim:
#line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
static bool _pololu_robot_display_initialized = false;

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _displayreaction_function_0(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Initialize only once if there are multiple instances.
    if (!_pololu_robot_display_initialized) {
      _pololu_robot_display_initialized = true;
      display_init();
      display_set_font(font_8x16);
      // clear the frame buffer
      display_fill(0);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _displayreaction_function_1(void* instance_args) {
    _display_self_t* self = (_display_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _display_line0_t* line0 = self->_lf_line0;
    int line0_width = self->_lf_line0_width; SUPPRESS_UNUSED_WARNING(line0_width);
    _display_line1_t* line1 = self->_lf_line1;
    int line1_width = self->_lf_line1_width; SUPPRESS_UNUSED_WARNING(line1_width);
    _display_line2_t* line2 = self->_lf_line2;
    int line2_width = self->_lf_line2_width; SUPPRESS_UNUSED_WARNING(line2_width);
    _display_line3_t* line3 = self->_lf_line3;
    int line3_width = self->_lf_line3_width; SUPPRESS_UNUSED_WARNING(line3_width);
    #line 43 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    if (line0->is_present) {
      // Clear the line.
      display_fill_rect(0, 0, DISPLAY_WIDTH, 16, 0);
      display_text(line0->value, 0, 0, COLOR_WHITE);
    }
    if (line1->is_present) {
      // Clear the line.
      display_fill_rect(0, 16, DISPLAY_WIDTH, 16, 0);
      display_text(line1->value, 0, 16, COLOR_WHITE);
    }
    if (line2->is_present) {
      // Clear the line.
      display_fill_rect(0, 32, DISPLAY_WIDTH, 16, 0);
      display_text(line2->value, 0, 32, COLOR_WHITE);
    }
    if (line3->is_present) {
      // Clear the line.
      display_fill_rect(0, 48, DISPLAY_WIDTH, 16, 0);
      display_text(line3->value, 0, 48, COLOR_WHITE);
    }
    // display buffer
    display_show();
}
#include "include/api/set_undef.h"
_display_self_t* new__display() {
    _display_self_t* self = (_display_self_t*)_lf_new_reactor(sizeof(_display_self_t));
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set input by default to an always absent default input.
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_line0 = &self->_lf_default__line0;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set the default source reactor pointer
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_default__line0._base.source_reactor = (self_base_t*)self;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set input by default to an always absent default input.
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_line1 = &self->_lf_default__line1;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set the default source reactor pointer
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_default__line1._base.source_reactor = (self_base_t*)self;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set input by default to an always absent default input.
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_line2 = &self->_lf_default__line2;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set the default source reactor pointer
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_default__line2._base.source_reactor = (self_base_t*)self;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set input by default to an always absent default input.
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_line3 = &self->_lf_default__line3;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    // Set the default source reactor pointer
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf_default__line3._base.source_reactor = (self_base_t*)self;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.number = 0;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.function = _displayreaction_function_0;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.self = self;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.name = "?";
    #line 31 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.number = 1;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.function = _displayreaction_function_1;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.self = self;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.name = "?";
    #line 42 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0.last = NULL;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0_reactions[0] = &self->_lf__reaction_1;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0.reactions = &self->_lf__line0_reactions[0];
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0.number_of_reactions = 1;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line0.physical_time_of_arrival = NEVER;
    #line 25 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED
    self->_lf__line0.tmplt.type.element_size = sizeof(string);
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1.last = NULL;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1_reactions[0] = &self->_lf__reaction_1;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1.reactions = &self->_lf__line1_reactions[0];
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1.number_of_reactions = 1;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line1.physical_time_of_arrival = NEVER;
    #line 26 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED
    self->_lf__line1.tmplt.type.element_size = sizeof(string);
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2.last = NULL;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2_reactions[0] = &self->_lf__reaction_1;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2.reactions = &self->_lf__line2_reactions[0];
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2.number_of_reactions = 1;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line2.physical_time_of_arrival = NEVER;
    #line 27 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED
    self->_lf__line2.tmplt.type.element_size = sizeof(string);
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3.last = NULL;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3_reactions[0] = &self->_lf__reaction_1;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3.reactions = &self->_lf__line3_reactions[0];
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3.number_of_reactions = 1;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #ifdef FEDERATED
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    self->_lf__line3.physical_time_of_arrival = NEVER;
    #line 28 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/Display.lf"
    #endif // FEDERATED
    self->_lf__line3.tmplt.type.element_size = sizeof(string);
    return self;
}

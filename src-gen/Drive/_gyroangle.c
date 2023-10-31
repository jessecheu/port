#include "include/api/api.h"
#include "include/IMU/GyroAngle.h"
#include "_gyroangle.h"
// ***** Start of method declarations.
// ***** End of method declarations.
_gyroangle_self_t* new__gyroangle() {
    _gyroangle_self_t* self = (_gyroangle_self_t*)_lf_new_reactor(sizeof(_gyroangle_self_t));
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set input by default to an always absent default input.
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set the default source reactor pointer
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.last = NULL;
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 121 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

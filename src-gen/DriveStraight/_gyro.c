#include "include/api/api.h"
#include "include/IMU/Gyro.h"
#include "_gyro.h"
// *********** From the preamble, verbatim:
#line 32 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
// Static global IMU instance struct.
static imu_inst_t imu_instance;
// Boolean to ensure the IMU instance is initialized only once.
static bool _pololu_robot_imu_initialized = false;

// *********** End of preamble.
// ***** Start of method declarations.
// ***** End of method declarations.
#include "include/api/set.h"
void _gyroreaction_function_0(void* instance_args) {
    _gyro_self_t* self = (_gyro_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    
    #line 45 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    if (!_pololu_robot_imu_initialized) {
      _pololu_robot_imu_initialized = true;
      imu_init(&imu_instance);
    }
}
#include "include/api/set_undef.h"
#include "include/api/set.h"
void _gyroreaction_function_1(void* instance_args) {
    _gyro_self_t* self = (_gyro_self_t*)instance_args; SUPPRESS_UNUSED_WARNING(self);
    _gyro_trigger_t* trigger = self->_lf_trigger;
    int trigger_width = self->_lf_trigger_width; SUPPRESS_UNUSED_WARNING(trigger_width);
    _gyro_x_t* x = &self->_lf_x;
    _gyro_y_t* y = &self->_lf_y;
    _gyro_z_t* z = &self->_lf_z;
    #line 80 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    axes_data_t gyro_data;
    imu_read_gyro(&imu_instance, &gyro_data);
    lf_set(x, gyro_data.x);
    lf_set(y, gyro_data.y);
    lf_set(z, gyro_data.z);
}
#include "include/api/set_undef.h"
_gyro_self_t* new__gyro() {
    _gyro_self_t* self = (_gyro_self_t*)_lf_new_reactor(sizeof(_gyro_self_t));
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set input by default to an always absent default input.
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_trigger = &self->_lf_default__trigger;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    // Set the default source reactor pointer
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf_default__trigger._base.source_reactor = (self_base_t*)self;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.number = 0;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.function = _gyroreaction_function_0;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.self = self;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.deadline_violation_handler = NULL;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.STP_handler = NULL;
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.name = "?";
    #line 44 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_0.mode = NULL;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.number = 1;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.function = _gyroreaction_function_1;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.self = self;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.deadline_violation_handler = NULL;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.STP_handler = NULL;
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.name = "?";
    #line 79 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__reaction_1.mode = NULL;
    #ifdef FEDERATED_DECENTRALIZED
    self->_lf__startup.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #endif // FEDERATED_DECENTRALIZED
    self->_lf__startup_reactions[0] = &self->_lf__reaction_0;
    self->_lf__startup.last = NULL;
    self->_lf__startup.reactions = &self->_lf__startup_reactions[0];
    self->_lf__startup.number_of_reactions = 1;
    self->_lf__startup.is_timer = false;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.last = NULL;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.intended_tag = (tag_t) { .time = NEVER, .microstep = 0u};
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED_DECENTRALIZED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger_reactions[0] = &self->_lf__reaction_1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.reactions = &self->_lf__trigger_reactions[0];
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.number_of_reactions = 1;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #ifdef FEDERATED
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    self->_lf__trigger.physical_time_of_arrival = NEVER;
    #line 38 "/home/dobbs/ucb_related/fall2023/eecs149/port/src/lib/IMU.lf"
    #endif // FEDERATED
    self->_lf__trigger.tmplt.type.element_size = sizeof(bool);
    return self;
}

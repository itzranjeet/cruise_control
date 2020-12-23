#ifndef APPLIED_ACCELERATION_H
#define APPLIED_ACCELERATION_H
#include "cruise_control/constants.hpp"
#include "datatypes/datatypes.hpp"

class AppliedAcceleration 
{
public:
    AppliedAcceleration() = default;
    virtual ~AppliedAcceleration() = default;
    virtual void UpdateAcceleration();
    Torque TorqueAtWheels;
    Distance distance;
    Force ForceAtWheels;
    Acceleration AppliedAcceleration_;
    Acceleration AppliedAccelerationG;
    Acceleration AppliedAccelerationInMPH;

private:
};

#endif // APPLIED_ACCELERATION_H
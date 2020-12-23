#include "cruise_control/stub_node.hpp"
#include "cruise_control/applied_acceleration.hpp"

void AppliedAcceleration::UpdateAcceleration()
{
    TorqueAtWheels = VehicleTorque * GearRatio;
    distance = TireRadius / InchtoFeet;
    ForceAtWheels = TorqueAtWheels / distance;
    AppliedAcceleration_ = ForceAtWheels / MassOfCar;
    AppliedAccelerationG = AppliedAcceleration_ * GravityPerFeetSquare;
    AppliedAccelerationInMPH = AppliedAccelerationG * ConstantMPHConvert;
}

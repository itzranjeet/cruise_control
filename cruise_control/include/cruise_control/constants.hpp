#ifndef CONSTANTS_H
#define CONSTANTS_H
#include "datatypes/datatypes.hpp"

static constexpr Constant EngineEfficiency{0.95};
static constexpr Constant threshold{5.0};

static constexpr char AlgorithmNodeOutputMessageTopic[]{"algorithm_node"};
static constexpr char StubNodeOutputMessageTopic[]{"stub_node"};

static constexpr unsigned AlgorithmNodeOutputMessageQueueSize{10};
static constexpr unsigned StubNodeOutputMessageQueueSize{10};

static constexpr Gain Ki{0.0};
static constexpr Gain Kd{0.0};
static constexpr Gain Kp{0.2};
static constexpr Time dt{0.001};
static constexpr Constant YawRate{0.05};

static constexpr Torque VehicleTorque{100.0};                  //N-m
static constexpr Constant GearRatio{6.0};               //6 Gears
static constexpr Inches TireRadius{12.0};
static constexpr Constant InchtoFeet{12.0};             //Inches
static constexpr Mass MassOfCar{2500.0};                //Lbs
static constexpr Constant GravityPerFeetSquare{32.2}; //GravityPerFeetSquare
static constexpr Constant ConstantMPHConvert{0.6818}; //ConstantMPHConvert

#endif // CONSTANTS_H
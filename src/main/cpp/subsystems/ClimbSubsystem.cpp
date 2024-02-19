#include "subsystems/ClimbSubsystem.h"

using namespace ClimbConstants;

ClimbSubsystem::ClimbSubsystem()
	: m_climbMotor { kClimbMotor }
	, m_climbSwitch { kClimbSwitch } { }

bool ClimbSubsystem::GetSwitchValue() { return m_climbSwitch.Get(); }

void ClimbSubsystem::Climb(double upSpeed, double downSpeed) {
	if (GetSwitchValue() == true) {
		downSpeed = 0;
	}
	m_climbMotor.Set((upSpeed - downSpeed));
}

void ClimbSubsystem::Stop() { m_climbMotor.Set(0); }
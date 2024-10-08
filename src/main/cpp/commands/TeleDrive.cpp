#include "commands/TeleDrive.h"

TeleDrive::TeleDrive(DriveSubsystem* subsystem, TeleDrive::Control controlType, frc::XboxController* controller)
	: m_drive(subsystem)
	, m_controlType(controlType)
	, m_controller(controller) {
	AddRequirements({ subsystem });
}

void TeleDrive::Initialize() { }

void TeleDrive::Execute() {
	// Boost
	if (m_controller->GetLeftBumper()) {
		m_speedMult = 1.0;
	} else {
		m_speedMult = 0.5;
	}

	if (m_controlType == TeleDrive::Control::kTank) {
		m_drive->TankDrive(
			-(m_speedMult * (m_controller->GetLeftY())), (m_speedMult * (m_controller->GetRightY())), true);
	}

	if (m_controlType == TeleDrive::Control::kArcade) {
		m_drive->ArcadeDrive(
			-(m_speedMult * (m_controller->GetLeftY())), -(m_speedMult * (m_controller->GetRightX())), true);
	}
}

void TeleDrive::End(bool interrupted) { }

bool TeleDrive::IsFinished() { return false; }
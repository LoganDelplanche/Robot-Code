#pragma once

#include <frc/XboxController.h>
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/ScheduleCommand.h>
#include <frc2/command/button/CommandXboxController.h>
#include <subsystems/DriveSubsystem.h>

#include <cmath>

class TeleDrive : public frc2::CommandHelper<frc2::CommandBase, TeleDrive> {
public:
	enum Control { kTank, kArcade };

	/**
	 * @brief Creates a new Drive Command
	 *
	 * Control Types
	 * =============
	 *
	 * kTank
	 * kArcade
	 * kMecanum
	 * kMecanumTank
	 *
	 * @param[in] subsystem The subsytem to use.
	 * @param[in] controlType Accepts one of 4 values to specify which control scheme is used.
	 */
	explicit TeleDrive(DriveSubsystem* subsystem, Control controlType, double left, double right);

	void Initialize() override;

	void Execute() override;

	void End(bool interrupted) override;

	bool IsFinished() override;

private:
	double m_left;
	double m_right;
	double m_speedMult;
	TeleDrive::Control m_controlType;
	frc2::CommandXboxController m_driverController { OIConstants::kDriverControllerPort };
	DriveSubsystem* m_drive;
};
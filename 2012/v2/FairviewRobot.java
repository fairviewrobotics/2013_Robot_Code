package fairviewrobotics.y2012;

import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Watchdog;

public class FairviewRobot extends IterativeRobot
{
    ///A way to access the global drive, fork, claw, and control.
    ///Yes, I admit, this is terrible hackery.
    public static FairviewRobot me;
    DriveTrain drive;
    Forklift fork;
    Claw claw;
    JoystickControl control;


	public void sleep(long time)
	{
		long before = System.currentTimeMillis();
		while(System.currentTimeMillis()-before > time)
			;
	}

    public void robotInit()
    {
        me = this;

        Watchdog.getInstance().setEnabled(false);
        
        drive = new DriveTrain();
        fork = new Forklift();
        claw = new Claw();
        control = new JoystickControl();
    }

	public void autonomousInit()
	{
		claw.setClawSpeed(.5);
		fork.setForkSpeed(.5);
		sleep(700);

		fork.setForkSpeed(0);
		drive.drive(0, 0.7, 0);

		sleep(2000);				
		drive.drive(0,0,0);

		fork.setForkSpeed(-.5);
		if ( fork.bottom.get() == true){
			fork.setForkSpeed(0);
		}
	}

    public void teleopContinuous()
    {
        update();
    }

    public void update()
    {
        drive.drive(control.getX(), control.getY(), control.getRot());
        claw.set(control.getClawPos());
        fork.set(control.getForklift());
    }
}

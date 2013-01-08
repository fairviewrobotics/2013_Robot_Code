
package fairviewrobotics.y2012;


import edu.wpi.first.wpilibj.DigitalInput;
import edu.wpi.first.wpilibj.AnalogChannel;
import edu.wpi.first.wpilibj.Jaguar;
import edu.wpi.first.wpilibj.Joystick;
import edu.wpi.first.wpilibj.IterativeRobot;
import edu.wpi.first.wpilibj.Watchdog;
import edu.wpi.first.wpilibj.DriverStationLCD;
import edu.wpi.first.wpilibj.Timer;

public class FairviewRobot extends IterativeRobot {

	public Jaguar fRight, fLeft, rRight, rLeft;
	public Jaguar forklift1, forklift2;
	public Jaguar claw;

	Joystick rJoy, lJoy;

	boolean enabled;
	boolean enableLast;

	DigitalInput top;
	DigitalInput bottom;

	public AnalogChannel clawPot;

        public double clawTarget;
	
	public DriverStationLCD station;

	public Timer timer;
	double previoustime;

        final double CLAW_UPPER = 3.25;
        final double CLAW_LOWER = 1.5;
	
    public void teleopInit() {
		Watchdog.getInstance().setEnabled(false);

		//6 = backleft
		//1 = backright
		//7 = frontleft
		//2 = frontright

		fRight = new Jaguar(2);
		fLeft = new Jaguar(7);
		rRight = new Jaguar(1);
		rLeft = new Jaguar(6);

		top = new DigitalInput(1);
		bottom = new DigitalInput(2);

		enabled = true;

		rJoy = new Joystick(1);
		lJoy = new Joystick(2);


		forklift1 = new Jaguar(3);
		forklift2 = new Jaguar(4);

		claw = new Jaguar(5);
                clawPot = new AnalogChannel(1);
                clawTarget = 3;

                station = DriverStationLCD.getInstance();
    }

    public void teleopContinuous() { update(); }

	public double sign(double d)
	{
		if (d==0) {return 0;}
		return d < 0 ? -1 : 1;
	}

	public double power(double d, int p)
	{
		for(int i = 0; i < p; ++i)
			d *= d;
		return d;
	}

	public double bound(double d, double low, double hi)
	{
		d= d>low ? d : low;
		d= d<hi  ? d : hi;
		return d;
	}

	public void update()
	{
		double factor = 1.1;//rJoy.getThrottle();

                
                //station.println(DriverStationLCD.Line.kUser2, 1, "angle:     "+clawPot.getAverageVoltage());

		/*else if(lJoy.getTrigger())
			factor = 0.5;*/

		//factor = -rJoy.getThrottle()*0.5;

                double transX = -rJoy.getX();
		double transY = -rJoy.getY();
		double rotate = -rJoy.getRawAxis(5);

		/*if (rJoy.getRawButton(2)){
			gyro_enabled=false;
		}
		else {
			if (!gyro_enabled) {
				gyro_enabled = true;
				originalRot=gyro.getAngle();
			}
		}*
		
		/*double rotate;
		if (gyro_enabled){
			//spinRate += sign(-rJoy.getTwist()*time_step*250 - spinRate)*time_step;
			//originalRot += spinRate;
			originalRot += -(rJoy.getTwist()*time_step*250)*factor;
			rotate = -((originalRot-gyro.getAngle())*0.03-rJoy.getTwist()*0.75)*factor;
			//System.out.println(gyro.getAngle());
			//double angleFactor = -1.0;
			//double angleChange = (analogGyro.getAverageVoltage()-2.5)*angleFactor;

			//rotate = bound(-angleChange, -1.0, 1.0);
			station.println(DriverStationLCD.Line.kUser3, 1, "angle:     "+gyro.getAngle());
			station.println(DriverStationLCD.Line.kUser4, 1, "target:    "+originalRot);
			station.println(DriverStationLCD.Line.kUser5, 1, "difference:"+(originalRot-gyro.getAngle()));
			station.println(DriverStationLCD.Line.kUser6, 1, "timestep:  " + time_step);
			
			/*transX = Math.sqrt(Math.abs(transX))*sign(transX);
			transY = Math.sqrt(Math.abs(transY))*sign(transY);
			rotate = Math.sqrt(Math.abs(rotate))*sign(rotate);
		}
		else {
			rotate=-rJoy.getTwist()*factor;
		}
		station.println(DriverStationLCD.Line.kUser2, 1, "rotate: "+rotate);
		station.updateLCD();*/

		if(enabled)
		{
			move(transX*factor, transY*factor, rotate);
			//System.out.println(transX*factor);
		}
		else
			setWheels(0.0, 0.0, 0.0, 0.0);

		//---Disable combination---
		boolean disablePress = (rJoy.getRawButton(5) && rJoy.getRawButton(7) && rJoy.getRawButton(11) && rJoy.getRawButton(10))
			|| (rJoy.getRawButton(5) && rJoy.getRawButton(7) && rJoy.getRawButton(11) && rJoy.getRawButton(10));
		if(disablePress && !enableLast)
		{
			enabled = !enabled;
		}
		enableLast = disablePress;

		setForklift();
	}

	public void setForklift()
	{
		double forkspeed = ((rJoy.getRawButton(5)||lJoy.getRawButton(5))?1:0)
						 - ((rJoy.getRawButton(4)||lJoy.getRawButton(4))?0.7:0);
		//forkspeed *= ((rJoy.getRawButton(1) || lJoy.getRawButton(1)) ? 0.7 : 1.0);

		if(bottom.get())
			setForkSpeed(Math.max(Math.min(forkspeed, 1),0));
		//else if(top.get())
		//	setForkSpeed(Math.max(Math.min(forkspeed, 0),-1));
		else
			setForkSpeed(Math.max(Math.min(forkspeed, 1),-1));

                clawTarget = Math.max(Math.min((rJoy.getRawAxis(3)*1.5/2+0.5)*(CLAW_UPPER-CLAW_LOWER)+CLAW_LOWER,CLAW_UPPER),CLAW_LOWER);
                

		double clawSpeed = -(clawTarget - clawPot.getVoltage())*2;

                //System.out.println(clawSpeed);
		//clawSpeed *= (rJoy.getRawButton(1) || lJoy.getRawButton(1)) ? 0.15 : 0.25;
		claw.set(Math.max(Math.min(clawSpeed, 1),-1));
	}


	public void setWheels(double frontRight, double frontLeft,
	                   double rearRight,  double rearLeft)
	{
		fRight.set(-frontRight);
		fLeft.set(frontLeft);
		rRight.set(-rearRight);
		rLeft.set(rearLeft);
	}

	public void move(double x, double y, double rot)
	{
		setWheels(
			Math.max(Math.min(y + rot + x, 1),-1),
			Math.max(Math.min(y - rot - x, 1),-1),
			Math.max(Math.min(y + rot - x, 1),-1),
			Math.max(Math.min(y - rot + x, 1),-1)
		);
	}

	public void setForkSpeed(double spd)
	{
		forklift1.set(spd);
		forklift2.set(spd);
		//claw.set(Math.max(Math.min(spd, 1),-1));
	}
}

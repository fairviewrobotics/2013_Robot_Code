package fairviewrobotics.y2012;

import edu.wpi.first.wpilibj.Jaguar;
//import edu.wpi.first.wpilibj.AnalogChannel;
import edu.wpi.first.wpilibj.DigitalInput;

public class Claw
{
    private final int PWM_PORT = 5;
    private final int ANALOG_PORT = 1;
    private final double LOWER_LIMIT = 3.6;
    private final double UPPER_LIMIT = 3.8;
	private final boolean DEBUG_CLAW = false;
	private final boolean DISABLED = true;
	private final double SPEED = 0.5;
    private Jaguar claw;
	DigitalInput clawSensor;
    //private AnalogChannel clawSensor;
    private double clawTarget;


    Claw()
    {
        claw = new Jaguar(PWM_PORT);

		clawSensor = new DigitalInput(4);
        //clawSensor = new AnalogChannel(ANALOG_PORT);
        //clawTarget = LOWER_LIMIT;
    }

	public void debug() {
		//System.out.println(clawSensor.getVoltage());
	}

	public void manualDrive(double value) {
		setClawSpeed(value/2);
	}

    ///Sets the claw's desired position, and translates towards it.
	// was doubled
    public void set(double value)
    {
		setClawSpeed(clawSensor.get() ? Utilities.clamp(value*SPEED, -1, 0) : value*SPEED);
		//if (MANUAL) {manualDrive(value);}
		//if (DEBUG_CLAW) { debug();}
		//if (DISABLED) { return; }
		//if (MANUAL || DEBUG_CLAW) {return;}
        //clawTarget = Utilities.lerp(value, LOWER_LIMIT, UPPER_LIMIT);
        //double clawSpeed = -(clawTarget - clawSensor.getVoltage()) * 2;
        //Utilities.clamp(clawSpeed, -1, 1);
        //setClawSpeed(clawSpeed);
    }

    public void setClawSpeed(double val)
    {
        claw.set(Utilities.clamp(val, -1, 1));
    }
}
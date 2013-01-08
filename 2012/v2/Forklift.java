package fairviewrobotics.y2012;

import edu.wpi.first.wpilibj.Jaguar;
import edu.wpi.first.wpilibj.DigitalInput;

public class Forklift
{
    private final int FL1_PWM_PORT = 3;
    private final int FL2_PWM_PORT = 4;
    private final int TOP_DIG_PORT_1 = 1;
	private final int TOP_DIG_PORT_2 = 3;
    private final int BOT_DIG_PORT = 2;
    private final boolean TOP_DISABLED = true;
    private final boolean BOT_DISABLED = false;
	private final boolean DEBUG = false;
	private Jaguar forklift1, forklift2;
    public DigitalInput top1, top2, bottom;

    Forklift()
    {
        forklift1 = new Jaguar(FL1_PWM_PORT);
        forklift2 = new Jaguar(FL2_PWM_PORT);

        top1 = new DigitalInput(TOP_DIG_PORT_1);
		top2 = new DigitalInput(TOP_DIG_PORT_2);
        bottom = new DigitalInput(BOT_DIG_PORT);
    }

    ///Sets the forklift speed, limiting movement to the lower and upper
    ///limit switch.
    public void set(double value)
    {
        if (bottom.get() && !BOT_DISABLED)
        {
            value = Math.max(value, 0);
        }
        if ((top1.get() || top2.get()) && !TOP_DISABLED)
        {
            value = Math.min(value, 0);
        }

		if (DEBUG) {
			System.out.println("Top: " + top1.get() + top2.get());
			System.out.println("Bot: " + bottom.get());

		}

        setForkSpeed(Utilities.clamp(value, -1, 1));
    }

    public void setForkSpeed(double speed)
    {
        forklift1.set(speed);
        forklift2.set(speed);
        //claw.set(Math.max(Math.min(spd, 1),-1));
    }
}
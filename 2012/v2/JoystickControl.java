package fairviewrobotics.y2012;

import edu.wpi.first.wpilibj.Joystick;

public class JoystickControl
{
    private Joystick rJoy;
    private final double AXIS_COMP_FACTOR = 1.1;

    JoystickControl()
    {
        rJoy = new Joystick(1);
    }

    public double getFactor()
    {
        return 1.0;
    }

    public double getX()
    {
        return -rJoy.getX() * AXIS_COMP_FACTOR * getFactor();
    }

    public double getY()
    {
        return -rJoy.getY() * AXIS_COMP_FACTOR * getFactor();
    }

    public double getRot()
    {
        return -rJoy.getRawAxis(5) * AXIS_COMP_FACTOR * getFactor();
    }

    public boolean getDisablePress()
    {
        return rJoy.getRawButton(5)
            && rJoy.getRawButton(7)
            && rJoy.getRawButton(11)
            && rJoy.getRawButton(10);
    }

    public double getForklift()
    {
        return (rJoy.getRawButton(5) ? 1 : 0)
                - (rJoy.getRawButton(4) ? 1 : 0);
    }

    public double getClawPos()
    {
        return (rJoy.getRawButton(1)?1:0) - (rJoy.getRawButton(2)?1:0);
    }
}

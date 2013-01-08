package fairviewrobotics.y2012;

import edu.wpi.first.wpilibj.Jaguar;

public class DriveTrain
{
    private final int FR_PWM_PORT = 2;
    private final int FL_PWM_PORT = 7;
    private final int RR_PWM_PORT = 1;
    private final int RL_PWM_PORT = 6;
    private Jaguar fRight, fLeft, rRight, rLeft;

    DriveTrain()
    {
        fRight = new Jaguar(FR_PWM_PORT);
        fLeft = new Jaguar(FL_PWM_PORT);
        rRight = new Jaguar(RR_PWM_PORT);
        rLeft = new Jaguar(RL_PWM_PORT);
    }

    ///Moves the robot with a translation of (x,y) and rotates it by rot.
    public void drive(double x, double y, double rot)
    {
        setWheels(
                Utilities.clamp(y + rot + x, -1, 1),
                Utilities.clamp(y - rot - x, -1, 1),
                Utilities.clamp(y + rot - x, -1, 1),
                Utilities.clamp(y - rot + x, -1, 1));
    }

    ///Directly sets the wheels, ensuring that positive is always forwards (backwards?).
    public void setWheels(double frontRight, double frontLeft,
            double rearRight, double rearLeft)
    {
        fRight.set(-frontRight);
        fLeft.set(frontLeft);
        rRight.set(-rearRight);
        rLeft.set(rearLeft);
    }
}

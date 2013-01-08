package fairviewrobotics.y2012;

public class Utilities
{
    ///Returns d limited to within [low, high]
    public static double clamp(double d, double low, double high)
    {
        return (d > low) ? (d < high ? d : high) : low;
    }

    ///Linearly interpolats between low and high.
    ///A factor of zero represents low, one represents high.
    public static double lerp(double factor, double low, double high)
    {
        return low * (1.0 - factor) + high * (factor);
    }
}

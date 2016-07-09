public class Solution {
    public double Power(double base, int exponent) {
        int p = 0;

        if (exponent > 0) {
            p = exponent;
        } else if (exponent < 0) {
            if (base == 0) {
                throw new RuntimeException("base cannot be zero here!");
            }
            p = -exponent;
        } else {
            return 1;	// including 0/0 == 1
        }

        double curr = 1.0;
        while (p > 0) {
            if ((p & 1) != 0) {
                curr *= base;
            }
            base *= base;
            p >>= 1;
        }
        return (exponent < 0) ? 1 / curr : curr;
    }
}

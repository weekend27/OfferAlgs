class Solution {
public:
    double Power(double base, int exponent) {

        // 参考： http://www.cnblogs.com/CheeseZH/p/5113000.html

        int p = abs(exponent);
        double r = 1.0;
        while (p) {
            if (p & 1) r *= base;
            base *= base;
            p >>= 1;
        }
        return exponent > 0 ? r : 1 / r;
    }
};

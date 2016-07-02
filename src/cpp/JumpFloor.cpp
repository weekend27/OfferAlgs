class Solution {
public:
    int jumpFloor(int number) {

        // 本质上是斐波那契数列问题
        // f(n) = f(n-1) + f(n-2)
        // f(0) = 1, f(1) = 1, f(2) = 2

        if (number <= 1) return 1;

        int i;
        int a = 1, b = 1;

        for (i = 2; i <= number; ++i) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};

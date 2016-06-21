class Solution {
public:
    int rectCover(int number) {

        // 变形的斐波那契数列

        if (number == 0 || number == 1) return 1;

        int a = 1, b = 1;

        while (number-- >= 2) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};

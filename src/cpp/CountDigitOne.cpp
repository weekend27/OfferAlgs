class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int res = 0;
        for (long long k = 1; k <= n; k *= 10) {
            int a = n / k, b = n % k;
            res += (a + 8) / 10 * k + (a % 10 == 1 ? b + 1 : 0);
        }
        return res;
    }
};

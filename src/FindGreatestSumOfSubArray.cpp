class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int n = array.size();
        if (n == 0) return 0;

        int maxSum = array[0];
        int curSum = 0;
        for (int i = 0; i < n; ++i) {
            curSum = (curSum + array[i] > array[i]) ? curSum + array[i] : array[i];
            maxSum = (maxSum > curSum) ? maxSum : curSum;
        }
        return maxSum;
    }
};

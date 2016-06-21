class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if (k <= 0 || k > input.size()) {
            return vector<int>();
        }

        vector<int> result;

        sort(input.begin(), input.end());
        for (int i = 0; i < k; ++i) {
            result.push_back(input[i]);
        }
        return result;
    }
};

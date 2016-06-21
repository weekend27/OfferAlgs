class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd;
        vector<int> even;

        for (auto &i : array) {
            if (i & 1) {
                odd.push_back(i);
            } else {
                even.push_back(i);
            }
        }

        for (int i = 0; i < odd.size(); ++i) {
            array[i] = odd[i];
        }

        for (int i = odd.size(); i < odd.size() + even.size(); ++i) {
            array[i] = even[i - odd.size()];
        }
    }
};

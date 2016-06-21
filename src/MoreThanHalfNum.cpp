class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if (numbers.size() == 0) {
            return 0;
        }

        int target = numbers[0];
        unsigned int cnt = 1;

        for (int i = 1; i < numbers.size(); ++i) {
            if (target == numbers[i]) {
                cnt++;
            } else {
                cnt--;
            }

            if (cnt == 0) {
                target = numbers[i];
                cnt = 1;
            }
        }

        cnt = 0;

        for (int i = 0; i < numbers.size(); ++i) {
            if (target == numbers[i]) {
                cnt++;
            }
        }

        if (2 * cnt > numbers.size()) {
            return target;
        } else {
            return 0;
        }
    }
};

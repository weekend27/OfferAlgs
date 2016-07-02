class Solution {
public:
    int (vector<int> rotateArray) {
        int len = rotateArray.size();
        if (len == 0) {
            return 0;
        }

        // 设置比较的初始对象，逐个逐个比较，找出比初始对象小的元素
        int tmp = rotateArray[0];
        for (int i = 1; i < len; ++i) {
            if (rotateArray[i] < tmp) {
                return rotateArray[i];
            }
        }
        return tmp;
    }
};

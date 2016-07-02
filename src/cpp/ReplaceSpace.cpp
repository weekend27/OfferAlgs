class Solution {
public:
	void replaceSpace(char *str,int length) {
        // 复杂度 O(N)

        if (str == NULL || length < 0) {
            return;
        }

        // 统计空格的个数，记录下总长度
        int spaces = 0;
        int i = 0;
        int reallen = 0;
        while (str[i] != '\0') {
            ++reallen;
            if (str[i] == ' '){
                ++spaces;
            }
            ++i;
        }

        // 新的数组空间大小
        int newlen = reallen + 2 * spaces;

        // 双指针，从后往前写，不需要开辟另外一个数组
        int p1 = reallen;
        int p2 = newlen;
        while (p1 >= 0 && p2 > p1) {
            if (str[p1] == ' ') {
                str[p2--] = '0';
                str[p2--] = '2';
                str[p2--] = '%';
            } else {
                str[p2--] = str[p1];
            }
            --p1;
        }
	}
};

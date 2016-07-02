class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.length() == 0) {
            return -1;
        }
        int hash[256] = {0};
        int i = 0;
        while (str[i] != '\0') {
            hash[str[i]]++;
            i++;
        }
        i = 0;
        while (str[i] != '\0') {
            if (1 == hash[str[i]]) {
                return i;
            }
            i++;
        }
        return -1;
    }
};

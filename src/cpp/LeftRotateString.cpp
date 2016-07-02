class Solution {
public:
    string LeftRotateString(string str, int n) {

        int len = str.size();

        if (len > 0 && n > 0 && n <= len) {
          int firstStart = 0;
          int firstEnd = n - 1;
          int secondStart = n;
          int secondEnd = len - 1;

          string &tmpStr = str;

          // 翻转字符串前面的n个字符
          Reverse(tmpStr, firstStart, firstEnd);
          // 翻转字符串后面剩下的字符
          Reverse(tmpStr, secondStart, secondEnd);
          // 最后翻转整个字符串
          Reverse(tmpStr, firstStart, secondEnd);

        }

        return str;

    }

    void Reverse(string& str, int start, int end) {
      if (start > end || str.size() == 0) {
        return;
      }
      while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
      }
    }
};

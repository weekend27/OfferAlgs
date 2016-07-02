class Solution {
public:
    string ReverseSentence(string str) {
      string &tmpStr = str;

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

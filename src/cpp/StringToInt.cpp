class Solution {
public:
    enum Status {kValid = 0, kInvalid};
    int g_nStatus = kValid;

    int StrToInt(string str) {
      int g_nStatus = kInvalid;
      long long num = 0;
      int i = 0;
      if (str.size() != 0 && str[i] != '\0') {
        bool minus = false;
        if (str[i] == '+') {
          i++;
        }
        else if (str[i] == '-') {
          minus = true;
          i++;
        }
        string newStr = str.substr(i);
        if (str[i] != '\0') {
          num = StrToIntCore(newStr, minus);
        }
      }

      return (int)num;
    }


    long long StrToIntCore(string digit, bool minus) {
      long long num = 0;
      int i = 0;
      while (digit[i] != '\0') {
        if (digit[i] >= '0' && digit[i] < '9') {
          int flag = minus ? -1 : 1;
          num = num * 10 + flag * (digit[i] - '0');

          if ((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000)) {
            num = 0;
            break;
          }

          ++i;
        }
        else {
          num = 0;
          break;
        }
      }

      if (digit[i] == '\0') {
        g_nStatus = kValid;
      }

      return num;
    }
};

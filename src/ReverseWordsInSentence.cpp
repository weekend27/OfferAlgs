class Solution {
public:
    string ReverseSentence(string str) {
      vector<string> vec;
      string res;
      if (str.size() == 0) {
        return str;
      }
      for (int i = 0; i < str.size(); ++i) {
        res += str[i];
        if (str[i] == ' ') {
          res.pop_back();  // pop the space out
          vec.push_back(res);
          res.clear();
          continue;
        }
      }
      vec.push_back(res);
      res.clear();
      for (int i = vec.size() - 1; i >= 0; --i) {
        res += vec[i];
        res += ' ';
      }
      res.pop_back();
      return res;
    }
};

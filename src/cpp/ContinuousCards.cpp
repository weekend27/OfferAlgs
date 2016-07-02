class Solution {
public:
    bool IsContinuous(vector<int> numbers ) {
      if (numbers.size() != 5) {
        return false;
      }

      sort(numbers.begin(), numbers.end());
      int jokers = 0;
      for (int i = 0; i < 5 && numbers[i] == 0; ++i) {
        jokers++;
      }

      if (jokers > 4) {
        return false;
      }

      for (int i = jokers; i < 4; ++i) {
        if (numbers[i] == numbers[i + 1]) {
          return false;
        }
      }

      int dis = numbers[4] - numbers[jokers];
      if (dis <= 4) return true;
      return false;
    }
};

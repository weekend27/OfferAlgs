class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
      if (sum < 3) {
        return vector<vector<int> >();
      }

      int small = 1;
      int big = 2;
      int mid = (1 + sum) / 2;
      int currSum = small + big;

      vector<vector<int> > result;

      while (small < mid) {
        if (currSum == sum) {
          vector<int> sequence;
          for (int i = small; i <= big; ++i) {
            sequence.push_back(i);
          }
          result.push_back(sequence);
        }

        while (currSum > sum && small < mid) {
          currSum -= small;
          small++;

          if (currSum == sum) {
            vector<int> sequence;
            for (int i = small; i <= big; ++i) {
              sequence.push_back(i);
            }
            result.push_back(sequence);
          }
        }

        big++;
        currSum += big;
      }

      return result;

    }
};

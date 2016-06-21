class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
      if (array.size() < 1) {
        return vector<int> ();
      }

      vector<int> result;

      int start = 0;
      int end = array.size() - 1;

      while (start < end) {
        int currSum = array[start] + array[end];

        if (currSum == sum) {
          result.push_back(array[start]);
          result.push_back(array[end]);
          break;
        }
        else if (currSum < sum) {
          start++;
        }
        else {
          end--;
        }
      }

      return result;
    }
};

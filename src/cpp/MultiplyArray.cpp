class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
      vector<int> result(A.size());
      result[0] = 1;
      for (int i = 1; i < A.size(); ++i) {
        result[i] = result[i-1] * A[i-1];
      }

      int tmp = 1;
      for (int i = A.size() - 2; i >= 0; --i) {
        tmp *= A[i+1];
        result[i] *= tmp;
      }

      return result;

    }
};

class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
      if (n < 1 || m < 1) {
        return -1;
      }

      unsigned int i = 0;
      list<int> nums;
      for (i = 0; i < n; ++i) {
        nums.push_back(i);
      }

      list<int>::iterator curr = nums.begin();
      while (nums.size() > 1) {
        for (int i = 1; i < m; ++i) {
          curr++;
          if (curr == nums.end()) {
            curr = nums.begin();
          }
        }

        list<int>::iterator next = ++curr;
        if (next == nums.end()) {
          next = nums.begin();
        }

        --curr;
        nums.erase(curr);
        curr = next;
      }

      return *curr;
    }
};

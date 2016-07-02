class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
      int len = data.size();
      int num = 0;

      if (len > 0) {
        int first = GetFirstK(data, len, k, 0, len - 1);
        int last = GetLastK(data, len, k, 0, len - 1);

        if (first > -1 && last > -1) {
          num = last - first + 1;
        }
      }

      return num;
    }

    int GetFirstK(vector<int>& data, int length, int k, int start, int end) {
      if (start > end) {
        return -1;
      }

      int midIndex = start + (end - start) / 2;
      int midData = data[midIndex];

      if (midData == k) {
        if (((midIndex > 0) && (data[midIndex-1] != midData)) || (midIndex == 0)) {
          return midIndex;
        } else {
            end = midIndex - 1;
        }
      }
      else if (midData < k) {
        start = midIndex + 1;
      }
      else {
        end = midIndex - 1;
      }

      return GetFirstK(data, length, k, start, end);
    }

    int GetLastK(vector<int>& data, int length, int k, int start, int end) {
      if (start > end) {
        return -1;
      }

      int midIndex = start + (end - start) / 2;
      int midData = data[midIndex];

      if (midData == k) {
        if (((midIndex < length - 1) && (data[midIndex + 1] != midData)) || (midIndex == length - 1)) {
          return midIndex;
        } else {
            start = midIndex + 1;
        }
      }
      else if (midData < k) {
        start = midIndex + 1;
      }
      else {
        end = midIndex - 1;
      }

      return GetLastK(data, length, k, start, end);
    }
};

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
      if (data.size() < 2) {
        return;
      }

      int resultExclusiveOR = 0;
      for (int i = 0; i < data.size(); ++i) {
        resultExclusiveOR ^= data[i];
      }

      unsigned int indexOf1 = FindFirstBit1(resultExclusiveOR);

      *num1 = *num2 = 0;

      for (int j = 0; j < data.size(); ++j) {
        if (IsBit1(data[j], indexOf1)){
          *num1 ^= data[j];
        }
        else {
          *num2 ^= data[j];
        }
      }

    }

    unsigned int FindFirstBit1(int num) {
      int indexBit = 0;
      while (((num & 1) == 0) && (indexBit < 8 * sizeof(int))) {
        num >>= 1;
        ++indexBit;
      }
      return indexBit;
    }

    bool IsBit1(int num, unsigned int indexBit) {
      num >>= indexBit;
      return (num & 1);
    }
};

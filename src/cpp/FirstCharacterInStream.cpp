class Solution
{
public:
    Solution() : index(0)
    {
      for (int i = 0; i < 256; ++i) {
        occurrence[i] = -1;
      }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
      if (occurrence[ch] == -1)
        occurrence[ch] = index;
      else if (occurrence[ch] >= 0)
        occurrence[ch] = -2;

      index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
      char ch = '\0';
      int minIndex = numeric_limits<int>::max();
      for (int i = 0; i < 256; ++i) {
        if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
          ch = (char)i;
          minIndex = occurrence[i];
        }
      }
      if (ch == '\0') {
          ch = '#';
      }
      return ch;
    }

private:
  int occurrence[256];
  int index;

};

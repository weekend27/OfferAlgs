public class Solution {

    private int[] occurrence = new int[256];
    private int index;

    public Solution() {
        for (int i = 0; i < 256; i++) {
            occurrence[i] = -1;
        }
        index = 0;
    }

    //Insert one char from stringstream
    public void Insert(char ch)
    {
        if (occurrence[ch] == -1) {
            occurrence[ch] = index;
        } else if (occurrence[ch] >= 0) {
            occurrence[ch] = -2;
        }

        index++;
    }

  	//return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
    	char ch = '\0';
        int minIndex = Integer.MAX_VALUE;
        for (int i = 0; i < 256; i++)  {
            if (occurrence[i] >= 0 && occurrence[i] < minIndex) {
                ch = (char)(i);
                minIndex = occurrence[i];
            }
        }

        if (ch == '\0') {
            return '#';
        }

        return ch;
    }
}

//num1,num2分别为长度为1的数组。传出参数
//将num1[0],num2[0]设置为返回结果
public class Solution {
    public void FindNumsAppearOnce(int [] array,int num1[] , int num2[]) {
        if (array == null || array.length < 2) {
            return ;
        }

        // find two nums
        int temp = 0;
        for (int i = 0; i < array.length; i++) {
            temp ^= array[i];
        }

        // split temp into two parts
        int indexOfOne = findFirstOneBit(temp);
        for (int i = 0; i < array.length; i++) {
            if (isOneBit(array[i], indexOfOne)) {
                num1[0] ^= array[i];
            } else {
                num2[0] ^= array[i];
            }
        }
    }

    private int findFirstOneBit(int num) {
        int indexOfOne = 0;
        int flag = 1;

        // count from right to left
        while (((num & flag) == 0) && (flag != 0)) {
            indexOfOne++;
            flag = flag << 1;
        }
        return indexOfOne;
    }

    private boolean isOneBit(int num, int index) {
        return ((num & (1 << index)) != 0);
    }
}

public class Solution {
    public boolean isContinuous(int [] numbers) {
        if (numbers == null || numbers.length != 5) {
            return false;
        }

        int max = -1;
        int min = 14;
        int flag = 0;
        for (int i = 0; i < numbers.length; i++) {
            int num = numbers[i];
            if (num < 0 || num > 13) return false;
            if (num == 0) continue;
            if(((flag >> num) & 1) == 1) return false;
            flag |= (1 << num);
            if (num > max) max = num;
            if (num < min) min = num;
            if (max - min >= 5) return false;
        }

        return true;
    }
}

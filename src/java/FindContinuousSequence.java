import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();

        if (sum < 3) {
            return result;
        }

        int small = 1;
        int big = 2;
        int mid = (sum + 1) / 2;
        int currSum = small + big;

        while (small < mid) {
            while (small < mid && currSum > sum) {
                currSum -= small;
                small++;
            }

            if (currSum == sum) {
                addToList(result, small, big);
            }

            big++;
            currSum += big;
        }

        return result;
    }

    private void addToList(ArrayList<ArrayList<Integer>> result, int small, int big) {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = small; i <= big; i++) {
            list.add(i);
        }
        result.add(list);
    }
}

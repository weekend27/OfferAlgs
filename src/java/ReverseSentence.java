public class Solution {
    public String ReverseSentence(String str) {
        // only blanks
        if (str.trim().equals("")) {
            return str;
        }

        // reverse the whole string
        String revString = reverse(str);

        // split the sentence
        String[] splitStrings = revString.split(" ");

        String result = "";

        // reverse each word
        for (String s : splitStrings) {
            result += reverse(s) + " ";
        }

        return result.trim();
    }

    // reverse a string
    private String reverse(String str) {
        char[] a = str.toCharArray();
        char temp;
        int start = 0;
        int end = a.length - 1;
        while (start < end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;

            start++;
            end--;
        }
        return String.valueOf(a);
    }
}

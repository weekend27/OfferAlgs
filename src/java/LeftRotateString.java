public class Solution {
    public String LeftRotateString(String str,int n) {
        if (str == null || str.trim().equals("")) {
            return str;
        }
        if (n > str.length()) {
            return "";
        }

        int preStart = 0;
        int preEnd = n - 1;
        int posStart = n;
        int posEnd = str.length() - 1;

        char[] a = str.toCharArray();

        // reverse the previous part
        reverse(a, preStart, preEnd);

        // reverse the post part
        reverse(a, posStart, posEnd);

        // reverse the whole sentence
        reverse(a, preStart, posEnd);

        StringBuffer sb = new StringBuffer(str.length());
        for (char c : a) {
            sb.append(c);
        }

        return sb.toString();
    }

    private void reverse(char[] a, int start, int end) {
        char temp;
        while (start < end) {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;

            start++;
            end--;
        }
    }
}

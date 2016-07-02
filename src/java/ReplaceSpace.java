public class Solution {
    public String replaceSpace(StringBuffer str) {

        // corner case
        if (str == null) {
            return null;
        }

        // calculate the space number
        int spaceNum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                spaceNum++;
            }
        }

        // resize the stringbuffer str
        int oldindex = str.length() - 1;
        int newlength = str.length() + 2 * spaceNum;
        int newindex = newlength - 1;
        str.setLength(newlength);

        // copy and replace
        for (; oldindex >= 0; oldindex--) {
            if(str.charAt(oldindex) == ' '){
                str.setCharAt(newindex--, '0');
                str.setCharAt(newindex--, '2');
                str.setCharAt(newindex--, '%');
            }else{
                str.setCharAt(newindex--, str.charAt(oldindex));
            }
        }

        return str.toString();
    }
}

public class Solution {
    public boolean match(char[] str, char[] pattern)
    {
        if (str == null || pattern == null) {
            return false;
        }

        int strIndex = 0;
        int patternIndex = 0;
        return helper(str, strIndex, pattern, patternIndex);
    }

    private boolean helper(char[] str, int strIndex, char[] pattern, int patternIndex) {
        //str到尾，pattern到尾，匹配成功
        if (strIndex == str.length && patternIndex == pattern.length) {
            return true;
        }
        //str未到尾，pattern到尾，匹配失败
        if (strIndex != str.length && patternIndex == pattern.length) {
            return false;
        }
        //str到尾，pattern未到尾(不一定匹配失败，因为a*可以匹配0个字符)
        if (strIndex == str.length && patternIndex != pattern.length) {
            //只有pattern剩下的部分类似a*b*c*的形式，才匹配成功
            if (patternIndex + 1 < pattern.length && pattern[patternIndex + 1] == '*') {
                return helper(str, strIndex, pattern, patternIndex + 2);
            }
            return false;
        }
        //str未到尾，pattern未到尾
        if (patternIndex + 1 < pattern.length && pattern[patternIndex + 1] == '*') {
            if (str[strIndex] == pattern[patternIndex] || (pattern[patternIndex] == '.' && strIndex != str.length)) {
                return helper(str, strIndex, pattern, patternIndex + 2)			// *匹配0个，跳过
                    || helper(str, strIndex + 1, pattern, patternIndex + 2)		// *匹配1个，跳过
                    || helper(str, strIndex + 1, pattern, patternIndex);		// *匹配1个，再匹配str中的下一个
            } else {
                // 直接跳过*（*匹配到0个）
                return helper(str, strIndex, pattern, patternIndex + 2);
            }
        }

        if (str[strIndex] == pattern[patternIndex] || (pattern[patternIndex] == '.' && strIndex != str.length)) {
            return helper(str, strIndex + 1, pattern, patternIndex + 1);
        }

        return false;
    }
}

public class Solution {
    public boolean isNumeric(char[] str) {
        if (str == null) {
            return false;
        }
        if (str.length == 0) {
            return false;
        }
        if ((str[0] < '0' || str[0] > '9') && (str[0] != '-' && str[0] != '+')) {
            return false;
        }
        int start = 0;
        boolean flag1 = false;	// 是否出现过 '+' or '-'
        boolean flag2 = false;	// 是否出现过 '.'
        boolean flag3 = false;	// 是否出现过 'e' or 'E'
        if (str[0] == '-' || str[0] == '+') {
            start = 1;
            flag1 = true;
        }
        for (int i = start; i < str.length; i++) {
            if (str[i] >= '0' && str[i] <= '9') {	// 遇到数字，跳过
                continue;
            }

            if (str[i] == '-' || str[i] == '+') {	// 遇到'+' or '-'
                if (flag1) {	// 不能重复出现 + -
                    return false;
                }
                if (i + 1 == str.length) {	// 不能在末尾出现 + -
                    return false;
                }
                if (!flag3 && start == 0) {	// 既不在最开始出现，也不在指数部分出现，返回错误
                    return false;
                }
                flag1 = true;	// 标记已经出现 + -

            } else if (str[i] == '.') {	// 遇到 '.'
                if (flag2) {	// 不能重复出现 '.'
                    return false;
                }
                flag2 = true;	// 标记已经出现 '.'

            } else if (str[i] == 'e' || str[i] == 'E') {	// 遇到'e' or 'E'
                if (flag3) {	// 不能重复出现'e' or 'E'
                    return false;
                }
                if (i + 1 == str.length) {	// 不能出现在末尾
                    return false;
                }
                flag3 = true;	// 标记已经出现'e' or 'E'
                flag1 = false;	// 在指数部分，+ - 可以再次出现
                flag2 = true;	// 指数不可以出现小数

            } else {	// 遇到其他字符，返回错误
                return false;
            }
        }
        return true;
    }
}

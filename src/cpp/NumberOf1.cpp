class Solution {
public:
     int  NumberOf1(int n) {

         // 负数需要特殊处理，因为负数右移会补1（符号位）

         unsigned int i = n;

         int sum = 0;

         while (i) {
             sum += (i & 1);
             i >>= 1;
         }

         return sum;
     }
};

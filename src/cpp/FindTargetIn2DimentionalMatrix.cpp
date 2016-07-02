class Solution {
public:

  // 规律：首先选取数组中右上角的数字。如果该数字等于要查找的数字，查找过程结束：
  // 如果该数字大于要查找的数字，剔除这个数字所在的列：如果该数字小于要查找的数字，剔除这个数字所在的行。
  // 也就是说如果要查找的数字不在数组的右上角，则每－次都在数组的查找范围中剔除）行或者一列，这样每一步都可以缩小 
    bool Find(vector<vector<int> > array,int target) {

        if (array.empty() || array.size() < 1 || array[0].size() < 1) {
            return false;
        }

        int rows = array.size();		// 数组的行数
        int cols = array[0].size();		// 数组的列数

        int row = 0;
        int col = cols - 1;

        while (row >= 0 && row < rows && col >= 0 && col < cols) {
            if (array[row][col] == target) {
                return true;
            } else if (array[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }

        return false;

    }
};

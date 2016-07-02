class Solution {
public:
    int InversePairs(vector<int> data) {
        int len = data.size();
        return mergeSort(data, 0, len - 1);
    }

    int mergeSort(vector<int>& data, int start, int end) {
        // 递归终止条件
        if (start >= end) {
            return 0;
        }

        // 递归
        int mid = start + (end - start) / 2;
        int leftCounts = mergeSort(data, start, mid);
        int rightCounts = mergeSort(data, mid+1, end);

        // 归并排序，并计算本次逆序对数
        vector<int> copy(data); // 数组副本，用于归并排序
        int prevIndex = mid;	// 前半部分的指标
        int nextIndex = end;	// 后半部分的指标
        int counts = 0;			// 记录本次逆序对数
        int copyIndex = end;	// 辅助数组的下标
        while (prevIndex >= start && nextIndex >= mid + 1) {
            if (data[prevIndex] > data[nextIndex]) {
                copy[copyIndex--] = data[prevIndex--];
                counts += nextIndex - mid;
            } else {
                copy[copyIndex--] = data[nextIndex--];
            }
        }
        while (prevIndex >= start) {
            copy[copyIndex--] = data[prevIndex--];
        }
        while (nextIndex >= mid + 1) {
            copy[copyIndex--] = data[nextIndex--];
        }
        for (int i = start; i <= end; i++) {
            data[i] = copy[i];
        }
        return (leftCounts + rightCounts + counts);
    }
};

package cetc15.algs;

public class Permutation2 {

	public static void permute(char[] buf, int start, int end) {
		if (start == end) {		// 当只要求对数组中一个字母进行全排列时，只要就按该数组输出即可
			for (int i = 0; i <= end; i++) {
				System.out.print(buf[i]);
			}
			System.out.println();
		} else {	// 多个字母全排列
			for (int i = start; i <= end; i++) {
				// 交换数组第一个元素与后续的元素
				char temp = buf[i];
				buf[i] = buf[start];
				buf[start] = temp;

				// 后续元素递归全排列
				permute(buf, start + 1, end);

				// 将交换后的数组还原
				temp = buf[i];
				buf[i] = buf[start];
				buf[start] = temp;
			}
		}
	}

	public static void main(String[] args) {
		char[] buf = {'a', 'b', 'c'};
		permute(buf, 0, 2);
	}

}

public class Solution {
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str)
    {
    	int[] visited = new int[matrix.length];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (helper(matrix, rows, cols, i, j, str, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

	private boolean helper(char[] matrix, int rows, int cols, int i, int j, char[] str, int k, int[] visited) {
        int index = i * cols + j;
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[index] != str[k] || visited[index] == 1) {
            return false;
        }

        if (k == str.length - 1) {
            return true;
        }

        // visited
        visited[index] = 1;
        if (helper(matrix, rows, cols, i - 1, j, str, k + 1, visited)
         || helper(matrix, rows, cols, i + 1, j, str, k + 1, visited)
         || helper(matrix, rows, cols, i, j - 1, str, k + 1, visited)
         || helper(matrix, rows, cols, i, j + 1, str, k + 1, visited)
        ) {
            return true;
        }

        // not visited
        visited[index] = 0;

        return false;
    }
}

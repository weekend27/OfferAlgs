import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix) {

        // corner case
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return null;
        }

        ArrayList<Integer> list = new ArrayList<>();

        int tR = 0;
        int tC = 0;
        int dR = matrix.length - 1;
        int dC = matrix[0].length - 1;
        while (tR <= dR && tC <= dC) {
            printEdge(list, matrix, tR++, tC++, dR--, dC--);
        }

        return list;
    }

    private void printEdge(ArrayList<Integer> list, int[][] m, int tR, int tC, int dR, int dC) {
        if (tR == dR) {		// only one row
            for (int i = tC; i <= dC; i++) {
                list.add(m[tR][i]);
            }
        } else if (tC == dC) {		// only one column
            for (int i = tR; i <= dR; i++) {
                list.add(m[i][tC]);
            }
        } else {	// common case
            int currR = tR;
            int currC = tC;

            while (currC != dC) {
                list.add(m[tR][currC]);
                currC++;
            }
            while (currR != dR) {
                list.add(m[currR][dC]);
                currR++;
            }
            while (currC != tC) {
                list.add(m[dR][currC]);
                currC--;
            }
            while (currR != tR) {
                list.add(m[currR][tC]);
                currR--;
            }
        }
    }

}

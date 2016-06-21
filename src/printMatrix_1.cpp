#include <iostream>
#include <vector>

using namespace std;


vector<int> printMatrix(vector<vector<int>> matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();
    cout << "rows = " << rows << endl;
    cout << "cols = " << cols << endl;

    int stRow = 0;
    int stCol = 0;
    int edRow = rows - 1;
    int edCol = cols - 1;

    vector<int> result;

    while (stRow <= edRow && stCol <= edCol) {

        cout << "stRow = " << stRow << endl;
        cout << "stCol = " << stCol << endl;
        cout << "edRow = " << edRow << endl;
        cout << "edCol = " << edCol << endl;

        // 处理特殊情况
        // 只有一行
        if (stRow == edRow) {
            for (int j = stCol; j <= edCol; ++j) {
                cout << "matrix[stRow][j] = " << matrix[stRow][j] << endl;
                result.push_back(matrix[stRow][j]);
            }
        }
        // 只有一列
        else if (stCol == edCol) {
            for (int i = stRow; i <= edRow; ++i) {
                cout << "matrix[i][edCol] = " << matrix[i][edCol] << endl;
                result.push_back(matrix[i][edCol]);
            }
        }
        // 一般情况
        else {
            int curRow = stRow;
            int curCol = stCol;
            // 打印上面一行
            while (curCol <= edCol) {
                result.push_back(matrix[stRow][curCol]);
                cout << "matrix[stRow][curCol++] = " << matrix[stRow][curCol] << endl;
                curCol++;
            }
            curCol--;
            // 打印右面一行
            curRow++;
            while (curRow <= edRow) {
                result.push_back(matrix[curRow][edCol]);
                cout << "matrix[++curRow][edCol] = " << matrix[curRow][edCol] << endl;
                curRow++;
            }
            curRow--;
            // 打印下面一行
            cout << "curCol = " << curCol << endl;
            curCol--;
            cout << "curCol = " << curCol << endl;
            while (curCol >= stCol) {
                result.push_back(matrix[edRow][curCol]);
                cout << "matrix[edRow][--curCol] = " << matrix[edRow][curCol] << endl;
                curCol--;
            }
            curCol++;
            // 打印左面一行
            curRow--;
            while (curRow >= stRow + 1) {
                result.push_back(matrix[curRow][stCol]);
                cout << "matrix[--curRow][stCol] = " << matrix[curRow][stCol] << endl;
                curRow--;
            }
            curRow++;
        }

        stRow++;
        stCol++;
        edRow--;
        edCol--;
    }

    return result;

}


int main() {
  const int SIZE = 6;
  vector<vector<int>> matrix(SIZE, vector<int>(SIZE));
  vector<int> result;

  int k = 1;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      matrix[i][j] = k++;
    }
  }

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j){
      cout << matrix[i][j] << " " ;
    }
  }
  cout << endl;

  result = printMatrix(matrix);

  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << " ";
  }
  cout << endl;

  return 0;

}

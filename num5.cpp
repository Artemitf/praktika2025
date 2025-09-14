#include <iostream> //ok 
#include <vector>

int main() {
  int len_x, len_y = 0;
  std::cin >> len_x;
  std::cin >> len_y;

  std::vector<std::vector<int>> matrix(len_x, std::vector<int> (len_y));

  //создание матрицы
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      std::cin >> matrix[i][j];
    }
  }

  int x1, x2, y1, y2 = 0;

  //поиск левого верхнего края
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if (matrix[i][j] == 1) {
        x1 = i - 1;
        y1 = j - 1;
        break;
      }
    }
  }  

  //поиск правого нижнего края
  for (int i = 0; i < len_x; i++) {
    for (int j = 0; j < len_y; j++) {
      if (matrix[i][j] == 1 && matrix[i + 1][j] == 0 && matrix[i][j + 1] == 0) {
        x2 = i + 1;
        y2 = j + 1;
        break;
      }
    }
  }
  
  std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;

}

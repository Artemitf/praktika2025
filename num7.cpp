#include <iostream> //ок
#include <vector>
#include <algorithm>

int main() {

  std::string number;
  std::cin >> number;
  int count = 0;

  //проверяем правильность написания цифр
  for (int i = 0; i < 6; i++) {
    if (int(number[i]) > 47 && int(number[i] < 58)) {
      if (i > 0 && i < 4) {
        count++;
      }

    //проверяем правильность букв
    } else {
      if (i == 0 || i == 4 || i == 5) {
        count++;
      }
    }
  }

  if (count == 6) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}
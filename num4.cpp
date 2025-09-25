#include <iostream>  //ок
#include <string>

int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  
  int indexes[100]; //индексы перестановки
  for (int i = 0; i < n; i++) {
    std::cin >> indexes[i];
  }
  
  std::string word;
  std::cout << "Введите слово:\n";
  std::cin >> word;
  
  for (int step = 0; step < k; step++) {
    std::string word2 = word;
    //перстановка
    for (int i = 0; i < n; i++) {
      word2[indexes[i] - 1] = word[i];
    }
    // обновление слова для след. итерации
    word = word2;
  }
  
  std::cout << "Ответ: " << word << '\n';
  
  return 0;
}
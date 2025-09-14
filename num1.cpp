#include <iostream>   //ок
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    //рандомайзер
    std::srand(std::time(0));
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<int>> pyramid(n);

    //заполнение пирамиды
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            pyramid[i].push_back(std::rand() % 101);
        }
    }

    //вывод пирамиды
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << pyramid[i][j] << " ";
        }
        std::cout << "\n";
    }

    //создаем копию
    std::vector<std::vector<int>> dp = pyramid;

    // Заполнение матрицы dp с предпоследнего уровня (n-2) и до вершины
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += std::min(dp[i+1][j], dp[i+1][j+1]);
            // Для каждого элемента находим минимальный путь из двух возможных снизу
            // и добавляем значение текущего элемента
        }
    }

    //восстановление пути
    std::cout << "\nAnswer: " << dp[0][0] << "\n" << pyramid[0][0];

    int current = 0;
    for (int i = 1; i < n; i++) {
        if (dp[i-1][current] - pyramid[i-1][current] == dp[i][current]) {
            std::cout << " " << pyramid[i][current];
        } else {
            current++;
            std::cout << " " << pyramid[i][current];
        }
    }

    return 0;
}

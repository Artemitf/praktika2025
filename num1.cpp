#include <iostream>   //n1
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> pyramid(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            pyramid[i].push_back(std::rand() % 101);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << pyramid[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::vector<std::vector<int>> dp = pyramid;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] += std::min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    std::cout << "\nAnswer: " << dp[0][0] << "\n" << pyramid[0][0];

    int current = 0;
    for (int i = 1; i < N; i++) {
        if (dp[i-1][current] - pyramid[i-1][current] == dp[i][current]) {
            std::cout << " " << pyramid[i][current];
        } else {
            current++;
            std::cout << " " << pyramid[i][current];
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    int n, k;
    std::cin >> n >> k;
    std::vector<int> streets(n + 1, 0);

    std::cout << "Events:\n";
    for (int i = 0; i < k; i++) {
        int type = std::rand() % 2 + 1;
        int a = std::rand() % n + 1;
        int b = std::rand() % n + 1;

        if (type == 1) {
            int x = std::rand() % 100 + 1;
            streets[a] += x;
            std::cout << "1 " << a << " " << x << "\n";
        } else {
            std::cout << "2 " << a << " " << b << "\n";
            int sum = 0;
            for (int j = a; j <= b; j++) {
                sum += streets[j];
            }
            std::cout << "Sum: " << sum << "\n";
        }
    }

    std::cout << "\nFinal snow amounts:\n";
    for (int i = 1; i <= n; i++) {
        std::cout << streets[i] << " ";
    }

    return 0;
}
#include <iostream>  //ок
#include <vector>

std::vector<int> parent;
//поиск корня вершины
int find(int x) {
    if (parent[x] == x) return x;
    return find(parent[x]);
}

//обьединение множеств с вершинами x, y
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) parent[y] = x;
}

int main() {
    int n, k = 0;
    std::cin >> n >> k;
    parent.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    //запись ребер
    for (int i = 0; i < k; i++) {
        int x, y = 0;
        std::cin >> x >> y;
        unite(x, y);
    }

    //считаем компоненты связности(если корень вершины - она сама)
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i) components++;
    }

    std::cout << components - 1 << "\n";

    return 0;
}
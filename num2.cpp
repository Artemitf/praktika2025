#include <iostream>   //n2
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<int> parent;

int find(int u) {
    if (parent[u] == u) return u;
    return find(parent[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
}

int main() {
    std::srand(std::time(0));
    int N, M;
    std::cin >> N >> M;
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    std::cout << "Connections:\n";
    for (int i = 0; i < M; i++) {
        int u = std::rand() % N + 1;
        int v = std::rand() % N + 1;
        std::cout << u << " - " << v << "\n";
        unite(u, v);
    }

    std::cout << "\nParents:\n";
    for (int i = 1; i <= N; i++) {
        std::cout << parent[i] << " ";
    }

    int components = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i) components++;
    }

    std::cout << "\n\nConnections needed: " << components - 1 << "\n";

    return 0;
}
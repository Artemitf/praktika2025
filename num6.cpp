#include <iostream> //ok
#include <vector>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> results;
    
  for (int i = 0; i < n; i++) {
    int a, b, x, y = 0;
    std::cin >> a >> b >> x >> y;
        
    //максимум рабочих пар
    int pairs = std::min(a + b, x + y);

    //убираем несовместимые модули
    int bad_b = std::max(0, b - x);
    int bad_y = std::max(0, y - a);

    pairs = std::min(pairs, a + b - bad_b);
    pairs = std::min(pairs, x + y - bad_y);
  }
    
  for (int i = 0; i < n; i++) {
    std::cout << results[i] << ' ';
  }
    
  return 0;
}
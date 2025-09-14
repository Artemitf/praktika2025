#include <iostream> //ок
#include <vector>

int main() {
    int n, k = 0;
    std::cin >> n >> k;
    
    //снег по улицам
    std::vector<int> streets(n + 1, 0);
    
    //обрабатываем запросы
    for (int i = 0; i < k; i++) {
        int type = 0;
        std::cin >> type;
        
        if (type == 1) {
            //добавление снега на улицу
            int str_id, snow = 0;
            std::cin >> str_id >> snow;
            streets[str_id] += snow;
            
        } else {
            //подсчет суммы снега на диапазоне улиц
            int first_str, second_str;
            std::cin >> first_str >> second_str;
            
            //сумма всего снега
            int total_snow = 0;
            for (int j = first_str; j <= second_str; j++) {
                total_snow += streets[j];
            }
            
            std::cout << total_snow << "\n";
        }
    }
    
    return 0;
}
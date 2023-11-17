#include <iostream>

int main() {
    int scores;

    std::cin >> scores;

    while (scores--) {
        int time;
        std::string half;
        std::cin >> time >> half;
        int overtime = 0;
        if (time > 45) {
            overtime = time - 45;
            time = 45;
        }
        if (half == "2T") {
            time += 45;
        }

        std::cout << time;
        if (overtime) {
            std::cout << "+" << overtime;
        }
        std::cout << std::endl;

    }
    
    return 0;
}

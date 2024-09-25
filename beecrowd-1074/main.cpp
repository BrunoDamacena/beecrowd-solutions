#include <iostream>
#include <vector>
 
int main() {
    int n;
    std::cin >> n;
    
    while (n--) {
        int x;
        std::cin >> x;

        if (x == 0) {
            std::cout << "NULL" << std::endl;
            continue;
        }
        if (x % 2 == 0) {
            std::cout << "EVEN ";
        }
        else {
            std::cout << "ODD ";
        }
        if (x > 0) {
            std::cout << "POSITIVE" << std::endl;
        }
        else {
            std::cout << "NEGATIVE" << std::endl;
        }
    }
    return 0;
}
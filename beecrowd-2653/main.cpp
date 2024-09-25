#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    std::string in;
    std::vector<std::string> jewels;
    while (std::cin >> in) {
        jewels.push_back(in);
    }
    
    std::sort(jewels.begin(), jewels.end());
    jewels.erase(std::unique(jewels.begin(), jewels.end()), jewels.end());
    std::cout << jewels.size() << std::endl;
    return 0;
}
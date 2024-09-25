#include <iostream>
#include <map>
#include <vector>

std::map<int, std::string> dtbmap = {
    {1, "*....."}, {2, "*.*..."}, {3, "**...."}, {4, "**.*.."}, {5, "*..*.."}, {6, "***..."}, {7, "****.."}, {8, "*.**.."}, {9, ".**..."}, {0, ".***.."}
};

std::string findBrailleFromDigit(int d) {
    return dtbmap.find(d)->second;
}

int findDigitFromBraille(std::string b) {
    for (auto it = dtbmap.begin(); it != dtbmap.end(); it++) {
        if (it->second == b) {
            return it->first;
        }
    }
    return -1;
}

void digitToBraille() {
    std::vector<std::string> lines(3, "");
    std::string in;
    std::cin >> in;
    for (char d : in) {
        int i = d - '0';
        std::string b = findBrailleFromDigit(i);
        lines[0] += b.substr(0,2) + " ";
        lines[1] += b.substr(2,2) + " ";
        lines[2] += b.substr(4,2) + " ";
    }
    for (std::string s : lines) {
        std::cout << s.substr(0, s.size() - 1) << std::endl;
    }
}

void brailleToDigit(int n) {
    std::vector<std::string> lines(4, "");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            std::string s;
            std::cin >> s;
            lines[i] += s;
        }
    }
    while (lines[0] != "") {
        std::string braille = lines[0].substr(0,2) + lines[1].substr(0,2) + lines[2].substr(0,2);
        lines[0].erase(0, 2);
        lines[1].erase(0, 2);
        lines[2].erase(0, 2);
        std::cout << findDigitFromBraille(braille);
    }
    std::cout << std::endl;
}
 
int main() {
    int n;
    std::cin >> n;
    while(n != 0) {
        char o;
        std::cin >> o;
        if (o == 'S') {
            digitToBraille();
        }
        else if (o == 'B') {
            brailleToDigit(n);
        }
        std::cin >> n;
    }
    return 0;
}
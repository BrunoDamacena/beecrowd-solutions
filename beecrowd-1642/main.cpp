#include <iostream>
#include <unordered_map>
#include <algorithm>

int longestSubstringLength(std::string str, int n) {
    std::unordered_map<char, int> count;
    int ans = 0;
    int start = 0;

    for (int end = 0; end < str.length(); end++) {
        char c = str[end];
        count[c]++;

        while (count.size() > n) {
            char left_char = str[start];
            count[left_char]--;
            if (count[left_char] == 0) {
                count.erase(left_char);
            }
            start++;
        }

        ans = std::max(ans, end - start + 1);
    }

    return ans;
}

int main() {
    int m;
    std::cin >> m;
    while (m != 0) {
        std::string input;
        std::cin.ignore();
        std::getline(std::cin, input);
        std::cout << longestSubstringLength(input, m) << std::endl;
        std::cin >> m;
    }
    return 0;
}
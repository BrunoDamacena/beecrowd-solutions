#include <iostream>
#include <cstdint>

int main() {
    std::string s;
    std::cin >> s;
    long long int out = 0;
    // the chosen number must be the remainder of the goal number divided by three
    // since a number is divisible by 3 if the sum of its digits is also divisible by 3
    // we can check the remainder of that number instead
    // or we could implement a method that does the division digit by digit, with carry over
    // but that seems more difficult :)
    for (int i = 0; i < s.size(); i++) {
        out += s[i] - '0';
    }
    std::cout << out%3 << std::endl;
    return 0;
}
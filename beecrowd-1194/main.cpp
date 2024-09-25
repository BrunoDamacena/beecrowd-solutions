#include <iostream>
#include <vector>

int find(std::vector<char>& v, int start, int end, char l) {
    for (int i = start; i <= end; i++) {
        if (v[i] == l) return i;
    }
    // just for the compiler
    return -1;
}

void findPos(std::vector<char>& pre, std::vector<char>& in, std::vector<char>& pos, int start, int curr, int end, int* curPos) {
    if (curr > end) return;
    int mid = find(in, curr, end, pre[start]);
    char c = pre[start];
    findPos(pre, in, pos, start + 1, curr, mid - 1, curPos); // left subtree
    findPos(pre, in, pos, start + mid - curr + 1, mid + 1, end, curPos); // rignt subtree
    pos[(*curPos)++] = c;
}


int main() {
    int c;
    std::cin >> c;
    while (c--) {
        int n;
        std::string s1, s2;
        std::cin >> n >> s1 >> s2;
        std::vector<char> pre(s1.begin(), s1.end()), in(s2.begin(), s2.end()), pos(n);

        int curPos = 0;

        findPos(pre, in, pos, 0, 0, n-1, &curPos);

        for (int i = 0; i < n; i++) {
            std::cout << pos[i];
        }
        std::cout << std::endl;
    }
    return 0;
}
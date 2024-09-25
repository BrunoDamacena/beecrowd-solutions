#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

#define MAX_SIZE 99999

int ballroom(int layers, int nOrM, bool horizontal, std::set<int>& planks, std::vector<int>& p, std::vector<int>& pAux) {
    int partial, current;
    int ans = 0;

    for (auto it = planks.rbegin(); layers && it != planks.rend(); ) {
        current = *it;
        partial = nOrM - current;

        // knowing if its trying to fit horizontally or vertically is important to know from which planks to consume
        if (horizontal) {
            if (p[current] <= 0 || partial < 0 || (partial == current ? (p[partial] - 1) <= 0 : p[partial] <= 0)) {
                it++;
                continue;
            }
        }
        else {
            if (pAux[current] <= 0 || partial < 0 || (partial == current ? (pAux[partial] - 1) <= 0 : pAux[partial] <= 0)) {
                it++;
                continue;
            }
        }

        // same here
        if (horizontal) {
            p[partial]--, p[current]--;
        } else {
            pAux[partial]--, pAux[current]--;
        }

        ans += partial ? 2 : 1;
        layers--;
    }

    if (layers) {
        return INT_MAX;
    }
    return ans;
}

int main() {
    int n, m;

    std::cin >> n >> m;

    while (n != 0 && m != 0) {
        // vectors to store quantity of p of length index
        std::vector<int> p(MAX_SIZE, 0);
        std::vector<int> pAux(MAX_SIZE, 0);
        std::set<int> planks;
        p[0] = pAux[0] = INT_MAX;
        int l, k;
        std::cin >> l >> k;

        for (int i = 0; i < k; i++) {
            int x;
            std::cin >> x;
            planks.insert(x);
            p[x]++, pAux[x]++;
        }

        int ans = INT_MAX;

        // if can be put on horizontal, try it
        if ((n * 100) % l == 0) {
            ans = ballroom((n * 100) / l, m, 1, planks, p, pAux);
        }

        // if can be put on vertical, try it and choose the min
        if ((m * 100) % l == 0) {
            ans = std::min(ans, ballroom((m * 100) / l, n, 0, planks, p, pAux));
        }

        if (ans >= INT_MAX || ans < 0) {
            std::cout << "impossivel" << std::endl;
        }
        else {
            std::cout << ans << std::endl;
        }

        std::cin >> n >> m;
    }

    return 0;
}

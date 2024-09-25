#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

std::pair<int, std::string> getTriesAndTime(std::string performance) {
    std::string triesStr = "";
    int i = 0;
    while(performance[i] != '/') {
        triesStr += performance[i];
        i++;
    }
    i++;
    int tries = std::stoi(triesStr);
    if (performance[i] == '-') {
        return {tries, "-"};
    }
    std::string timeStr = "";
    while (i < performance.length()) {
        timeStr += performance[i];
        i++;
    }
    return {tries, timeStr};
}

int main() {
    int t, p;
    int maxP = 11, penalty = 20;
    std::cin >> t >> p;
    while (t != 0 && p != 0) {
        std::vector<std::pair<int,int>> results(t);
        // group together everybody that solved p problems
        std::vector<std::vector<std::pair<int, int>>> solved(maxP);
        for (int i = 0; i < t; i++) {
            int a = 0, s = 0, problemsSolved = 0;
            for (int j = 0; j < p; j++) {
                std::string performance;
                std::cin >> performance;
                std::pair<int, std::string> result = getTriesAndTime(performance);

                if (result.second == "-") {
                    continue;
                }
                a += result.first - 1;
                s += stoi(result.second);
                problemsSolved++;
            }
            results[i] = {a, s};
            // this is a first degree equation! (that will be important)
            solved[problemsSolved].push_back({penalty * a + s, i});
        }

        int pLowerBound = 1, pUpperBound = INT_MAX;
        for (int i = 0; i < maxP; i++) {
            // nobody solved i problems
            if (solved[i].size() == 0) {
                continue; 
            }
            std::sort(solved[i].begin(), solved[i].end());
            for (int j = 0; j < solved[i].size() - 1; j++) {
                int teamA = solved[i][j].second;
                int teamB = solved[i][j + 1].second;

                // here well try to find the intersection of the two team ratings
                // by comparing the equations and try to find a common x
                // a1 * x + b1 = a2 * x + b2
                // if a1 = a2, the lines are parallel and no x exists
                // else x = (b2 - b1) / (a1 - a2)
                // with x we can find the lower and upper penalty bound that still keeps the equation valid

                int a1 = results[teamA].first;
                int b1 = results[teamA].second;
                int a2 = results[teamB].first;
                int b2 = results[teamB].second;

                if (a1 == a2) {
                    continue;
                }
                int num = b2 - b1;
                int den = a1 - a2;
                int x = num / den;

                // if x is greater or equal the current penalty, we update the upper bound that wont alter the order
                // if x is smaller then the current penalty, we update the lower bound
                if (x > penalty || (x == penalty && (num % den) != 0)) {
                    int offset = (num % den) == 0;
                    pUpperBound = std::min(pUpperBound, x - offset);
                }
                else if (x < penalty) {
                    pLowerBound = std::max(pLowerBound, x + 1);
                }
                else { // x == penalty
                    pLowerBound = penalty;
                    pUpperBound = penalty;
                }
            }
        }
        std::cout << pLowerBound << " ";
        if (pUpperBound != INT_MAX) {
            std::cout << pUpperBound;
        }
        else {
            std::cout << "*";
        }
        std::cout << std::endl;
        std::cin >> t >> p;
    }
}
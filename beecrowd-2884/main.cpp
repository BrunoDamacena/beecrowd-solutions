#include <iostream>
#include <vector>
#include <map>

bool isEverythingOff(std::vector<int>& lamps) {
    for (int i = 0; i < lamps.size(); i++) {
        if (lamps[i]) {
            return false;
        }
    }
    return true;
}

bool equals(std::vector<int>& lamps, std::vector<int>& initialState) {
    for (int i = 0; i < lamps.size(); i++) {
        if (lamps[i] != initialState[i]) {
            return false;
        }
    }

    return true;
}

int switchCount(std::vector<int>& lamps, std::map<int, std::vector<int>>& switches) {
    if (isEverythingOff(lamps)) {
        return 0;
    }

    int c = 0;
    int sw = 0;
    int looped = false;
    // reserve initial state to check for loops
    // if theres a loop, its impossible to use janitors strats
    std::vector<int> initialState = lamps;
    while(!(looped && equals(lamps, initialState))) {
        // toggle switch
        std::vector<int> lampsToToggle = switches[sw];
        for (int i = 0; i < lampsToToggle.size(); i++) {
            lamps[lampsToToggle[i]] = (lamps[lampsToToggle[i]] + 1) % 2;
        }
        c++;
        if (isEverythingOff(lamps)) {
            return c;
        }
        sw = sw + 1;
        if (sw == switches.size()) {
            sw = 0;
            looped = true;
        }
    }

    return -1;
}

int main() {
    int n, m, l;
    std::cin >> n >> m >> l;

    std::vector<int> lamps(m, 0);
    std::map<int, std::vector<int>> switches;
    for (int i = 0; i < l; i++) {
        int lPos;
        std::cin >> lPos;
        lamps[lPos - 1] = 1;
    }

    for (int i = 0; i < n; i++) {
        int lts;
        std::cin >> lts;
        std::vector<int> lampToSwitch(lts);
        for (int j = 0; j < lts; j++) {
            int lamp;
            std::cin >> lamp;
            lampToSwitch[j] = lamp - 1;
        }
        switches[i] = lampToSwitch;
    }

    std::cout << switchCount(lamps, switches) << std::endl;

    return 0;
}
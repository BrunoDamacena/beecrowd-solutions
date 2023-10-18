#include <iostream>
#include <queue>

int iterativeSolution(int soldiers, int step) {
    int soldiersList[soldiers];
    for (int i = 0; i < soldiers; i++) {
        soldiersList[i] = 1;
    }
    int i = 0, currentStep = 1;
    int soldiersAlive = soldiers;
    while (soldiersAlive > 1) {
        if (currentStep == step) {
            if (soldiersList[i] == 0) {
                i++;
                if (i == soldiers) {
                    i = 0;
                }
                continue;
            }
            // suicidio acontece
            soldiersList[i] = 0;
            soldiersAlive--;
            currentStep = 1;
        }
        else {
            if (soldiersList[i] == 1) {
                currentStep++;
            }
        }
        i++;
        if (i == soldiers) {
            i = 0;
        }
    }
    for (int i = 0; i < soldiers; i++) {
        if (soldiersList[i] == 1) {
            return i + 1;
        }
    }
    return -1; // invalid, should never hit
}

int queueSolution(int soldiers, int step) {
    std::queue<int> q;

    for (int i = 0; i < soldiers; i++) {
        q.push(i+1);
    }

    int lastPop = -1;

    // will remove all soldiers until one is remaining
    while (q.size() != 1) {
        // moves the soldiers from front to back
        for (int i = 1; i < step; i++) {
            int tmp = q.front();
            q.push(tmp);
            q.pop();
        }
        // suicide happens
        q.pop();
    }
    return lastPop;
}

// uses recursion to solve the problem, removing the soldiers and adjusting the positions accordingly
int recursiveSolution(int soldiers, int step) {
    // break condition, only one survivor
    if (soldiers == 1) {
        return 1;
    }
    // recursion, removes a soldier and adjust the position to consider the removal
    // adjust the solution to step - 1 because of the zero-indexing of the array
    // mod soldiers to get the actual position from 0 to soldiers - 1
    // finally, +1 to readjust because of the zero-indexing array
    return (recursiveSolution(soldiers - 1, step) + step - 1) % soldiers + 1;
}

// iterative version of the recursive solution
// its also the most space efficient solution
int mathSolution(int soldiers, int step) {
    int survivor = 0;
    for (int i = 0; i < soldiers; i++) {
        survivor = (survivor + step) % (i + 1);
    }
    return survivor + 1;
}


int main() {
    int cases;
    std::cin >> cases;
    for (int currentCase = 0; currentCase < cases; currentCase++) {
        int soldiers, step;
        std::cin >> soldiers >> step;
        std::cout << "Case " << currentCase + 1 << ": " << queueSolution(soldiers, step) << std::endl;
    }
    return 0;
}

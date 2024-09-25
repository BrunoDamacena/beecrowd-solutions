#include <iostream>
#include <stack>
#include <queue>

int main() {
    int n;
    while (std::cin >> n) {
        std::stack<int> stk;
        std::queue<int> q;
        std::priority_queue<int> pq;

        bool isStk = true, isQ = true, isPq = true;
        for (int i = 0; i < n; i++) {
            int cmd, x;
            std::cin >> cmd >> x;

            if (cmd == 1) {
                if (isStk) {
                    stk.push(x);
                }
                if (isQ) {
                    q.push(x);
                }
                if (isPq) {
                    pq.push(x);
                }
            } else { // cmd = 2
                if (isStk) {
                    if (stk.top() != x) {
                        isStk = false;
                    } else {
                        stk.pop();
                    }
                }

                if (isQ) {
                    if (q.front() != x) {
                        isQ = false;
                    } else {
                        q.pop();
                    }
                }

                if (isPq) {
                    if (pq.top() != x) {
                        isPq = false;
                    } else {
                        pq.pop();
                    }
                }
            }
        }
        if (!isStk && !isQ && !isPq) {
            std::cout << "impossible" << std::endl;
        } else if (isStk && !isQ && !isPq) {
            std::cout << "stack" << std::endl;
        } else if (!isStk && isQ && !isPq) {
            std::cout << "queue" << std::endl;
        } else if (!isStk && !isQ && isPq) {
            std::cout << "priority queue" << std::endl;
        } else {
            std::cout << "not sure" << std::endl;
        }
    }
    return 0;
}
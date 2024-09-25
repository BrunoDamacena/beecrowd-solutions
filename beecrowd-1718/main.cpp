#include <iostream>

int main() {
    int circ, olives;
    std::cin >> circ >> olives;

    int olivesPositions[olives];

    for (int i = 0; i < olives; i++) {
        std::cin >> olivesPositions[i];
    }

    for (int i = 0; i < olives; i++) {
        std::cout << "Azeitona " << i + 1 << " na posicao " << olivesPositions[i] << ", ";
    }

    std::cout << "Cu" << std::endl;
}

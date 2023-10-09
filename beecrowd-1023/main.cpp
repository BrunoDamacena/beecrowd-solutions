#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

struct Property {
    int residents;
    int consumption;

    Property(int r, int c) : residents(r), consumption(c) {};
    Property() : residents(0), consumption(0) {};

    double averageConsumption() const {
        return static_cast<double>(consumption)/residents;
    }

    bool operator<(const Property& other) const {
        return averageConsumption() < other.averageConsumption();
    }
};

int main() {
    int numberOfProperties;
    int instance = 1;
    std::cin >> numberOfProperties;
    while (numberOfProperties) {
        std::vector<Property> properties;
        for (int i = 0; i < numberOfProperties; i++) {
            int r, c;
            std::cin >> r >> c;
            properties.emplace_back(r, c);
        }

        std::sort(properties.begin(), properties.end());
        std::cout << "Cidade# "<< instance << ":" << std::endl;

        double totalConsumption = 0;
        int totalResidents = 0;
        std::map<int, int> averageConsumptionToResidents; 

        // Calculate and print the sorted properties
        for (const Property& prop : properties) {
            totalResidents += prop.residents;
            totalConsumption += prop.consumption;
            averageConsumptionToResidents[(int)prop.averageConsumption()] += prop.residents;
        }

        for (const auto& entry : averageConsumptionToResidents) {
            std::cout << entry.second << "-" << entry.first << " ";
        }
        std::cout << std::endl;

        double averageConsumption = std::floor(totalConsumption / totalResidents * 100) / 100;
        std::cout << "Consumo medio: "
                  << std::fixed << std::setprecision(2)
                  << averageConsumption << " m3."
                  << std::endl << std::endl;

        std::cin >> numberOfProperties;
        instance++;
    }
    return 0;
}

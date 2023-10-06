#include <iostream>
#include <iomanip>

int main() {
  int hour, minute;
  std::cout << std::setfill('0');
  while (std::cin >> hour >> minute) {
    std::cout << std::setw(2) << hour / 30 << ":" << std::setw(2) << minute / 6 << std::endl;
  }
  return 0;
}
#include <iostream>

int main() {
  int number;
  int pos = 0, neg = 0, odd = 0, even = 0;
  while (std::cin >> number) {
    if (number > 0) {
      pos++;
    }
    if (number < 0) {
      neg++;
    }
    if (number % 2) {
      odd++;
    }
    else {
      even++;
    }
  } 
  std::cout << even << " valor(es) par(es)" << std::endl;
  std::cout << odd << " valor(es) impar(es)" << std::endl;
  std::cout << pos << " valor(es) positivo(s)" << std::endl;
  std::cout << neg << " valor(es) negativo(s)" << std::endl;
  return 0;
}
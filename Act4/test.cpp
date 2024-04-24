#include <iostream>
#include <string>

int main () {
    std::string firstInput;
    std::string secondInput;

    std::cin >> firstInput;
    std::cin.ignore();
    std::getline(std::cin, secondInput);

    std::cout << firstInput << '\n' << secondInput << std::endl;

    return 0;
}
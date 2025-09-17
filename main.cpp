#include <iostream>
#include <cstdlib>

int main() {
    const std::string lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }

    return EXIT_SUCCESS;
}
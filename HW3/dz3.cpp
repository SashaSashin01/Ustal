#include <iostream>
#include <string>
#include <limits>


int main() {
    uint64_t sum = 0;
    const uint64_t STOP_NUMBER = 5312;

    std::cout << "Enter positive integers (enter 5312 to stop):\n";

    while (true) {
        std::string input;
        if (!(std::cin >> input)) { 
            std::cout << "\nEnd of input detected.\n";
            break;
        }

        try {
            size_t pos;
            unsigned long number = std::stoul(input, &pos, 10);

            if (pos != input.length() || number > std::numeric_limits<uint64_t>::max()) {
                throw std::invalid_argument("Invalid input");
            }

            if (number == STOP_NUMBER) {
                break;
            }
            if (number == 0) {
                std::cout << "Please enter a non-zero positive integer.\n";
                continue;
            }
            if (sum > std::numeric_limits<uint64_t>::max() - number) {
                std::cout << "Integer overflow detected! Please enter a smaller number.\n";
                continue;
            }

            sum += number;

        } catch (const std::exception& e) {
            std::cout << "Invalid input format\n";
            continue;
        }
    }

    std::cout << "The sum of the entered numbers: " << sum << "\n";
    return 0;
}

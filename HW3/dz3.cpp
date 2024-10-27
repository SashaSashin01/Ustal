#include <iostream>
#include <limits>
#include <cstdint>

int main() {
    uint32_t sum = 0;
    const uint32_t STOP_NUMBER = 5312;

    std::cout << "Enter positive integers (enter 5312 to stop):\n";

    while (true) {
        std::string input;
        std::cin >> input;

        try {
            size_t pos;
            unsigned long number = std::stoul(input, &pos, 10);

            if (pos != input.length() || number > std::numeric_limits<uint32_t>::max()) {
                throw std::invalid_argument("Invalid input");
            }

            if (number == STOP_NUMBER) {
                break;
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
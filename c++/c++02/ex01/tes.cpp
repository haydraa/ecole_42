#include <iostream>

#define FRACTIONAL_BITMASK (0b11111111)

int main() {
    int fractionalPart = 0b11001010;  // Binary representation of the fractional part

    // Apply the bitmask to extract the fractional part
    int extractedFractionalPart = fractionalPart & FRACTIONAL_BITMASK;

    std::cout << "Fractional part: " << extractedFractionalPart << std::endl;

    return 0;
}

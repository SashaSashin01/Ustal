#include <iostream>

int main() {
    
    int varInt1 = 2;
    int varInt2 = 20;

    char varChar1 = '@';  
    char varChar2 = 'z';  

    double varDouble1 = 3.000046579;
    double varDouble2 = 500.567000241;


    std::cout << "1. (int + int) " << "2 + 20 = " << varInt1 + varInt2 << std::endl;  
    std::cout << "2. (int + char) " << "2 + @ = " << varInt1 + varChar1 << std::endl;  
    std::cout << "3. (char + char) " << "@ + z = " << varChar1 + varChar2 << std::endl;  
    std::cout << "4. (char + double) " << "@ + 3.000046579 = " << varChar1 + varDouble1 << std::endl;  
    std::cout << "5. (double + double) " << "3.000046579 + 500.567000241 = " << varDouble1 + varDouble2 << std::endl;  
    std::cout << "6. (double + int) " << "500.567000241 + 20 = " << varDouble2 + varInt2 << std::endl;  

    return 0;
}

#include <iostream>

int factorial(const int& userNum)
{
    if(userNum == 1)
    {
        return 1;
    }
    else
    {
        return userNum * factorial(userNum - 1);
    }
}

int main()
{
    std::cout << "Let's use recursion to find the factorial of a number. Please enter a number.\n";

    int userNum{0};
    std::cin >> userNum;

    std::cout << userNum << "! is equal to " << factorial(userNum) << ".\n\n";

    return 0;
}

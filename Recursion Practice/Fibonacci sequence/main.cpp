#include <iostream>

int fib(const int& userNum)
{
    if(userNum == 0)
    {
        return 0;
    }
    else if (userNum == 1)
    {
        return 1;
    }
    else
    {
        return (fib(userNum - 1) + fib(userNum - 2));
    }

}


int main()
{
    std::cout << "Let's use the Fibonacci sequence by using recursion.\n"
              << "Please enter a number.\n";

    int userNum{0};
    std::cin >> userNum;


    std::cout << "The number you entered " << userNum << " equals to " << fib(userNum) << ".\n";

    return 0;
}

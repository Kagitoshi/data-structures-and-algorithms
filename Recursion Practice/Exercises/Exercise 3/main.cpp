#include <iostream>

//This is a function that returns Nth triangular number.
int triangularNumber(int userInput)
{
    if(userInput == 1)
    {
        return 1;
    }

    return userInput + triangularNumber(userInput - 1);
}


int main()
{
    std::cout << "Let's find the Nth number of a triangular number. Please tell me what N is equal to: \n";

    int userInput{};
    std::cin >> userInput;

    std::cout << "The " << userInput << " triangular number is: " << triangularNumber(userInput) << ".\n\n";
    return 0;
}

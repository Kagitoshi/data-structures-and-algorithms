#include <iostream>

std::string reversedString(std::string userInput)
{
    if(userInput.size() == 1)
    {
        return userInput;
    }
    else
    {
        return reversedString(userInput.substr(1, userInput.size())) + userInput.at(0);
    }
}


int main()
{
    std::cout << "Let's reverse a string using recursion. Please enter a string for us to reverse, with no spaces.\n";

    std::string userInput{};
    std::cin >> userInput;

    std::cout << "Your string         : " << userInput <<'\n';
    std::cout << "Your string reversed: " << reversedString(userInput) << "\n\n";

    return 0;
}


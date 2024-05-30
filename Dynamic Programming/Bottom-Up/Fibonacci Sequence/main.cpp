#include <iostream>


//Doing the Fibonacci Sequence function that uses a loop to return the nth
//number in the Fibonacci Sequence.
int fibonacci(int userInput)
{
    if ( userInput == 0)
    {
        return 0;
    }

    int a{0};
    int b{1};
    int temp{0};

    for(int i{1}; i < userInput; ++i)
    {
        temp = a;
        a = b;
        b = (temp + a);
    }
    return b;
}

int main()
{
    std::cout << "Let's use the bottom-up method to solve the Fibonacci Sequence.\n"
              << "Please enter a number and we will return the value of it from the Fibonacci Sequence: ";

    int userInput{0};
    std::cin >> userInput;

    std::cout << "After " << userInput <<" steps of the Fibonacci Sequence the function returned with the\n"
              << "value of " << fibonacci(userInput) << ".\n\n";

    return 0;
}

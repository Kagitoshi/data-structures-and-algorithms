#include <iostream>
#include <unordered_map>


//Doing the Fibonacci Sequence function using a hashmap to remember the answers from
//previously answered recursion calls to prevent too many calls from being made.
//The Key is the input and value is the value from two other answers from a called recursion.
int fibonacci(int userInput, std::unordered_map<int,int> answerTracker)
{
    if ( userInput == 0 || userInput == 1)
    {
        return userInput;
    }

    if(answerTracker.find(userInput) == answerTracker.end())
    {
        answerTracker[userInput] = (fibonacci(userInput - 2, answerTracker) +
                                    fibonacci(userInput - 1, answerTracker));
    }

    return answerTracker[userInput];
}

int main()
{
    std::cout << "Let's use a memoization to solve the Fibonacci Sequence.\n"
              << "Please enter a number and we will return the value of it from the Fibonacci Sequence: ";

    int userInput{0};
    std::cin >> userInput;

    std::unordered_map<int,int> answerTracker{};

    std::cout << "After " << userInput <<" steps of the Fibonacci Sequence the function returned with the\n"
              << "value of " << fibonacci(userInput, answerTracker) << ".\n\n";

    return 0;
}

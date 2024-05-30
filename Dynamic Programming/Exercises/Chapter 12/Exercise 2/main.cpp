#include <iostream>
#include <unordered_map>


//Using Memoization to get the Nth Golomb number.
int golomb(int userInput, std::unordered_map<int, int>& answerTracker)
{
    if( answerTracker.find(userInput) == answerTracker.end())
    {
        answerTracker[userInput] = (1 +
                golomb(userInput - golomb(golomb(userInput -1, answerTracker), answerTracker), answerTracker));
    }

    return answerTracker[userInput];
}

int main()
{
    std::cout << "Let's calculate the Nth number using the\n"
              << "\"Golomb Sequence\"! Please enter a number: ";

    int userInput{0};
    std::cin >> userInput;

    std::unordered_map<int, int> answerTracker{};
    answerTracker[1] = 1;


    std::cout << "\n\nThe Nth number is " << golomb(userInput, answerTracker) << ".\n\n";

    std::cout << "Let's print it out also!\n";

    for( int i {1}; i <= userInput; ++i)
    {
        std::cout << answerTracker[i] << ' ';
    }
    std::cout << "\n\n";

    return 0;
}

#include <iostream>

bool palindromeChecker(const std::string& usersWord)
{
    int leftIndex{0};
    int rightIndex{static_cast<int>(usersWord.size()) - 1};

    while(leftIndex < ((static_cast<int>(usersWord.size())) - 1) / 2)
    {
        if(usersWord[leftIndex] != usersWord[rightIndex])
        {
            return false;
        }
        else
        {
            leftIndex++;
            rightIndex--;
        }
    }
    return true;
}

int main()
{
    std::cout << "Please enter a word to check: ";

    std::string usersWord{};
    std::cin >> usersWord;

    bool stringCheck{palindromeChecker(usersWord)};

    if(stringCheck)
    {
        std::cout << "That word is a palindrome.\n";
    }
    else
    {
        std::cout << "That word is not a palindrome.\n";
    }

    return 0;
}

#include <iostream>
#include <string>

//This is a function the returns the index of the first occurrence of a chosen
// character from a given string.
int indexOfFirstChracterOccurance(std::string userString, char& userChar)
{
    if (userString.empty())
    {
        return 1;
    }
    else if(userString[0] == userChar)
    {
        return 0;
    }

    return 1 + indexOfFirstChracterOccurance(userString.erase(0,1), userChar);
}

int main()
{
    std::cout << "Let's use a function that accepts a string and returns the index of\n"
              << "the index of the first occurrence of a given character, using recursion.\n"
              << "Please enter a string and press the 'enter' key: ";

    std::string userString {};
    std::getline(std::cin, userString);

    std::cout << "Great, now please enter a character and press the 'enter' key: ";
    char userChar{};
    std::cin >> userChar;

    int foundIndex{indexOfFirstChracterOccurance(userString, userChar)};

    if (foundIndex > userString.size())
    {
        std::cout << "There was no '"<< userChar <<"' found in that string.\n\n";
    }
    else
    {
        std::cout << "The index of the first occurrence of the character '"<< userChar <<"' in the \n"
                  << "string \""<< userString <<"\" is " << foundIndex << ".\n\n";
    }

    return 0;
}

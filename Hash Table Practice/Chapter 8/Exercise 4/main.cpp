#include <iostream>
#include <unordered_map>

bool duplicateCharFinder(const std::string& word)
{
    std::unordered_map<char, bool> findDuplicateChar;

    for(char i : word)
    {
        if(findDuplicateChar[i])
        {
            std::cout << "The character '" << i << "' is the first character found \n"
                      <<"that is a duplicated in the word '" << word << "'.\n";
            return true;
        }
        else
        {
            findDuplicateChar[i] = true;
        }
    }

    return false;
}

int main()
{
    std::cout << "Let's print out the first duplicated letter from a word.\n\n";

    std::string word{"minimum"};

    if(duplicateCharFinder(word))
    {
        return 1;
    }
    else
    {
        std::cout << "The word '" << word << "' does not have any duplicate letters.\n";
    }

    return 0;
}

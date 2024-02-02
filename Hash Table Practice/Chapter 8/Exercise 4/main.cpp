#include <iostream>
#include <unordered_map>

bool nonDuplicateCharFinder(const std::string& word)
{
    std::unordered_map<char, int> findNonDuplicateChar;

    for(char i : word)
    {
            findNonDuplicateChar[i] += 1;
    }

    for(char i : word)
    {
        if(findNonDuplicateChar[i] == 1)
        {
            std::cout << "The character '" << i << "' is the first character found \n"
                      <<"that is a non-duplicate in the word '" << word << "'.\n";
            return true;
        }
        else
        {
            ;
        }
    }

    return false;
}

int main()
{
    std::cout << "Let's print out the first non-duplicated letter from a word.\n\n";

    std::string word{"minimum"};

    if(nonDuplicateCharFinder(word))
    {
        return 0;
    }
    else
    {
        std::cout << "The word '" << word << "' has all duplicate letters.\n";
        return 1;
    }
}

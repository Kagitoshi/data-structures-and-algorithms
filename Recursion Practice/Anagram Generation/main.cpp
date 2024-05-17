#include <iostream>
#include <string>
#include <vector>

std::vector <std::string> anagramGenerator(std::string userInput)
{
    if(userInput.size() == 1)
    {
        std::vector <std::string> lastChar{userInput};
        return lastChar;
    }

    std::vector <std::string> anagrams{};

    std::vector <std::string> substringAnagrams{anagramGenerator(userInput.substr(1, userInput.size()))};

    for(std::string& i : substringAnagrams)
    {
        for(int j{0}; j <= i.size() ; ++j)
        {
            std::string substringCopy{i};

            anagrams.push_back(substringCopy.insert(j, 1, userInput[0]));
        }
    }

    return anagrams;
}

int main()
{
    std::cout << "Let's make some anagrams using a string. Please enter a string and " << '\n'
              << "let's see all the anagrams we can make from it.\n";

    std::string userInput{};
    std::cin >> userInput;

    std::cout << "Here are all of the anagrams:\n";

    std::vector anagrams{anagramGenerator(userInput)};

    for(std::string& i : anagrams)
    {
        std::cout << i << '\n';
    }

    return 0;
}

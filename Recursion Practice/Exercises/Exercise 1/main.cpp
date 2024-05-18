#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int countCharsInVector(std::vector <std::string>& vectorOfStrings)
{
    if(vectorOfStrings.size() == 1)
    {
        int count{};
        for(char i : vectorOfStrings[0])
        {
            count++;
        }
        return count;
    }

    int charCount{};

    for(char i : vectorOfStrings[0] )
    {

        charCount++;

    }

    std::vector <std::string> copyOfVector(vectorOfStrings.size() - 1);
    std::copy(vectorOfStrings.begin()+1, vectorOfStrings.end(), copyOfVector.begin());

    return charCount + countCharsInVector(copyOfVector);
}

int main()
{
    std::cout << "Let's count how many characters there are in a vector with \n"
              << "elements filled with strings.\n\n";

    std::vector <std::string> vectorOfStrings{"ab", "c", "def", "ghij"};

    std::cout << "There are a total of " << countCharsInVector(vectorOfStrings) << " characters in all \n"
              << "of the elements in that vector.\n\n";

    return 0;
}

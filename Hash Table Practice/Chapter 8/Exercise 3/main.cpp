#include <iostream>
#include <unordered_map>

bool checkPangram(const std::string& maybePangram)
{
    std::unordered_map<char, bool> pangramMap;

    for(char i : maybePangram)
    {
        pangramMap[static_cast<char>(std::tolower(i))] = true;
    }

    for(char i{'a'}; i <= 'z'; ++i )
    {
        if(pangramMap[i])
        {
            ;
        }
        else
        {
            std::cout << "The character '" << i
                      << "' is missing from the sentence:\n" << maybePangram
                      << '\n';
            return false;
        }
    }

    return true;
}

int main()
{
    std::cout << "Let's check a string to see if it pangram or not.\n\n";

    std::string maybePangram{"The quick brown box jumps over the lazy dog"};

    if(checkPangram(maybePangram))
    {
        std::cout << "The following sentence is a pangram: \n"
                  << maybePangram << '\n';
        return 0;
    }
    else
    {
        ;
    }

    return 0;
}

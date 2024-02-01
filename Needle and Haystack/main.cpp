#include <iostream>

bool findTheNeedle(const std::string& haystack, const std::string& needle)
{
    int needleStartIndex{0};

    while(needleStartIndex <= ((haystack.size() -1)  - (needle.size() -1)))
    {
        if(needle[0] == haystack[needleStartIndex])
        {
            int needleOffset{0};

            while(needleOffset < needle.size())
            {
                if(needle[needleOffset] != haystack[needleStartIndex + needleOffset])
                {
                    break;
                }
                else
                {
                    if(needleOffset == needle.size() -1 )
                        return true;
                }
                ++needleOffset;
            }

        }
        ++needleStartIndex;
    }
    return false;
}

int main()
{
    std::cout << "Please tell me a word that would be the haystack: ";

    std::string haystack{};
    std::cin >> haystack;

    std::cout << "Please tell me the substring that would be the needle: ";

    std::string needle{};
    std::cin >> needle;

    if(haystack.size() < needle.size())
    {
        std::cout << "Either you mixed up the haystack and needle\n"
                  << "or the needle is bigger than the haystack.\n"
                  <<"Either way, that is a big needle, please try again.\n";
        return 1;
    }

    if (findTheNeedle(haystack, needle))
    {
        std::cout << "We found the needle : " << needle << '\n'
                  << "It was in the haystack: " << haystack << '\n';
        return 0;
    }
    else
    {
        std::cout << "We did not find the needle : " << needle << '\n'
                  << "It was not in the haystack: " << haystack << '\n';
        return 1;
    }

    return 0;
}

#include <iostream>
#include <unordered_map>
#include <vector>

bool findDuplicates(const std::vector<std::string>& vectorOfStrings)
{
     std::unordered_map<std::string, bool> duplicatorFinder;

     for(const std::string& i : vectorOfStrings)
     {
         if(duplicatorFinder[i])
         {
             std::cout << "A duplicate was found and it is " << i << '\n';
             return true;
         }
         else
         {
             duplicatorFinder[i] = true;
         }
     }

    return false;
}

int main()
{
    std::cout << "Let's see if the vector has duplicates.\n\n";

    std::vector<std::string> vectorOfStrings{"a", "b", "c", "d", "c", "e", "f"};

    if(findDuplicates(vectorOfStrings))
    {
        return 0;
    }
    else
    {
        std::cout << "No duplicates were found in the vector.\n";
        return 1;
    }
}

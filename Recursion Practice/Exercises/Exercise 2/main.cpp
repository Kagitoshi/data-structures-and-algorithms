#include <iostream>
#include <vector>

std::vector <int> evenOnlyFromVector(std::vector<int> vectorOfNumbers)
{
    if(vectorOfNumbers.size() == 1)
    {
        if((vectorOfNumbers[0] % 2) == 0)
        {
            return vectorOfNumbers;
        }
        else
        {
            return {};
        }
    }

    if((vectorOfNumbers[0] % 2) == 0)
    {
        std::vector<int> copyOfVector(vectorOfNumbers.size() - 1);
        std::copy(vectorOfNumbers.begin() + 1, vectorOfNumbers.end(), copyOfVector.begin());

        std::vector<int> evenNums{evenOnlyFromVector(copyOfVector)};
        evenNums.insert(evenNums.begin(), vectorOfNumbers[0]);

        return evenNums;
    }

    else
    {
        std::vector<int> copyOfVector(vectorOfNumbers.size() - 1);
        std::copy(vectorOfNumbers.begin() + 1, vectorOfNumbers.end(), copyOfVector.begin());

        std::vector <int> evenNums{evenOnlyFromVector(copyOfVector)};

        return evenNums;
    }
}


int main()
{
    std::cout << "Let's use recursion to accept a vector of numbers and return only the even numbers.\n\n";

    std::vector <int> vectorOfNumbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 20};

    std::cout << "Here are all of the even numbers from the array:\n";

    int count {};

    for (int i : evenOnlyFromVector(vectorOfNumbers))
    {
        std::cout << i << '\n';
        ++count;
    }

    std::cout << "There were " << count << " even numbers found in your vector.\n\n";

    return 0;
}

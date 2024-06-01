#include <iostream>
#include <vector>

int partition (int leftPointer, int rightPointer, std::vector<int>& vectorToSort)
{
    int pivotIndex{rightPointer};
    int pivot{vectorToSort[pivotIndex]};

    --rightPointer;

    while(true)
    {
        while(vectorToSort[leftPointer] < pivot)
        {
            ++leftPointer;
        }

        while(vectorToSort[rightPointer] > pivot)
        {
            --rightPointer;
        }

        if(leftPointer >= rightPointer)
        {
            break;
        }
        else
        {
            std::swap(vectorToSort[leftPointer], vectorToSort[rightPointer]);
        }

        ++leftPointer;
    }

    std::swap(vectorToSort[leftPointer], vectorToSort[pivotIndex]);

    return leftPointer;
}

//In this exercise we are using quick sort to sort the vector and then return the missing number.
void findTheMissingNumber(int leftIndex, int rightIndex, std::vector<int>& vectorToSearch)
{
    if((rightIndex - leftIndex) <= 0)
    {
        ;
    }
    else
    {
        int pivotIndex{partition(leftIndex, rightIndex, vectorToSearch)};

        findTheMissingNumber( leftIndex, pivotIndex - 1, vectorToSearch);

        findTheMissingNumber(pivotIndex + 1, rightIndex, vectorToSearch);
    }

}


int main()
{
    std::cout << "Let's use quick sort to find the missing number in an unsorted array.\n"
              << "Here is the current array. Now let's find that missing number:\n";

    std::vector<int> vectorOfNumbers{9, 3, 2, 5, 6, 7, 1, 0 , 4};

    for(int i : vectorOfNumbers)
    {
        std::cout << i << ' ';
    }

    if(vectorOfNumbers.size() == 1)
    {
        std::cout << "\n\nThere is only single element in that array and it is " << vectorOfNumbers[0]
                  << ".\nSo there is no missing number to look for.\n\n";
        return -1;
    }
    else if (vectorOfNumbers.empty())
    {
        std::cout << "\n\nReally... An empty array? Give me something to work with please.\n\n";
        return -2;
    }

    //Creating a scope here so the copied vector deletes itself when the vector goes out of scope.
    {
        std::vector<int> copyOfVector{vectorOfNumbers};

        findTheMissingNumber(0, (static_cast<int>(copyOfVector.size())- 1), copyOfVector);

        bool missingNumberFound{false};

        for(int i{0}; i < (copyOfVector.size()- 1); ++ i)
        {
            if ((copyOfVector[i] + 1) == copyOfVector[i + 1])
            {
                ;
            }
            else
            {
                std::cout << "\n\nThe missing number is: " << (copyOfVector[i] + 1) << "\n\n";
                missingNumberFound = true;
            }
        }

        if(!missingNumberFound)
        {
            std::cout << "\n\nNo number seems to be missing. Everything seems to be in order.\n\n";
        }
    }

    return 0;
}

#include <iostream>
#include <vector>

int partition(int leftPointer, int rightPointer, std::vector<int>& vectorToPartition)
{
    int pivotIndex{rightPointer};
    int pivot{vectorToPartition[pivotIndex]};

    --rightPointer;

    while(true)
    {
        while(vectorToPartition[leftPointer] < pivot)
        {
            ++leftPointer;
        }

        while(vectorToPartition[rightPointer] > pivot)
        {
            --rightPointer;
        }

        if(leftPointer >= rightPointer)
        {
            break;
        }
        else
        {
            std::swap(vectorToPartition[leftPointer], vectorToPartition[rightPointer]);
        }

        ++leftPointer;
    }

    std::swap(vectorToPartition[leftPointer], vectorToPartition[pivotIndex]);

    return leftPointer;
}


void sortAndPickTheLargest(int leftIndex, int rightIndex, std::vector<int>& vectorToSort)
{
    if((rightIndex - leftIndex) <= 0)
    {
        ;
    }
    else
    {
        int pivotIndex{partition(leftIndex, rightIndex, vectorToSort)};

        sortAndPickTheLargest(leftIndex, pivotIndex -1, vectorToSort);
        sortAndPickTheLargest(pivotIndex + 1, rightIndex, vectorToSort);
    }
}


int nestedLoop(const std::vector<int>& vectorToSearch)
{
    for(int i{0}; i < vectorToSearch.size(); ++i)
    {
        bool greatestNumber{true};

        for(int j {i + 1}; j < vectorToSearch.size(); ++j)
        {
            if(vectorToSearch[i] < vectorToSearch[j])
            {
                greatestNumber = false;
                break;
            }
            else
            {
                ;
            }
        }

        if(greatestNumber)
        {
            return vectorToSearch[i];
        }
    }
}

int constantTimeBigNumberFinder(const std::vector<int>& vectorToSearch)
{
    int largestNumber{vectorToSearch[0]};

    for(int i : vectorToSearch)
    {
        if(i > largestNumber)
        {
            largestNumber = i;
        }
    }

    return largestNumber;
}

int main()
{
    std::cout << "We are going to run 3 different functions that each will find\n"
              << "The greatest number in an unsorted array.Out unsorted array is as follows:\n";

    std::vector<int> vectorOfNumbers{9, 3, 2, 5, 6, 7, 1, 8, 0, 4};

    for(int i : vectorOfNumbers)
    {
        std::cout << i << ' ';
    }

    std::cout << "\n\nThe first function is O(N) squared.\n"
              << "This function is a nested loop. The inner loop compares its number with the\n"
              << "outer loop. If the number is greater. The inner loop breaks and other loop\n"
              << "increments by one and the inner loops tries again from the beginning.\n"
              << "If the other loop completes with no issue. The other loop returns the number.\n"
              << "\nThe answer of the greatest number found in the array is: "
              << nestedLoop(vectorOfNumbers);

    {
        std::vector<int> copyOfVector{vectorOfNumbers};

        std::cout << "\n\nThe second function is O(N log N). For this function we will sort then pull the last element.\n"
                  << "While it is easy in concept and to explain. It isn't quite so fast since the\n"
                  << "whole array needs to be sorted first. Of course since this chapter has been focused\n"
                  << "on how quick sort works. I will use their version of it instead of the built in one.\n"
                  << "And the answer should be the same as above as the greatest number in the array.\n\n";

        sortAndPickTheLargest(0, (static_cast<int>(copyOfVector.size()) - 1), copyOfVector);

        std::cout << "That number is: " <<  copyOfVector.back();
    }

    std::cout << "\n\nAnd our last function is O(N).\n"
              << "The function iterates through the array, keeping track of\n"
              << "the largest number and returns it when it finishes.\n"
              << "And the greatest number found should be same as the other\n"
              << "two which is " << constantTimeBigNumberFinder(vectorOfNumbers) << ".\n\n";

    return 0;
}

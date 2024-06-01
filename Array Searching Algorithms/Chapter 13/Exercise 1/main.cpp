#include <iostream>
#include <numeric> //std::multiplies
#include <vector>

int partition(int leftPointer, int rightPointer, std::vector<int>& vectorToSort)
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
            ++leftPointer;
        }
    }

    std::swap(vectorToSort[leftPointer], vectorToSort[pivotIndex]);

    return leftPointer;
}

//Using the partition function that is used when doing quick sort we are
//able to narrow down the 3 largest numbers and return the product of those numbers.
//The exercise does mention there is a fast algorithm. This is just for practice.
int productOf3LargestNums(int leftIndex, int rightIndex, std::vector<int>& vectorOfNums)
{
    if(static_cast<int>(vectorOfNums.size()) < 4)
    {
        int initialProduct{1};

        //First time using std::multiplies. The 3 argument is the initial value to multiply by.
        return std::accumulate(vectorOfNums.begin(), vectorOfNums.end(), initialProduct, std::multiplies<int>());
    }

    int pivotIndex{partition(leftIndex, rightIndex, vectorOfNums)};

    if(pivotIndex == (static_cast<int>(vectorOfNums.size()) - 4)
    || pivotIndex == (static_cast<int>(vectorOfNums.size()) - 3))
    {
        int initialProduct{1};

//The following added to ensure my answer was correct and double check some things. Please ignore it.
//        std::cout << "\n\nLast 3 numbers are: ";
//        int product{1};
//
//        for (int i{(static_cast<int>(vectorOfNums.size()) - 1)}; i > ((static_cast<int>(vectorOfNums.size()) - 4)); --i)
//        {
//            std::cout << vectorOfNums[i] << ' ';
//
//            product *= vectorOfNums[i];
//        }
//
//        std::cout << "\n\nThe sum should be " << product << ".\n\n";

        return std::accumulate(vectorOfNums.end() - 3, vectorOfNums.end(), initialProduct, std::multiplies<int>());
    }
    else if(pivotIndex < (static_cast<int>(vectorOfNums.size()) - 4))
    {
        return productOf3LargestNums(pivotIndex + 1, rightIndex, vectorOfNums);
    }
    else
    {
        return productOf3LargestNums(leftIndex, pivotIndex - 1, vectorOfNums);
    }
}

int main()
{
    std::cout << "Let's use quick sort to find the product of the 3 largest numbers from an unsorted array.\n\n";

    std::vector<int> vectorOfNumbers{8, 3, 6, 2, 1, 9, 10, 0, 11, 60, 2};

    std::cout << "The array of numbers are as follows: \n";

    for (int i: vectorOfNumbers)
    {
        std::cout << i << ' ';
    }

    {
        std::vector<int> copyOfVector{vectorOfNumbers};

        std::cout << "\n\nFrom that array the product from the 3 largest numbers is "
                  << productOf3LargestNums(0, (static_cast<int>(copyOfVector.size()) - 1), copyOfVector) << ".\n\n";
    }

    return 0;
}

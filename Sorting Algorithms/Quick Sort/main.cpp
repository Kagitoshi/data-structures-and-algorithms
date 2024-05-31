#include <iostream>
#include <vector>

//This exercise is to learn how to manually implement quicksort, although
//there is usually an embedded quick sort function. This is done to learn how it works.

//Takes in a left pointer and right pointer and sorts it.
int partitionAndSort(int leftPointer, int rightPointer, std::vector<int>& vectorToSort)
{
    int pivotIndex{rightPointer};
    int pivot{vectorToSort[pivotIndex]};

    rightPointer -= 1;

    while(true)
    {
        while(vectorToSort[leftPointer] < pivot)
        {
            leftPointer++;
        }

        while(vectorToSort[rightPointer] > pivot)
        {
            rightPointer--;
        }

        if(leftPointer >= rightPointer)
        {
            break;
        }
        else
        {
            std::swap(vectorToSort[leftPointer], vectorToSort[rightPointer]);
        }

        leftPointer++;
    }
    std::swap(vectorToSort[leftPointer], vectorToSort[pivotIndex]);

    return leftPointer;
}

//Quicksort function runs recursively until the vector is sorted.
void quickSort(int leftIndex, int rightIndex, std::vector<int>& vectorToSort)
{
    if((rightIndex - leftIndex) <= 0)
    {
        ;
    }
    else
    {
        int pivotIndex{partitionAndSort(leftIndex, rightIndex, vectorToSort)};

        //Quicksort whatever is left of the pivot.
        quickSort(leftIndex, pivotIndex - 1, vectorToSort);

        //Quicksort whatever is right of the pivot.
        quickSort(pivotIndex + 1, rightIndex, vectorToSort);
    }
}

int main()
{
    std::cout << "Let's use quick sort to sort a vector.\n";

    std::vector<int> unsortedVector{0, 5, 2, 1, 6, 3};

    std::cout << "This is what the vector looks like before sorting:\n";

    for(int i : unsortedVector)
    {
        std::cout << i << ' ';
    }

    std::cout<<"\n\nThis is what it looks like after sorting:\n";

    quickSort(0, static_cast<int>(unsortedVector.size()) - 1, unsortedVector);

    for(int i : unsortedVector)
    {
        std::cout << i << ' ';
    }

    std::cout << "\n\n";

    return 0;
}

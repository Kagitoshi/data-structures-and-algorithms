#include <iostream>
#include <vector>

//This exercise is to learn how to implement quickselect
//to quickly search for the second to lowest value in an array.

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
            ++leftPointer;
        }
    }

    return leftPointer;
}

int quickSelect(int kthLowestValue, int leftPointer, int rightPointer, std::vector<int>& vectorToSearch)
{
    if((rightPointer - leftPointer) <= 0)
    {
        return vectorToSearch[leftPointer];
    }
    
    int pivotIndex{partition(leftPointer, rightPointer, vectorToSearch)};
    
    if(kthLowestValue < pivotIndex)
    {
        return quickSelect(kthLowestValue, leftPointer, pivotIndex - 1, vectorToSearch);
    }
    else if(kthLowestValue > pivotIndex)
    {
        return quickSelect(kthLowestValue, pivotIndex + 1, rightPointer, vectorToSearch);
    }
    else
    {
        return vectorToSearch[pivotIndex];
    }
}

int main()
{
    std::cout << "Let's use quickselect to search for the second to lowest\n"
              << "value in an unsorted array.\n\n";
    
    std::vector<int> vectorOfNumbers{0, 50, 20, 10, 60, 30};
    
    std::cout << "The values in the array are as follows in the this order:\n";
    
    for(int i : vectorOfNumbers)
    {
        std::cout << i << ' ';
    }

    //Creating a scope so the copyOfVector variable will be deleted when out of scope.
    {
        //I need a vector to modify to pass in a reference for the quickselect functions but,
        //I do not want to modify the original. Since this is placed into a scope, it will delete itself after
        //it finishes the output below it.
        std::vector<int> copyOfVector{vectorOfNumbers};

        std::cout << "\n\nThe second to lowest value in that array is: "
                  << quickSelect(1, 0, static_cast<int>(vectorOfNumbers.size()) - 1, vectorOfNumbers) << ".\n\n";
    }
    
    return 0;
}

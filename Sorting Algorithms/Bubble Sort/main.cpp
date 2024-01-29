#include <array>
#include <iostream>

int main()
{
    //Create an unsorted array
    std::array<int, 7> arrayToSort{65, 55, 45, 35, 25, 15, 10};

    std::cout << "Array before sorting: ";

    for(int i:arrayToSort)
    {
        std::cout << i << ' ';
    }

    std::cout << "\n \n";

    std::cout << "Let's use bubble sort!\n\n";

    //Create a variable to keep track of which index the array has been unsorted till.
    //Which to begin with will be the last index of the array.
    int unsortedUntilIndex{arrayToSort.size() - 1};

    //A bool to see if we swapped integers.
    bool sorted{false};

    //A while loop that runs until the 'sorted' variable is set as true by the end of a loop.
    while(!sorted)
    {
        //Setting the 'sorted' array to true.
        sorted = true;

        //Iterate through the array until the last unsorted index.
        // The largest int will always bubble to the top each loop.
        for(int i{0}; i < unsortedUntilIndex; ++i)
        {
            //If the element on the left is greater than the element to the right, swap them and
            //change the 'sorted' variable to false.
            if(arrayToSort[i] > arrayToSort[i +1])
            {
                sorted = false;
                std::swap(arrayToSort[i], arrayToSort[i + 1]);
            }
        }

        if (!sorted)
        {
            std::cout << arrayToSort[unsortedUntilIndex] << " sorted to the top of the array to index "
                      << unsortedUntilIndex << ".\n";
        }
        //Since the last index has been sorted, we can reduce the amount of
        //iterations we need to loop through by 1.
        --unsortedUntilIndex;
    }


    std::cout << "\nArray after sorting: ";

    for(int i: arrayToSort)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';


    return 0;
}

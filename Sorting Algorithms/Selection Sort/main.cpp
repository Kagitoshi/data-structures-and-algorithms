#include <array>
#include <iostream>

int main() {
    //Create an unsorted array
    std::array<int, 7> arrayToSort{65, 55, 45, 35, 25, 15, 10};

    std::cout << "Array before sorting: ";

    for (int i: arrayToSort) {
        std::cout << i << ' ';
    }

    std::cout << "\n \n";

    std::cout << "Let's use selection sort!\n\n";


    for (int i{0}; i < arrayToSort.size() - 1; ++i)
    {
        //Sets the lowest number in the array as the first one we will check each loop.
        //Each loop the index increases
        int lowestNumberIndex{i};

        //An inner loop that compares the next number with the number in the lowest number index.
        //If arrayToSort[j] is lower than arrayToSort[lowestNumberIndex],
        // lowestNumberIndex is set to j.
        for(int j{i + 1}; j <= arrayToSort.size() - 1; ++j)
        {
            if(arrayToSort[j] < arrayToSort[lowestNumberIndex])
            {
                lowestNumberIndex = j;
            }
        }

        //If the lowestNumberIndex is not i then swap with i.
        if(lowestNumberIndex != i)
        {
            std::swap(arrayToSort[lowestNumberIndex], arrayToSort[i]);
        }
    }


    std::cout << "\nArray after sorting: ";

    for(int i: arrayToSort)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';


    return 0;
}

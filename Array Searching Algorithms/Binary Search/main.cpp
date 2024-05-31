#include <array>
#include <iostream>

int binarySearchFunction(std::array<int, 10> searchThis, int numToFind)
{
    //Setting the upper bounds of the array, which is the size of the array minus 1.
    int upperBounds{searchThis.size() - 1};
    //Setting the lower bounds of the array, which is of course 0.
    int lowerBounds{0};

    //Setting an int variable to see how many loops it takes to find a number.
    int loopsToFindNum{0};

    //A while loop that runs until the lower bounds is greater than the upper bounds.
    while(lowerBounds <= upperBounds)
    {
        int midpoint{(lowerBounds + upperBounds) /2};

        ++loopsToFindNum;

        //If the number you found is in this element the function will return to the main function.
        if(numToFind == searchThis[midpoint])
        {
            std::cout << "The number " << numToFind << " was found at index " << midpoint << " of the array.\n"
                      << "It took " << loopsToFindNum << " loops to find your number.\n";
            return 0;
        }

        //If the number you are trying to search for is greater than the number in this element,
        //it will set the midpoint plus 1 as the new lower bounds.
        else if (numToFind > searchThis[midpoint])
        {
            lowerBounds = midpoint + 1;
        }
            //If the number you are trying to search for is less than the number in this element,
            //it will set the midpoint minus 1 as the new upper bounds.
        else
        {
            upperBounds = midpoint - 1;
        }
    }

    std::cout << "I am sorry... We could not find your number.\n"
              << "It took " << loopsToFindNum << "to search the entire sorted array.\n";
    return 1;
}

int main()
{
    //Creating a basic sorted array.
    std::array<int, 10> searchThis {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //Creating an int variable to search for in the array.
    int numToFind {7};

    //Calling the Binary Search Function.
    binarySearchFunction(searchThis, numToFind);

    return 0;
}

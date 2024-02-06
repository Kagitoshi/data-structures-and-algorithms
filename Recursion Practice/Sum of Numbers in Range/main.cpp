#include <iostream>

int sumOfRangeOfNumbers(const int& low, const int& high)
{
    if(low == high)
    {
        return low;
    }
    else
    {
        return low + (sumOfRangeOfNumbers(low + 1, high) );
    }
}

int main()
{
    std::cout << "Let's use recursion to find the sum of all of the numbers within a range.\n\n";

    int low{1};
    int high{100};

    std::cout << "The low number is " << low << " and the high number is " << high << ".\n";
    std::cout << "The sum of the low and high numbers is: " << sumOfRangeOfNumbers(low, high) << ".\n\n";

    return 0;
}

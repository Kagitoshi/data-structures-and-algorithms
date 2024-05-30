#include <iostream>
#include <vector>

//In the book, I was given a function and was asked to fix it
//by removing any unnecessary recursion calls.
int countTo100(const std::vector<int>& nums)
{
    int sumTo100{0};

    for(int i {static_cast<int>(nums.size()) - 1}; i >= 0; -- i)
    {
        if(nums[i] + sumTo100 <= 100)
        {
            sumTo100+= nums[i];
        }
        else
        {
            ;
        }
    }

    return sumTo100;
}

//Here is the answer from the book. They used memoization.
//I think I was supposed to use memoization instead of a bottom-up solution.
int memoization(const std::vector<int>& nums)
{
    if(nums.size() == 0)
    {
        return 0;
    }

    std::vector<int> copyOfVector(nums.size() - 1);
    std::copy(nums.begin() + 1, nums.end(), copyOfVector.begin());

    int sumOfRemainingNumbers {memoization((copyOfVector))};
    if(nums[0] + sumOfRemainingNumbers > 100)
    {
        return sumOfRemainingNumbers;
    }
    else
        return nums[0] + sumOfRemainingNumbers;
}

int main()
{
    std::cout << "Let's add up some numbers in the array without going over 100\n\n";

    std::vector<int> nums{0, 2, 4, 50, 30, 22, 199, 99, 1, 2, 4, 14};

    std::cout << "We were able to get a sum of " << countTo100(nums) << " without going over.\n\n";

    std::cout <<"That was using our solution, the solution from the book comes\n"
              <<"returns with a sum of " << memoization(nums) << ".\n\n";

    return 0;
}

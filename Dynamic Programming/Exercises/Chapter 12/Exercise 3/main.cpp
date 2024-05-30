#include <iostream>
#include <unordered_map>

//To use pairs inside the unordered map I need to implement a hash
//and include that when I create the pair inside the map.
struct PairHasher
{
    template <class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const
    {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

//The exercise gives a solution. I am told to improve it with memoization.
//I will do that by using an unordered map.
int uniquePaths(int userColumns, int userRows, std::unordered_map<std::pair<int,int>, int, PairHasher> answerTracker)
{

    if(userColumns == 1 || userRows == 1 )
    {
        return 1;
    }

    std::pair<int, int> pairToFind{userRows, userColumns};

    if(answerTracker.find(pairToFind) == answerTracker.end())
    {
        answerTracker[pairToFind] = uniquePaths((userColumns - 1), (userRows), answerTracker) +
                                    uniquePaths((userColumns), (userRows - 1), answerTracker);
    }


    return answerTracker[pairToFind];
}

int main()
{
    std::cout << "Let's use recursion to find all the unique shortest paths\n"
              << " in a grid of rows and columns!\n\n"
              << "We will use memoization to help improve the efficiency from the last solution.\n"
              << "Please enter the number of columns there are: ";

    int userColumns{};
    std::cin >> userColumns;

    std::cout << "Now, please enter the number of rows there are: ";

    int userRows{};
    std::cin >> userRows;

    std::unordered_map<std::pair<int,int>, int, PairHasher> answerTracker{};

    std::cout << "There are " << uniquePaths(userColumns, userRows, answerTracker)  << " unique shortest paths found\n"
              << "in a grid that starts from 0,0 going to " << (userColumns - 1)  << ',' << (userRows - 1) << ".\n\n";

    return 0;
}
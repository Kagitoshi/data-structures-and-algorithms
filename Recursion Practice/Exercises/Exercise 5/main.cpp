#include <iostream>

//Using recursion to find all the shortest unique paths in a grid.
int uniquePaths(int userColumns, int userRows)
{
    if(userColumns == 1 || userRows == 1 )
    {
        return 1;
    }

    return uniquePaths((userColumns - 1), (userRows)) + uniquePaths((userColumns), (userRows - 1));
}

int main()
{
    std::cout << "Let's use recursion to find all the unique shortest paths\n"
              << " in a grid of rows and columns!\n\n"
              << "Please enter the number of columns there are: ";

    int userColumns{};
    std::cin >> userColumns;

    std::cout << "Now, please enter the number of rows there are: ";

    int userRows{};
    std::cin >> userRows;

    std::cout << "There are " << uniquePaths(userColumns, userRows)  << " unique shortest paths found\n"
              << "in a grid that starts from 0,0 going to " << (userColumns - 1)  << ',' << (userRows - 1) << ".\n\n";

    return 0;
}

#include <iostream>

int numberOfPaths(const int& userStairs)
{
    if ( userStairs < 0)
        return 0;

    else if( userStairs == 1 || userStairs == 0)
        return 1;

    else
    return (numberOfPaths(userStairs - 1) + numberOfPaths(userStairs - 2) +
    numberOfPaths(userStairs - 3));

}


int main()
{
    std::cout << "Let's find out how many paths there are to climb the stairs depending\n"
              << "on how many steps there are. We climb the stairs, 1, 2, or 3 steps at a time.\n"
              << "\nSo, how many steps are the stairs?";

    int userStairs{};
    std::cin >> userStairs;

    std::cout << "\n\nThere are " << numberOfPaths(userStairs) << " different paths to climb those stairs.\n\n";

    return 0;
}

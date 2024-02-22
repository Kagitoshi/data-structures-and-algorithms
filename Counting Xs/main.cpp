#include <iostream>

int counting(const std::string& userString)
{
    if (userString.size() == 0)
    {
        return 0;
    }
    if(userString[0] == 'x')
    {
        return 1 + counting(userString.substr(1, userString.size() - 1));
    }
    else
    {
        return counting(userString.substr(1, userString.size() - 1));
    }
}


int main()
{
    std::cout << "Using Recursion, let's count how many x's are in a string.\n\n";

    std::string userString{"axbxcxd"};

    std::cout << "In the string " << userString << " there are " << counting(userString) << " x's.\n\n";

    return 0;
}

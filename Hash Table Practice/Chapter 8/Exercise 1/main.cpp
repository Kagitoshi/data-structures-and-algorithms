#include <iostream>
#include <unordered_map> // allow usage of unordered_map(hash table)
#include <vector>

std::vector<int> findIntersections(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    std::vector<int> largerVector{};
    std::vector<int> smallerVector{};

    if(vector1.size() >= vector2.size())
    {
        largerVector = vector1;
        smallerVector = vector2;
    }
    else
    {
        largerVector = vector2;
        smallerVector = vector1;
    }

    //Initialize the hash table as empty
    //In the <> The type of the key goes first, then the type of the value.
    std::unordered_map<int, bool> mapForLargestVector{};

    //Iterated through the vector adding each vector's value as the key
    //and setting each value as true.
    for(int i : largerVector)
    {
        mapForLargestVector[i] = true;
    }

    std::vector<int> intersections{};

    //The other vector checks it's value to see if it matches with the
    // hash table's key. If it matches, it returns with a true value and
    //adds it another vector that will be returned.
    for(int i : smallerVector)
    {
        if(mapForLargestVector[i])
        {
            intersections.push_back(i);
        }
        else;
    }

    return intersections;
}



int main()
{
    std::cout << "Using a hash table, let's get the intersection of two tables.\n\n";

    std::vector<int> vector1{1,2,3,4,5};
    std::vector<int> vector2{0,2,4,6,8};

    std::vector<int> intersections{findIntersections(vector1, vector2)};

    if(static_cast<int>(intersections.size()) > 0)
    {
        std::cout << "We found the following intersections: ";

        for(int i : intersections)
        {
            std::cout << i << ' ';
        }

        std::cout << '\n';
    }
    else
    {
        std::cout << "No intersections were found.\n";
    }

    return 0;
}

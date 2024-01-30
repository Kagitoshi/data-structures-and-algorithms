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

    std::cout << "Let's use insertion sort!\n\n";


    for(int i{1}; i < arrayToSort.size(); ++i)
    {
        int temp{arrayToSort[i]};

        int position{i - 1};

        while(position >= 0)
        {
            if(arrayToSort[position] > temp)
            {
                arrayToSort[position + 1] = arrayToSort[position];
                --position;
            }
            else
            {
                break;
            }
        }

        arrayToSort[position + 1] = temp;
    }

    std::cout << "Array after sorting: ";

    for(int i: arrayToSort)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';


    return 0;
}

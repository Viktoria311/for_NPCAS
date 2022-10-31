#include "cdarray.h"
#include "funcs.h"
#include <iostream>
#include <random>


int main()
{
    CDArray<int> my_arr(700);

    int min, max;

    std::cout << "Enter a range of values:" << std::endl;
    std::cout << "Enter a min: ";
    if (!(std::cin >> min))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again to enter a min: ";
    }
    std::cout << "Enter a max: ";
    if (!(std::cin >> max))
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Try again to enter a max: ";
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);

    for(int i = 0; i < my_arr.Size(); ++i)
    {
        my_arr[i] = dist6(rng);
    }

    std::cout << std::endl;
    for(int i = 0; i < my_arr.Size(); ++i)
    {
        std::cout << my_arr[i] << ' ';
    }
    std::cout << std::endl;

    // sorting
    int helping_arr[max + 1] = {0};

    for(int i = 0; i < my_arr.Size(); ++i)
    {
        helping_arr[my_arr[i]] += 1;
    }

    for(int i = 0, j = 0; i < sizeof(helping_arr) / sizeof(helping_arr[0]); ++i)
    {
        if (helping_arr[i] != 0)
        {
            for(int k = 1; k <= helping_arr[i]; ++k)
            {
                my_arr[j] = i;
                ++j;
            }
        }
    }

    std::cout << "sorted CDArray: "<< std::endl;
    for(int i = 0; i < my_arr.Size(); ++i)
    {
        std::cout << my_arr[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "expectation: " << expectation(my_arr.Ptr(),my_arr.Size()) << std::endl;
    std::cout << "deviation: " << deviation(my_arr.Ptr(),my_arr.Size()) << std::endl;


    return 0;
}

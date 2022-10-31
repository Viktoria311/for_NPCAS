#include <cmath>

double expectation(int * arr, int size) // the arithmetic mean of the CDArray
{
    double sum = 0;

    for(int i = 0; i < size; ++i)
    {
        sum += *(arr + i);
    }

    return sum / size;
}

double variance(int * arr, int size)
{
    double sum = 0;
    double mean = expectation(arr, size);

    for(int i = 0; i < size; ++i)
    {
        sum += (*(arr + i) - mean) * (*(arr + i) - mean);
    }

    return sum / size;
}

double deviation(int * arr, int size) // Среднеквадратическое отклонение СКО
{
    return std::sqrt(variance(arr, size));
}

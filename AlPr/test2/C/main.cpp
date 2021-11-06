#include <iostream>

using namespace std;

int main()
{
    int* my_array;
    int M;
    int N;
    std::cout << "Input M = ";
    std::cin >> M;
    std::cout << "Input N = ";
    std::cin >> N;

    int size;
    size = (int)((M - N) / 2) + 1;
    my_array = new int[size];

    int i = 0;
    for (int k=N; k<=M; k++) {
        if (k%2 == 0) {
            my_array[i] = k;
            i++;
        }
    }

    for (int x = 1; x<=M; x++) {
        for (int f = 0; f < size; f++) {
            if(my_array[f] == x*x) {
                        std::copy(my_array + f + 1,
                                  my_array + size,
                                  my_array + f);
                        size--;
                    }
        }
    }


    for (int k=0; k<size; k++)
        std::cout << my_array[k] << std::endl;

    delete[] my_array;
    return 0;
}

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>

int main()
{


    ///////////////////////// Read integers from a single line
    std::string s;
    std::getline( std::cin, s );
    std::istringstream is( s );
    std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );
    /////////////////////////////////////////////////////////////////////////////////////////

    ////fill array with previously input values. i - counts the array elements
    int i = 0;
    int masivs[10000];
    for (int x : v)  {
            masivs[i] = x;
            i++;
    }
    ///////////////////////////////////////////////////////////////////////////

    ////////////////// Find maximum value and it's index in array
    int maxValue = masivs[0];
    int maxIndex = 0;
    for (int j = 0; j < i; j++ ) {
        if (masivs[j] > maxValue) {
            maxValue = masivs[j];
            maxIndex = j;
        }
    }
    ////////////////////////////////////////////////////////////////


    //////////////// Swaps the last element with previously found maxValue
    int tempValue = masivs[i - 1];
    masivs[i - 1] = maxValue;
    masivs[maxIndex] = tempValue;
    /////////////////////////////////////////////////////////////

    ////////// Output result
    for (int j = 0; j < i; j++ ) {
        std::cout << masivs[j] << " ";
    }
    std::cout << std::endl;
    ///////////////////////////


    return 0;
}

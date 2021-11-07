/***************

Anda Sulca, as21271

C4: Given sequence of distinct integers a(1), a(2),  , a(n). Swap the biggest element for last element.

***************/


#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip>      // std::setw

int main()
{

    bool repeat = true;
    char repeatChar[2];
    bool validInput = false;

    while(repeat) {
        ///////////////////////// Read integers from a single line
        std::string s;
        std::getline( std::cin, s );
        std::istringstream is( s );
        std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );
        ///////////////////////////////////////////////////////////////////////////


        ////fill array with previously input values. i - counts the array elements
        int i = 0;
        int masivs[10000];
        for (int x : v)  {
            masivs[i] = x;
            i++;
        }
        ///////////////////////////////////////////////////////////////////////////

        ///////////////////////// Find maximum value and it's index in array
        int maxValue = masivs[0];
        int maxIndex = 0;
        for (int j = 0; j < i; j++ ) {
            if (masivs[j] > maxValue) {
                maxValue = masivs[j];
                maxIndex = j;
            }
        }
        ///////////////////////////////////////////////////////////////////////////


        ///////////////////////// Swaps the last element with previously found maxValue
        int tempValue = masivs[i - 1];
        masivs[i - 1] = maxValue;
        masivs[maxIndex] = tempValue;
        ///////////////////////////////////////////////////////////////////////////

        ///////////////////////// Output result
        for (int j = 0; j < i; j++ ) {
            std::cout << masivs[j] << " ";
        }
        std::cout << std::endl;
        ///////////////////////////////////////////////////////////////////////////
}

        std::cout << std::endl << "Enter 1 to continue. Enter any other character to exit." << std::endl;
        std::cin >> std::setw(3) >> repeatChar;
        repeat = (std::string(repeatChar) == "1");
        std::cout << std::endl;

    return 0;
}

/************
 *
 * Input number | Desired response Result                                                                              | Actual response
 * -------------+------------------------------------------------------------------------------------------------------+----------------------------------
 * 0            |0                                                                   |
 * -888         |Error: Not a natural number entered                                                                   |
 * ABC          |Error: Invalid input detected                                                                         |
 * 2147483699   |Error: Invalid input detected                                                                         |
 * 1            |-                                                                                                     |
 * 11122233     |Repeating number: 1; Occurences:3;Repeating number: 2; Occurences:3;Repeating number: 3; Occurences:2;|
 * 2147483647   |Repeating number: 4; Occurences:3;Repeating number: 7; Occurences:2;                                  |
 * 100          |Repeating number: 0; Occurences:2;                                                                    |
 * 00001        |-                                                                                                     |
 * 10000        |Repeating number: 0; Occurences:4;                                                                    |
 * ***********/

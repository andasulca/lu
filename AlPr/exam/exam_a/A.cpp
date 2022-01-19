#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int sum2_index1;
    int sum2_index2;

    int sum3_index1;
    int sum3_index2;
    int sum3_index3;

    int sum2;
    int sum3;

        std::cout << "Enter array elements (divided with spaces): " << std::endl;
        ///////////////////////// Read integers from a single line
        std::string s;
        std::getline( std::cin, s );
        std::istringstream is( s );
        std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );
        ///////////////////////////////////////////////////////////////////////////

        ////fill array with previously input values. i - counts the array elements
        int i = 0;
        int masivs1[10000];
        for (int x : v)  {
            masivs1[i] = x;
            i++;
        }

        if (i < 3) {
            cout << "Size of the array too small." << endl;
            return 0;
        }

        sum2 = masivs1[0] + masivs1[1];
        sum2_index1 = 0;
        sum2_index2 = 1;

        for (int n = 0; n < i - 1; n++)    {
            if (masivs1[n] + masivs1[n+1] > sum2) {
                sum2 = masivs1[n] + masivs1[n+1];
                sum2_index1 = n;
                sum2_index2 = n + 1;
            }
        }

        sum3 = masivs1[0] + masivs1[1] + masivs1[2];
        sum3_index1 = 0;
        sum3_index2 = 1;
        sum3_index3 = 2;

        for (int n = 0; n < i - 2; n++)    {
            if (masivs1[n] + masivs1[n+1] + masivs1[n+2]> sum3) {
                sum3 = masivs1[n] + masivs1[n+1] + masivs1[n+2];
                sum3_index1 = n;
                sum3_index2 = n + 1;
                sum3_index3 = n + 2;
            }
        }

        bool isTwoInThree = false;

        if ((sum2_index1 == sum3_index1 || sum2_index1 == sum3_index2 || sum2_index1 == sum3_index3) &&
            (sum2_index2 == sum3_index1 || sum2_index2 == sum3_index2 || sum2_index2 == sum3_index3)) {
                isTwoInThree = true;
            }

        cout << "Sums are " << sum2 << " and " << sum3 << ",";
        if (isTwoInThree) {
            cout << " and the two are part of the three." << endl;
        } else {
            cout << " and the two are not fully part of the three." << endl;
        }


    return 0;
}

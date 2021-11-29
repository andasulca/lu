#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
        int n;
        std::cin.clear();
        std::cin.sync();
        std::cout << "Enter natural n: " << std::endl;
        cin >> n;

        std::cin.clear();
        std::cin.sync();
        std::cout << "Enter first sequence: " << std::endl;
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

        std::cin.clear();
        std::cin.sync();
        std::cout << "Enter second sequence: " << std::endl;
        ///////////////////////////////////////////////////////////////////////////
        std::getline( std::cin, s );
        std::istringstream is2( s );
        std::vector<int> v2( ( std::istream_iterator<int>( is2 ) ), std::istream_iterator<int>() );
        ///////////////////////////////////////////////////////////////////////////

        ////fill array with previously input values. i - counts the array elements
        i = 0;
        int masivs2[10000];
        for (int x2 : v2)  {
            masivs2[i] = x2;
            i++;
        }
        bool match = true;
        for (int c = 0; c < n; c++) {
            for (int c2 = 0; c2 < n; c2 ++) {
                if (masivs1[c] == masivs2[c2]) {
                    masivs1[c] = -1;
                    masivs2[c2] = -1;
                    break;
                }
                if (c2 == n - 1) {
                    match = false;
                }
            }
            if(!match) break;
        }

        if (match)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    return 0;
}

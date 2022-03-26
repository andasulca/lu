/***************

Anda Šulca, as21271

G18. Create function to delete from list elements with value equal with element sequence number in list.

***************/

#include <algorithm>
#include <iostream>
#include <list>

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <vector>
#include <iomanip>      // std::setw

using namespace std;

int main()
{
    int action;
    repeatProgram:
    std::list<int> l;
    std::cin.clear();
    std::cin.sync();
    std::cout << "Enter numbers: " << std::endl;
    ///////////////////////// Read integers from a single line
    std::string s;
    std::getline( std::cin, s );
    std::istringstream is( s );
    std::vector<int> v( ( std::istream_iterator<int>( is ) ), std::istream_iterator<int>() );
    ///////////////////////////////////////////////////////////////////////////

    ////fill list with previously input values
    for (int x : v)  {
        l.push_back(x);
    }
    cout << endl;
    cout << "Initial values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    int counter = 1;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ) {
        if (*it == counter) {
            it = l.erase(it);
        } else {
            ++it;
        }
        counter++;
    }

    // Print out the list
    cout << "Resulting values:";
    for (int n : l) {
        std::cout << n << " ";
    }

    cout << endl << "Enter 0 to exit, 1 to repeat: ";
    cin >> action;
    if (action == 1) {
        goto repeatProgram;
    }
    else {
        return 0;
    }
    return 0;
}

/************
 *
 * Input                         | Desired response Result                            | Actual response
 * ------------------------------+----------------------------------------------------+----------------------------------
 * 1.                            |                                         |
 * 1 2 3 4 5
 *
 * 2.                            |2 1 5 4                                             |
 * 2 1 3 5 4
 *
 * 3.                            |                                        |
 * 1
 *
 * 4.                            |0 1                                                 |
 * 0 1
 *
 * 5.                            |-1 1 5                                              |
 * -1 1 3 5
 * ***********/

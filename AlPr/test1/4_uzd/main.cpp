#include <iostream>

using namespace std;

int main()
{
    int input;
    cin >> input;

    for (int z = 1; z < input; z++) {
       for (int j = 1; j <= z; j++) {
            if (z%j == 0) {
                //output results
                cout << "(" << z << ", " << j << ")";
                //formatting output
                if (!(z == input - 1 && j == input - 1)) {
                    cout << ", ";
                }
            }
        }
    }
    //formatting output
    if (input > 1) cout << "." << endl;
    else cout << "No pairs found" << endl;
    return 0;
}

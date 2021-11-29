#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned int)time(NULL));
    int results[6];
    int x;

    for (int j = 0; j < 6; j++) {
        roll_again:
            x=int(rand()%10)+1;
            for (int j2 = 0; j2 < j; j2++) {
                if (results[j2] == x)
                    goto roll_again;
            }
        results[j] = x;
    }

    for (int i = 0; i < 6; i++)
        cout << results[i] << endl;
    return 0;
}

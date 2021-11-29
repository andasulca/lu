#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int results[30][15];
    int counter[30][15];
    int x;
    for (int j = 0; j < 30; j++) {
        for (int j2 = 0; j2 < 15; j2++) {
            results[j][j2] = 0;
            counter[j][j2] = 0;
        }
    }
    int student = -1;
    int course = -1;
    int grade = -1;

    do {
        cin >> student >> course >> grade;
        if (student == 0 && course == 0 && grade == 0)
            break;
            results[student - 1][course - 1] = results[student - 1][course - 1] + grade;
            counter[student - 1][course - 1] = counter[student - 1][course - 1] + 1;
    } while (true);



    double outputGrade;
    for (int j = 0; j < 30; j++) {
            cout << j + 1 << ". student ";
        for (int j2 = 0; j2 < 15; j2++) {
            if (results[j][j2] == 0)
                cout << j2 + 1 << ". course n" << endl;
            else {
                cout << std::setprecision(7) << j2 + 1 << ". course " << (double)results[j][j2]/counter[j][j2] << endl;
            }
        }
    }
    return 0;
}

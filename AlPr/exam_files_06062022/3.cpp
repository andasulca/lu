#include <algorithm>
#include <iostream>
#include <list>
#include <map>

using namespace std;

int removeMostFrequentNumbers (list<int> &l) {
    std::map<int,int> m;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ) {
            if (m.find(*it) == m.end()) {
              m[*it] = 1;
            } else {
              m[*it]++;
            }
            ++it;
    }
    int currentMax = 0;
    int arg_max = 0;
    for(auto it = m.cbegin(); it != m.cend(); ++it) {
        if (it ->second > currentMax) {
            arg_max = it->first;
            currentMax = it->second;
        }
    }

    int distinctCounter = 0;
    for(auto it = m.cbegin(); it != m.cend(); ++it ) {
        if (it ->second == currentMax) {
                l.remove(it->first);
                distinctCounter++;
        }
    }
    return distinctCounter;
}

int main()
{
    std::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);
    l.push_back(5);
    l.push_back(4);
    l.push_back(3);
    l.push_back(2);

    cout << "Initial values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    int distinctNumbers = removeMostFrequentNumbers(l);

    cout << "Result values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    cout << "distinct numbers deleted:" << distinctNumbers<< endl;
    return 0;
}

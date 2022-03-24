#include <iostream>
#include <list>

using namespace std;

struct elem {int num; elem *next;};

void deleteSecond2xNotEqual(elem *node) {
    elem *prev;
    elem *current;
    elem *first;
    elem *scnd;
    elem *prevPrevToLast;
    elem *prevToLast;
    elem *last;

    if (node->next == NULL) return;
    first = node;
    scnd = node->next;
    prevToLast = node;
    prevPrevToLast = NULL;
    current = node->next;
    while (current->next != NULL) {
        prevPrevToLast = prevToLast;
        prevToLast = current;
        current = current->next;
    }
    last = current;
    if (scnd->num != prevToLast->num) {
        first->next = scnd->next;
        delete scnd;
        if (prevPrevToLast != NULL) {
            prevPrevToLast->next = last;
        }
        delete prevToLast;
    }
}

void deleteSecond2xNotEqual(std::list<int> l) {

    int scnd;
    int prevToLast;
    int scndIndex;
    int prevToLastIndex;

    if(l.size() <= 1) return;

    int counter = 1;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ) {
        if (*it == 1) {
            scnd = *it;
            scndIndex = counter;
        }
        if (*it == l.size() - 1) {
            prevToLast = *it;
            prevToLastIndex = counter;
        }
        ++it;
        counter++;
    }

    if (scnd != prevToLast)  {
        int counter = 1;
        for (std::list<int>::iterator it = l.begin(); it != l.end(); ) {
            if (*it == scndIndex) {
                it = l.erase(it);
            } else if (*it == prevToLastIndex) {
                it = l.erase(it);
            } else {
                ++it;
            }
            counter++;
        }
    }
}

int main()
{
    int arr[] = {3,5,2};
    //linkedList *list = new linkedList();
    elem *first = new elem();
    first->num = arr[0];

    elem *current = first;
    for(int i = 1; i < sizeof(arr)/sizeof(int); i++) {
        elem *newNode = new elem();
        newNode->num = arr[i];
        current->next = newNode;
        current = newNode;
    };

    current = first;
        do {
            cout << current->num << " ";
            current = current->next;
        } while(current != NULL);
    cout << endl;

    deleteSecond2xNotEqual(first);

    current = first;
    if (current != NULL) {
        do {
            cout << current->num << " ";
            current = current->next;
        } while(current != NULL);
    cout << endl;
    }





    std::list<int> l = { 0, 9, 4, 89, 5 };

    cout << endl;
    cout << "Initial values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    deleteSecond2xNotEqualXXX(l);

    // Print out the list
    cout << "Resulting values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;



    cout << "Hello world!" << endl;
    return 0;
}

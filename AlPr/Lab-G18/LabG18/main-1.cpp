/***************

Anda Šulca, as21271

G18. Create function to delete from list elements with value equal with element sequence number in list.

***************/

#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

struct node {
    int value;
    node *next;
    node *prev;
    node(int value) {
        this->value = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct linkedList {
    node *first;
    node *last;
    node *current;
    int count;
    linkedList() {
        this->first = NULL;
        this->last = NULL;
        this->current = NULL;
        this->count = 0;
    }
    void push(int value) {
        if (this->first == NULL) {
            this->first = new node(value);
            this->last = this->first;
        } else {
            node* newNode = new node(value);
            newNode->prev = this->last;
            this->last->next = newNode;
            this->last = newNode;
        }
        this->count = this->count + 1;
    };

    void removeCurrent() {
        if (this->current == NULL || this->count == 0) {
            return;
        }
        if (this->count == 1) {
            delete this->current;
            this->count = 0;
            this->first = NULL;
            this->last = NULL;
            this->current = NULL;
        }
        if (this->count > 1) {
            if(this->current->next != NULL) {
                this->current->next->prev = this->current->prev;
            }
            if (this->current->prev != NULL) {
                this->current->prev->next = this->current->next;
            }
            if (this->current->prev == NULL) {
                this->first = this->current->next;
            }
            if (this->current->next == NULL) {
                this->last = this->current->prev;
            }
            delete this->current;
            this->current = NULL;
            this->count = this->count - 1;
        }

    }

    void printValues () {
        this->current = this->first;
        for(int i = 0; i < this->count; i++) {
            cout << this->current->value << " ";
            this->current = this->current->next;
        }
        cout << endl;
    }
};

int main()
{

    linkedList *list = new linkedList();

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
        list->push(x);
    }
    cout << endl;
    cout << "Initial values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    cout << "Initial values:" << endl;
    list->printValues();

    list->current = list->last;
    int startingCount = list->count;
    for(int i = startingCount; i > 0; i--) {
        if(list->current->value == i) {
                node *prev = list->current->prev;
                list->removeCurrent();
                list->current = prev;
        } else {
                list->current = list->current->prev;
        }
    }

    cout << "Resulting values:" << endl;
    list->printValues();

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


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
    int arr[] = {0,2,4,3,5};
    linkedList *list = new linkedList();
    for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        list->push(arr[i]);
    };

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



    std::list<int> l = { 0, 2, 4, 3, 5 };

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
        //cout << *it;
        counter++;
    }

    // Print out the list
    cout << "Resulting values:";
    for (int n : l) {
        std::cout << n << " ";
    }
    cout << endl;

    return 0;
}

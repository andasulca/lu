#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

struct Node {
    int value;
    Node *next;
};

void DeleteEven (Node* &listHead) {
    Node* &head = listHead;
    Node *current = head;
    do {
        Node *nextUneven;
        if (current->next != NULL || current->next->next != NULL) {
            nextUneven = current->next->next;
        }
        Node *toDelete;
        if (current->next != NULL) {
            current->value = current->value + current->next->value;
            toDelete = current->next;
            delete toDelete;
        }
        current->next = nextUneven;
        if(current->next == NULL) break;
            else current = current->next;
    } while (current != NULL);
}

int main()
{
    Node *listHead;
    Node *current;
    listHead->value = 1;
    listHead->next = new Node();
    current = listHead;
    current = current->next;
    current->next = new Node();
    current->value = 2;
    current = current->next;
    current->next = new Node();
    current->value = 5;
            current = current->next;
    current->next = new Node();
    current->value = 3;
    current = current->next;
    current->next = new Node();
    current->value = 6;
    current = current->next;
    //current->next = new Node();
    current->value = 6;

    current = listHead;
     do {
        cout << current->value << " ";
        current = current->next;
    } while (current != NULL);
    cout << endl;

    DeleteEven(listHead);

    current = listHead;
    do {
        cout << current->value << " ";
        current = current->next;
    } while (current != NULL);
    cout << endl;

    return 0;
}

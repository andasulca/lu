#include <iostream>
using namespace std;

class MyList {
public:
   int data;
   MyList *next;
   MyList() {next = NULL;}
   MyList(int a) {next = NULL; data=a;}
   ~MyList() { cout<<"Delete element with value "<<data<<endl;
       if(next != NULL) delete next;}
   void print() {
       cout<<data<<' ';
       if(next != NULL) next->print();
   }
   void insert(int a) {
       MyList *tmp = new MyList(a);
       tmp->next = this->next;
       this->next = tmp;
   }
   void erase() {
       if(next != NULL) {
          MyList *tmp = next;
          next = tmp->next;
          tmp->next = NULL;
          delete tmp;
       }
   }
};


int main() {
  int n;
  cin>>n;
  MyList *top = new MyList(n);
  for(int i=0;i<n;i++)
    top ->insert(i);

  top ->print();
  cout<<endl;

  MyList *cur = top;
  cur = cur->next;
  cur = cur->next;
  cur = cur->next;
  cur->insert(100);

  top ->print();
  cout<<endl;

  cur->erase();

  top ->print();
  cout<<endl;

  delete top;
return 0;
}

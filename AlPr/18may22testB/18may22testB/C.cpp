#include<iostream>
#include <list>
#include <type_traits>
using namespace std;
template <class X>
class plant {
protected:
    string name;
    X height;
public:
    plant() {};
    plant(string name, X height) {
        this->name = name;
        this->height = height;
    }
    virtual void add_petal_count(int petal_count) {};
    ~plant() {
    }
};

    template<class X> inline void print<double> {
        cout << this->name << ", " << std::to_string(height) << " m high" <<endl;
    }

    template<class X> inline void print<string> {
        cout << this->name << ", " << height << " m high" <<endl;
    }

int main()
{
     // name, height in m
    plant<double> *p = new plant<double>("oak",13.5);
    p->print(); // oak, 13.5 m high
    cout<<endl;
     // name, height in m, blossom color
    plant<string> *m = new plant<string>("lilacs","2.7");
    m->print();
    cout<<endl;

    delete m;
    delete p;
}

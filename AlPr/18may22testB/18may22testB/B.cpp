#include<iostream>
#include <list>
using namespace std;
class plant {
protected:
    string name;
    double height;
public:
    plant() {};
    plant(string name, double height) {
        this->name = name;
        this->height = height;
    }
    virtual void print() {
        cout << this->name << ", " << std::to_string(height) << " m high" <<endl;
    }
    virtual void add_petal_count(int petal_count) {};
    ~plant() {
    }
};

class bush : public plant {
private:
    string color;
    std::list<int> petal_count;
public:
    bush() {};
    bush(string name, double height, string color) {
        this->name = name;
        this->height = height;
        this->color = color;
    }
    void add_petal_count(int petal_count) override {
        if (petal_count < 2) return;
        this->petal_count.push_back(petal_count);
    }
    void print() override {
        cout << this->name << ", " << std::to_string(height) << " m high, " << color << " color, petals:";
        for (int n : this->petal_count) {
            std::cout << n << " ";
        }
    }
    ~bush() {
    }
};

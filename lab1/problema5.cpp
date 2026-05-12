#include <iostream>
using namespace std;

struct Vector {
    int* data;
    int size;
    int capacity;

    void init() {
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    void push_back(int x) {
        if (size == capacity) {
            capacity *= 2;
            int* newdata = new int[capacity];
            for (int i = 0; i < size; i++)
                newdata[i] = data[i];
            delete[] data;
            data = newdata;
        }
        data[size++] = x;
    }

    int get_size() {
        return size;
    }

    void pop_back() {
        if (size > 0)
            size--;
    }
};

int main() {
    Vector v;
    v.init();

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout << "size: " << v.get_size() << endl;  

    v.pop_back();

    cout << v.get_size() << endl;  

    for (int i = 0; i < v.get_size(); i++)
        cout << v.data[i] << " ";  

    return 0;
}

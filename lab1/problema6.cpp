#include <iostream>
using namespace std;

struct Vector{
    int* data;
    int size;
    int capacity;

    void init(){
        size = 0;
        capacity = 1;
        data = new int[capacity];
    }

    void insert(int x){
        if (size == capacity){
            capacity *= 2;
            int *newdata = new int[capacity];
            for (int i = 0; i < size; i++)
                newdata[i] = data[i];
            delete[] data;
            data = newdata;
        }
        data[size++] = x;
    }
    void pop(){
        int index = rand() % size;
        cout << data[index];
        data[index] = data[index-1];
        size--;
    }
};

int main() {
    Vector v;
    v.init();

    v.insert(5);
    v.insert(3);
    v.insert(8);
    v.insert(1);
    v.insert(7);

    cout << v.size << endl; 

    v.pop();  
    v.pop();  

    cout << v.size << endl; 

    return 0;
}

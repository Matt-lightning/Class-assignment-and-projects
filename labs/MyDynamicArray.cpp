#include <iostream>

using namespace std;

class MyDynamicArray {
    private:
        int size, capacity, error;
        int *a;
    public:
        MyDynamicArray() {
           capacity = 2;
           size = 0;
           error = 0;
           a = new int[capacity];
        }
        MyDynamicArray(int s) {
            /* Your code goes here */
             capacity = s;
            size = s;
            error = 0;
            a = new int[capacity];
        }
        int& operator[](int i){
            /* Your code goes here */
            if (i < size) {
                return a[i];
            } else {
                cout << "Out of bounds reference : " << i << endl;
                return error;
            }
        }
        void add(int v) {
            /* Your code goes here */
             if (size == capacity) {
                capacity *= 2;
                int *new_a = new int[capacity];
                for (int i = 0; i < size; i++) {
                    new_a[i] = a[i];
                }
                delete[] a;
                a = new_a;
                cout << "Doubling to : " << capacity << endl;
            }
            a[size] = v;
            size++;
        }
        void del() {
            /* Your code goes here */
            size--;
            if (size <= capacity / 4) {
                capacity /= 2;
                int *new_a = new int[capacity];
                for (int i = 0; i < size; i++) {
                    new_a[i] = a[i];
                }
                delete[] a;
                a = new_a;
                cout << "Reducing to : " << capacity << endl;
            }

        }
        int length() {
            return size;
        }
        void clear() {
            /* Your code goes here */
             delete[] a;
            capacity = 2;
            size = 0;
            a = new int[capacity];
        }
};

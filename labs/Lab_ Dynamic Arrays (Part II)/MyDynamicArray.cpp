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
        ~MyDynamicArray() {
            /* Your code goes here */
            cout << "In the destructor" << endl;
            delete [] a;
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
        MyDynamicArray& operator=(const MyDynamicArray& src) {
           /* Your code goes here */
           cout << "In the copy assignment operator" << endl;

           
        if(this != &src){
           delete []  a;

           a = new int[src.capacity];

           for(int i = 0; i < src.size; i++){
            a[i] = src.a[i];
           }

           error = src.error;
           capacity = src.capacity;
           size = src.size;


        }

          /* int *new_a = new int[capacity];
           int new_e = error;
           int new_s = size;
           int new_c = capacity;*/


           return *this;

          // a = new int[src.a + 1];
           //a = src.a;


        }
        
        MyDynamicArray(const MyDynamicArray & src) {
           /* Your code goes here */
           cout << "In the copy constructor" << endl;

           

           a = new int[src.capacity];

           for(int i = 0; i < src.size; i++){
            a[i] = src.a[i];
           }

           error = src.error;
           capacity = src.capacity;
           size = src.size;


        


           

           //a = new int[src.a + 1];
           //a = src.a;
        }
};


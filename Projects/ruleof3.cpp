#include <iostream>
#include <cmath>

using namespace std;

class Term {
public:
    double coef;
    int degree;
    Term *next;

    Term(double coef = 0, int degree = 0, Term *next = nullptr) {
        this->coef = coef;
        this->degree = degree;
        this->next = next;
    }

    void print(ostream &os) {
        if (this->degree == 0) {
            os << this->coef;
        }
        else if (this->degree == 1) {
            os << this->coef << "x";
        }
        else {
            os << this->coef << "x^" << this->degree;
        }
    }
};

class Poly {
private:
    Term *head;
public:
    Poly() {
        head = nullptr;
    }

    void addFront(double coef, int degree) {
        Term *n = new Term(coef, degree, head);
        head = n;
    }

    void addBack(double coef, int degree) {
        Term *n = new Term(coef, degree);
        if (head == nullptr) {
            head = n;
        }
        else {
            Term *cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = n;
        }
    }

    bool addOrdered(double coef, int degree) {
        if (search(degree)) {
            return false;
        }

        Term *n = new Term(coef, degree);
        if (head == nullptr) {
            head = n;
        }
        else if (head->degree < n->degree) {
            n->next = head;
            head = n;
        }
        else {
            Term *prev = head;
            Term *cur = head->next;
            while (cur != nullptr) {
                if (n->degree > cur->degree) {
                    break;
                }
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = n;
            n->next = cur;
        }
        return true;
    }

    void print(ostream &os) {
        for (Term *cur = head; cur != nullptr; cur = cur->next) {
            cur->print(os);

            if (cur->next != nullptr) {
                os << " + ";
            }
        }
    }

    double eval(double x) {
        double total = 0;
        for (Term *cur = head; cur != nullptr; cur = cur->next) {
            total += cur->coef * pow(x, cur->degree);
        }
        return total;
    }

    bool search(int degree) {
        for (Term *cur = head; cur != nullptr; cur = cur->next) {
            if (cur->degree == degree) {
                return true;
            }
        }
        return false;
    }
    
    bool remove(int degree) {
        if (!search(degree)) return false;

        if (head->degree == degree) {
            Term *next = head->next;
            delete head;
            head = next;
        }
        else {
            Term *prev = head;
            Term *cur = head->next;
            while (cur->degree != degree) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;
        }

        return true;
    }

    void deepCopy(const Poly &src) {
        // for (Term *ptr = src.head; ptr != nullptr; ptr = ptr->next) {
        //     addBack(ptr->coef, ptr->degree);
        // }

        if (src.head == nullptr) return;

        head = new Term(src.head->coef, src.head->degree);
        Term *back = head;
        for (Term *ptr = src.head->next; ptr != nullptr; ptr = ptr->next) {
           Term *n = new Term(ptr->coef, ptr->degree);
           back->next = n;
           back = n;
        }
    }

    void clear() {
        while (head != nullptr) {
            remove(head->degree);
            // Term *next = head->next;
            // delete head;
            // head = next;
        }
    }

    Poly(const Poly &src) { // Poly b = a; Poly b(a);
        head = nullptr;
        deepCopy(src);
    }

    Poly &operator=(const Poly &src) { // b = a;
        if (this != &src) {
            clear();
            deepCopy(src);
        }
        return *this;
    }

    ~Poly() { // delete poly; or at the end of a function/method call
        clear();
    }
};

ostream &operator<<(ostream &os, Poly &poly) {
    poly.print(os);
    return os;
}

int main() {
    Poly poly;
    poly.addOrdered(1, 5); // add empty
    cout << poly << endl;
    poly.addOrdered(1, 3); // add back no traverse
    cout << poly << endl;
    poly.addOrdered(1, 4); // add middle no traverse
    cout << poly << endl;
    poly.addOrdered(1, 6); // add front
    cout << poly << endl;
    poly.addOrdered(1, 1); // add back with traverse
    cout << poly << endl;
    poly.addOrdered(1, 2); // add middle with traverse
    cout << poly << endl;
    if (!poly.addOrdered(10, 2)) { // add middle with traverse
        cout << "Could not insert duplicate" << endl;
    } 
    cout << poly << endl;
    cout << "--------" << endl;
    poly.remove(6); // remove front
    cout << poly << endl;
    poly.remove(2); // remove middle with traversal
    cout << poly << endl;
    poly.remove(1); // remove back with traversal
    cout << poly << endl;
    poly.remove(100); // remove item that does not exist
    cout << poly << endl;
    poly.remove(4); // remove middle no traversal
    cout << poly << endl;
    poly.remove(3); // remove back no traversal
    cout << poly << endl;
    poly.remove(5); // remove front to empty list
    cout << poly << endl;
    poly.addOrdered(1, 1); // add item to verify list is in valid state
    cout << poly << endl;
    poly.addOrdered(1, 2);
    cout << poly << endl;

    // cout << "when x==3 poly is " << poly.eval(3) << endl;

    // int searchDegree = 5;
    // if (poly.search(searchDegree)) {
    //     cout << "found term with degree " << searchDegree << endl;
    // }
    // else {
    //     cout << "could not find term with degree "<< searchDegree << endl;
    // }

    return 0;
}
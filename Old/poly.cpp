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
};

ostream &operator<<(ostream &os, Poly &poly) {
    poly.print(os);
    return os;
}

int main() {
    Poly poly;
    poly.addBack(2, 2);
    poly.addBack(5, 1);
    poly.addBack(7, 0);

    cout << poly << endl;
    cout << "when x==3 poly is " << poly.eval(3) << endl;

    int searchDegree = 5;
    if (poly.search(searchDegree)) {
        cout << "found term with degree " << searchDegree << endl;
    }
    else {
        cout << "could not find term with degree "<< searchDegree << endl;
    }

    return 0;
}
#include <iostream>

using namespace std;

class Letter {
public:
    char ch;
    Letter *next;

    Letter(char ch = '\0', Letter *next = nullptr) {
        this->ch = ch;
        this->next = next;
    }
};

int main() {
    // int *ptr = nullptr; // NULL nullptr 0
    // Letter t; // ch=='\0', next==nullptr
    // Letter i('I'); 
    // Letter d('D', &i);

    // Letter t('T');
    // Letter i('I');
    // Letter d('D');
    // Letter e('E');

    // Letter *head = &t;
    // t.next = &i;
    // i.next = &d;
    // d.next = &e;

    Letter *t = new Letter('T');
    Letter *i = new Letter('I');
    Letter *d = new Letter('D');
    Letter *e = new Letter('E');

    Letter *head = t;
    t->next = i;
    i->next = d;
    d->next = e;

    cout << head->ch;
    cout << head->next->ch;
    cout << head->next->next->ch;
    cout << head->next->next->next->ch;
    cout << endl;

    for (Letter *cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->ch;
    }
    cout << endl;

    Letter *cur = head;
    while (cur != nullptr) {
        cout << cur->ch;
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
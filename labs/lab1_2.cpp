#include <iostream>
#include <vector>
using namespace std;

int main() {
    int amount; 
    int threshold;
    cin >> amount;
    vector<int> lst;
    for (int i = 0; i < amount; i++) {
        int x;
        cin >> x;
        lst.push_back(x);
    }
    threshold = lst.back();
    lst.pop_back();
    for (int x : lst) {
        if (x <= threshold) {
            cout << x << ",";
        }
    }
    cout << endl;
    return 0;
}

#include "Number.h"
#include <iostream>
using namespace std;

Number::Number(int number) {
	num = number;
}

void Number::SetNum(int number) {
	num = number;
}

int Number::GetNum() {
	return num;
}

ostream& operator<<(std::ostream& os, const Number& num){
    os << "This value is " << num.num << endl;
}
// "New" means new compared to previous level
#include <iostream>
using namespace std;

class InchSize {
   public:
      InchSize(int wholeInches = 0, int sixteenths = 0);
      void Print() const;
      InchSize operator+(InchSize rhs);
      InchSize operator+(int sixteenthsOfInch);
   private:
      int inches;
      int sixteenths;
};

InchSize InchSize::operator+(InchSize rhs) {
   InchSize totalSize;

   totalSize.inches = inches + rhs.inches;
   totalSize.sixteenths = sixteenths + rhs.sixteenths;

   // If sixteenths is greater than an inch, carry 1 to inches.
   if (totalSize.sixteenths >= 16) {
      totalSize.inches += 1;
      totalSize.sixteenths -= 16;
   }

   return totalSize;
}

// New: Overloaded + operator adding integers.
InchSize InchSize::operator+(int sixteenthsOfInch) {
   InchSize totalSize;

   totalSize.inches = inches;
   totalSize.sixteenths = sixteenths + sixteenthsOfInch;

   // While sixteenths is greater than an inch, carry to inches.
   while (totalSize.sixteenths >= 16) {
      totalSize.inches += 1;
      totalSize.sixteenths -= 16;
   }

   return totalSize;
}

InchSize::InchSize(int wholeInches, int sixteenthsOfInch) {
   inches = wholeInches;
   sixteenths = sixteenthsOfInch;
}

void InchSize::Print() const {
   cout << inches << " " << sixteenths << "/16 inches" << endl;
}

int main() {
   InchSize size1(4, 10);
   InchSize size2(8, 12);
   InchSize sumSize;
   InchSize totalSize;

   sumSize = size1 + size2;
   totalSize = sumSize + 18;

   totalSize.Print();

   return 0;
}
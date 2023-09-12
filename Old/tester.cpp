#include <iostream>
using namespace std;

class Vehicle {
   public:
      void SetSpeed(int speedToSet) {
         speed = speedToSet;
      }

      void PrintSpeed() {
         cout << speed;
      }

   private:
      int speed;
};

class Carriage {
   public:
      void SetSeats(int seatsToSet) {
         seats = seatsToSet;
      }

      void PrintSeats() {
         cout << seats << " seats in chariot";
      }

   private:
      int seats;
};

class AnimalDrawnCarriage : public Vehicle, public Carriage {
   public:
      void SetAnimal(string animalToSet) {
         animal = animalToSet;
      }

      void PrintAnimalSpeed() {
         cout << animal << " speed: ";
         PrintSpeed();
      }

   private:
      string animal;
};

int main() {
   AnimalDrawnCarriage chariot;

   chariot.SetSpeed(7);
   chariot.SetSeats(2);
   chariot.SetAnimal("Horse");

   chariot.PrintAnimalSpeed();
   cout << endl;
   chariot.PrintSeats();

   return 0;
}
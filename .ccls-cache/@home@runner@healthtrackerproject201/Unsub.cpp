#include "Unsub.h"
/*Underweight = <18.5
Normal weight = 18.5–24.9
Overweight = 25–29.9
Obesity = BMI of 30 or greater*/
Unsub::Unsub(const std::string& n, int h, int w, int a, char s, char g) : User(n, h, w, a, s, g) {}

void Unsub::print(ostream &fout){
  if(getBMI() <= 18.5){
    cout<< "You are underweight." << endl;
  }
  else if (getBMI() >= 18.5 && getBMI() <= 24.9){
    fout << "You are normal weight." << endl;
  }
  else if (getBMI() >= 25 && getBMI() <= 29.9){
    fout << "You are overweight." << endl;
  }
  else if (getBMI() >= 30){
    fout << "You are obese." << endl;
  }

}
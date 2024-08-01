#include "Sub.h"

/*The subscribed customer will be able Underweight = <18.5
Normal weight = 18.5–24.9
Overweight = 25–29.9
Obesity = BMI of 30 or greater
& we will give them && diet tips like, for weight loss drink more water, portion
control. For muscle gain increase calories, more lean proiten, eat more meals,
try dirty bulk. */

Sub::Sub(const std::string &n, int h, int w, int a, char s, char g)
    : User(n, h, w, a, s, g) {}

void Sub::print(ostream &fout) {
  if (getBMI() <= 18.5) {
    fout << "You are underweight." << endl;
  } else if (getBMI() >= 18.5 && getBMI() <= 24.9) {
    fout << "You are normal weight." << endl;
  } else if (getBMI() >= 25 && getBMI() <= 29.9) {
    fout << "You are overweight." << endl;
  } else if (getBMI() >= 30) {
    fout << "You are obese." << endl;
  }
  if (goal == 'W') {
    fout << "Since your goal is to lose weight. Here are some tips: " << endl
         << "Portion control you meals" << endl
         << "Eat slowly " << endl
         << "Drink more water " << endl
         << "Eat a more protein rich breakfast " << endl
         << "Track your calories to be in a deficit" << endl;
  }

  else if (goal == 'M') {
    fout << "Since your goal is to gain muscle. Here are some tips: " << endl
         << "Eat more lean protien" << endl
         << "Increase your caloric intake " << endl
         << "Drink more water" << endl
         << "Consider going on a dirty bulk" << endl
         << "Track calories to be in a surplus" << endl;
  }
  fout<<"Your Caloric intake should be around "<<getBMR();
}

float Sub::getBMR() {
  if (sex == 'M') {
    return (10 * weight) + (6.25 * height) - (5 * age) + 5;
  } else if (sex == 'F') {
    return (10 * weight) + (6.25 * height) - (5 * age) - 161;
  }
  return 0;
}
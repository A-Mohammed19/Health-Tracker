#include "User.h"

User::User() {
  name = " ";
  weight = 0;
  height = 0;
  age = 0;
  sex = 'X';
  goal = 'X';
}

User::User(string n, int w, int h, int a, char s, char g) {
  name = n;
  weight = w;
  height = h;
  age = a;
  sex = s;
  goal = g;
}
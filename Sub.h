#include "User.h"
#pragma once

class Sub : public User {
public:
  void print(ostream &fout);
  float getBMR();
  Sub(const std::string& n, int h, int w, int a, char s, char g);
};
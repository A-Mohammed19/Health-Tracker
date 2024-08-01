#include "User.h"
#pragma once

class Unsub : public User {
public:
  void print(ostream &fout);
  Unsub(const std::string& n, int h, int w, int a, char s, char g);
};
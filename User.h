#pragma once

#include <assert.h>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class User {
protected:
  string name;
  int weight;
  int height;
  int age;
  char sex;
  char goal;

public:
  // default constructor
  User();

  // overloaded constructor
  User(string n, int w, int h, int a, char s, char g);

  // setters
  void setName(string n) { name = n; }
  void setHeight(int h) { height = h; }
  void setWeight(int w) { weight = w; }
  void setGoal(char g) { goal = g; }
  void setSex(char s) { sex = s; }
  void setAge(char a) { age = a; }

  // getters
  string getName() { return name; }
  int getAge() { return age; }
  char getSex() { return sex; }
  int getHeight() { return height; }
  int getWeight() { return weight; }
  char getGoal() { return goal; }
  float getBMI() { return (((weight) / pow(height, 2)) * 703); }

  virtual void print(ostream &fout) = 0;
};

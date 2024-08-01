#pragma once
#include "Sub.h"
#include "Unsub.h"
#include "User.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
  User *userPtr = nullptr;
  Node *nextPtr;
  struct Node *next;
};

class Linked {
protected:
  Node *headPtr;
  Node *tailPtr;

public:
  Linked();
  ~Linked();
  void addNode(User *u);
  void delNode(string name);
  void printList(ostream &fout);
  bool listIsEmpty();
  void printByGoal(ostream &fout, char goal);
  void printBySex(ostream &fout, char sex);
  void printByHealth(ostream &fout, float BMI);
  void printSpecific(ostream &fout, string name);
  
};
#include "Function.h"
#include "List.h"
#include <fstream>
#include <iostream>
// Abdul Mohammed
using namespace std;

int main() {
  // INSERT PROGRAM HERE
  /*We are going to be taking in user input
    and based on the command we will output to the file. Just going to the
    ability to search due to lack of time. No command to add anything to input
    file. */
  ofstream fout;
  fout.open("Output.txt");
  if (!fout.is_open()) {
    cout << "Error opening files";
    return 0;
  }

  Linked list1;

  readHealthList(list1);
  
  // A list1.printSpecific(fout, "Alex");

  char c;
  bool a = true;
  cout << "Welcome to HealthyHearts!! \n" << endl;
  while (a == true) {
    cout << "Pick a command:" << endl
         << "A= All" << endl
         << "G = Goal," << endl
         << "N = Gender" << endl
         << "B = BMI" << endl
         << "S=Specific" << endl
         << "D= Delete" << endl
         << "Q= Quit" << endl;
    cout << "Please enter a command: ";
    cin >> c;

    switch (c) {
    case 'A':
      fout << "You chose to print the whole list" << endl;
      list1.printList(fout);
      a = true;
      break;

    case 'G': {
      fout << "You chose to search based on goal" << endl;
      char gl;
      cout << "Please enter a goal (W/M): ";
      cin >> gl;
      list1.printByGoal(fout, gl);
      a = true;
    } break;

    case 'N': {
      fout << "You chose to search based on gender" << endl;
      char gen;
      cout << "Please enter a gender:";
      cin >> gen;
      list1.printBySex(fout, gen);
      a = true;
    } break;
    case 'B': {
      fout << "You chose to search based on BMI" << endl;
      float bmi;
      cout << "Please enter the BMI:";
      cin >> bmi;
      list1.printByHealth(fout, bmi);
      a = true;
    } break;
    case 'S': {
      fout << "You chose to search based on specific name" << endl;
      string n1 = " ";
      cout << "Please enter a name:";
      cin >> n1;
      cout << n1;
      list1.printSpecific(fout, n1);
      a = true;
    } break;

    case 'D': {
      fout << "You chose to delete a record" << endl;
      string name;
      cout << "Please enter a name to delete";
      cin >> name;
      a = true;
    } break;
    case 'Q':
      fout << "You chose to quit" << endl;
      a = false;
      break;
    default:
      cout << "Please enter a valid command" << endl;
      break;
    }
  }
  fout.close();
}
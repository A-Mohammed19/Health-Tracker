#include "Function.h"
#include <string>

void readHealthList(Linked &L) {
  ifstream fin;
  fin.open("Input.txt");
  if (!fin.is_open()) {
    cout << "Error opening files";
    return;
  }

  string inStr, tempStr;
  vector<string> row;

  

  while(fin >> inStr) {
    
    stringstream inSS(inStr);
    row.clear();
    
    while (getline(inSS, tempStr, ',')) {
      row.push_back(tempStr);
      //cout << tempStr << endl;
    }
      
    //cout << row[1] << endl;
    //cout<< row[4]<<endl;
      
    try {
      
      if (row[0][0] == 'Y') {
        Sub *tempSubUser = new Sub(row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), row[5][0], row[6][0]);

        User *tempTemp = tempSubUser;
        L.addNode(tempTemp);
        
      }

      else if (row[0][0] == 'N') {
        Unsub *tempUnUser = new Unsub(row[1], stoi(row[2]), stoi(row[3]), stoi(row[4]), row[5][0], row[6][0]);

        //cout <<1 << endl;
        User *tempTemp = tempUnUser;
        L.addNode(tempTemp);
        //cout << 2 << endl;
        
      }
      
    } catch (const std::invalid_argument &e) {
      cout << "error1" << endl;
    } catch (const std::out_of_range &e) {
      cout << "error2" << endl;
    }
  }
  fin.close();
}

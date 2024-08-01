#include "List.h"
#include "Sub.h"
#include "Unsub.h"
#include "User.h"
#include <fstream>
/*need LinkedList(); okay
+ void addElement(listType); add this
+ listType peek(); add this
+ void delElement(); okay
+ void printList(); // okay
+ bool listIsEmpty() // okay
 data = int & struct Node* next;
int findPeakElement(struct Node* head) {
   if (head == NULL) {
      return -1;
   }
   if (head->next == NULL) {
      return head->data;
   }
   int prev = head->data;
   Node *current_node;
   for (current_node = head->next; current_node->next != NULL; current_node =
current_node->next) { if (current_node->data > current_node->next->data &&
current_node->data > prev) { return current_node->data;
      }
      prev = current_node->data;
   }
   if (current_node->data > prev) {
      return current_node->data;
   }
   return -1;
}

courtesy of tutorialspoint.com
*/

User *peek(struct Node *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    return head->userPtr;
  }
  User *prev = head->userPtr;
  Node *current_node;
  for (current_node = head->next; current_node->next != NULL;
       current_node = current_node->next) {
    if (current_node->userPtr > current_node->next->userPtr &&
        current_node->userPtr > prev) {
      return current_node->userPtr;
    }
    prev = current_node->userPtr;
  }
  if (current_node->userPtr > prev) {
    return current_node->userPtr;
  }
  return 0;
}

Linked::Linked() {
  headPtr = nullptr;
  tailPtr = nullptr;
}

Linked::~Linked() {
  // Destructor will loop through the list and delete each node
  Node *delPtr;
  while (headPtr != nullptr) {
    delPtr = headPtr;
    headPtr = headPtr->nextPtr;
    delete delPtr;
    delPtr = nullptr;
  }
  tailPtr = nullptr;
}

void Linked::addNode(User *u) {
  // Create a new node (set data & pointer values)
  Node *newNode = new Node;
  newNode->userPtr = u;
  newNode->nextPtr = nullptr;
  // if the list is empty, set head & tail pointers to new node
  if (headPtr == nullptr) {
    headPtr = newNode;
    tailPtr = newNode;
  }
  // else add node to the end
  else {
    tailPtr->nextPtr = newNode;
    tailPtr = newNode;
  }
}

void Linked::delNode(string key) {
  // start at the headPtr and loop until you find key or get to the end of the
  // list
  Node *tempPtr = headPtr;
  Node *delPtr;
  // condition 1: delete data at headptr
  if (tempPtr->userPtr->getName() == key) {
    delPtr = tempPtr;
    headPtr = headPtr->nextPtr;
    delete delPtr;
    delPtr = nullptr;
  }
  // condition 2: delete a value in the middle of the list
  else {
    // get tempPtr->nextPtr to point to value to delete
    while (tempPtr->nextPtr != nullptr &&
           tempPtr->nextPtr->userPtr->getName() != key) {
      tempPtr = tempPtr->nextPtr;
    }
    if (tempPtr->nextPtr != nullptr &&
        tempPtr->nextPtr->userPtr->getName() == key) {
      delPtr = tempPtr->nextPtr;
      tempPtr->nextPtr = delPtr->nextPtr;
      // tempPtr->nextPtr = tempPtr->nextPtr->nextPtr;
      // condition 3: delete value at the end of the list
      if (tempPtr->nextPtr == nullptr) {
        tailPtr = tempPtr;
      }
      delete delPtr;
      delPtr = nullptr;
    }
  }
}

void Linked::printList(ostream &fout) {
  // start at the headPtr and loop - printing data from each node
  fout << "--------------------------------" << endl;
  fout << "Printing the Linked List" << endl;
  fout << "--------------------------------" << endl;
  Node *tempPtr = headPtr;
  if (tempPtr == nullptr) {
    cout << "This list is empty\n";
  } else {
    while (tempPtr != nullptr) {
      fout << tempPtr->userPtr->getName() << " "
           << tempPtr->userPtr->getWeight() << " "
           << tempPtr->userPtr->getHeight() << " " << tempPtr->userPtr->getBMI()
           << endl;
      tempPtr = tempPtr->nextPtr;
    }
  }
}

bool Linked::listIsEmpty() {
  if (headPtr == nullptr) {
    return true;
  } else
    return false;
}

void Linked::printByGoal(ostream &fout, char goal) {
  // start at the headPtr and loop - printing data from each node
  fout << "---------------------------------------" << endl;
  fout << "Printing the Linked List By Goal - " << goal << endl;
  fout << "---------------------------------------" << endl;

  Node *tempPtr = headPtr;

  if (tempPtr == nullptr) {
    cout << "This list is empty\n";
  } else {
    while (tempPtr != nullptr) {
      if (tempPtr->userPtr->getGoal() == goal) {
        fout << tempPtr->userPtr->getName() << " "
             << tempPtr->userPtr->getWeight() << " "
             << tempPtr->userPtr->getHeight() << " "
             << tempPtr->userPtr->getBMI() << endl;
      }
      tempPtr = tempPtr->nextPtr;
    }
  }
}

void Linked::printBySex(ostream &fout, char sex) {
  // start at the headPtr and loop - printing data from each node
  fout << "---------------------------------------" << endl;
  fout << "Printing the Linked List By Sex - " << sex << endl;
  fout << "---------------------------------------" << endl;
  Node *tempPtr = headPtr;
  if (tempPtr == nullptr) {
    cout << "This list is empty\n";
  } else {
    while (tempPtr != nullptr) {
      if (tempPtr->userPtr->getSex() == sex) {
        fout << tempPtr->userPtr->getName() << " "
             << tempPtr->userPtr->getWeight() << " "
             << tempPtr->userPtr->getHeight() << " "
             << tempPtr->userPtr->getBMI() << endl;
      }
      tempPtr = tempPtr->nextPtr;
    }
  }
}

void Linked::printByHealth(ostream &fout, float BMI) {
  // start at the headPtr and loop - printing data from each node
  fout << "---------------------------------------" << endl;
  fout << "Printing the Linked List by BMI - " << BMI << endl;
  fout << "---------------------------------------" << endl;

  Node *tempPtr = headPtr;

  if (tempPtr == nullptr) {
    cout << "This list is empty\n";
  } else {
    while (tempPtr != nullptr) {
      if (tempPtr->userPtr->getBMI() <= BMI) {
        fout << tempPtr->userPtr->getName() << " "
             << tempPtr->userPtr->getWeight() << " "
             << tempPtr->userPtr->getHeight() << " "
             << tempPtr->userPtr->getBMI() << endl;
      }
      tempPtr = tempPtr->nextPtr;
    }
    // tempPtr -> subPtr -> printList(fout);
  }
}

void Linked::printSpecific(ostream &fout, string name) {
  // start at the headPtr and loop - printing data from each node
  fout << "--------------------------------" << endl;
  fout << "Printing the User Profile - " << name << endl;
  fout << "--------------------------------" << endl;
  Node *tempPtr = headPtr;
  // bool found = false;
  if (tempPtr == nullptr) {
    cout << "No person found\n";
  } else {
    while (tempPtr != nullptr) {
      if (tempPtr->userPtr->getName() == name) {
        tempPtr->userPtr->print(fout);
        // found = true;
        break;
      }
      tempPtr = tempPtr->nextPtr;
    }
    /*if (!found) {
      fout << "No person found with the name: " << name << endl;
    }*/
  }
  tempPtr = tempPtr->nextPtr;
}
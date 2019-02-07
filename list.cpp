#include "list.h"
using namespace std;

list::list(){
  head = NULL;
  tail = NULL;
}

void list::makeNode(float time, float answerLength, int clientNum, char PorD){
  //creates a client, and assigns to front of list if phone, or tail of list if door
  node *temp = new node;
  temp->time = time;
  temp->answerLength = answerLength;
  temp->clientNum = clientNum;
  temp->PorD = PorD;
  temp->next = NULL;

  if(head == NULL){
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else if (PorD == 'D'){
    tail->next = temp;
    tail = temp;
    temp = NULL;
  }
  else if (PorD == 'P'){
    temp->next = head;
    head = temp;
    temp = NULL;
  }
  else {
    cout << "\nERROR: NODE NOT CREATED\n";
  }
}

void list::deleteNode(){
  //deletes client at head of list, simulates question being answered
  node *temp = new node;
  temp = head;
  head = head->next;
  delete temp;
}

int list::size(){
  //size of list, essentially number of clients in line
  node *it = head;
  int size = 0;
  while (it != NULL){
    it = it->next;
    size++;
  }
  return size;
}

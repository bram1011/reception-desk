#include <cstddef>
#include<iostream>

struct node {
  //time client appears
  float time;
  //how long answer takes
  float answerLength;
  //client ID
  int clientNum;
  //phone or door
  char PorD;
  node *next;
};

class list {

  public:
    list();
    void makeNode(float time, float answerLength, int clientNum, char PorD);
    void deleteNode();
    int size();
    node* head;
    node* tail;

  private:


};

#include<cstdlib>
#include "list.h"

using namespace std;

void answerQuestion(float currTime, list &clientList, node* served){
  //removes client from list and prints to log
  cout << "Client #" << served->clientNum;
  if (served->PorD == 'P'){
    cout << " (Phone) ";

  }
  else if (served->PorD == 'D'){
    cout << " (Door) ";
  }
  cout << " had their question answered at "
  << currTime << " seconds. The line is now " << clientList.size()
  << " clients long\n";
  clientList.deleteNode();
}

void doorClient(list &clientList, float clientTime, int &clientID, float q){
  //creates client at tail and prints to log
  float answerTime = (q * ((float) rand())/RAND_MAX);
  clientList.makeNode(clientTime, answerTime, clientID, 'D');
  int size = clientList.size();
  cout << "Client #" << clientID << " has joined the back of the line at "
  << currTime << " seconds\n";
  cout << "The line is now " << size << " clients long.\n";
  clientID++;

}

void phoneClient(list &clientList, float clientTime, int &clientID, float q){
  //creates client at head and prints to log
  float answerTime = (q * ((float) rand())/RAND_MAX);
  clientList.makeNode(clientTime, answerTime, clientID, 'P');
  int size = clientList.size();
  cout << "Client #" << clientID << " has called the receptionist at "
  << currTime << " seconds.\n";
  cout << "The line is now " << size << " clients long.\n";
  clientID++;
}


int main() {
  //declaring needed variables
  const float MAX_TIME = 10.0;
  const float d = 1.0;
  const float p = 2.0;
  const float q = 2.0;
  float currTime = 0.0;
  bool wasAnswered = true;
  bool wasDoor = true;
  bool wasPhone = true;
  int clientID = 1;
  list clientLine;
  node* currClient = new node;

  //initial client
  float doorTime = (d * ((float) rand())/RAND_MAX);
  float phoneTime = (p * ((float) rand())/RAND_MAX);
  float answerTime;

  if (doorTime < phoneTime){
    doorClient(clientLine, doorTime, clientID, q);
  }
  else if (phoneTime < doorTime){
    phoneClient(clientLine, phoneTime, clientID, q);
  }

  while (currTime < MAX_TIME){
    //main loop
    srand(clientID); //reseeds the RNG
    currClient = clientLine.head;
    if (wasDoor == true){
      doorTime = (d * ((float) rand())/RAND_MAX) + currTime;
    }
    if (wasPhone == true){
      phoneTime = (p * ((float) rand())/RAND_MAX) + currTime;
    }
    if (currClient != NULL && wasAnswered == true){
      answerTime = currClient->answerLength + currTime;
    }
    else if (currClient == NULL){
      answerTime = 99.9;
    }

    if (answerTime < phoneTime && answerTime < doorTime){
      //answer comes before new client
      answerQuestion(currTime, clientLine, currClient);
      currTime = answerTime;
      wasAnswered = true;
    }
    else if (phoneTime < answerTime && phoneTime < doorTime){
      //client calls front desk
      phoneClient(clientLine, phoneTime, clientID, q);
      currTime = phoneTime;
      wasAnswered = false;
    }
    else if (doorTime < answerTime && doorTime < phoneTime){
      //client walks in
      doorClient(clientLine, doorTime, clientID, q);
      currTime = doorTime;
      wasAnswered = false;
    }
  }

  return 0;
}

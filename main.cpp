// SEGFAULT from vector access in makeAgent
// doesnt print agent things properly

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

const float cost = 0.01;
const float benefit = 0.03;
const float deathRate = 0.10;
const float mutRate = 0.05;
const int immigrationRate = 1;
const int runLength = 200;

class Agent {
  public:
    float potential = 0.12;
    int xpos, ypos = 0;
    enum Strat {
      ethnocentric,
      humanitarian,
      selfish,
      traitor
    } strat = ethnocentric;
    enum Colour {
      red,
      green,
      blue
    } colour = red;
};

Agent makeAgent() {
  Agent a;
  int i, j;
  int r1, r2, r3, r4;
  Agent::Strat st;
  Agent::Colour col;
  r1 = rand() % 50; //xpos
  r2 = rand() % 50; //ypos
  r3 = rand() % 4;  //strat
  r4 = rand() % 3;  //colour
  // set strat
  if (r3==0) st = Agent::Strat::ethnocentric;
  if (r3==1) st = Agent::Strat::humanitarian;
  if (r3==2) st = Agent::Strat::selfish;
  if (r3==3) st = Agent::Strat::traitor;
  // set colour
  if (r4==0) col = Agent::Colour::red;
  if (r4==1) col = Agent::Colour::green;
  if (r4==2) col = Agent::Colour::blue;
  // set agent values
  a.xpos = r1;
  a.ypos = r2;
  a.strat = st;
  a.colour = col;

  return a;
}

vector<vector<Agent>> fillGrid(vector<vector<Agent>> arr) {
  int i, j;
  Agent current = makeAgent();
  for (i=0;i<5;i++) {
    arr.push_back({});
    for (j=0;j<5;j++) {
      arr[i].push_back(current);
      Agent current = makeAgent();
    }
  }
  return arr;
}

vector<vector<Agent>> initGrid(vector<vector<Agent>> arr) {
  int i, j;
  Agent current;
  for (i=0;i<5;i++) {
    arr.push_back({});
    for (j=0;j<5;j++) {
      arr[i].push_back(current);
    }
  }
  return arr;
}

vector<vector<Agent>> placeAgents(vector<vector<Agent>> arr) {
  int i;
  int x, y;
  cout << "making a" << endl;
  Agent a = makeAgent();
  cout << "begin loop" << endl;
  for (i=0;i<=immigrationRate;i++) {
    cout << "loop " << i << endl;
    x = a.xpos;
    y = a.ypos;
    cout << "vector access" << endl;
    arr[y][x] = a;
  }
  return arr;
}

int main() {
  cout << "Begin" << endl;
  srand(time(NULL));
  vector<vector<Agent>> arr;
  cout << "Fill arr" << endl;
  arr = initGrid(arr);
  cout << "Place agents" << endl;
  fillGrid(arr); 
  cout << arr[0][0].xpos << "," << arr[0][0].ypos << endl;
  cout << arr[0][0].strat << "," << arr[0][0].colour << endl;
  cout << "End" << endl;
}






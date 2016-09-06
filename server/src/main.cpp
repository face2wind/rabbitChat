#include <iostream>

#include "network/network_agent.hpp"

using namespace std;

int main()
{
  cout << "Server start running ..... " << endl;
  NetworkAgent agent;
  agent.Listening();
}

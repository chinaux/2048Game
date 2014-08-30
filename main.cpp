#include <iostream>
#include <stdio.h>

#include "module.h"

using namespace std;

int main(int argc, char* argv[])
{
  char direction;
  Module* pModule = new Module();
  
  pModule->init();
  pModule->show();
  
  while(pModule->isRunning()){
    
    cin >> direction;
    if (direction == _UP){
      cout << "you inter k" << endl;    
      pModule->mvUp();
    }else if (direction == _DOWN){
      cout << "you inter j" << endl;      
      pModule->mvDown();
    }else if (direction == _LEFT){
      cout << "you inter h" << endl;       
      pModule->mvLeft();
    }else if (direction == _RIGHT){
      cout << "you inter l" << endl;       
      pModule->mvRight();
    }else{
      cout << "unknown command,please inter [j(down),k(up),h(left),l(right)]" << endl;
      pModule->show();
      continue;
    }
    pModule->show();
  }
  
  
  return 0;
}

#include <iostream>
#include <time.h> 
#include <cstdlib>
#include "module.h"
using namespace std;

void Module::init(){
  for(int i=0; i < 4; i++)
    for(int j=0; j < 4; j++)
      a[i][j] = 0;
  int rand_x,rand_y;
  
  a[0][0] = 2;
  a[1][0] = 2;
  a[2][0] = 2;
  a[3][0] = 0; 
  /*
  for(int i=0; i < 2; i++){
    srand(time(NULL));
    rand_x = rand() % 4;
    rand_y = rand() % 4;
    a[rand_x][rand_y] = 2;
  }*/
  
  running = true;
}
void Module::show(){
  cout << "show" << endl;
  for(int i=0; i < 4; i++)
  {
    for(int j=0; j < 4; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  cout << endl;
  cout << "score:" << score << endl;
}

void Module::mvUp(){
  cout << "mvUp" << endl;
  int i,j;

  for(j=0;j<4;j++){
    
    bool mv = true;
    while(mv){
      //combine
      mv = false;
      
      for(i=1;i<4;i++){
        if (a[i-1][j] != 0 && a[i][j] != 0 && a[i-1][j] == a[i][j]){
          a[i-1][j] += a[i][j];
          score += a[i-1][j];
          a[i][j] = 0;
        }
      }
      //move
      for(int k=0;k<4;k++){
        for(i=1;i<4;i++){
          if (a[i-1][j] == 0 && a[i][j] != 0){
            a[i-1][j] = a[i][j];
            a[i][j] = 0;
            mv = true;
          }
        }
      }
    }
  }
  next();
}

void Module::mvDown(){
  cout << "mvDown" << endl;
  int i,j;
  for(j=0;j<4;j++){

    bool mv = true;
    while(mv){
      //combine
      mv = false;
      
      for(i=3;i>0;i--){
        if (a[i-1][j] != 0 && a[i][j] != 0 && a[i-1][j] == a[i][j]){
          a[i][j] += a[i-1][j];
          score += a[i-1][j];
          a[i-1][j] = 0;
        }
      }
      //move
      for(int k=0;k<4;k++){
        for(i=3;i>0;i--){
          if (a[i][j] == 0 && a[i-1][j] != 0){
            a[i][j] = a[i-1][j];
            a[i-1][j] = 0;
            mv = true;
          }
        }
      }
    }
  }
  next();
}

void Module::mvLeft(){
  cout << "mvLeft" << endl;
  int i,j;

  for(i=0;i<4;i++){
    
    bool mv = true;
    while(mv){
      //combine
      mv = false;
      
      for(j=1;j<4;j++){
        if (a[i][j-1] != 0 && a[i][j] != 0 && a[i][j-1] == a[i][j]){
          a[i][j-1] += a[i][j];
          score += a[i][j-1];
          a[i][j] = 0;
        }
      }
      //move
      for(int k=0;k<4;k++){
        for(j=1;j<4;j++){
          if (a[i][j-1] == 0 && a[i][j] != 0){
            a[i][j-1] = a[i][j];
            a[i][j] = 0;
            mv = true;
          }
        }
      }
    }
  }
  next();
}

void Module::mvRight(){
  cout << "mvRight" << endl;  	
  int i,j;
  for(i=0;i<4;i++){

    bool mv = true;
    while(mv){
      //combine
      mv = false;
      for(j=3;j>0;j--){
        if (a[i][j] != 0 && a[i][j-1] != 0 && a[i][j-1] == a[i][j]){
          a[i][j] += a[i][j-1];
          score += a[i][j];
          a[i][j-1] = 0;
        }
      }
      //move
      for(int k=0;k<4;k++){
        for(j=3;j>0;j--){
          if (a[i][j] == 0 && a[i][j-1] != 0){
            a[i][j] = a[i][j-1];
            a[i][j-1] = 0;
            mv = true;
          }
        }
      }
    }
  }
  next();
}

void Module::check(){
  //check
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      if(a[i][j] == 0){
        return;
      } 
    }
  }
  //TODO:check is realy over

  cout << "GAME OVER" << endl;
  running = false; 
}
void Module::next(){
  int i,j;
  bool flag_next = true;
  check();
  while(flag_next){
    srand(time(NULL));
    i = rand() % 4;
    j = rand() % 4;
    if (a[i][j] == 0){
      a[i][j] = 2;
      flag_next = false;
    }
  }
}
bool Module::isRunning(){
  return running;
}

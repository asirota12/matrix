#include <iostream>
#include <fstream>
#include <string>
#include <functions.h>

using namespace std;

void splitfile(void){
  ifstream file("vectors.dat");
  ofstream f1("top.dat");
  ofstream f2("bottom.dat");
  int i=0;
  string line;
  while(getline(file,line)){
    if(i<102){
      f1<<line<<endl;
    }else{
      f2<<line<<endl;
    }
    i++;
  }
}

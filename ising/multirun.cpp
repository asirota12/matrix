#include<header.h>
#include<iostream>
#include<string> 
#include<fstream>

using namespace std;

int main(){
  string file="gsenergiestest.dat";
  ofstream myfile;
  myfile.open(file.c_str());
  myfile<<endl;
  
  for (int i=2;i<=20;i++){
    myfile<<i<<" "<<run(i,1,1)<<endl;
  }
  myfile.close();
}

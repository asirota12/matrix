#include <iostream>
#include <fstream>
#include <string>
#include <functions.h>

using namespace std;

void process(void){
  ofstream n("new.dat");
  ifstream f("values.dat");
  string line;
  getline(f,line);
  if (f.is_open()){
    while(getline(f,line)){
      size_t a=line.find_first_of("(");
      size_t b=line.find_first_of(",");
      string k = line.substr(0,a);
     
      string thing = line.substr(a+1,b-a-1);
 // this is our eigen value next to it's k value
      n<< thing<<"	"<<k<<endl;
    }
    f.close();
  }
  else cout<<"didn't open";
}


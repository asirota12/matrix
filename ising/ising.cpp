#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <fstream>
#include <string>
#include <complex>
#include <unsupported/Eigen/KroneckerProduct>

#include <sys/stat.h>
#include <unistd.h>

using namespace std;
using namespace Eigen;

  

MatrixXd zprod(int spincurrent,int i,int spins, MatrixXd A){  //gotta start count at 2 since it at minimum returns a 4x4
  MatrixXd sz(2,2);
  sz(0,0)=1;
  sz(1,0)=0;
  sz(0,1)=0;
  sz(1,1)=-1;
  MatrixXd I(2,2);
  I(0,0)=1;
  I(1,0)=0;
  I(0,1)=0;
  I(1,1)=1;
  
  //base case

  if (spincurrent==spins){
    if(i+1==spincurrent||i==spincurrent){  
      return kroneckerProduct(sz,A);
    } 
      return kroneckerProduct(I,A); 
  } 
  
  //recursize bit   

  if(spincurrent==i||spincurrent==i+1){
      return zprod(spincurrent+1,i,spins,kroneckerProduct(sz,A)); 

  } else{
      return zprod(spincurrent+1,i,spins,kroneckerProduct(I,A));
  }

  //cout<< "ya screwed up"<<endl; //didn't return if it got here 
}

MatrixXd xprod(int spincurrent,int i,int spins, MatrixXd A){  //gotta start count at 2 since it at minimum returns a 4x4
  MatrixXd sx(2,2);
  sx(0,0)=0;
  sx(1,0)=1;
  sx(0,1)=1;
  sx(1,1)=0;
  MatrixXd I(2,2);
  I(0,0)=1;
  I(1,0)=0;
  I(0,1)=0;
  I(1,1)=1; 
  //base case
  if (spincurrent==spins){
    if(i==spincurrent){  
      return kroneckerProduct(sx,A);
    } 
      return kroneckerProduct(I,A); 
  } 
  
  //recursize bit   

  if(spincurrent==i){
    return xprod(spincurrent+1,i,spins,kroneckerProduct(sx,A));
  }else{
    return xprod(spincurrent+1,i,spins,kroneckerProduct(I,A));
  }

 // cout<< "ya screwed up with z"<<endl; //didn't return if it got here 
}

bool exists (const string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

MatrixXd Ham(int spins,double a,double b){
  MatrixXd sx(2,2);
  sx(0,0)=0;
  sx(1,0)=1;
  sx(0,1)=1;
  sx(1,1)=0;
  MatrixXd sz(2,2);
  sz(0,0)=1;
  sz(1,0)=0;
  sz(0,1)=0;
  sz(1,1)=-1; 
  MatrixXd I(2,2);
  I(0,0)=1;
  I(1,0)=0;
  I(0,1)=0;
  I(1,1)=1;

  MatrixXd H=a*xprod(2,1,spins,sx);
 // cout<< H<<endl<<endl<<endl;
  H=H+b*zprod(2,1,spins,sz);
 // cout<< H<<endl<<endl<<endl;
  for (int j=2;j<spins;j++){
    H=H+ a*xprod(2,j,spins,I) + b*zprod(2,j,spins,I);
  //  cout<< H<<endl<<endl<<endl;
  } 
  H=H+ a*xprod(2,spins,spins,I);
  H=H+ b*zprod(2,spins,spins,sz); //this one is periodic boundary conditions 
  return H;
} 

string filename(int spins){
  stringstream ss;
  ss << spins;
  string str = ss.str();

  string file= string("data/") + "data"+str+".dat";

  if(exists(file)){
 //  cout << "file named "<<file<<" exists"<<endl; 
   return "stop";
  } else{ return file;}
}



double run(int spins,double a,double b){
  time_t timer;
  time_t timer1;
  time(&timer);

  int n=pow(static_cast<double>(2),spins);  
  
  
  string file = filename(spins);
  if (file=="stop"){
    return 0;
  }
   
  ofstream myfile;
  myfile.open(file.c_str()); //filename is a std::string, but the stream constructor wants a plain C-style string (pointer to char)
  myfile<<endl;
  
 // cout<<"spins are "<<spins<< " and n is "<<n<<endl;
  MatrixXd H=Ham(spins,a,b); 
  if(spins<4){
    cout<<H<<endl;
  } 
// EigenSolver<MatrixXd> solution(H);
  SelfAdjointEigenSolver<MatrixXd> solution(H);
  time(&timer1);
  double seconds=difftime(timer1,timer);
//  cout<<"solution made at"<< " time="<<seconds<<endl;
  myfile<< "it took "<<seconds<<" seconds."<<endl;

  VectorXd evals= solution.eigenvalues();
 //maybe but VectorXcd
  float smallest=0;
  int state=0;
  for (int k=0;k<n;k++){
    if (evals(k)<=smallest+1){
  //    cout<<" close one at e= "<<evals(k)<< " and state "<<k<<endl;   
      myfile<<" close one at e= "<<evals(k)<< " and state "<<k<<endl;   
    }
    if (evals(k)<=smallest){
      smallest=evals(k);
      state=k;
   //   cout<<" new gs energy = "<< smallest<< " at state "<<state<<endl;
      myfile<<" new gs energy = "<< smallest<< " at state "<<state<<endl;}
  } 
 // cout<<endl<<"ground state energy " <<smallest<<endl; 
 // cout<<"state= "<< state <<endl;//<<solution.eigenvectors().col(state)<<endl<<endl;
  
  //myfile<<"these are the eigen values "<<endl<<evals<<endl<<endl;   
 // myfile<<"these are the eigen vectors "<<endl;
 // for (int q=0;q<n;q++){
  //  myfile<<endl<<solution.eigenvectors().col(state)<<endl;
 // }

  myfile.close();
  return smallest;
}

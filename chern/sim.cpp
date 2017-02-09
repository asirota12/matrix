#include <iostream>
#include <Eigen/Eigenvalues>
#include <Eigen/Dense>
#include <fstream>
#include <complex>
#include <functions.h>

using namespace Eigen;
using namespace std;

int main()
{
//making my matrix set up
  int n=50;
  MatrixXd H(2*n,2*n);
   
//opening my file
  ofstream myfile;
  ofstream vectfile;
  vectfile.open("vectors.dat");
  myfile.open("values.dat");
  myfile<<endl;
  vectfile<<endl;
  double m=1.0;
  double e=-1.5;
  double t=1.0; 
// making my set of k's to plug into m
  double pi=3.14159;
  int q=61;
  double factor=(double) q  -1.0;
  factor= factor/2.0;
  factor= 1.0/factor;  
  double array[q];
  for(int l=0;l<q;l++){
    array[l]=-pi+pi*factor*l;
  }
//for each k make a whole matrix
  for(int i=0;i<q;i++){
    double x=array[i];
//first 2 lines have 4 elements
    H(0,0)=m+2*e-e*cos(x);
    H(0,1)=t*sin(x);
    H(0,2)=-e/2;
    H(0,3)=t/2;
    H(1,0)=t*sin(x);
    H(1,1)=-m-2*e+e*cos(x);
    H(1,2)=-t/2;
    H(1,3)=e/2;
//most have 6
    for (int a=2;a<(2*n-2);a=a+2){
      H(a,a-2)=-e/2;
      H(a,a-1)=-t/2;
      H(a,a)=m+2*e-e*cos(x);
      H(a,a+1)=t*sin(x);
      H(a,a+2)=-e/2;
      H(a,a+3)=t/2;

      H(a+1,a-2)=t/2;
      H(a+1,a-1)=e/2;
      H(a+1,a)=t*sin(x);
      H(a+1,a+1)=-m+-2*e+e*cos(x);
      H(a+1,a+2)=-t/2;
      H(a+1,a+3)=e/2;
    }
//last 2 lines have 4
    H(2*n-2,2*n-4)=-e/2;
    H(2*n-2,2*n-3)=-t/2;
    H(2*n-2,2*n-2)=m+2*e-e*cos(x);
    H(2*n-2,2*n-1)=t*sin(x);
    H(2*n-1,2*n-4)=t/2;
    H(2*n-1,2*n-3)=e/2;
    H(2*n-1,2*n-2)=t*sin(x);
    H(2*n-1,2*n-1)=-m-2*e+e*cos(x);
    
    VectorXcd evals= H.eigenvalues();
    if(((q-1)/2)==i){
      EigenSolver<MatrixXd> h(H);
      for (int p=0;p<2*n;p++){
        if((h.eigenvalues().cwiseAbs()(p,0))<.1){
          vectfile<<h.eigenvectors().cwiseAbs().col(p)<<endl<<endl<<endl;
        }
      } 
    }
   // print my evals for each matrix 
    for(int j=0;j<2*n;j++){ 
      myfile<<x<<"	"<<evals(j)<<endl;
    } 
  }
  myfile.close(); 
  process();
  splitfile();
}


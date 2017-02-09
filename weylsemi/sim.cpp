#include <iostream>
#include <Eigen/Eigenvalues>
#include <Eigen/Dense>
#include <fstream>
#include <complex>
#include <functions.h>
#include <math.h>
#include <time.h>

using namespace Eigen;
using namespace std;

int main()
{
  time_t timer;
  time_t timer1;
  time(&timer);
//making my matrix set up
  int n=80;

  MatrixXcd H(2*n,2*n);
   
//opening my file
  ofstream myfile;
  ofstream vectfile;
  vectfile.open("vectors.dat");
  myfile.open("values.dat");
  myfile<<endl;
  vectfile<<endl;
  double t1=1.0;
  double t2=1.0;
  double v=1.0; 
  double kz=0;
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
    complex<double> a (v*kz,0);
    complex<double> amin (-v*kz,0);
    complex<double> b (t2*cos(x),t1-t2*sin(x));
    complex<double> bdag (t2*cos(x),-t1+t2*sin(x));
    complex<double> c (t2+t1*sin(x),t1*cos(x));
    complex<double> cdag (t2+t1*sin(x),-t1*cos(x));
    
    H(0,0)=a;
    H(0,1)=b;
    H(0,2)=0;
    H(0,3)=c;
    H(1,0)=bdag;
    H(1,1)=amin;
    H(1,2)=0;
    H(1,3)=0;
//most have 6
    for (int a=2;a<(2*n-2);a=a+2){
      H(a,a-2)=0;
      H(a,a-1)=0;
      H(a,a)=a;
      H(a,a+1)=b;
      H(a,a+2)=0;
      H(a,a+3)=c;

      H(a+1,a-2)=cdag;
      H(a+1,a-1)=0;
      H(a+1,a)=bdag;
      H(a+1,a+1)=amin;
      H(a+1,a+2)=0;
      H(a+1,a+3)=0;
    }
//last 2 lines have 4
    H(2*n-2,2*n-4)=0;
    H(2*n-2,2*n-3)=0;
    H(2*n-2,2*n-2)=a;
    H(2*n-2,2*n-1)=b;
    H(2*n-1,2*n-4)=cdag;
    H(2*n-1,2*n-3)=0;
    H(2*n-1,2*n-2)=bdag;
    H(2*n-1,2*n-1)=amin;
    
    VectorXcd evals= H.eigenvalues();
    if(((q-1)/2)==i){
      ComplexEigenSolver<MatrixXcd> h(H);
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
  time(&timer1);
  double seconds=difftime(timer1,timer);
  cout<<" n="<<n<< " time="<<seconds<<endl;
}


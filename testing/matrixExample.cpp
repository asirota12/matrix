#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include <fstream>
#include <string>
#include <complex>

using namespace std;
using namespace Eigen;

int main(){
// initialization of matrix and complex numbers 
  MatrixXcd  H(2,2);
// (a,b) =a+bi

// have to initialize seperately. if you do it in the matrix it will cut off the imaginary part
  complex<double> a (0,0);
  complex<double> b (0,-1);
  complex<double> c (0,1);
  complex<double> d (0,0);
 
  H(0,0)=a;
  H(1,0)=b;
  H(0,1)=c;
  H(1,1)=d; 

  
//H is output as a matrix 
  cout<<"H= "<<endl<<H<<endl<<endl;

  cout<<"H.imag()=  "<<endl<<H.imag()<<endl<<endl;

  cout<<"H.real()=  "<<endl<<H.real()<<endl<<endl;
//cwiseAbs() just takes the absolute value of a complex number component by component
  cout<<"H.cwiseAbs()= "<<endl<<H.cwiseAbs()<<endl<<endl;
// an object that contains vectors and values of H
  ComplexEigenSolver<MatrixXcd> solution(H);
 
 
  VectorXcd evals= solution.eigenvalues();
  
  cout<<"eigenvalues="<<endl<<evals(0).real()<<" + "<<evals(0).imag()<<"i"<<endl;
  cout<<evals(1).real()<<" + "<<evals(1).imag()<<"i"<<endl; 
  cout<<"eigenvectors= " <<endl<<solution.eigenvectors()<<endl<<endl;
}

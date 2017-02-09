(* ::Package:: *)


w=Exp[2*Pi*I/3];
X= SparseArray[{{0,0,1},{1,0,0},{0,1,0}}];
Z= SparseArray[{{1,0,0},{0,w,0},{0,0,w^2}}];
Id1=SparseArray[{Band[{1,1}] -> 1  },3];
Id2=SparseArray[{Band[{1,1}] -> 1  },3^2];
Id3=SparseArray[{Band[{1,1}] -> 1  },3^3];
Id4=SparseArray[{Band[{1,1}] -> 1  },3^4];
Id5=SparseArray[{Band[{1,1}] -> 1  },3^5];
Id6=SparseArray[{Band[{1,1}] -> 1  },3^6];
Id7=SparseArray[{Band[{1,1}] -> 1  },3^7];
Id8=SparseArray[{Band[{1,1}] -> 1  },3^8];
Id9=SparseArray[{Band[{1,1}] -> 1  },3^9];







H=KroneckerProduct[Z,Z,Id7];
H=H+KroneckerProduct[Id1,Z,Z,Id6];
H=H+KroneckerProduct[Id2,Z,Z,Id5];
H=H+KroneckerProduct[Id3,Z,Z,Id4];
H=H+KroneckerProduct[Id4,Z,Z,Id3];
H=H+KroneckerProduct[Id5,Z,Z,Id2];
H=H+KroneckerProduct[Id6,Z,Z,Id1];
H=H+KroneckerProduct[Id7,Z,Z];
H=H+KroneckerProduct[Z,Id7,Z];


H=H+KroneckerProduct[X,Id8];
H=H+KroneckerProduct[Id1,X,Id7];
H=H+KroneckerProduct[Id2,X,Id6];
H=H+KroneckerProduct[Id3,X,Id5];
H=H+KroneckerProduct[Id4,X,Id4];
H=H+KroneckerProduct[Id5,X,Id3];
H=H+KroneckerProduct[Id6,X,Id2];
H=H+KroneckerProduct[Id7,X,Id1];
H=H+KroneckerProduct[Id8,X];

H=H+ConjugateTranspose[H] 
file= OpenWrite["../Desktop/Z3Potts/test.txt"];
Close["../Desktop/Z3Potts/test.txt"];



Eigenvalues[H,Method->{"FEAST","Interval"->{-20,-10}}]//N




(* ::Package:: *)

Timing[X= SparseArray[PauliMatrix[1]];
Z= SparseArray[PauliMatrix[3]];
Id1=SparseArray[{Band[{1,1}] -> 1  },2^1];
Id2=SparseArray[{Band[{1,1}] -> 1  },2^2];
Id3=SparseArray[{Band[{1,1}] -> 1  },2^3];
Id4=SparseArray[{Band[{1,1}] -> 1  },2^4];
Id5=SparseArray[{Band[{1,1}] -> 1  },2^5];
Id6=SparseArray[{Band[{1,1}] -> 1  },2^6];
Id7=SparseArray[{Band[{1,1}] -> 1  },2^7];
Id8=SparseArray[{Band[{1,1}] -> 1  },2^8];
Id9=SparseArray[{Band[{1,1}] -> 1  },2^9];
Id10=SparseArray[{Band[{1,1}] -> 1  },2^10];
Id11=SparseArray[{Band[{1,1}] -> 1  },2^11];
Id12=SparseArray[{Band[{1,1}] -> 1  },2^12];
Id13=SparseArray[{Band[{1,1}] -> 1  },2^13];
Id14=SparseArray[{Band[{1,1}] -> 1  },2^14];
Id15=SparseArray[{Band[{1,1}] -> 1  },2^15];
Id16=SparseArray[{Band[{1,1}] -> 1  },2^16];
Id17=SparseArray[{Band[{1,1}] -> 1  },2^17];
Id18=SparseArray[{Band[{1,1}] -> 1  },2^18];
Id19=SparseArray[{Band[{1,1}] -> 1  },2^19];
Id20=SparseArray[{Band[{1,1}] -> 1  },2^20];
Id21=SparseArray[{Band[{1,1}] -> 1  },2^21];]



Timing[
H=KroneckerProduct[Z,Z,Id20];
H=H+KroneckerProduct[Id1,Z,Z,Id19];
H=H+KroneckerProduct[Id2,Z,Z,Id18];
H=H+KroneckerProduct[Id3,Z,Z,Id17];
H=H+KroneckerProduct[Id4,Z,Z,Id16];
H=H+KroneckerProduct[Id5,Z,Z,Id15];
H=H+KroneckerProduct[Id6,Z,Z,Id14];
H=H+KroneckerProduct[Id7,Z,Z,Id13];
H=H+KroneckerProduct[Id8,Z,Z,Id12];
H=H+KroneckerProduct[Id9,Z,Z,Id11];
H=H+KroneckerProduct[Id10,Z,Z,Id10];
H=H+KroneckerProduct[Id11,Z,Z,Id9];
H=H+KroneckerProduct[Id12,Z,Z,Id8];
H=H+KroneckerProduct[Id13,Z,Z,Id7];
H=H+KroneckerProduct[Id14,Z,Z,Id6];
H=H+KroneckerProduct[Id15,Z,Z,Id5];
H=H+KroneckerProduct[Id16,Z,Z,Id4];
H=H+KroneckerProduct[Id17,Z,Z,Id3];
H=H+KroneckerProduct[Id18,Z,Z,Id2];
H=H+KroneckerProduct[Id19,Z,Z,Id1];
H=H+KroneckerProduct[Id20,Z,Z];
H=H+KroneckerProduct[Z,Id20,Z];

H=H+KroneckerProduct[X,Id21];
H=H+KroneckerProduct[Id1,X,Id20];H=H+KroneckerProduct[Id2,X,Id19];H=H+KroneckerProduct[Id3,X,Id18];H=H+KroneckerProduct[Id4,X,Id17];H=H+KroneckerProduct[Id5,X,Id16];H=H+KroneckerProduct[Id6,X,Id15];H=H+KroneckerProduct[Id7,X,Id14];H=H+KroneckerProduct[Id8,X,Id13];H=H+KroneckerProduct[Id9,X,Id12];H=H+KroneckerProduct[Id10,X,Id11];H=H+KroneckerProduct[Id11,X,Id10];
H=H+KroneckerProduct[Id12,X,Id9];
H=H+KroneckerProduct[Id13,X,Id8];
H=H+KroneckerProduct[Id14,X,Id7];
H=H+KroneckerProduct[Id15,X,Id6];
H=H+KroneckerProduct[Id16,X,Id5];
H=H+KroneckerProduct[Id17,X,Id4];
H=H+KroneckerProduct[Id18,X,Id3];
H=H+KroneckerProduct[Id19,X,Id2];
H=H+KroneckerProduct[Id20,X,Id1];
H=H+KroneckerProduct[Id21,X];
ham=SparseArray[H];]



Timing[Eigenvalues[ham,2, Method->"Arnoldi"]//N]

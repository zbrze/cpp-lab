#include <iostream>

using namespace std;

#include "matrix.h"

TwoDimensionMatrix :: TwoDimensionMatrix(const TwoDimensionMatrix& org) {
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                matrixTab[i][j] = org.matrixTab[i][j];
    }



TwoDimensionMatrix :: TwoDimensionMatrix(const MatrixElement matrix[size][size]) {
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            matrixTab[i][j]= matrix[i][j];
    }

ostream& operator<<(ostream& o, const TwoDimensionMatrix& matrix) {
    for(int i = 0; i < matrix.size; i++) {
        for(int j = 0; j < matrix.size; j++)
            o << matrix.get(i, j) << " ";
        o<<endl;
    }
    return o;
}

MatrixElement TwoDimensionMatrix :: get(int row, int col) const{
	 return matrixTab[row][col]; 
}


TwoDimensionMatrix& TwoDimensionMatrix :: operator*= (MatrixElement number){
     for(int i = 0; i < size; i++){
       for(int j = 0; j < size; j++){
          matrixTab[i][j] = (matrixTab[i][j] * number);
       }
   }
}

MatrixElement* TwoDimensionMatrix :: operator[](int i) {
        return matrixTab[i];
    }


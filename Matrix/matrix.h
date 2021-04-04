#ifndef MATRIX_H
#define MATRIX_H


#include <iosfwd>

#include "matrixElement.h"


class TwoDimensionMatrix
{
    static const int size = 2;
    MatrixElement matrixTab[size][size];
    
public:
    //konstruktory
    TwoDimensionMatrix() : matrixTab{{0}} {}
    TwoDimensionMatrix(const TwoDimensionMatrix& matrix); 
    TwoDimensionMatrix(const MatrixElement matrix[size][size]);

    MatrixElement get(int row, int col) const;
    constexpr int getSize() const {return size;};

    friend std::ostream& operator<<(std::ostream& o, const TwoDimensionMatrix& matrix); //friend std::ostream& operator<< (std::ostream& o, const TwoDimensionMatrix& mx);
    TwoDimensionMatrix& operator*=(MatrixElement number);
    TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
    MatrixElement* operator[](int i);
    constexpr explicit operator size_t() const {return getSize();}
};

TwoDimensionMatrix operator+ (const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2){    
    MatrixElement matrix3[matrix2.getSize()][matrix2.getSize()];
   for(int i = 0; i < matrix2.getSize(); i++){
       for(int j = 0; j < matrix2.getSize(); j++){
          matrix3[i][j] = (matrix1.get(i, j) + matrix2.get(i, j));
       }
   }
   TwoDimensionMatrix *sum = new TwoDimensionMatrix(matrix3);
   return *sum;
}
 #endif

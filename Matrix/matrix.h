#ifndef MATRIX_H
#define MATRIX_H

/** Tresc zadania:
Ćw2 [16pkt] Przeciążanie operatorów w C++
Plan zajęć:
    Proszę uzupełnić dane w pliku programmerDetails.h

    Zaimplementuj klasę TwoDimensionMatrix odzwierciedlajaca macierz 2*2, zawierającą:
           - A tablice typu MatrixElement (tzn. int), oraz size (=2)
           - konstruktory:
             - bezargumentowy - zerujący wszystkie elementy
             - kopiujący
             - przyjmujący jako argument tablicę (const MatrixElement matrix[size][size]) i kopiujący z niej wartości
           - funkcja składowa do dostępu do elementów (get() zwracająca odpowiedni element
           - funkcja zwracająca size o nazwie (getSize()), proponuję aby była static constexpr
    Uzupełnij klasy o następujące operacje zdefiniowane poprzez przeciążenie operatorów:
        - A operatory wypisywania do strumienia (funkcja zewn.) - forma dowolna, byleby wszystkie elementy były w strumieniu
        - operatory arytmetyczne (stosujące odpowiednie operacje na macierzach):
           A TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2); // jako funkcja globalna
           A TwoDimensionMatrix& operator*=(MatrixElement number); // metoda klasy
        - zadany operator logiczny (metoda klasy),
           A TwoDimensionMatrix operator&&(const TwoDimensionMatrix& matrix) const;
        - operator tablicowy dostający się po indeksie do pierwszego z wymiarów tablicy (metoda klasy), proszę pamiętać o wersji const
            MatrixElement* operator[](size_t i);
        - operator konwersji do size_t, zwracający to co getSize() (metoda klasy),
    Deklaracja klasy i funkcji globalnych powinna się znaleźć w pliku "matrix.h", natomiast definicje funkcji zewnętrznych i metod klas w pliku źródłowym "matrix.cpp"

Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

Punktacja zdalna: (jak ktoś się nie zgadza proszę o informacje, wtedy ocenimy wg punktacji z treści zadania):
- do 9p: przejście wszystkich testów automatycznych
- 1p: wszystkie atrybuty powinny być prywatne
- 1p: konstruktory i metody - publiczne
- 1p: metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane poza klasą
- 1p: obiekty typów klasowych powinny być w miarę możliwości przekazywane w argumentach funkcji przez referencję
- 1p: proszę też stosować słówko "const" w odpowiednich miejscach
- 1p: ogólna estetyka/czytelność kodu
- 1p: podział na pliki matrix.h i matrix.cpp
**/

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
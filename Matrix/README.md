# Matrix
## Tresc zadania:
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

## Uwaga:
Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne,
metody większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane
poza klasą, obiekty typów klasowych powinny być w miarę możliwości przekazywane
w argumentach funkcji przez referencję, proszę też stosować słówko "const" w
odpowiednich miejscach.

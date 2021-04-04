#ifndef FRACTION_H
#define FRACTION_H

/** Implementacja ulamka:
[3pkt] Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
[1pkt] Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
[1pkt] Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/
#include <iosfwd>
#include<stdexcept>

class Fraction
{
       int numerator;
       int denominator;

public:
       Fraction(int numerator = 0, int denominator = 1);
       int getNumerator() const { return numerator; };
       int getDenominator() const { return denominator; };
       void setNumerator(int x) { this->numerator = x;};
       void setDenominator(int x);

       Fraction operator+(const Fraction other) const;
       Fraction operator*(const Fraction other) const;
};
#endif // FRACTION_H

 
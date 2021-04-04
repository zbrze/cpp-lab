#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include "fraction.h"
#include "utils/memoryManagement.h"

using namespace std;

class Vector
{
    Fraction *data;
    int _size;
    int _capacity;

public:
    Vector(int capacity = 0); //konstruktor
    Vector(Vector& source); //konstruktor kopiujący
    Vector(Vector&& other); //konstruktor przenoszący
    ~Vector();  //destruktor
    int size() const {return _size;};
    int capacity() const {return _capacity;};
    void push_back(const Fraction obj);
    Vector& operator=(Vector&& other);    //przenoszący operator podstawienia
    Fraction operator[](int index) const;
    Vector& operator=( Vector& other); //operator podstawienia

};
#endif // VECTOR_H

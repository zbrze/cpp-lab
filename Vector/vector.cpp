#include "vector.h"
#include<stdexcept>
#include<iostream>



Vector :: ~Vector(){	//destruktor
	delete[] data;
	_size = 0;
	_capacity = 0;
}

Vector :: Vector(int capacity){
	data = (Fraction*) calloc (_capacity,sizeof(Fraction));
    _capacity =capacity; 
    _size= 0; 

}


Vector :: Vector( Vector& source){	//konstruktor głęboko kopiujący
	delete[] data;
	_size = source.size();
	_capacity = source.capacity();
if(source.data){
	data = (Fraction*) calloc (_capacity,sizeof(Fraction));

	for(int i = 0; i < _size; i++){
		data[i] = source.data[i];
		}
	}else{
		data = nullptr;
	}	
}


Vector :: Vector(Vector&& other){	//konstruktor przenoszący
	data = nullptr;
	_capacity = 0;
	_size = 0;
	data = other.data;
	_size = other.size();
	_capacity = other.capacity();
	other.data = nullptr;
	other._capacity = 0;
	other._size = 0;
}

Vector& Vector :: operator=(Vector&& other){	//przenoszący operator podstawienia
	if(this !=& other){
		delete[] data;
		data = other.data;
		_size = other.size();
		_capacity = other.capacity();
		other.data = nullptr;
		other._size = 0;
		other._capacity = 0;
	}
	return *this;
}

Vector& Vector :: operator=(Vector& other){	//operator podstawienia
	if(this != &other){
		Fraction *new_data;
		new_data = (Fraction*) calloc (other._capacity,sizeof(Fraction));
		std :: copy(other.data, other.data + other._size, new_data);
		data = new_data;
		_size = other._size;
		_capacity = other._capacity;
	}
	return *this;
  }

Fraction Vector :: operator[](int index) const{
	if(index >= _size){
		throw std::out_of_range("Index > size");
	}
	return data[index];
}

void Vector :: push_back(Fraction obj){
	if(_capacity == _size){
		Fraction *new_data;
		new_data = (Fraction*) calloc (_capacity + 1,sizeof(Fraction));
		for (int i = 0; i < _capacity; i++)
		{
			new_data[i] = data[i];
		}
		delete[] data;
		_capacity = _capacity+1;
		data = new_data;
	}
	data[_size] = obj;
	_size++;
}

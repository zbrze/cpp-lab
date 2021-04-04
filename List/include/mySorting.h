#include<stdexcept>
#include<iostream>
#include<memory>
#include<forward_list>
#include <type_traits>
#include <string.h>
#include "mylist.h"
using std::unique_ptr;


template <class T>
    static void mySort(T &arr) {
    int size_m = std::size(arr);
    for (int i = 0; i < size_m; i++) {
        for (int j = 0; j < size_m - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}





template <typename T>
void mySort(MyList<T> &list) {
    int length = list.size();
    for(int i=0; i<length; i++) {
        auto next = list.begin();
        ++next;
        auto iterator = list.begin();
        while (next != list.end()) {
            if (*iterator > *next) {
                std::swap(*iterator, *next);
            }
            ++iterator;
            ++next;
        }
    }
}
bool compare_string(char* a,  char* b, int size_a, int size_b){
    for(int i = 0; i < size_a; i++){
        if(i <= size_b) {
            if (tolower(a[i]) > tolower(b[i])) return true;
            if (tolower(a[i]) < tolower(b[i])) return false;
        }else{
            return true;
        }
    }
    return false;
}
template <int size_m, int size_s>
    static void mySort(char (&arr)[size_m][size_s]) {
    for (int j = 0; j < size_m; j++)
    {
        for (int i = j + 1; i <  size_m- 1; i++)
        {
            char tmp_a[size_s], tmp_b[size_s];
            int size_a = snprintf(tmp_a,size_m+1, "%s",arr[j]);
            int size_b = snprintf(tmp_b, size_m+1, "%s",arr[i]);
            if (compare_string(arr[j], arr[i],size_a, size_b))
            {

                for (int k = 0; k < size_s; k++) {
                    std::swap(arr[j][k], arr[i][k]);
                }
                }
            }
    }
}


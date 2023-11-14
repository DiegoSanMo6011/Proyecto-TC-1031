/*
 *
 * Proyecto "Gestión de Vendedores y Ventas" calse 
 * 
 * Diego Gerardo Sanchez Moreno
 * 
 * A01276011
 * 
 * 19/09/2023
 * 
 * 
 * 
 * 
 * Clase Sort que contiene un merge sort 
 */



#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T> class Sort {

private:
  void copyArray(std::vector<T> &, std::vector<T> &, int, int);
  void mergeArray(std::vector<T> &, std::vector<T> &, int, int, int);
  void mergeSplit(std::vector<T> &, std::vector<T> &, int, int);

public:

  std::vector<T> MergeSort(std::vector<T> &);

};



// Merge sort
template <class T> std::vector<T> Sort<T>::MergeSort(std::vector<T> &v) {

  std::vector<T> tmp(v.size());

  mergeSplit(v, tmp, 0, v.size() - 1);

  return v;
}

template <class T>
void Sort<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low,
                          int high) {
  if (high > low) {
    int mid = (low + high) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
  }
}

template <class T>
void Sort<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low,
                          int mid, int high) {

  int pos_1a_parte = low;
  int fin_1a_parte = mid;
  int pos_2da_parte = mid + 1;
  int fin_2da_parte = high;

  for (int i = pos_1a_parte; i <= fin_2da_parte; i++) {
    if ((A[pos_1a_parte] < A[pos_2da_parte] && pos_1a_parte <= fin_1a_parte) ||
        pos_2da_parte > fin_2da_parte) {
      B[i] = A[pos_1a_parte];
      pos_1a_parte++;
    } else {
      B[i] = A[pos_2da_parte];
      pos_2da_parte++;
    }
  }

  copyArray(A, B, low, high);
}

template <class T>
void Sort<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low,
                         int high) {
  for (int i = low; i <= high; i++) {
    A[i] = B[i];
  }
}



#endif // SORT_H_
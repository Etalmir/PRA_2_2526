#ifndef DYV_H
#define DYV_H
#include <vector>

template <typename T>
int binarySearch(const std::vector<T>& arr, T e) {
    int izq = 0;
    int der = arr.size() - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == e) {
            return mid; // Elemento encontrado
        } 
        else if (arr[mid] < e) {
            izq = mid + 1; // Buscamos en la mitad derecha
        } 
        else {
            der = mid - 1; // Buscamos en la mitad izquierda
        }
    }
    return -1; // Elemento no encontrado
}

template <typename T>
int binarySearchRecursive(const std::vector<T>& arr, const T& e, int izq, int der) {
    if (izq > der) {
        return -1; // Elemento no encontrado
    }
    int mid = izq + (der - izq) / 2;
    if (arr[mid] == e) {
        return mid; // Elemento encontrado
    } 
    else if (arr[mid] < e) {
        return binarySearchRecursive(arr, e, mid + 1, der); // Buscamos en la mitad derecha
    } 
    else {
        return binarySearchRecursive(arr, e, izq, mid - 1); // Buscamos en la mitad izquierda
    }
}

template <typename T>
int binarySearchINV(const std::vector<T>& arr, const T& e) {
    int izq = 0;
    int der = arr.size() - 1;
    while (izq <= der) {
        int mid = izq + (der - izq) / 2;
        if (arr[mid] == e) {
            return mid; // Elemento encontrado
        } 
        // Igual que antes, pero invertimos las condiciones
        else if (arr[mid] > e) {
            izq = mid + 1; // Buscamos en la mitad derecha
        } 
        else {
            der = mid - 1; // Buscamos en la mitad izquierda
        }
    }
    return -1; // Elemento no encontrado
}

template <typename T>
int binarySearchRecursiveINV(const std::vector<T>& arr, const T& e, int izq, int der) {
    if (izq > der) {
        return -1; // Elemento no encontrado
    }
    int mid = izq + (der - izq) / 2;
    if (arr[mid] == e) {
        return mid; // Elemento encontrado
    } 
    else if (arr[mid] > e) {
        return binarySearchRecursive(arr, e, mid + 1, der); // Buscamos en la mitad derecha
    } 
    else {
        return binarySearchRecursive(arr, e, izq, mid - 1); // Buscamos en la mitad izquierda
    }
}

#endif
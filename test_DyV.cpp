#include "DyV.h"
#include <iostream>
#include <vector>
#include<chrono>

int main() {
    // Creamos tres tipos de vectores diferentes para probar las funciones
    std::vector<int> vecInt = {1, 3, 5, 7, 9, 11, 13, 15};
    std::vector<double> vecDouble = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5};
    std::vector<char> vecChar = {'a', 'c', 'e', 'g', 'i', 'k', 'm'};

    // Probamos las funciones de búsqueda binaria no recursivas
    int indexInt = binarySearch(vecInt, 7);
    int indexDouble = binarySearch(vecDouble, 3.5);
    int indexChar = binarySearch(vecChar, 'e');

    // Printeamos los resultados
    std::cout << "Busqueda binaria no recursiva con int: " << indexInt << std::endl;
    std::cout << "Busqueda binaria no recursiva con double: " << indexDouble << std::endl;
    std::cout << "Busqueda binaria no recursiva con char: " << indexChar << std::endl;

    // Probamos las funciones de búsqueda binaria recursivas
    indexInt = binarySearchRecursive(vecInt, 11, 0, vecInt.size() - 1);
    indexDouble = binarySearchRecursive(vecDouble, 0.5, 0, vecDouble.size() - 1);
    indexChar = binarySearchRecursive(vecChar, 'k', 0, vecChar.size() - 1);

    // Printeamos los resultados
    std::cout << "Busqueda binaria recursiva con int: " << indexInt << std::endl;
    std::cout << "Busqueda binaria recursiva con double: " << indexDouble << std::endl;
    std::cout << "Busqueda binaria recursiva con char: " << indexChar << std::endl;

    // Probamos las funciones de búsqueda binaria no recursivas invertidas
    // Primero invertimos los vectores
    // Usamos rbegin() y rend() para crear vectores invertidos, rbegin() apunta al último elemento y rend() al antes del primero
    std::vector<int> vecIntInv(vecInt.rbegin(), vecInt.rend());
    std::vector<double> vecDoubleInv(vecDouble.rbegin(), vecDouble.rend());
    std::vector<char> vecCharInv(vecChar.rbegin(), vecChar.rend());

    indexInt = binarySearchINV(vecIntInv, 7);
    indexDouble = binarySearchINV(vecDoubleInv, 3.5);
    indexChar = binarySearchINV(vecCharInv, 'e');

    // Printeamos los resultados
    std::cout << "Busqueda binaria no recursiva invertida con int: " << indexInt << std::endl;
    std::cout << "Busqueda binaria no recursiva invertida con double: " << indexDouble << std::endl;
    std::cout << "Busqueda binaria no recursiva invertida con char: " << indexChar << std::endl;

    // Añadimos vectores int, double y char desordenados para probar el quickSort
    std::vector<int> vecIntUnsorted = {15, 3, 9, 1, 7, 11, 5, 13};
    std::vector<double> vecDoubleUnsorted = {4.5, 1.5, 5.5, 0.5, 3.5, 2.5};
    std::vector<char> vecCharUnsorted = {'m', 'c', 'i', 'a', 'g', 'e', 'k'};

    auto start = std::chrono::system_clock::now();
    quickSort(vecIntUnsorted, 0, vecIntUnsorted.size() - 1);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> duracion = end - start;
    std::cout << "Tiempo de quickSort con int: " << duracion.count() << "s\n";

    start = std::chrono::system_clock::now();
    quickSort(vecDoubleUnsorted, 0, vecDoubleUnsorted.size() - 1);
    end = std::chrono::system_clock::now();
    duracion = end - start;
    std::cout << "Tiempo de quickSort con double: " << duracion.count() << "s\n";

    start = std::chrono::system_clock::now();
    quickSort(vecCharUnsorted, 0, vecCharUnsorted.size() - 1);
    end = std::chrono::system_clock::now();
    duracion = end - start;
    std::cout << "Tiempo de quickSort con char: " << duracion.count() << "s\n";

    return 0;
}
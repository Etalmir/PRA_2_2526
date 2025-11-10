#include <vector>
#include <climits>
#include <algorithm>

int min_cambio(const std::vector<int> &monedas, int cantidad, int n, std::vector<std::vector<int>> &mem){
    if (n < 0){
        return INT_MAX;
    }
    if (cantidad < 0){
        return INT_MAX - 10000; // Evitar overflow
    }
    if(mem[n][cantidad] != -1) return mem[n][cantidad];
    if(cantidad == 0){
        mem[n][cantidad] = 0;
        return mem[n][cantidad];
    }
    mem[n][cantidad] = std::min(min_cambio(monedas, cantidad - monedas[n], n, mem) + 1, min_cambio(monedas, cantidad, n - 1, mem));
    return mem[n][cantidad];
}
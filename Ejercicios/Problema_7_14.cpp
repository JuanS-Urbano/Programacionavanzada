#include <iostream>

using namespace std;

void invertirarreglo(int arreglo[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arreglo[i];
        arreglo[i] = arreglo[n - i - 1];
        arreglo[n - i - 1] = temp;
    }
}

int main() {
    const int tamanoarreglo = 10; 
    int numeros[tamanoarreglo];

    cout << "Ingrese " << tamanoarreglo << " números enteros:" << endl;
    for (int i = 0; i < tamanoarreglo; i++) {
        cin >> numeros[i];
    }

    invertirarreglo(numeros, tamanoarreglo);

    cout << "Arreglo invertido:" << std::endl;
    for (int i = 0; i < tamanoarreglo; i++) {
        cout << numeros[i] << " ";
    }

    return 0;
}

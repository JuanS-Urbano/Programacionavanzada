#include <iostream>

using namespace std;

double calcularMedia(const double numeros[], int tamano) {
    if (tamano <= 0) {
        cout << "Error: La lista de números está vacía." << endl;
        return 0.0;
    }

    double suma = 0.0;

    for (int i = 0; i < tamano; i++) {
        suma += numeros[i];
    }

    return suma / tamano;
}

int main() {
    const int MAX_NUMEROS = 100;  
    double listaNumeros[MAX_NUMEROS];

    int tamanoLista;

    cout << "Ingrese el tamaño de la lista de números: ";
    cin >> tamanoLista;

    if (tamanoLista > MAX_NUMEROS || tamanoLista <= 0) {
        cout << "Error: Tamaño de lista no válido." << endl;
        return 1; 
    }

    cout << "Ingrese la lista de números:" << endl;
    for (int i = 0; i < tamanoLista; i++) {
        cout << "Número " << i + 1 << ": ";
        cin >> listaNumeros[i];
    }

    double media = calcularMedia(listaNumeros, tamanoLista);

    cout << "La media aritmética de la lista es: " << media << endl;

    return 0;
}

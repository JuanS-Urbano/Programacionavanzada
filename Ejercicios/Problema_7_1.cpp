#include <iostream>

using namespace std;

int numeromano(char romano) {
    switch (romano) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
    }
}

int main() {  
  
    string numero;

    cout << "Ingrese un número romano: ";
    cin >> numero;

    int resultado = 0;
    int auxiliar = 0;

    for (int i = numero.size() - 1; i >= 0; i--) {
        int valoractual = numeromano(numero[i]);

        if (valoractual == 0) {
            cout << "Error: Carácter romano inválido." << endl;
            return 1;
        }

        if (valoractual < auxiliar) {
            resultado -= valoractual;
        } else {
            resultado += valoractual;
        }

          auxiliar = valoractual;
    }

    cout << "El número arábigo equivalente es: " << resultado << endl;

    return 0;
}
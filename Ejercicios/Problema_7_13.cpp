#include <iostream>

using namespace std;

string arabicoaromano(int arabico) {
    if (arabico <= 0 || arabico > 3999) {
        return "Error: Número fuera del rango permitido (1-3999)";
    }

    string romano = "";
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string simbolos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    for (int i = 0; i < 13; i++) {
        while (arabico >= valores[i]) {
            arabico -= valores[i];
            romano += simbolos[i];
        }
    }

    return romano;
}

int main() {
    int numero;

    cout << "Ingrese un número arábigo (1-3999): ";
    cin >> numero;

    string romanNumber = arabicoaromano(numero);

    cout << "El número romano equivalente es: " << romanNumber << endl;

    return 0;
}


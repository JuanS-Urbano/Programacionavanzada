#include <iostream>
#include <string>

using namespace std;

struct EquipoBaloncesto {
    string nombreequipo;
    int victorias;
    int derrotas;
    int perdidasbalon;
    int rebotescogidos;
    string mejoranotador;
    int triplesanotador;
};

struct EquipoFutbol {
    string nombreequipo;
    int victorias;
    int derrotas;
    int empates;
    int golesfavor;
    int golescontra;
    string goleador;
    int golesgoleador;
};

void introducirEquipoBaloncesto(EquipoBaloncesto &equipo) {
    cout << "Nombre del equipo: ";
    getline(cin, equipo.nombreequipo);
    cout << "Número de victorias: ";
    cin >> equipo.victorias;
    cout << "Número de derrotas: ";
    cin >> equipo.derrotas;
    cout << "Número de pérdidas de balón: ";
    cin >> equipo.perdidasbalon;
    cout << "Número de rebotes cogidos: ";
    cin >> equipo.rebotescogidos;
    cin.ignore();
    cout << "Nombre del mejor anotador de triples: ";
    getline(cin, equipo.mejoranotador);
    cout << "Número de triples del mejor triplista: ";
    cin >> equipo.triplesanotador;
}

void introducirEquipoFutbol(EquipoFutbol &equipo) {
    cout << "Nombre del equipo: ";
    getline(cin, equipo.nombreequipo);
    cout << "Número de victorias: ";
    cin >> equipo.victorias;
    cout << "Número de derrotas: ";
    cin >> equipo.derrotas;
    cout << "Número de empates: ";
    cin >> equipo.empates;
    cout << "Número de goles a favor: ";
    cin >> equipo.golesfavor;
    cout << "Número de goles en contra: ";
    cin >> equipo.golescontra;
    cin.ignore();
    cout << "Nombre del goleador del equipo: ";
    getline(cin, equipo.goleador);
    cout << "Número de goles del goleador: ";
    cin >> equipo.golesgoleador;
}

int main() {
    EquipoBaloncesto equipoBaloncesto;
    cout << "Introducir información del equipo de baloncesto:" << endl;
    introducirEquipoBaloncesto(equipoBaloncesto);

    EquipoFutbol equipoFutbol;
    cout << "\nIntroducir información del equipo de fútbol:" << endl;
    introducirEquipoFutbol(equipoFutbol);

    cout << "\nInformación del equipo de baloncesto:" << endl;
    cout << "Nombre del equipo: " << equipoBaloncesto.nombreequipo << endl;
    cout << "Número de victorias: " << equipoBaloncesto.victorias << endl;
    cout << "Número de derrotas: " << equipoBaloncesto.derrotas << endl;
    cout << "Número de pérdidas de balón: " << equipoBaloncesto.perdidasbalon << endl;
    cout << "Número de rebotes cogidos: " << equipoBaloncesto.rebotescogidos << endl;
    cout << "Nombre del mejor anotador de triples: " << equipoBaloncesto.mejoranotador << endl;
    cout << "Número de triples del mejor triplista: " << equipoBaloncesto.triplesanotador << endl;

    cout << "\nInformación del equipo de fútbol:" << endl;
    cout << "Nombre del equipo: " << equipoFutbol.nombreequipo << endl;
    cout << "Número de victorias: " << equipoFutbol.victorias << endl;
    cout << "Número de derrotas: " << equipoFutbol.derrotas << endl;
    cout << "Número de empates: " << equipoFutbol.empates << endl;
    cout << "Número de goles a favor: " << equipoFutbol.golesfavor << endl;
    cout << "Número de goles en contra: " << equipoFutbol.golescontra << endl;
    cout << "Nombre del goleador del equipo: " << equipoFutbol.goleador << endl;
    cout << "Número de goles del goleador: " << equipoFutbol.golesgoleador << endl;

    return 0;
}
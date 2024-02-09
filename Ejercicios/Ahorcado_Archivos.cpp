#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<string> cargarpalabras(const char *nombrearchivo) {
  vector<string> palabras;
  ifstream archivo(nombrearchivo);

  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo: " << nombrearchivo << endl;
    exit(EXIT_FAILURE);
  }

  string palabra;
  while (archivo >> palabra) {
    palabras.push_back(palabra);
  }

  archivo.close();
  return palabras;
}

string palabraleatoria(const vector<string> &palabras) {
  int adivinar = rand() % palabras.size();
  return palabras[adivinar];
}

void agregarpalabra(const string &palabra, const char *nombrearchivo) {
  ofstream archivo(nombrearchivo, ios::app);
  if (!archivo.is_open()) {
    cerr << "Error al abrir el archivo: " << nombrearchivo << endl;
    exit(EXIT_FAILURE);
  }

  archivo << palabra << endl;
  archivo.close();
}

void ahorcado(int intentosrestantes) {
  switch (intentosrestantes) {
  case 6:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 5:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 4:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << "  |   |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 3:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << " /|   |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 2:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << " /|\\  |\n";
    cout << "      |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 1:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << " /|\\  |\n";
    cout << " /    |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  case 0:
    cout << "  +---+\n";
    cout << "  |   |\n";
    cout << "  O   |\n";
    cout << " /|\\  |\n";
    cout << " / \\  |\n";
    cout << "      |\n";
    cout << "=========\n\n";
    break;
  }
}

int main() {

  srand(time(0));

  char opcion;
  cout << "¿Que deseas hacer?\n";
  cout << "1. Jugar\n";
  cout << "2. Agregar una nueva palabra al archivo\n";
  cout << "Selecciona 1 o 2: ";
  cin >> opcion;

  if (opcion == '1') {

    vector<string> palabras = cargarpalabras("palabras.txt");

    agregarpalabra("palabras.txt", "palabra");

    string palabrasecreta = palabraleatoria(palabras);

    string palabractual(palabrasecreta.length(), '_');

    int intentosrestantes = 6;

    char letra;

    cout << "Bienvenido al juego del ahorcado!\n";
    cout << "Tienes que adivinar la palabra secreta letra por letra.\n";
    cout << "Tienes " << intentosrestantes << " intentos para adivinarla.\n";

    while (intentosrestantes > 0) {

      ahorcado(intentosrestantes);

      cout << palabractual << "\n\n";
      cout << "Introduce una letra: ";
      cin >> letra;

      if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z')) {
        if (letra >= 'A' && letra <= 'Z') {
          letra = tolower(letra);
        }

        if (palabrasecreta.find(letra) != string::npos) {
          cout << "Bien hecho! La letra " << letra << " está en la palabra.\n";

          for (int i = 0; i < palabrasecreta.length(); i++) {
            if (palabrasecreta[i] == letra) {
              palabractual[i] = letra;
            }
          }

          if (palabractual == palabrasecreta) {

            ahorcado(intentosrestantes);

            cout << palabractual << "\n\n";
            cout << "Felicidades! Has adivinado la palabra: " << palabrasecreta
                 << "\n";
            cout << "Has ganado el juego!\n";
            break;
          }
        } else {

          cout << "Lo siento, la letra " << letra
               << " no está en la palabra.\n";
          intentosrestantes--;

          if (intentosrestantes == 0) {
            ahorcado(intentosrestantes);

            cout << palabractual << "\n\n";
            cout << "Has perdido el juego!\n";
            cout << "La palabra secreta era: " << palabrasecreta << "\n";
            break;
          }
        }
      } else {
        cout << "Por favor, introduce una letra válida.\n";
      }
    }
  } else if (opcion == '2') {

    string palabra;
    cout << "Introduce la palabra que deseas agregar: ";
    cin >> palabra;

    agregarpalabra(palabra, "palabras.txt");
    cout << "La palabra ha sido agregada al archivo.\n";

  } else {

    cout << "Opción inválida. Hasta luego.\n";
  }
  return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

const char* palabras[] = {"programacion", "ahorcado", "juegos", "frutas", "animales"};

string palabraleatoria()
{
    int adivinar = rand() % (sizeof(palabras) / sizeof(palabras[0]));
    return palabras[adivinar];
}

void ahorcado(int intentosrestantes)
{
    switch (intentosrestantes)
    {
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

int main()
{
    
    srand(time(0));

    string palabrasecreta = palabraleatoria();

    string palabractual(palabrasecreta.length(), '_');

    int intentosrestantes = 6;

    char letra;

    cout << "Bienvenido al juego del ahorcado!\n";
    cout << "Tienes que adivinar la palabra secreta letra por letra.\n";
    cout << "Tienes " << intentosrestantes << " intentos para adivinarla.\n";

    while (intentosrestantes > 0)
    {
        
        ahorcado(intentosrestantes);

        cout << palabractual << "\n\n";
        cout << "Introduce una letra: ";
        cin >> letra;

          if ((letra >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z'))
            {
                if (letra >= 'A' && letra <= 'Z')
                {
                    letra = tolower(letra);
                }
              
            if (palabrasecreta.find(letra) != string::npos)
            {
                cout << "Bien hecho! La letra " << letra << " está en la palabra.\n";

                for (int i = 0; i < palabrasecreta.length(); i++)
                {
                    if (palabrasecreta[i] == letra)
                    {
                        palabractual[i] = letra;
                    }
                }

                if (palabractual == palabrasecreta)
                {
                    
                    ahorcado(intentosrestantes);

                    cout << palabractual << "\n\n";
                    cout << "Felicidades! Has adivinado la palabra: " << palabrasecreta << "\n";
                    cout << "Has ganado el juego!\n";
                    break;
                }
            }
            else
            {

                cout << "Lo siento, la letra " << letra << " no está en la palabra.\n";
                intentosrestantes--;

                if (intentosrestantes == 0)
                {
                    ahorcado(intentosrestantes);

                    cout << palabractual << "\n\n";
                    cout << "Has perdido el juego!\n";
                    cout << "La palabra secreta era: " << palabrasecreta << "\n";
                    break;
                }
            }
        }
        else
        {
            cout << "Por favor, introduce una letra válida.\n";
        }
    }
    return 0;
}

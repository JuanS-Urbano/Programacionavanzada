#include <iostream>
#include <iomanip>

using namespace std;

struct Libro {
    string titulo;
    string fechaPublicacion;
    string autor;
    int totalLibros;
    int librosEnPedidos;
    double precioVenta;
};

void leerDatosLibro(Libro &libro) {
    cout << "Ingrese el título del libro: ";
    getline(cin, libro.titulo);

    cout << "Ingrese la fecha de publicación: ";
    getline(cin, libro.fechaPublicacion);

    cout << "Ingrese el autor del libro: ";
    getline(cin, libro.autor);

    cout << "Ingrese el número total de libros existentes: ";
    string totalLibrose;
    getline(cin, totalLibrose);
    libro.totalLibros = stoi(totalLibrose);

    cout << "Ingrese el número total de libros en pedidos: ";
    string librospedido;
    getline(cin, librospedido);
    libro.librosEnPedidos = stoi(librospedido);

    cout << "Ingrese el precio de venta del libro: ";
    string precioventa;
    getline(cin, precioventa);
    libro.precioVenta = stod(precioventa);
}

void visualizarLibro(const Libro &libro) {
    cout << "Título: " << libro.titulo << endl;
    cout << "Fecha de Publicación: " << libro.fechaPublicacion << endl;
    cout << "Autor: " << libro.autor << endl;
    cout << "Total de Libros: " << libro.totalLibros << endl;
    cout << "Libros en Pedidos: " << libro.librosEnPedidos << endl;
    cout << fixed << setprecision(2);
    cout << "Precio de Venta: $" << libro.precioVenta << endl;
    cout << "----------------------------------------" << endl;
}

int main() {
    const int MAX_LIBROS = 10;
    Libro inventario[MAX_LIBROS];

    int numLibros;

    cout << "Ingrese el número de libros en el inventario (máximo " << MAX_LIBROS << "): ";
    cin >> numLibros;
    cin.ignore();

    if (numLibros > MAX_LIBROS) {
        cout << "Número de libros excede el límite. Se tomarán los primeros " << MAX_LIBROS << " libros." << endl;
        numLibros = MAX_LIBROS;
    }

    for (int i = 0; i < numLibros; i++) {
        cout << "Ingrese los datos para el libro " << i + 1 << ":" << endl;
        leerDatosLibro(inventario[i]);
    }

    cout << "Base de Datos de Libros:" << endl;
    for (int i = 0; i < numLibros; i++) {
        visualizarLibro(inventario[i]);
    }

    return 0;
}

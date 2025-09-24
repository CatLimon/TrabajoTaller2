#include <iostream>
using namespace std;

class Nodo {
public:
    int valor, x, y;
    Nodo* siguiente;
    Nodo(int v, int x_, int y_) : valor(v), x(x_), y(y_), siguiente(nullptr) {}
};

class MatrizDispersa {
private:
    Nodo* comienzo;
    int filasTotales;
    int columnasTotales;

public:
    // el constructor a
    MatrizDispersa(int filas, int columnas) {
        comienzo = nullptr;
        filasTotales = filas;
        columnasTotales = columnas;
    }
    //destructorr
    ~MatrizDispersa() {
        Nodo* aux = comienzo;
        while (aux != nullptr) {
            Nodo* temp = aux;
            aux = aux->siguiente;
            delete temp;
        }
    }

    // poner el valor en un lugar de la matriz
    void insertar(int valor, int x, int y) {
        if (x >= filasTotales || y >= columnasTotales || x < 0 || y < 0) {
            cout << "Posicion fuera de rango." << endl;
            return;
        }

        // Si es un 0 no se toma lol
        if (valor == 0) {
            eliminar(x, y);
            return;
        }

        Nodo* nuevo = new Nodo(valor, x, y);
        nuevo->siguiente = comienzo;
        comienzo = nuevo;
    }

    // Obtener valor segun su posicion
    int get(int x, int y) {
        Nodo* aux = comienzo;
        while (aux != nullptr) {
            if (aux->x == x && aux->y == y) {
                return aux->valor;
            }
            aux = aux->siguiente;
        }
        return 0; // si no esta es 0
    }

    // eliminar valor de un nodo de la matriz 
    void eliminar(int x, int y) {
        Nodo* aux = comienzo;
        Nodo* anterior = nullptr;
        while (aux != nullptr) {
            if (aux->x == x && aux->y == y) {
                if (anterior == nullptr) {
                    comienzo = aux->siguiente;
                } else {
                    anterior->siguiente = aux->siguiente;
                }
                delete aux;
                return;
            }
            anterior = aux;
            aux = aux->siguiente;
        }
    }

    // los valores != 0
    void mostrarValores() {
        Nodo* aux = comienzo;
        if (!aux) {
            cout << "Matriz vacia." << endl;
            return;
        }
        while (aux != nullptr) {
            cout << "valor " << aux->valor
                 << " en ( " << aux->x << ", " << aux->y << " )" << endl;
            aux = aux->siguiente;
        }
    }

    // Calcular la densidad ah
    double calculaDensidad() {
        int contador = 0;
        Nodo* aux = comienzo;
        while (aux != nullptr) {
            contador++;
            aux = aux->siguiente;
        }
        int totalPosiciones = filasTotales * columnasTotales;
        return (double)contador / totalPosiciones;
    }
// Multiplicar con otra matriz
    MatrizDispersa multiplicar(const MatrizDispersa& otra) {
        if (columnasTotales != otra.filasTotales) {
            cout << "No se pueden multiplicar: dimensiones incompatibles." << endl;
            return MatrizDispersa(0, 0); 
        }

        MatrizDispersa resultado(filasTotales, otra.columnasTotales);

        // Recorro todos los elementos de la primera matriz
        Nodo* aux1 = comienzo;
        while (aux1 != nullptr) {
            // Recorro los elementos de la segunda matriz
            Nodo* aux2 = otra.comienzo;
            while (aux2 != nullptr) {
                if (aux1->y == aux2->x) { 
                    int suma = resultado.get(aux1->x, aux2->y);
                    resultado.eliminar(aux1->x, aux2->y);
                    resultado.insertar(suma + (aux1->valor * aux2->valor), aux1->x, aux2->y);
                }
                aux2 = aux2->siguiente;
            }
            aux1 = aux1->siguiente;
        }

        return resultado;
    }
   
    };
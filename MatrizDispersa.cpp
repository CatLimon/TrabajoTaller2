using namespace std;
#include <iostream>
class Nodo {
public:
    int valor, x, y;
    Nodo* siguiente;
    Nodo(int v, int x_, int y_) : valor(v), x(x_), y(y_), siguiente(nullptr) {}
};

class MatrizDispersa {
public:
    Nodo* comienzo;
    MatrizDispersa() : comienzo(nullptr) {}

    void insertar(int valor, int x, int y) {
        Nodo* nuevo = new Nodo(valor, x, y);
        if (!comienzo) {
            comienzo = nuevo;
        } else {
            Nodo* actual = comienzo;
            while (actual->siguiente) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevo;
        }
    }

    int get(int x, int y);
};

void Agregar(MatrizDispersa& matriz , int valor , int x, int y){
    Nodo* nuevo = new Nodo(valor, x, y);
    if(matriz.comienzo == nullptr){
        matriz.comienzo = nuevo;
    } else {
        Nodo* aux = matriz.comienzo;
        while(aux->siguiente != nullptr){
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}

int MatrizDispersa::get(int x,int y){
    Nodo* aux = comienzo;
    while(aux != nullptr){
        if(aux->x == x && aux->y == y){
            return aux->valor;
        }
        aux = aux->siguiente;
    }
    return 0; // si no se encuentra es 0
}

//me voy a wachiturrear no sabes nada que cansación
void eliminar(int x,int y){
    Nodo* aux=comienzo;
    Nodo* anterior = nullptr;
    while (aux != nullptr)
    {
        if (aux->x == x && aux->y == y)
        {
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
void mostrarValores(){
    Nodo* aux=comienzo;
    while (aux != nullptr)
    {
        cout<<"valor " <<aux->valor<< " en ( " << aux->x << ", " << aux->y << " )"<<endl;
        aux = aux->siguiente;
    }
    
}
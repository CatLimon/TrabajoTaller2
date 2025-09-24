#pragma once

struct Nodo
{
    int valor;
    int x;
    int y;
    Nodo* siguiente;
    Nodo(int v,int x_,int y_): valor(v), x(x_), y(y_), siguiente(nullptr) {}
};

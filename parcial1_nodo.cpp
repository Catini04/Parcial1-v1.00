#include<iostream>
#include<string>

using namespace std;

/* CONSTRUCTOR CLASE NODO */
template <class T> class Nodo {
private:
    T dato;
    Nodo* next;
/* METODOS CLASE NODO */
public:
    Nodo() { next = NULL; };
    Nodo(T a) { dato = a; next = NULL; };
    void set_dato(T a) { dato = a; };
    void set_next(Nodo* n) { next = n; };
    T get_dato() { return dato; };
    Nodo* get_next() { return next; };
    bool es_vacio() { return next == NULL; }
};



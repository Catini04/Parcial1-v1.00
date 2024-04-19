#include<iostream>
#include<string>
#include <cstdlib>
#include <sstream>

using namespace std;
/* CLASE LISTA CON CONSTRUCTOR Y METODOS DEFINIDOS EN CLASE*/
template <class T> class Lista {
private: Nodo<T>* czo;
public:
    Lista() { czo = new Nodo<T>(); };
    Lista(Nodo<T>* n) { czo = n; };
    void add(T d); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
                        //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    void impre(void);
    T suma(T i);
    int size();
    bool esta(T d);// detecta si d esta en la lista
    void borrarDato(T d) { borrarD(d, NULL); }//borra el nodo que contiene d
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d) { addO(d, NULL); }; //sumar nodos a la lista Ordenados de menor a MAYOR

};


/* METODOS LISTA*/


/* agrega un elemento d a la lista*/
template <class T>
void Lista<T>::add(T d) 
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_next(czo);
    czo = nuevo;
}
/* llama al metodo es_vacio() de nodo para saber si la lista esta vacia*/
template <class T>
bool Lista<T>::esvacia(void)
{
    return czo->es_vacio();
}

/*retorna el dato de la cabeza de la lista*/
template <class T>
T Lista<T>::cabeza(void)
{
    if (this->esvacia()) {
        return NULL;
    }
    return czo->get_dato();
}
/*retorna los elementos del resto de la lista*/
template <class T>
Lista<T>* Lista<T>::resto(void)
{
    Lista* l = new Lista(czo->get_next());
    return (l);
}
/* retorna un string p pasado */
template <class T>
string Lista<T>::toPrint(string p)
{
    if (this->esvacia()) {
        return p;
    }
    else {
        ostringstream stm;
        stm << this->cabeza() << "-" << this->resto()->toPrint(p) << endl;
        return stm.str();
    }
}
/* suma los elementos de una lista*/
template <class T>
T Lista<T>::suma(T i)
{
    if (this->esvacia()) {
        return i;
    }
    else {
        return this->resto()->suma(i + this->cabeza());
    }
}
/* retorna el tamaño de una lista*/

template <class T> int Lista<T>::size()
{
    if (this->esvacia()) return 0;
    return 1 + this->resto()->size();
}


/* borra la cabeza de la lista */
template <class T> void Lista<T>::borrar(void)
{
    if (!this->esvacia()) {
        Nodo<T>* tmp = czo;
        czo = czo->get_next();
        delete tmp;
    }
}

/* borra el ultimo elemento de la lista*/
template <class T> void Lista<T>::borrar_last()
{
    if (!this->esvacia()) {
        if ((czo->get_next())->get_next() == NULL) {
            delete czo->get_next();
            czo->set_next(NULL);
        }
        else this->resto()->borrar_last();
    }
}

/* le transfiere los datos de una lista l1 pasada a la lista con la que estamos trabajando */
template <class T> void Lista<T>::concat(Lista<T>* l1)
{
    if (!(l1->esvacia())) {
        this->concat(l1->resto());
        this->add(l1->cabeza());
    }
}

/* hace una copia de la lista, en aux*/
template <class T> Lista<T>* Lista<T>::copy(void)
{
    Lista<T>* aux = new Lista();
    aux->concat(this);
    return aux;
}
/* deja una lista de n elementos, borra el resto de la lista*/
template <class T> void Lista<T>::tomar(int n)
{ 
    if (this->size() > n) {
        this->borrar_last();
        this->tomar(n);
    }
}


/* imprime los datos de la lista tabeados uno por uno*/
template <class T> void Lista<T>::impre(void)
{
    Nodo<T>* aux;
    aux = czo;
    while (aux->get_next() != NULL) {
        cout << aux->get_dato() << endl;
        aux = aux->get_next();
    }
}
/* busca el dato d en la lista y retorna true o false*/
template <class T> bool Lista<T>::esta(T d)
{// busca d en la lista
    if (this->esvacia()) return false;
    if (this->cabeza() == d) return true;
    
    return this->resto()->esta(d);    
}

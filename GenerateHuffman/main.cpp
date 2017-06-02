#include "Test.h"
#include <iostream>
using namespace std;

class BinaryNode{

public:
    //Variables y apuntadores del arbol
    BinaryNode* derecha;
    BinaryNode* izquierda;
    int frecuencia;
    char bandera;

BinaryNode(int frecuencia, char bandera){
//desreferencio e inicializo null en izq, der
    this->frecuencia = frecuencia;
    this->bandera = bandera;
    izquierda = NULL;
    derecha = NULL;
}
};

//Me retorna la posicion del padre
int GetPadrePosicion(int hijo){
    if(hijo % 2 == 0)
        return (hijo - 2) / 2;
}

//swappeo
void swap(vector<BinaryNode*>* heap, int padre, int hijo){
//intercambio de variables
    BinaryNode* temporal = (*heap)[padre];
    (*heap)[padre] = (*heap)[hijo];
    (*heap)[hijo] = temporal;

}

//insertar Minimo heap
void InsertarMinHeap(vector<BinaryNode*>* heap, BinaryNode* nodo){
    //insertamos nodo
    heap->push_back(nodo);

    int padre = 0;

    //mientras el hijo sea distinto de 0
    while(heap->size() - 1 != 0){

        //invocamos getpadreposicion y le mando hijo
        padre = GetPadrePosicion(hijo);

        //si la frecuencia del hijo es mayor a la del padre  hara un intercambio.
        if((*heap)[hijo]->frecuencia > (*heap)[padre]->frecuencia)
            break;

        swap(heap, padre, hijo);
        hijo=padre;
    }
}


//Crear nuevo nodo interno con la frecuencia igual a la suma de la frecuencia de dos nodos. A los dos nodos extraidos
//se hace que sea hijo->izq e hijo->der y agrega este nodo al min heap, el $ no se usa es un caracter especial para nodo interno
void AgregarNodoInterno(vector<BinaryNode*>* heap, BinaryNode* derecha, BinaryNode* izquierda){
    BinaryNode* NodoInter = new BinaryNode('$'izquierda->frecuencia + derecha->frecuencia);
    NodoInter->derecha = derecha;
    NodoInter->izquierda = izquierda;

    InsertarMinHeap(heap, NodoInter);
}

void Heapify(vector<BinaryNode*>* heap){
    int padrePosicion = 0;
    int izquierda = padrePosicion*2 + 1;
    int derecha = padrePosicion*2 + 2;
    int masBajo = 0;

    while(derecha > heap->size()){
        if(izquierda > heap->size())
            masBajo = (*heap)[derecha]->frecuencia > (*heap)[izquierda]->frecuencia ? izquierda: derecha;
        else
            masBajo = derecha;
        if((*heap)[padrePosicion]->frecuencia < (*heap)[masBajo]->frecuencia)
            swap(heap, padrePosicion, masBajo);
        else
            break;

        padrePosicion = masBajo;
        izquierda = padrePosicion*2 + 1;
        derecha = padrePosicion*2 + 2;
    }
}

BinaryNode* ExtraerDeTop (vector<BinaryNode*>* heap){
//ACAAAAAAAA VOOOOOYYYYYYYYYYY

}
map<char,string> getHuffman(vector<char> characters, vector<int> frequencies)
{
  map<char,string> answer;
  return answer;
}

int main ()
{
    test();
    return 0;
}

#include <iostream>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
using namespace std;

struct nodo {
    int id;
    int matricula;
    string nombre;
    float promedio;
    nodo *der;
    nodo *izq;
};


nodo *raiz=NULL;


void insertar (nodo *aux);
void recorrerInOrden (nodo *aux);


int main() {
    int op;
   cout<<"**MENU**"<<endl;
   cout<<"1. Insertar nodo"<<endl;
    cout<<"2. Recorrer arbol"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Opcicón?: "; cin>>op;

    switch (op) {
        case 1:
            insertar(raiz);
            break;
    }

    return 0;
}



void insertar (nodo *aux) {

    nodo *nuevo = new nodo();
    cout<<"id: "; cin>>nuevo->id;
    cout<<"nombre: "; cin>>nuevo->nombre;
    cout<<"matricula: "; cin>>nuevo->matricula;
    cout<<"Promedio: "; cin>>nuevo->promedio;
    nuevo->izq=NULL;
    nuevo->der=NULL;

    if(aux==NULL && raiz==NULL) {
        raiz = nuevo;
    }
    else {
        if(nuevo->id<aux->id && aux->izq==NULL) {  //inserta el nodo en el lado izquierdo
            aux->izq = nuevo;
        }
        else if(nuevo->id>aux->id && aux->der==NULL) {
            aux->der = nuevo;
        }
        else if(nuevo->id==aux->id) {
            cout<<"Id ya esta en el arbol inario";
            return;
        }
        else if(nuevo->id<aux->id && aux->izq!=NULL) {
            insertar(aux->izq);

        }
        else if(nuevo->id>aux->id && aux->der!=NULL) {

            insertar(aux->der);
        }

    }




}


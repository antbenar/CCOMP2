#include "ArrayVector.h"
#include <iostream>
#include <Vector.h>
using namespace std;

ArrayVector::ArrayVector()
{
    tam = 0;
    ArrayP = new Vector[0];
    cout << "Se creo el arreglo default\n";
}

ArrayVector::ArrayVector(const Vector pt[], int a){
    ArrayP=new Vector[a];
    for(int i=0; i<a;i++){
        ArrayP[i]=pt[i];
    }
    tam=a;
    cout << "Se creo el arreglo de lista de vectores ya creada []\n";
}

ArrayVector::ArrayVector(const ArrayVector& pt){
    tam=pt.tam;
    ArrayP=new Vector[tam];
    for(int i=0; i<tam;i++)
        ArrayP[i]=pt.ArrayP[i];
    tam=pt.tam;
    cout << "Se creo el arreglo &pt\n";
}

void ArrayVector::redimensionar(int tm)
{
    Vector *p = new Vector[tm];
    tam = tm;
    for(int i=0;i<tm;i++)
        p[i]=ArrayP[i];
    delete[] ArrayP;
    ArrayP = p;
}

void ArrayVector::agregar(Vector &pt){
    tam++;
    redimensionar(tam+1);
    ArrayP[tam]=pt;
}
void ArrayVector::insertar(const int position, const Vector &p)
{
    redimensionar(tam+1);
    for(int i=tam;i>position;i--)
        ArrayP[i]=ArrayP[i--];
    ArrayP[position]=p;
}

void ArrayVector::remover(const int position){
    for(int i=position; i<tam-1; i++)
        ArrayP[i]=ArrayP[i+1];
    redimensionar(tam-1);
}

void ArrayVector::imprimirArray(){
    cout << "El arreglo:\n";
    for(int i=0;i<tam;i++)
        ArrayP[i].PrintVector();
}

const int ArrayVector::getSize() const{
    return tam;
}

void ArrayVector::borrar(){
    delete []ArrayP;
}

ArrayVector::~ArrayVector()
{
    delete []ArrayP;
    cout<<"\n se Borro el Array";
}


#ifndef ARRAYVECTOR_H
#define ARRAYVECTOR_H
#include <Vector.h>

class ArrayVector
{
    private:
        Vector* ArrayP;
        int tam;
        void redimensionar(int tm);
    public:
        ArrayVector();
        ArrayVector(const Vector pt[],  int a);
        ArrayVector(const ArrayVector& pt);
        void imprimirArray();
        void agregar(Vector &pt);
        void insertar(const int position, const Vector &pt);
        void remover(const int position);
        const int getSize() const;
        void borrar();

        virtual ~ArrayVector();
};

#endif // ARRAYVECTOR_H

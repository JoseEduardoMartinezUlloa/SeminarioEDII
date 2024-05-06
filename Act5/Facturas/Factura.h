#ifndef
#define FACTURA_H

class Factura
{
public:
    char numero[10], proveedor[30], cliente[35], producto[30], cantidad[10], fecha_p[15], fecha_e[15];
    void Capturar();
    void Modificar();
    void Mostrar();
    void Eliminar();
    void Buscar();
    void menu_facturas();
    void Leer();
    void descomprimir();
};

#endif
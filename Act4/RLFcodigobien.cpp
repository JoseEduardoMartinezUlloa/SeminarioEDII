#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

class Orden
{
public:
    char numero_orden[4],fecha[30],cliente[35],articulo[25],cantidad[4],total[5];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} OrdCom;
void Orden::Agregar()
{
    cout<<"GENERAR ORDEN DE COMPRA"<<endl;
    cout<<"Numero de orden: ";
    cin.getline(numero_orden,4);
    cin.getline(numero_orden,4);
    cout<<"Fecha: ";
    cin.getline(fecha,30);
    cout<<"Cliente: ";
    cin.getline(cliente,35);
    cout<<"Articulo: ";
    cin.getline(articulo,25);
    cout<<"Cantidad: ";
    cin.getline(cantidad,4);
    cout<<"Total: ";
    cin.getline(total,5);
    ofstream archivo("compras.txt",ios::app);
    archivo.write((char*)&OrdCom,sizeof(OrdCom));
    archivo.close();
}
void Orden::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("compras.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ORDENES DE COMPRA"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Orden de compra: "<<numero_orden<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Cliente: "<<cliente<<endl;
            cout<<"Articulo: "<<articulo<<endl;
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"Total: $"<<total<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}
void Orden::Modificar()
{
    char valor[4];
    ifstream archivo("compras.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MODIFICAR ORDEN DE COMPRA"<<endl;
        cout<<"Ingrese el numero de orden a modificar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_orden,valor)==0)
            {
                cout<<""<<endl;
                cout<<"Nuevo numero de orden: ";
                cin.getline(numero_orden,4);
                cout<<"Nueva fecha: ";
                cin.getline(fecha,30);
                cout<<"Nuevo cliente: ";
                cin.getline(cliente,35);
                cout<<"Nuevo Articulo: ";
                cin.getline(articulo,25);
                cout<<"Nueva Cantidad: ";
                cin.getline(cantidad,4);
                cout<<"Nuevo total: ";
                cin.getline(total,5);
                ofstream archivo("compras.txt",ios::app);
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }

        }
        archivo.close();
        archivo2.close();
        remove("compras.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="compras.txt";
        rename(oldname,newname);
    }
}
void Orden::Eliminar()
{
    char valor[4];
    int opcion=0;
    ifstream archivo("compras.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ELIMINAR ORDEN DE COMPRA"<<endl;
        cout<<"Ingrese el numero de orden a eliminar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&OrdCom,sizeof(OrdCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(numero_orden,valor)==0)
            {
                cout<<"\tOrden Encontrada"<<endl;
                cout<<"Orden de compra: "<<numero_orden<<endl;
                cout<<"Fecha: "<<fecha<<endl;
                cout<<"Cliente: "<<cliente<<endl;
                cout<<"Articulo: "<<articulo<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Total: $"<<total<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&OrdCom,sizeof(OrdCom));
                }
            }
            else
            {
                archivo2.write((char*)&OrdCom,sizeof(OrdCom));
            }
        }
        archivo.close();
        archivo2.close();
        remove("compras.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="compras.txt";
        rename(oldname,newname);
    }

}
void Orden::Buscar()
{
    char valor[4];
    ifstream archivo("compras.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"BUSCAR ORDEN DE COMPRA"<<endl;
        cout<<"Ingrese el numero de orden a buscar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        archivo.read((char*)&OrdCom,sizeof(OrdCom));
        if(strcmp(numero_orden,valor)==0)
        {
            cout<<"\tOrden Encontrada"<<endl;
            cout<<"Orden de compra: "<<numero_orden<<endl;
            cout<<"Fecha: "<<fecha<<endl;
            cout<<"Cliente: "<<cliente<<endl;
            cout<<"Articulo: "<<articulo<<endl;
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"Total: $"<<total<<endl;
        }
        else
        {
            cout << "Orden no encontrada..." << endl;
        }
    }
    archivo.close();
}
void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}
int main()
{
    int op;
    do
    {
        system("cls");
        cout<<"MENU ORDENES DE COMPRA"<<endl;
        cout<<"1.-Capturar" <<endl;
        cout<<"2.-Imprimir todo" <<endl;
        cout<<"3.-Modificar "<<endl;
        cout<<"4.-Eliminar" <<endl;
        cout<<"5.-Buscar "<<endl;
        cout<<"6.-Salir "<<endl;
        cout<<"Ingresa la opcion->";
        cin>>op;
        switch(op)
        {
        case 1:
            system("cls");
            OrdCom.Agregar();
            Pausar();
            break;
        case 2:
            system("cls");
            OrdCom.Mostrar();
            Pausar();
            break;
        case 3:
            system("cls");
            OrdCom.Modificar();
            Pausar();
            break;
        case 4:
            system("cls");
            OrdCom.Eliminar();
            Pausar();
            break;
        case 5:
            system("cls");
            OrdCom.Buscar();
            Pausar();
            break;
        case 6:
            op=6;
            break;
        }
    }
    while(op!=6);
    return 0;
}

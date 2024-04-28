#include <iostream>
#include "Factura.h"
//#include "Proveedor.h"
//#include "Cliente.h"
//#include "Productos.h"
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<zlib.h>

using namespace std;

Factura fact;

void Factura::Capturar(){
    Proveedor pro;
    Cliente x;
    Productos p;
    int bus, confirmar;
    cout<<"\nNumero de factura: ";
    cin.ignore();
    cin.getline(numero,10);
    do{
        cout << "\nRFC del proveedor: ";
        cin.getline(proveedor, 20);
        bus = pro.buscar(proveedor);
        for(int i=0;i < strlen(pro.nombre);i++){
            proveedor[i] = pro.nombre[i];
        }
        if(bus==0){
            cout << "\n�Es el proveedor que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
            cout << "\nElige una opcion: ";
            cin >> confirmar;
            cin.ignore();
            if(confirmar==3){break;}
        }else if(bus==1){
            cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
            cout << "\nElige una opcion: ";
            cin >> confirmar;
            cin.ignore();
            if(confirmar==2){break;}
        }
    }while(confirmar == 2||bus==1&&confirmar==1);
    if(confirmar==2||confirmar==3){}else{
        do{
             x = x.buscar_dos();
            for(int i=0;i < strlen(x.nombre);i++){
                cliente[i] = x.nombre[i];
            }
            if(bus==0){
                cout << "\n�Es el cliente que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
                cout << "\nElige una opcion: ";
                cin >> confirmar;
                cin.ignore();
                if(confirmar==3){break;}
            }else if(bus==1){
                cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
                cout << "\nElige una opcion: ";
                cin >> confirmar;
                cin.ignore();
                if(confirmar==2){break;}
            }
        }while(confirmar == 2||bus==1&&confirmar==1);
        if(confirmar==2||confirmar==3){}else{
            do{
                cout << "\nCodigo del producto: ";
                cin.getline(producto, 30);
                bus = p.buscar(producto);
                for(int i=0;i < strlen(producto);i++){
                    producto[i] = p.nombre[i];
                }
                if(bus==0){
                    cout << "\n�Es el producto que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
                    cout << "\nElige una opcion: ";
                    cin >> confirmar;
                    cin.ignore();
                    if(confirmar==3){break;}
                }else if(bus==1){
                    cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
                    cout << "\nElige una opcion: ";
                    cin >> confirmar;
                    cin.ignore();
                    if(confirmar==2){break;}
                }
            }while(confirmar == 2||bus==1&&confirmar==1);
            if(confirmar==2||confirmar==3){}else{
                cout<<"\nCantidad: ";
                cin.getline(cantidad,10);
                cout<<"\nFecha de pedido: ";
                cin.getline(fecha_p,15);
                cout<<"\nFecha de entrega: ";
                cin.getline(fecha_e,15);
                ofstream a("Facturas.bin", ios::binary);
                a.write((char*)&fact,sizeof(fact));
                a.close();
            }
        }
    }
}

void Factura::Modificar(){
    Proveedor pro;
    Cliente x;
    Productos p;
    int bus, confirmar;
    int modif = 0;
    char numero2[10];
    ifstream a("Facturas.bin", ios::in);
    if(!a.good()){
        cout<<"\n NO EXISTE EL ARCHIVO"<<endl;
    }else{
        cout<<"\nIngrese el numero de factura: ";
        cin.ignore();
        cin.getline(numero2,10);
        ofstream b("temp.bin",ios::binary);
        while(!a.eof()){
            a.read((char*)&fact,sizeof(fact));
            if(a.eof()){
                break;
            }
            if(strcmp(numero,numero2)==0){
                cout<<"\nNumero de factura: ";
                cin.getline(numero,10);
                do{
                    cout << "\nRFC del proveedor: ";
                    cin.getline(proveedor, 20);
                    bus = pro.buscar(proveedor);
                    for(int i=0;i < strlen(pro.nombre);i++){
                        proveedor[i] = pro.nombre[i];
                    }
                    if(bus==0){
                        cout << "\n�Es el proveedor que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
                        cout << "\nElige una opcion: ";
                        cin >> confirmar;
                        cin.ignore();
                        if(confirmar==3){break;}
                    }else if(bus==1){
                        cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
                        cout << "\nElige una opcion: ";
                        cin >> confirmar;
                        cin.ignore();
                        if(confirmar==2){break;}
                    }
                }while(confirmar == 2||bus==1&&confirmar==1);
                if(confirmar==2||confirmar==3){}else{
                    do{
                        x = x.buscar_dos();
                        for(int i=0;i < strlen(x.nombre);i++){
                            cliente[i] = x.nombre[i];
                        }
                        if(bus==0){
                            cout << "\n�Es el proveedor que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
                            cout << "\nElige una opcion: ";
                            cin >> confirmar;
                            cin.ignore();
                            if(confirmar==3){break;}
                        }else if(bus==1){
                            cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
                            cout << "\nElige una opcion: ";
                            cin >> confirmar;
                            cin.ignore();
                            if(confirmar==2){break;}
                        }
                    }while(confirmar == 2||bus==1&&confirmar==1);
                    if(confirmar==2||confirmar==3){}else{
                        do{
                            cout << "\nCodigo del producto: ";
                            cin.getline(producto, 30);
                            bus = p.buscar(producto);
                            for(int i=0;i < strlen(producto);i++){
                                producto[i] = p.nombre[i];
                            }
                            if(bus==0){
                                cout << "\n�Es el producto que buscaba?  (1)Si   (2)No   (3)Salir"<<endl;
                                cout << "\nElige una opcion: ";
                                cin >> confirmar;
                                cin.ignore();
                                if(confirmar==3){break;}
                            }else if(bus==1){
                                cout << "\n�Quiere seguir buscando?  (1)Si   (2)No"<<endl;
                                cout << "\nElige una opcion: ";
                                cin >> confirmar;
                                cin.ignore();
                                if(confirmar==2){break;}
                            }
                        }while(confirmar == 2||bus==1&&confirmar==1);
                        if(confirmar==2||confirmar==3){}else{
                            cout<<"\nCantidad: ";
                            cin.getline(cantidad,10);
                            cout<<"\nFecha de pedido: ";
                            cin.getline(fecha_p,15);
                            cout<<"\nFecha de entrega: ";
                            cin.getline(fecha_e,15);
                            modif=1;
                            b.write((char*)&fact,sizeof(fact));
                        }
                    }
                }
            }else{
                b.write((char*)&fact,sizeof(fact));
            }
        }
        if(modif!=1){
            cout << "\nRegresando al menu Principal\n";
        }
        a.close();
        b.close();
        remove("Facturas.bin");
        char oldname[] ="temp.bin";
        char newname[] ="Facturas.bin";
        rename(oldname,newname);
    }
}

void Factura::Mostrar(){
    ifstream a("Facturas.bin");
    if(!a.good()){
        cout<<"\n NO EXISTE ARCHIVO"<< endl;
    }else{
        while(!a.eof()){
            a.read((char*)&fact,sizeof(fact));
            if(a.eof()){
                break;
            }
            cout<<"\nNumero de factura: "<<numero<<endl;;
            cout<<"Proveedor: "<<proveedor<<endl;
            cout<<"Cliente: "<<cliente<<endl;
            cout<<"Producto: "<<producto<<endl;
            cout<<"Cantidad: "<<cantidad<<endl;
            cout<<"Fecha de pedido: "<<fecha_p<<endl;
            cout<<"Fecha de entrega: " << fecha_e<<endl;
        }
    }
    a.close();
}

void Factura::Buscar(){
    char numero2[10];
    int band=0;
    ifstream a("Facturas.bin");
    if(!a.good()){
        cout<<"\n NO EXISTE ARCHIVO";
    }else{
        cout<<"\nIngrese el numero de factura: ";
        cin.ignore();
        cin.getline(numero2,10);
        while(!a.eof()){
            a.read((char*)&fact,sizeof(fact));
            if(a.eof()){
                break;
            }
            if(strcmp(numero,numero2)==0){
                cout<<"\nNumero de factura: "<<numero<<endl;;
                cout<<"Proveedor: "<<proveedor<<endl;
                cout<<"Cliente: "<<cliente<<endl;
                cout<<"Producto: "<<producto<<endl;
                cout<<"Cantidad: "<<cantidad<<endl;
                cout<<"Fecha de pedido: "<<fecha_p<<endl;
                cout<<"Fecha de entrega: " << fecha_e<<endl;
            }else{
                cout<<"\nRegresando a menu anterior\n";
            }
        }
    }
    if(band==0){
        cout<<endl;
    }
    a.close();
}

void Factura::Eliminar(){
    ifstream a("Facturas.bin");
    ofstream escribirAux("Facturasaux.bin", ios::binary);
    char elimi[10];
    int bandera = 0;
    if(!a.good()){
        cout<<"\nEl archivo no existe "<<endl;
    }else{
        cout<<"\nNumero de factura: ";
        cin>>elimi;
        while(!a.eof()){
            a.read((char *) & fact, sizeof(fact));
            if(a.eof()){
                break;
            }
            if(elimi == numero){
                cout<<"Factura eliminada"<<endl;
                bandera = 1;
            }else{
                escribirAux.write((char *) & fact, sizeof(fact));
            }
        }
        if(bandera != 1){
            cout<<"\n\tDatos eliminados"<<endl;
        }
    }
    a.close();
    escribirAux.close();
    remove("Facturas.bin");
    rename("Facturaaux.bin", "Facturas.bin");
}

void Factura::Leer()
{
     string datos;
     fstream archivo("Facturas.bin", ios::in);
     if(archivo.is_open())
     {
         while( !archivo.eof())
         {
             datos += archivo.get();

             if( archivo.eof())
             {
                 datos.erase( datos.end()-1);

                  break;
             }
         }
         cout << datos;
         gzFile *f = (gzFile*)gzopen("Comprimidofactura.gz", "w");
         if( f != NULL)
         {
             gzwrite(f, datos.c_str(),datos.length());
             gzclose(f);
         }
     }
}
void Factura::descomprimir()
{
    gzFile *f =(gzFile *)gzopen("Comprimidofactura.gz", "r");
    if( f != NULL)
    {
        char buf[10];
        string datos;
         gzrewind(f);

         while( !gzeof(f))
         {
             int cant = gzread(f, buf, 10);

             if(cant == -1)
                 break;
             else{
                 datos += string(buf, cant);
             }
         }
         cout << datos;
    }
}

void Factura::menu_facturas(){
    int opc;
    do{
        cout<<"\nMenu de facturas"<<endl;
        cout<<"\n1. Capturar factura \n";
        cout<<"2. Mostrar facturas \n";
        cout<<"3. Buscar factura  \n";
        cout<<"4. Eliminar factura \n";
        cout<<"5. Modificar factura \n";
        cout<<"6. Comprimir \n";
        cout<<"7. Descomprimir \n";
        cout<<"8. Salir ";
        cout << "\nElige una opcion: ";
        cin>>opc;
        switch(opc){
            case 1: fact.Capturar();
                    break;
            case 2: fact.Mostrar();
                    break;
            case 3: fact.Buscar();
                    break;
            case 4: fact.Eliminar();
                    break;
            case 5: fact.Modificar();
                    break;
            case 6: fact.Leer();
                    break;
            case 7: fact.descomprimir();
                    break;
            case 8: break;
            default: cout << "\nOpcion invalida" << endl;
        }
    }while(opc!=8);
}

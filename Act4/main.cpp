// Registros de longitud fija
// Jose Eduardo Martinez Ulloa
// 15/02/2024

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>
#include <limits>

using namespace std;

class Compra{
    public:
    char folio_compra[5], fecha_compra[11],id_proveedor[5];
    void Add();
    void Show();
    // void Mod();
    // void Search();
    // void Delete();
} Cmpr;

void Compra::Add(){
    cout<<"Folio de Compra (xxxx): ";
    cin.getline(folio_compra, 5); 
    cout<<"Fecha (DD/MM/AAAA): ";
    cin.getline(fecha_compra, 11);
    cout<<"ID del proveedor (xxxx): ";
    cin.getline(id_proveedor, 5);
    ofstream myFile("compraSimple.txt", ios::app);
    myFile.write((char*)&Cmpr,sizeof(Cmpr));
    myFile.close();
}

void Compra::Show() {
    char folio_compra[4], fecha_compra[10],id_proveedor[4];
    int band=0;
    ifstream myFile("compraSimple.txt");
    if(!myFile.good()) cout<<"\n Archivo no encontrado."<<endl;
    else{
        cout<<"Ordenes de Compra"<<endl;
        while(!myFile.eof()){
            myFile.read((char*)&Cmpr,sizeof(Cmpr));
            if(myFile.eof()) break;
        cout<<"No. Orden de Compra: "<<Cmpr.folio_compra<<endl;
        cout<<"Fecha: "<<Cmpr.fecha_compra<<endl;
        cout<<"ID de Proveedor: "<<Cmpr.id_proveedor<<endl;
        }
        myFile.close();
    }
}

void menu(){
    int sel = 0;
    int lastsel = 0;
    do{
    system("cls");
    cout<<"Menu de ordenes de compra"<<endl;
    cout<<"1. Capturar orden"<<endl;
    cout<<"2. Mostrar todas las ordenes"<<endl;
    cout<<"6. Salir del menu"<<endl;
    cout<<"Su ultima seleccion fue: " << lastsel <<endl;
    cout<<"Ingrese su seleccion: ";
    cin>>sel;
    cin.ignore();
    lastsel=sel;
    switch (sel)
    {
    case 1:{Cmpr.Add(); break;}
    case 2:{Cmpr.Show(); break;}
    case 3:{cout<<"Usaste 3"<<endl; break;}
    case 6:{cout<<"Saliendo del programa."; break;}
    default: break;
    }
    }while(sel!=6);
}

int main(){
    menu();
    return 0;
}
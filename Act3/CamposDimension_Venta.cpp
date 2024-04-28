// Registros de Longitud variable (campos de dimensión)
// Jose Eduardo Martinez Ulloa
// Seminario de Solucion de Problemmas de Estructura de Datos II


#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"


using namespace std;

class Venta{
    public:
    char folio_ven[11], id_cli[11], fecha_ven[11], tipo_ven[21];

    void Agregar();
    void Mostrar();
    void Modificar();
    void Eliminar();
    void Buscar();
    void Menu();
}ven;

int dim_folio, dim_cli, dim_fecha, dim_tipo, opc = 0;

void Venta::Agregar(){

    cout<<"Ingrese el Folio de Venta: ";
    cin.getline(folio_ven, 11);
    cin.getline(folio_ven, 11);
    cout<<"Ingrese el ID del Cliente: ";
    cin.getline(id_cli, 11);
    cout<<"Ingrese la Fecha de Venta (DD/MM/AAAA): ";
    cin.getline(fecha_ven, 11);
    cout<<"Ingrese el Tipo de Venta (Tienda/Telefono): ";
    cin.getline(tipo_ven, 21);

    ofstream ArchivoApp("FoliosVentas.txt", ios::app);
    dim_folio = strlen(folio_ven);
    dim_cli = strlen(id_cli);
    dim_fecha = strlen(fecha_ven);
    dim_tipo = strlen(tipo_ven);

    ArchivoApp.write((char*)&dim_folio,sizeof(int));
    ArchivoApp.write((char*)&folio_ven,dim_folio);
    ArchivoApp.write((char*)&dim_cli,sizeof(int));
    ArchivoApp.write((char*)&id_cli,dim_cli);
    ArchivoApp.write((char*)&dim_fecha,sizeof(int));
    ArchivoApp.write((char*)&fecha_ven,dim_fecha);
    ArchivoApp.write((char*)&dim_tipo,sizeof(int));
    ArchivoApp.write((char*)&tipo_ven,dim_tipo);

    ArchivoApp.close();

}

void Venta::Mostrar(){

    ifstream ArchivoIn("FoliosVentas.txt");
    if(!ArchivoIn.good()){ cout<<"\nEl Archivo no existe... "; }
    else{
        cout<<"Folio\tID del Cliente\tFecha\tTipo de Venta\n";
        while(!ArchivoIn.eof()){

            ArchivoIn.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoIn.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            ArchivoIn.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            ArchivoIn.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<endl;
        }
    }
    ArchivoIn.close();
}

void Venta::Modificar(){
    int flag=0;
    char folio_search[11];

    ifstream ArchivoIn("FoliosVentas.txt");
    if(!ArchivoIn.good()){ cout<<"\nEl Archivo no existe... "; }
    else{
        cout<<"Ingrese el Folio de Venta a Modificar: ";
        cin.getline(folio_search, 11);
        cin.getline(folio_search, 11);
        while(!ArchivoIn.eof()&&!flag){
            ArchivoIn.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoIn.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            ArchivoIn.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            ArchivoIn.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(strcmp(folio_search, folio_ven) == 0){ //Comparacion de campo clave con la busqueda
                cout<<"Folio\tID del Cliente\tFecha\tTipo de Venta\n";
                cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<endl;
                flag=1;
                cout<<"Desea Modificar? \t 1 - SI \t 0 - NO: ";
                cin>>opc;
            }
        }
        ArchivoIn.close();


        if(opc==1){
            ifstream ArchivoApp("FoliosVentas.txt");
            ofstream ArchivoTemp("TempVentas.txt", ios::app);
            while(!ArchivoTemp.eof()){
            ArchivoApp.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoApp.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoApp.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoApp.read((char*)&id_cli, dim_cli);
            folio_ven[dim_cli]='\0';

            ArchivoApp.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoApp.read((char*)&fecha_ven, dim_fecha);
            folio_ven[dim_fecha]='\0';

            ArchivoApp.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoApp.read((char*)&tipo_ven, dim_tipo);
            folio_ven[dim_tipo]='\0'; 
            

            if(strcmp(folio_search, folio_ven) == 0){
                cout<<"Ingrese el Folio de Venta: ";
                cin.getline(folio_ven, 11);
                cin.getline(folio_ven, 11);
                cout<<"Ingrese el ID del Cliente: ";
                cin.getline(id_cli, 11);
                cout<<"Ingrese la Fecha de Venta (DD/MM/AAAA): ";
                cin.getline(fecha_ven, 11);
                cout<<"Ingrese el Tipo de Venta (Tienda/Telefono): ";
                cin.getline(tipo_ven, 21);

                dim_folio = strlen(folio_ven);
                dim_cli = strlen(id_cli);
                dim_fecha = strlen(fecha_ven);
                dim_tipo = strlen(tipo_ven);
            }

            ArchivoTemp.write((char*)&dim_folio, sizeof(int));
            ArchivoTemp.write((char*)&folio_ven, dim_folio);
            ArchivoTemp.write((char*)&dim_cli, sizeof(int));
            ArchivoTemp.write((char*)&id_cli, dim_cli);
            ArchivoTemp.write((char*)&dim_fecha, sizeof(int));
            ArchivoTemp.write((char*)&fecha_ven, dim_fecha);
            ArchivoTemp.write((char*)&dim_tipo, sizeof(int));
            ArchivoTemp.write((char*)&tipo_ven, dim_tipo);
            }
        ArchivoTemp.close();
        ArchivoApp.close();
        remove("FoliosVentas.txt");
        rename("TempVentas.txt", "FoliosVentas.txt");
        }
    }
}

void Venta::Eliminar(){
    int flag=0;
    char folio_search[11];

    ifstream ArchivoIn("FoliosVentas.txt");
    if(!ArchivoIn.good()){cout<<"El Archivo No Fue Encontrado.";}
    else{
        cout<<"Ingrese El Folio A Eliminar: ";
        cin.getline(folio_search, 11);
        cin.getline(folio_search, 11);
        while(!ArchivoIn.eof()&&!flag){
            ArchivoIn.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoIn.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            ArchivoIn.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            ArchivoIn.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(strcmp(folio_search, folio_ven) == 0){ //Comparacion de campo clave con la busqueda
                cout<<"Folio\tID del Cliente\tFecha\tTipo de Venta\n";
                cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<endl;
                flag=1;
                cout<<"Desea Eliminar? \t 1 - SI \t 0 - NO: ";
                cin>>opc;
            }
        }
        ArchivoIn.close();

        if(opc==1){
            ifstream ArchivoIn("FoliosVentas.txt");
            ofstream ArchivoTemp("TempVentas.txt", ios::app);
            while(!ArchivoIn.eof()){

            ArchivoIn.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoIn.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            ArchivoIn.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            ArchivoIn.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0';  

            if(strcmp(folio_search, folio_ven)!=0){
            ArchivoTemp.write((char*)&dim_folio,sizeof(int));
            ArchivoTemp.write((char*)&dim_folio, sizeof(int));
            ArchivoTemp.write((char*)&folio_ven, dim_folio);
            ArchivoTemp.write((char*)&dim_cli, sizeof(int));
            ArchivoTemp.write((char*)&id_cli, dim_cli);
            ArchivoTemp.write((char*)&dim_fecha, sizeof(int));
            ArchivoTemp.write((char*)&fecha_ven, dim_fecha);
            ArchivoTemp.write((char*)&dim_tipo, sizeof(int));
            ArchivoTemp.write((char*)&tipo_ven, dim_tipo);
            }

            }
        ArchivoTemp.close();

        ArchivoIn.close();
        remove("FoliosVentas.txt");
        rename("TempVentas.txt", "FoliosVentas.txt");
        }
    }
}

void Venta::Buscar(){
    char folio_search[11];
    int flag = 0;
    system("cls");

    ifstream ArchivoIn("FoliosVentas.txt");
    if(!ArchivoIn.good()){ cout<<"\nArchivo No Encontrado."; }
    else{
        cout<<"Ingrese el Folio de Venta a Buscar: ";
        cin.getline(folio_search, 10);
        cin.getline(folio_search, 10);
        while(!ArchivoIn.eof()&&!flag){
            ArchivoIn.read((char*)&dim_folio, sizeof(int)); //dim folio contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            ArchivoIn.read((char*)&dim_cli, sizeof(int)); //dim cli contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            ArchivoIn.read((char*)&dim_fecha, sizeof(int)); //dim fecha contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            ArchivoIn.read((char*)&dim_tipo, sizeof(int)); //dim tipo contiene el tamaño de la cadena a leer
            ArchivoIn.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0';
            if(strcmp(folio_search, folio_ven) == 0){ //Comparacion de campo clave con la busqueda
                cout<<"Folio\tID del Cliente\tFecha\tTipo de Venta\n";
                cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<endl;
                flag=1;
            }
        }
        if(!flag) cout<<"\nFolio No Encontrado.";
    }
    ArchivoIn.close();    
        }

int main(){
    system("cls");
    cout<<"\n\t\tFolios de Venta\n\n";
    do{
        cout<<"\t1. Agregar\n\t2. Mostrar\n\t3. Buscar\n\t4. Modificar\n\t5. Eliminar\n";
        cin>>opc;
        switch(opc){
            case 1:{ven.Agregar();break;};
            case 2:{ven.Mostrar();break;};
            case 3:{ven.Buscar();break;};
            case 4:{ven.Modificar();break;};
            case 5:{ven.Eliminar();break;};
            case 0:{system("pause");break;};
        }
    }while(opc!=0);
    return 0;
}

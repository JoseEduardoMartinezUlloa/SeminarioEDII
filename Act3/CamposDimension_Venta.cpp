// Registros de Longitud variable (campos de dimensión)
// Jose Eduardo Martinez Ulloa
// Seminario de Solucion de Problemmas de Estructura de Datos II


#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"

void clear_screen(){std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;}

inline void Pause(){
    std::string dummy;
    std::cout << "Presione Entrar para continuar..." << std::endl;
    getline(std::cin, dummy);
}
class Venta{
    public:

    char folio_ven[11], id_cli[11], fecha_ven[11], tipo_ven[2];

    void Agregar();
    void Mostrar();
    void Modificar();
    void Eliminar();
    void Buscar();
};



void Venta::Agregar(){
    int dim_folio, dim_cli, dim_fecha, dim_tipo = 0;
    std::ofstream wFile("FoliosVentas.txt", std::ios::app);

    std::cout<<"Ingrese el Folio de Venta: ";
    std::cin.ignore();
    std::cin.getline(folio_ven, 11);
    std::cout<<"Ingrese el ID del Cliente: ";
    std::cin.getline(id_cli, 11);
    std::cout<<"Ingrese la Fecha de Venta (DD/MM/AAAA): ";
    std::cin.getline(fecha_ven, 11);
    std::cout<<"Ingrese el Tipo de Venta (S - Sucursal/T - Telefono): ";
    std::cin.getline(tipo_ven, 2);

    dim_folio = strlen(folio_ven);
    dim_cli = strlen(id_cli);
    dim_fecha = strlen(fecha_ven);
    dim_tipo = strlen(tipo_ven);

    wFile.write((char*)&dim_folio,sizeof(int));
    wFile.write((char*)&folio_ven,dim_folio);

    wFile.write((char*)&dim_cli,sizeof(int));
    wFile.write((char*)&id_cli,dim_cli);

    wFile.write((char*)&dim_fecha,sizeof(int));
    wFile.write((char*)&fecha_ven,dim_fecha);

    wFile.write((char*)&dim_tipo,sizeof(int));
    wFile.write((char*)&tipo_ven,dim_tipo);

    wFile.close();
    Pause();
}

void Venta::Mostrar(){
    int dim_folio, dim_cli, dim_fecha, dim_tipo = 0;
    std::ifstream rFile("FoliosVentas.txt");
    if(!rFile.good()) std::cout<<"\nEl Archivo no existe..."<<std::endl;
    else{
        std::cout<<"Folio\tID del Cliente\tFecha\t\tTipo de Venta"<<std::endl;
        while(!rFile.eof()){
            rFile.read((char*)&dim_folio, sizeof(int));
            rFile.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            rFile.read((char*)&dim_cli, sizeof(int));
            rFile.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            rFile.read((char*)&dim_fecha, sizeof(int));
            rFile.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            rFile.read((char*)&dim_tipo, sizeof(int));
            rFile.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(!rFile.eof()) std::cout<<folio_ven<<"\t"<<id_cli<<"\t\t"<<fecha_ven<<"\t"<<tipo_ven<<std::endl;
        }
    }
    std::cout<<std::endl;
    rFile.close();
    std::cin.ignore();
    Pause();
}

void Venta::Modificar(){
    int dim_folio, dim_cli, dim_fecha, dim_tipo = 0;
    bool found = false;
    char srch_folio[11];
    char confirm;

    std::ifstream rFile("FoliosVentas.txt");
    std::fstream tempFile("TempVentas.txt", std::ios::app);
    if(!rFile.good()) std::cout<<"\nArchivo no encontrado."<<std::endl;
    else{
        std::cout<<"Ingrese el Folio de Venta a Modificar: ";
        std::cin.ignore();
        std::cin.getline(srch_folio, 11);
        while(!rFile.eof()){
            rFile.read((char*)&dim_folio, sizeof(int));
            rFile.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            rFile.read((char*)&dim_cli, sizeof(int));
            rFile.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            rFile.read((char*)&dim_fecha, sizeof(int));
            rFile.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            rFile.read((char*)&dim_tipo, sizeof(int));
            rFile.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(strcmp(srch_folio, folio_ven) == 0){
                std::cout<<"Folio\tID del Cliente\tFecha\t\tTipo de Venta"<<std::endl;
                std::cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<std::endl;
                found=true;
                std::cout<<"Desea Modificar este folio? (Y/n): ";
                std::cin>>confirm;
                if(confirm=='y'||confirm=='Y'){
                    std::cout<<"Ingrese el Folio de Venta: ";
                    std::cin.getline(folio_ven, 11);
                    std::cin.getline(folio_ven, 11);
                    std::cout<<"Ingrese el ID del Cliente: ";
                    std::cin.getline(id_cli, 11);
                    std::cout<<"Ingrese la Fecha de Venta (DD/MM/AAAA): ";
                    std::cin.getline(fecha_ven, 11);
                    std::cout<<"Ingrese el Tipo de Venta (Tienda/Telefono): ";
                    std::cin.getline(tipo_ven, 21);
                }else std::cout<<"No confirmado. Modificacion cancelada."<<std::endl;
            }
        if(!rFile.eof()){
            tempFile.write((char*)&dim_folio, sizeof(int));
            tempFile.write((char*)&folio_ven, dim_folio); 
            tempFile.write((char*)&dim_cli, sizeof(int));
            tempFile.write((char*)&id_cli, dim_cli);
            tempFile.write((char*)&dim_fecha, sizeof(int));
            tempFile.write((char*)&fecha_ven, dim_fecha);
            tempFile.write((char*)&dim_tipo, sizeof(int));
            tempFile.write((char*)&tipo_ven, dim_tipo);
        }
        }
        if (!found) std::cout << "Folio no encontrado." << std::endl;
    }
    tempFile.close();
    rFile.close();
    remove("FoliosVentas.txt");
    rename("TempVentas.txt", "FoliosVentas.txt");
    Pause();
}

void Venta::Eliminar(){
    int dim_folio, dim_cli, dim_fecha, dim_tipo = 0;
    bool found = false;
    bool passable = true;
    char srch_folio[11];
    char confirm;

    std::ifstream rfile("foliosVentas.txt");
    std::ofstream tempfile("tempVentas.txt", std::ios::app);
    if(!rfile.good()) std::cout<<"El archivo no fue encontrado.";
    else{
        std::cout<<"Ingrese el folio a eliminar: ";
        std::cin.ignore();
        std::cin.getline(srch_folio, 11);
        while(!rfile.eof()){
            rfile.read((char*)&dim_folio, sizeof(int));
            rfile.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            rfile.read((char*)&dim_cli, sizeof(int));
            rfile.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            rfile.read((char*)&dim_fecha, sizeof(int));
            rfile.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            rfile.read((char*)&dim_tipo, sizeof(int));
            rfile.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(strcmp(srch_folio, folio_ven) == 0){
                found = true;
                std::cout<<"Folio\tID del Cliente\tFecha\t\tTipo de Venta"<<std::endl;
                std::cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<std::endl;
                found=true;
                std::cout<<"Desea eliminar este folio? (Y/n): ";
                std::cin>>confirm;
                if(confirm=='y'||confirm=='Y') passable = false;
                else std::cout<<"No confirmado. Eliminacion cancelada.";
            }
        if(passable==true&&!rfile.eof()){
            tempfile.write((char*)&dim_folio, sizeof(int));
            tempfile.write((char*)&folio_ven, dim_folio); 
            tempfile.write((char*)&dim_cli, sizeof(int));
            tempfile.write((char*)&id_cli, dim_cli);
            tempfile.write((char*)&dim_fecha, sizeof(int));
            tempfile.write((char*)&fecha_ven, dim_fecha);
            tempfile.write((char*)&dim_tipo, sizeof(int));
            tempfile.write((char*)&tipo_ven, dim_tipo);
        }    
        passable=true;
        }
    }
    tempfile.close();
    rfile.close();
    remove("foliosVentas.txt");
    rename("TempVentas.txt", "FoliosVentas.txt");
    std::cin.ignore();
    Pause();
}


void Venta::Buscar(){
    int dim_folio, dim_cli, dim_fecha, dim_tipo = 0;
    char srch_folio[11];
    bool found = false;

    std::ifstream rFile("FoliosVentas.txt");
    if(!rFile.good()){ std::cout<<"\nArchivo No Encontrado."; }
    else{
        std::cout<<"Ingrese el folio a buscar: ";
        std::cin.ignore();
        std::cin.getline(srch_folio, 11);
        while(!rFile.eof()){
            rFile.read((char*)&dim_folio, sizeof(int));
            rFile.read((char*)&folio_ven, dim_folio);
            folio_ven[dim_folio]='\0';

            rFile.read((char*)&dim_cli, sizeof(int));
            rFile.read((char*)&id_cli, dim_cli);
            id_cli[dim_cli]='\0';

            rFile.read((char*)&dim_fecha, sizeof(int));
            rFile.read((char*)&fecha_ven, dim_fecha);
            fecha_ven[dim_fecha]='\0';

            rFile.read((char*)&dim_tipo, sizeof(int));
            rFile.read((char*)&tipo_ven, dim_tipo);
            tipo_ven[dim_tipo]='\0'; 

            if(strcmp(srch_folio, folio_ven) == 0){
                found = true;
                std::cout<<"Folio\tID del Cliente\tFecha\t\tTipo de Venta"<<std::endl;
                std::cout<<folio_ven<<"\t"<<id_cli<<"\t"<<fecha_ven<<"\t"<<tipo_ven<<std::endl;
            }
        }
        if(!found) std::cout<<"\nFolio No Encontrado."<<std::endl;
    }
    rFile.close();    
    Pause();
}

int main(){
    Venta ven;
    int sel=0;
    
    do{
        clear_screen();
        std::cout<<"\tFolios de Venta"<<std::endl<<std::endl;
        std::cout<<"1 - Registrar un cliente"<<std::endl;
        std::cout<<"2 - Mostrar los clientes registrados"<<std::endl;
        std::cout<<"3 - Buscar un cliente"<<std::endl;
        std::cout<<"4 - Modificar datos de un cliente"<<std::endl;
        std::cout<<"5 - Eliminar un cliente"<<std::endl;
        std::cout<<"6 - Salir del programa"<<std::endl;
        std::cout<<"Su seleccion: ";
        std::cin.clear();
        std::cin>>sel;
        switch(sel){
            case 1:{ven.Agregar(); break;};
            case 2:{ven.Mostrar(); break;};
            case 3:{ven.Buscar(); break;};
            case 4:{ven.Modificar(); break;};
            case 5:{ven.Eliminar(); break;};
            case 6:{Pause(); break;};
        }
    }while(sel!=6);
    return 0;
}

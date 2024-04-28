//Registros de longitud fija (Acceso Directo)
//Jose Eduardo Martinez Ulloa
//Seminario de Solucion de Problemas de Estructuras de Datos II

#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>

void clear_screen(){std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;}

inline void Pause(){
    std::string dummy;
    std::cout << "Presione Entrar para continuar..." << std::endl;
    getline(std::cin, dummy);
}

class Compra{
    public:
    char folio_compra[5], fecha_compra[11],id_proveedor[5];
    void Add();
    void Show();
    void Search();
    void Modify();
    void Delete();
}Cmpr;

void Compra::Add(){
    clear_screen();
    std::cout<<"Folio de Compra (xxxx): ";
    std::cin.ignore();
    std::cin.getline(folio_compra, 5); 
    std::cout<<"Fecha (DD/MM/AAAA): ";
    std::cin.getline(fecha_compra, 11);
    std::cout<<"ID del proveedor (xxxx): ";
    std::cin.getline(id_proveedor, 5);
    std::ofstream myFile("compraSimple.txt", std::ios::app);
    myFile.write((char*)&Cmpr,sizeof(Cmpr));
    myFile.close();
}
void Compra::Show() {
    char folio_compra[4], fecha_compra[10],id_proveedor[4];
    int band=0;
    std::ifstream myFile("compraSimple.txt");
    clear_screen();
    if(!myFile.good()) std::cout<<"\n Archivo no encontrado."<<std::endl;
    else{
        std::cout<<std::endl<<"\tOrdenes de Compra"<<std::endl;
        while(!myFile.eof()){
            myFile.read((char*)&Cmpr,sizeof(Cmpr));
            if(myFile.eof()) break;
        std::cout<<std::endl<<"No. Orden de Compra: "<<Cmpr.folio_compra<<std::endl;
        std::cout<<"Fecha: "<<Cmpr.fecha_compra<<std::endl;
        std::cout<<"ID de Proveedor: "<<Cmpr.id_proveedor<<std::endl;
        }
        myFile.close();
    }
    std::cout<<std::endl;
}

void Compra::Search(){
    char srchfolio[5];
    bool found = false;
    std::ifstream myFile("compraSimple.txt");
    clear_screen();
    if(!myFile.good()) std::cout<<"\n Archivo no encontrado."<<std::endl;
    else{
        std::cout << "\tBusqueda de Ordenes" << std::endl;
        std::cout << "Folio a buscar (xxxx): ";
        std::cin.ignore();
        std::cin.getline(srchfolio, 5);
        while (!myFile.eof()) {
            myFile.read((char*)&Cmpr, sizeof(Cmpr));
            if (myFile.eof()) break;
            if (strcmp(folio_compra, srchfolio) == 0) {
                std::cout<<std::endl<<"Orden de compra: "<<folio_compra<<std::endl;
                std::cout<<"Fecha de compra: "<<fecha_compra <<std::endl;
                std::cout<<"ID de Proveedor: " <<id_proveedor <<std::endl;
                found = true;
                break;
            }
        }
        if (!found) std::cout << "Orden no encontrada." << std::endl;
    }
    std::cout<<std::endl;
    myFile.close();
}

void Compra::Modify(){
    char srchfolio[5];
    bool found = false;

    std::fstream myFile("compraSimple.txt", std::ios::in | std::ios::out);
    if (!myFile.good()) {
        std::cout << "\n Archivo no encontrado." << std::endl;
    } else {
        std::cout << "\tModificacion de Ordenes" << std::endl;
        std::cout << "Folio a buscar (xxxx): ";
        std::cin.ignore();
        std::cin.getline(srchfolio, 5);
        while (!myFile.eof()) {
            myFile.read((char*)&Cmpr, sizeof(Cmpr));
            if (myFile.eof()) break;

            if (strcmp(folio_compra, srchfolio) == 0) {
                std::cout << "Orden de compra encontrada:" << std::endl;
                std::cout << "No. Orden de Compra: " << folio_compra << std::endl;
                std::cout << "Fecha: " << fecha_compra << std::endl;
                std::cout << "ID de Proveedor: " << id_proveedor << std::endl;
                std::cout <<"Nueva fecha (DD/MM/AAAA): ";
                std::cin.getline(fecha_compra, 11);
                std::cout<<"Nuevo ID de Proveedor: ";
                std::cin.getline(id_proveedor,5);

                myFile.seekp(-static_cast<int>(sizeof(Cmpr)), std::ios::cur);
                myFile.write((char*)&Cmpr, sizeof(Cmpr));
                found = true;
                break;
            }
        }
        if (!found) std::cout << "Orden no encontrada." << std::endl;
        myFile.close();
    }
    std::cout << std::endl;
}
// void Compra::Delete(){
//     char srchfolio[5];
    
//     char confirm;

//     std::ifstream myFile("compraSimple.txt", std::ios::in| std::ios::out);
//     std::fstream TempFile("tempCompraSimple.txt", std::ios::out);
//     if (!myFile.good()) {
//         std::cout << "\n Archivo no encontrado." << std::endl;
//     } else {
//         bool found = false;
//         std::cout << "\tEliminacion de Ordenes" << std::endl;
//         std::cout << "Folio a eliminar (xxxx): ";
//         std::cin.ignore();
//         std::cin.getline(srchfolio, 5);
//         while (!myFile.eof()) {
//             myFile.read((char*)&Cmpr, sizeof(Cmpr));
//             if (myFile.eof()) break;
//             if (strcmp(folio_compra, srchfolio) == 0) {
//                 std::cout << "Orden de compra encontrada:" << std::endl;
//                 std::cout << "No. Orden de Compra: " << folio_compra << std::endl;
//                 std::cout << "Fecha: " << fecha_compra << std::endl;
//                 std::cout << "ID de Proveedor: " << id_proveedor << std::endl;
//                 std::cout << "Desea eleminar el registro? S/N: ";
//                 std::cin >> confirm;
//                 if(confirm=='S'|| confirm=='s'){
//                     found = true;
//                     std::cout<<"Aceptado, eliminando..."<<std::endl;
//                 }
//                 else TempFile.write((char*)&Cmpr, sizeof(Cmpr));
//             }
//         }
//         myFile.close();
//         TempFile.close();
//         if (!found) std::cout << "Orden no encontrada." << std::endl;
//         std::remove("compraSimple.txt");
//         std::rename("tempCompraSimple.txt", "compraSimple.txt");
//     }
// }
void Compra::Delete() {
    char srchfolio[5];
    std::fstream myFile("compraSimple.txt", std::ios::in | std::ios::out);
    if (!myFile.good()) {
        std::cout << "\n Archivo no encontrado." << std::endl;
    } else {
        std::cout << "\tEliminacion de Ordenes" << std::endl;
        std::cout << "Folio a buscar (xxxx): ";
        std::cin.ignore();
        std::cin.getline(srchfolio, 5);

        bool found = false;
        std::fstream tempFile("tempCompraSimple.txt", std::ios::out); // Declare tempFile

        while (!myFile.eof()) {
            myFile.read((char*)&Cmpr, sizeof(Cmpr));
            if (myFile.eof()) break;

            if (strcmp(folio_compra, srchfolio) == 0) {
                std::cout << "Orden de compra encontrada y eliminada:" << std::endl;
                std::cout << "No. Orden de Compra: " << folio_compra << std::endl;
                std::cout << "Fecha: " << fecha_compra << std::endl;
                std::cout << "ID de Proveedor: " << id_proveedor << std::endl;
                char confirm;
                std::cout << "¿Desea eliminar esta orden? (S/N): ";
                std::cin >> confirm;
                if (confirm == 's' || confirm == 'S') {
                    found = true;
                    std::cout<<"Confirmado, eliminando..."<<std::endl;
                    continue; // Skip writing this record to temp file
                }
            } else {
                tempFile.write((char*)&Cmpr, sizeof(Cmpr));
            }
        }

        if (!found) {
            std::cout << "Orden no encontrada." << std::endl;
        }

        myFile.close();
        tempFile.close();

        // Replace the original file with the modified content
        std::remove("compraSimple.txt");
        std::rename("tempCompraSimple.txt", "compraSimple.txt");
    }
    std::cout << std::endl;
}

int main(){
    int sel;
    do{
    std::cout<<"Menu de Ordenes de Compra"<<std::endl;
    std::cout<<"1. Captura una nueva orden de compra" <<std::endl;
    std::cout<<"2. Muestra las ordenes registradas" <<std::endl;
    std::cout<<"3.-Modifica una orden existente"<<std::endl;
    std::cout<<"4.-Elimina una orden existente" <<std::endl;
    std::cout<<"5.-Busca una orden existente "<<std::endl;
    std::cout<<"6.-Salir del programa"<<std::endl;
    std::cout<<"Ingresa la opcion: ";
    std::cin>>sel;
    switch (sel)
    {
    case 1:
        clear_screen();
        Cmpr.Add();
        break;
    case 2:
        clear_screen();
        Cmpr.Show();
        break;
    case 3:
        clear_screen();
        Cmpr.Modify();
        break;
    case 4:
        clear_screen();
        Cmpr.Delete();
        break;
    case 5:
        clear_screen();
        Cmpr.Search();
        break;
    case 6:
        std::cout<<"Saliendo del programa..."<<std::endl;
    default:
        break;
    }
    }while(sel!=6);
    std::cin.ignore();
    Pause();
    return 0;
}
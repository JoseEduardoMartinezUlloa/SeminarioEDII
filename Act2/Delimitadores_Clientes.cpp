//Delimitadores (Tabla Clientes)
//Jose Eduardo Martinez Ulloa
//Seminario de Solucion de Problemas de Estructuras de Datos II

#include <iostream>
#include <fstream> 
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void clear_screen(){for (int i = 0; i < 25; i++) std::cout<<std::endl;}

inline void Pause(){
    std::string dummy;
    std::cout << "Presione Entrar para continuar..." << std::endl;
    std::cin.ignore();
}

class Cli{
    public:

    char id_cli[10], firstn_cli[25], lastn_p_cli[20], lastn_m_cli[20], bday_cli[11], phonenum_cli[11], mail_cli[50];
    void Add();
    void Show();
    void Search();
    void Delete();
    void Mod();
    void GetField(std::ifstream&, std::string&);
};

void Cli::Add()
{
    clear_screen();
    std::cout<<"Codigo del cliente: ";
    std::cin.ignore();
    std::cin.getline(id_cli, 10);
    std::cout<<"Ingrese el nombre (sin apellidos) del cliente: ";
    std::cin.getline(firstn_cli,25);
    std::cout<<"Ingrese el apellido paterno del cliente: ";
    std::cin.getline(lastn_p_cli,20);
    std::cout<<"Ingrese el apellido materno del cliente: ";
    std::cin.getline(lastn_m_cli,20);
    std::cout<<"Ingrese la fecha de nacimiento del cliente (DD/MM/AAAA): ";
    std::cin.getline(bday_cli,11);
    std::cout<<"Ingrese el numero de telefono del cliente (10 digitos): ";
    std::cin.getline(phonenum_cli,11);
    std::cout<<"Ingrese el correo electronico del cliente: ";
    std::cin.getline(mail_cli,50);
    std::ofstream wFile("InfoClientes.txt",std::ios::app);
    wFile<<id_cli<<'|'<<firstn_cli<<'|'<<lastn_p_cli<<'|'<<lastn_m_cli<<'|'<<bday_cli<<'|'<<phonenum_cli<<'|'<<mail_cli<<'|';
    wFile.close();
    std::cout<<std::endl;
}

void Cli::GetField(std::ifstream& logic_file, std::string& field){
    char c;
    while (logic_file.get(c)) {
        if (c == '|') break;
        field += c;
    }
}

void Cli::Show(){
    std::ifstream wFile("InfoClientes.txt");
    clear_screen();
    if(!wFile.good()){ std::cout<<"Archivo no encontrado.\n"; Pause(); }
    else{
        std::cout<<"\tLista de clientes registrados"<<std::endl;
        while(!wFile.eof()){
            std::string id_cli, firstn_cli, lastn_p_cli, lastn_m_cli, bday_cli, phonenum_cli, mail_cli;
            GetField(wFile,id_cli);
            GetField(wFile,firstn_cli);
            GetField(wFile,lastn_p_cli);
            GetField(wFile,lastn_m_cli);
            GetField(wFile,bday_cli);
            GetField(wFile,phonenum_cli);
            GetField(wFile,mail_cli);
            if(!id_cli.empty()){
            std::cout << "\nCodigo del Cliente: " << id_cli << std::endl;
            std::cout << "Nombre Completo: " << firstn_cli << " " << lastn_p_cli << " " << lastn_m_cli << std::endl;
            std::cout << "Fecha de Nacimiento: " << bday_cli << std::endl;
            std::cout << "Numero de Telefono: " << phonenum_cli << std::endl;
            std::cout << "Correo Electronico: " << mail_cli << std::endl;
            }
        }
    wFile.close();
    }
    std::cout<<std::endl;
    std::cin.ignore();
    Pause();
}

void Cli::Search(){
    char srch_id[10];
    bool found = false;
    std::ifstream rFile("InfoClientes.txt");

    clear_screen();
    if(!rFile.good()){std::cout<<"\n Archivo no encontrado."<<std::endl; return;} 

    std::cout<<"\tBusqueda de Clientes\n"<<std::endl;
    std::cout<<"ID de cliente a buscar: ";
    std::cin.ignore();
    std::cin.getline(srch_id, 10);
    while(!rFile.eof()){
    std::string id_cli, firstn_cli, lastn_p_cli, lastn_m_cli, bday_cli, phonenum_cli, mail_cli;
        GetField(rFile,id_cli);
        GetField(rFile,firstn_cli);
        GetField(rFile,lastn_p_cli);
        GetField(rFile,lastn_m_cli);
        GetField(rFile,bday_cli);
        GetField(rFile,phonenum_cli);
        GetField(rFile,mail_cli);
        if(srch_id==id_cli){
        found = true;
        std::cout << "\nCodigo del Cliente: " << id_cli << std::endl;
        std::cout << "Nombre Completo: " << firstn_cli << " " << lastn_p_cli << " " << lastn_m_cli << std::endl;
        std::cout << "Fecha de Nacimiento: " << bday_cli << std::endl;
        std::cout << "Numero de Telefono: " << phonenum_cli << std::endl;
        std::cout << "Correo Electronico: " << mail_cli << std::endl;
        break;
        }
    }
    rFile.close();
    if (!found) std::cout << "Cliente con ID " << srch_id << " no encontrado."<<std::endl;
    Pause();
 }

void Cli::Delete(){
    char srch_id[10];
    char confirm;
    bool found = false;
    std::ifstream rFile("InfoClientes.txt");
    clear_screen();
    if(!rFile.good()){ std::cout<<"\n Archivo no encontrado."<<std::endl; return; } 
    std::ofstream wFile("TempInfoClientes.txt");
    std::cout<<"\tEliminacion de Clientes\n"<<std::endl;
    std::cout<<"ID de cliente a eliminar: ";
    std::cin.ignore();
    std::cin.getline(srch_id, 10);

    while(!rFile.eof()){
    std::string id_cli, firstn_cli, lastn_p_cli, lastn_m_cli, bday_cli, phonenum_cli, mail_cli;
        GetField(rFile,id_cli);
        GetField(rFile,firstn_cli);
        GetField(rFile,lastn_p_cli);
        GetField(rFile,lastn_m_cli);
        GetField(rFile,bday_cli);
        GetField(rFile,phonenum_cli);
        GetField(rFile,mail_cli);
        if(srch_id==id_cli){
            found = true;
            std::cout << "\nCodigo del Cliente: " << id_cli << std::endl;
            std::cout << "Nombre Completo: " << firstn_cli << " " << lastn_p_cli << " " << lastn_m_cli << std::endl;
            std::cout << "Fecha de Nacimiento: " << bday_cli << std::endl;
            std::cout << "Numero de Telefono: " << phonenum_cli << std::endl;
            std::cout << "Correo Electronico: " << mail_cli << std::endl;
            std::cout << "Desea eliminar el registro? (Y/n): ";
            std::cin>>confirm;
            if(confirm == 'Y' || confirm == 'y') continue;
            else{
                std::cout << "No confirmado, eliminacion cancelada." << std::endl;
                wFile << id_cli << "|" << firstn_cli << "|" << lastn_p_cli << "|" << lastn_m_cli << "|" << bday_cli << "|" << phonenum_cli << "|" << mail_cli << "|";    
            }
        }
        else if(!id_cli.empty()) wFile << id_cli << "|" << firstn_cli << "|" << lastn_p_cli << "|" << lastn_m_cli << "|" << bday_cli << "|" << phonenum_cli << "|" << mail_cli << "|";
    }
    rFile.close();
    wFile.close();
    std::remove("InfoClientes.txt");
    std::rename("TempInfoClientes.txt","InfoClientes.txt");
    if (!found) {std::cout << "Cliente con ID " << srch_id << " no encontrado."<<std::endl; Pause(); return; }
    std::cin.ignore();
    Pause();
}

void Cli::Mod(){
    char srch_id[10];
    char confirm;
    bool found = false;
    std::ifstream rFile("InfoClientes.txt");
    clear_screen();
    if(!rFile.good()){ std::cout<<"\n Archivo no encontrado."<<std::endl; return; } 
    std::ofstream wFile("TempInfoClientes.txt");
    std::cout<<"\tModificacion de Clientes\n"<<std::endl;
    std::cout<<"ID de cliente a modificar: ";
    std::cin.ignore();
    std::cin.getline(srch_id, 10);

    while(!rFile.eof()){
    std::string id_cli, firstn_cli, lastn_p_cli, lastn_m_cli, bday_cli, phonenum_cli, mail_cli;
    char wid_cli[10], wfirstn_cli[25], wlastn_p_cli[20], wlastn_m_cli[20], wbday_cli[11], wphonenum_cli[11], wmail_cli[50];
        GetField(rFile,id_cli);
        GetField(rFile,firstn_cli);
        GetField(rFile,lastn_p_cli);
        GetField(rFile,lastn_m_cli);
        GetField(rFile,bday_cli);
        GetField(rFile,phonenum_cli);
        GetField(rFile,mail_cli);
        if(srch_id==id_cli){
            int sel=0;
            found = true;
            std::cout << "\nCodigo del Cliente: " << id_cli << std::endl;
            std::cout << "Nombre Completo: " << firstn_cli << " " << lastn_p_cli << " " << lastn_m_cli << std::endl;
            std::cout << "Fecha de Nacimiento: " << bday_cli << std::endl;
            std::cout << "Numero de Telefono: " << phonenum_cli << std::endl;
            std::cout << "Correo Electronico: " << mail_cli << std::endl;
            std::cout << "\n1) Modificar Codigo"<< std::endl;
            std::cout << "2) Modificar Nombre"<< std::endl;
            std::cout << "3) Modificar Apellido Paterno"<< std::endl;
            std::cout << "4) Modificar Apellido Materno"<< std::endl;
            std::cout << "5) Modificar Fecha de Nacimiento"<< std::endl;
            std::cout << "6) Modificar Numero de Telefono"<< std::endl;
            std::cout << "7) Modificar Correo Electronico"<< std::endl;
            std::cout << "8) Cancelar Modificacion"<< std::endl;
            std::cout << "Su seleccion: ";
            std::cin>>sel;
            switch(sel){
                case 1:
                    std::cout<<"Nuevo Codigo: ";
                    std::cin.ignore();
                    std::cin.getline(wid_cli, 10);
                    id_cli=wid_cli;
                    break;
                case 2:
                    std::cout<<"Nuevo Nombre: ";
                    std::cin.ignore();
                    std::cin.getline(wfirstn_cli, 25);
                    firstn_cli=wfirstn_cli;
                    break;
                case 3:
                    std::cout<<"Nuevo Apellido Paterno: ";
                    std::cin.ignore();
                    std::cin.getline(wlastn_p_cli, 20);
                    lastn_p_cli=wlastn_p_cli;
                    break;
                case 4:
                    std::cout<<"Nuevo Apellido Materno: ";
                    std::cin.ignore();
                    std::cin.getline(wlastn_m_cli, 20);
                    lastn_m_cli=wlastn_m_cli;
                    break;
                case 5:
                    std::cout<<"Nueva Fecha de Nacimiento (DD/MM/AAAA): ";
                    std::cin.ignore();
                    std::cin.getline(wbday_cli, 11);
                    bday_cli=wbday_cli;
                    break;
                case 6:
                    std::cout<<"Nuevo Numero de Telefono: ";
                    std::cin.ignore();
                    std::cin.getline(wphonenum_cli, 11);
                    phonenum_cli=wphonenum_cli;
                    break;
                case 7:
                    std::cout<<"Nuevo Correo Electronico: ";
                    std::cin.ignore();
                    std::cin.getline(wmail_cli, 50);
                    mail_cli=wmail_cli;
                    Pause();
                    break;
                case 8:
                    std::cout<<"Modificacion Cancelada. Regresando al Menu de Clientes..."; 
                    break;
                default: std::cout << "Opcion invalida."<<std::endl; break;
            }
        }
    if(!id_cli.empty()) wFile<<id_cli<<"|"<<firstn_cli<<"|"<<lastn_p_cli<<"|"<<lastn_m_cli<<"|"<<bday_cli<<"|"<<phonenum_cli<<"|"<<mail_cli<<"|";
    }
    rFile.close();
    wFile.close();
    std::remove("InfoClientes.txt");
    std::rename("TempInfoClientes.txt","InfoClientes.txt");
    if (!found) {std::cout << "Cliente con ID " << srch_id << " no encontrado."<<std::endl; Pause(); return; }
    std::cin.ignore();
    Pause();
}

int main(){
    int opc;
    Cli cli;
    do{
    std::cout<<"\tMenu de Clientes"<<std::endl;
    std::cout<<"1 - Registrar un cliente"<<std::endl;
    std::cout<<"2 - Mostrar todos los registros"<<std::endl;
    std::cout<<"3 - Buscar un registro"<<std::endl;
    std::cout<<"4 - Eliminar un registro"<<std::endl;
    std::cout<<"5 - Modificar un registro"<<std::endl;
    std::cout<<"6 - Salir del sistema"<<std::endl;
    std::cout<<"\nSu seleccion: ";
    std::cin.clear();
    std::cin>>opc;
    switch(opc){
    case 1:{ cli.Add(); break;}
    case 2:{ cli.Show(); break;}
    case 3:{ cli.Search(); break;}
    case 4:{ cli.Delete(); break;}
    case 5:{ cli.Mod(); break;}
    case 6: std::cout<<"Saliendo del programa..."<<std::endl; break;
    default: std::cout<<"Opcion Invalida.\n"<<std::endl; break;
    }
    } while(opc!=6);
    std::cin.ignore();
    Pause();
    return 0;
}
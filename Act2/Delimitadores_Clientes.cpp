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
        else wFile << id_cli << "|" << firstn_cli << "|" << lastn_p_cli << "|" << lastn_m_cli << "|" << bday_cli << "|" << phonenum_cli << "|" << mail_cli << "|";
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
                    std::cin.getline(srch_id, 10);
                    break;
                case 2:
                    std::cout<<"Nuevo Nombre: ";
                    std::cin.getline(firstn_cli, 25);
                    break;
                case 3:
                    std::cout<<"Nuevo Apellido Paterno: ";
                    std::cin.getline(lastn_p_cli, 20);
                    break;
                case 4:
                    std::cout<<"Nuevo Apellido Materno: ";
                    std::cin.getline(lastn_m_cli, 20);
                    break;
                case 5:
                    std::cout<<"Nueva Fecha de Nacimiento (DD/MM/AAAA): ";
                    std::cin.getline(bday_cli, 10);
                    break;
                case 6:
                    std::cout<<"Nuevo Numero de Telefono: ";
                    std::cin.getline(phonenum_cli, 10);
                    break;
                case 7:
                    std::cout<<"Nuevo Correo Electronico: ";
                    std::cin.getline(mail_cli, 10);
                    break;
                case 8:
                    std::cout<<"Modificacion Cancelada. Regresando al Menu de Clientes..."; 
                    break;
                default: std::cout << "Opcion invalida."<<std::endl;
            }
        }
    wFile<<id_cli<<"|"<<firstn_cli<<"|"<<lastn_p_cli<<"|"<<lastn_m_cli<<"|"<<bday_cli<<"|"<<phonenum_cli<<mail_cli<<"|";
    }
    rFile.close();
    wFile.close();
    std::remove("InfoClientes.txt");
    std::rename("TempInfoClientes.txt","InfoClientes.txt");
    if (!found) {std::cout << "Cliente con ID " << srch_id << " no encontrado."<<std::endl; Pause(); return; }
    std::cin.ignore();
    Pause();
}


//             if(strcmp(id_cli,id_cli_mod)==0 && !b)
//             {
//                 cout<<endl<<"\nCodigo del Cliente: "<<id_cli<<endl<<"\nNombre Completo: "<<nombre_cli<<" "<<apellido_pat_cli<<" "<<apellido_mat_cli<<"\nFecha de Nacimiento:"<<fecha_nac_cli<<"\nNumero de Telefono: "<<num_tel_cli<<"\nCorreo Electronico: "<<mail_cli<<"\n";

//                 cout <<"\n Seleccione el Dato a Modificar:\n";
//                 cout <<"\n 1) Modificar Codigo: ";
//                 cout <<"\n 2) Modificar Nombre: ";
//                 cout <<"\n 3) Modificar Apellido Paterno: ";
//                 cout <<"\n 4) Modificar Apellido Materno: ";
//                 cout <<"\n 5) Modificar Fecha de Nacimiento: ";
//                 cout <<"\n 6) Modificar Numero de Telefono: ";
//                 cout <<"\n 7) Modificar Correo Electronico: ";
//                 cout <<"\n 8) Regresar: ";

//                 cout<<"\n   Elige la opcion a realizar: ";
//                 cin>>opcion;


//                 switch(opcion) ///switch para realizar las modificaciones
//                 {
//                     case 1: //nuevo id_cli
//                         cout<<"\n Ingrese el Nuevo Codigo del Cliente: ";
//                         cin.getline(id_cli,10);
//                         cin.getline(id_cli,10);
//                         break;
//                     case 2://nuevo nombre_cli
//                         cout<<"\n Ingrese el Nuevo Nombre del Cliente: ";
//                         cin.getline(nombre_cli,35);
//                         cin.getline(nombre_cli,35);
//                         break;
//                     case 3: //nuevo apellido_pat_cli
//                         cout<<"\n Ingrese el Nuevo Apellido Paterno del Cliente: ";
//                         cin.getline(apellido_pat_cli,15);
//                         cin.getline(apellido_pat_cli,15);
//                         break;
//                     case 4: //nuevo apellido_mat_cli
//                         cout<<"\n Ingrese el Nuevo Apellido Paterno del Cliente: ";
//                         cin.getline(apellido_mat_cli,15);
//                         cin.getline(apellido_mat_cli,15);
//                         break;
//                     case 5: //nuevo fecha_nac_cli
//                         cout<<"\n Ingrese el Nuevo Apellido Paterno del Cliente: ";
//                         cin.getline(fecha_nac_cli,15);
//                         cin.getline(fecha_nac_cli,15);
//                         break;
//                     case 6: //nuevo num_tel_cli
//                         cout<<"\n Ingrese el Nuevo Apellido Paterno del Cliente: ";
//                         cin.getline(num_tel_cli,15);
//                         cin.getline(num_tel_cli,15);
//                         break;
//                     case 7: //nuevo mail_cli
//                         cout<<"\n Ingrese el Nuevo Apellido Paterno del Cliente: ";
//                         cin.getline(mail_cli,15);
//                         cin.getline(mail_cli,15);
//                         break;
                    
//                     default: cout<<"\n Opcion Invalida.";
//                 }

//                 if(opcion!=8 && opcion>0 && opcion<9)
//                     b = true;
//             }
//             LecturaTemporal<<id_cli<<"|"<<nombre_cli<<"|"<<apellido_pat_cli<<"|"<<apellido_mat_cli<<"|"<<fecha_nac_cli<<"|"<<num_tel_cli<<mail_cli<<"|";
//         }
//         Lectura.close();
//         LecturaTemporal.close();
//         if(!b)
//             cout<<"\n No existe el archivo.";

//         remove("InfoClientes.txt");
//         rename("TempClientes.txt","InfoClientes.txt");
//     }
// }
// xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx //

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
    case 6: std::cout<<"Saliendo del programa..."<<std::endl;
    default: std::cout<<"Opcion Invalida."; break;
    }
    } while(opc!=6);
    std::cin.ignore();
    Pause();
    return 0;
}

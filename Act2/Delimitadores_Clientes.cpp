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
    getline(std::cin, dummy);
}

class Cli
{
public:
    char id_cli[10], firstn_cli[25], lastn_p_cli[20], lastn_m_cli[20], bday_cli[11], phonenum_cli[11], mail_cli[50];
    void Add();
    void Show();
    // void Search();
    // void Delete();
    // void Mod();
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
    Pause();
}

void Cli::Search(){
    int srch_id[10];
    bool found = false;
    std::ifstream rFile("InfoClientes.txt");

    clear_screen();
    if(!rFile.good()){std::cout<<"\n Archivo no encontrado."<<std::endl; return;} 

    std::cout<<"\tBusqueda de Clientes"<<std::endl;
    std::cout<<"ID de cliente a buscar: ";
    std::cin.clear();
    std::cin.getline(srch_id, 10);
    while(!arc.eof()){
    std::string id_cli, firstn_cli, lastn_p_cli, lastn_m_cli, bday_cli, phonenum_cli, mail_cli;
        GetField(wFile,id_cli);
        GetField(wFile,firstn_cli);
        GetField(wFile,lastn_p_cli);
        GetField(wFile,lastn_m_cli);
        GetField(wFile,bday_cli);
        GetField(wFile,phonenum_cli);
        GetField(wFile,mail_cli);
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
        wFile.close();
        if (!found) std::cout << "Cliente con ID " << targetId << " no encontrado.\n";
 }
    

// void Clientes::Eliminar(){
//     int b = 0; // Bandera
//     int i; // Contador
//     int iguales,respuesta; respuesta = 0;
//     char caracter;
//     char id_search[10];


//     ifstream arc("InfoClientes.txt");/* Abrimos el archivo */
//     if(!arc.good())   /* Verificamos si el archivo existe */
//     {
//         cout<<"\n El Archivo No Existe...\n";
//     }

//     else{
//         cout<<"\n Ingrese el Codigo del Cliente A Buscar: ";
//         cin.getline(id_search,10);
//         cin.getline(id_search,10);


//         while(!arc.eof()){

//             //lectura de id_cli
//             i = 0;
//             do{ // ciclo para leer cada uno de los campos
//                 arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
//                 if(caracter!='|')
//                 {
//                     id_cli[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
//                     i++;
//                 }

//             }while(caracter != '|');

//             id_cli[i]= '\0'; // Finaliza la cadena despues del fin del atributo

//             //Lectura de nombre_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|')
//                 {
//                    nombre_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|');
//             nombre_cli[i]= '\0';

//             //Lectura de apellido_pat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_pat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_pat_cli[i]= '\0';

//             //Lectura de apellido_mat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_mat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_mat_cli[i]= '\0';

//             //Lectura de apellido_mat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_mat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_mat_cli[i]= '\0';

//             //Lectura de fecha_nac_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     fecha_nac_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             fecha_nac_cli[i]= '\0';

//             //Lectura de num_tel_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     num_tel_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             num_tel_cli[i]= '\0';

//             //Lectura de mail_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     mail_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             mail_cli[i]= '\0';


//             if(arc.eof())
//             {
//                 break;
//             }

//             iguales = strcmp(id_cli,id_search);

//             if(iguales == 0){
//                 cout<<endl<<"\nCodigo del Cliente: "<<id_cli<<endl<<"\nNombre Completo: "<<nombre_cli<<" "<<apellido_pat_cli<<" "<<apellido_mat_cli<<"\nFecha de Nacimiento:"<<fecha_nac_cli<<"\nNumero de Telefono: "<<num_tel_cli<<"\nCorreo Electronico: "<<mail_cli<<"\n";
//                 b = 1; // Activamos la bandera
//                 break;
//             }
//         }

//         if( b == 0){
//             cout<<"\n\n No Existe el Registro... \n\n";
//         }
//         if(b == 1){
//             cout<<"\n Ingrese \"1\" para Eliminar Este Registro: ";

//             cin>>respuesta;

//             if(respuesta == 1){
//                 ifstream arc ("InfoClientes.txt"); // Abrimos el archivo de datos
//                 ofstream temporal ("TempClientes.txt",ios::app); // Creamos el archivo temporal

//                 while(!arc.eof()){
//                     //lectura de id_cli
//             i = 0;
//             do{ // ciclo para leer cada uno de los campos
//                 arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
//                 if(caracter!='|')
//                 {
//                     id_cli[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
//                     i++;
//                 }

//             }while(caracter != '|');

//             id_cli[i]= '\0'; // Finaliza la cadena despues del fin del atributo

//             //Lectura de nombre_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|')
//                 {
//                    nombre_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|');
//             nombre_cli[i]= '\0';

//             //Lectura de apellido_pat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_pat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_pat_cli[i]= '\0';

//             //Lectura de apellido_mat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_mat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_mat_cli[i]= '\0';

//             //Lectura de apellido_mat_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     apellido_mat_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             apellido_mat_cli[i]= '\0';

//             //Lectura de fecha_nac_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     fecha_nac_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             fecha_nac_cli[i]= '\0';

//             //Lectura de num_tel_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     num_tel_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             num_tel_cli[i]= '\0';

//             //Lectura de mail_cli
//             i = 0;
//             do
//             {
//                 arc.read((char*)&caracter,1);
//                 if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
//                 {
//                     mail_cli[i] = caracter;
//                     i++;
//                 }

//             }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
//             mail_cli[i]= '\0';

//                    if(arc.eof())
//                     {
//                         break;
//                     }

//                     iguales = strcmp(id_cli,id_search);
//                     if(iguales != 0){
//                         temporal <<id_cli<<"|"<<nombre_cli<<"|"<<apellido_pat_cli<<"|"<<apellido_mat_cli<<"|"<<fecha_nac_cli<<"|"<<num_tel_cli<<mail_cli<<"|";

//                     }
//                 } // while

//                 arc.close();
//                 temporal.close();
//                 remove("InfoClientes.txt");
//                 rename("TempClientes.txt","InfoClientes.txt");
//                 cout<<"\n\n El Registro Fue Eliminado Con Exito. \n\n";
//                 b = 1;
//             } // if

//             else {
//                 cout<<"\n El Registro No Fue Eliminado... \n\n";
//             }
//         }
//     }
// }

// void Clientes::Modificar(){
//     int i;//contador
//     int opcion;
//     char id_cli_mod[10];
//     bool b;

//     ifstream Lectura("InfoClientes.txt");/* Abrimos el archivo */
//     ofstream LecturaTemporal("TempClientes.txt",ios::app);

//     if(!Lectura.good())
//         cout<<"\n EL REGISTRO NO EXISTE \n ";
//     else
//     {
//         cout<<"\n Introduce el codigo a modificar :  ";
//         cin.getline(id_cli_mod,10);
//         cin.getline(id_cli_mod,10);

//         b = false;

//         while(!Lectura.eof()){
            
//             //Lectura de id_cli
//             i=0;
//             do{
//                 Lectura.read((char*)&id_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(id_cli[i-1]!='|');
//             id_cli[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

//             //Lectura de nombre_cli
//             i=0;
//             do{
//                 Lectura.read((char*)&nombre_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(nombre_cli[i-1]!='|');
//             nombre_cli[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;


//             //Lectura de apellido_pat_cli
//             i=0;
//             do{// ciclo para leer cada uno de los campos
//                 Lectura.read((char*)&apellido_pat_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(apellido_pat_cli[i-1]!='|');
//             apellido_pat_cli[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

            
//             //Lectura de apellido_mat_cli
//             i=0;
//             do{// ciclo para leer cada uno de los campos
//                 Lectura.read((char*)&apellido_mat_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(apellido_mat_cli[i-1]!='|');
//             apellido_mat_cli[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

            
//             //Lectura de fecha_nac_cli
//             i=0;
//             do{// ciclo para leer cada uno de los campos
//                 Lectura.read((char*)&fecha_nac_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(fecha_nac_cli[i-1]!='|');
//             fecha_nac_cli[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

//             //Lectura de num_tel_cli
//             i=0;
//             do{// ciclo para leer cada uno de los campos
//                 Lectura.read((char*)&num_tel_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(num_tel_cli[i-1]!='|');
//             num_tel_cli[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

//             //Lectura de mail_cli
//             i=0;
//             do{// ciclo para leer cada uno de los campos
//                 Lectura.read((char*)&num_tel_cli[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
//                 if(Lectura.eof()) break;
//                 i++;
//             }while(mail_cli[i-1]!='|');
//             mail_cli[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
//             if(Lectura.eof()) break;

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
    std::cout << std::flush;
    std::cin>>opc;
    switch(opc){
    case 1:
        clear_screen();
        cli.Add();
        break;
    case 2:
        clear_screen();
        cli.Show();
        break;
        // case 3:{ cli.Search(); break;}
        // case 4:{ cli.Delete(); break;}
        // case 5:{ cli.Mod(); break;}
    case 6: 
        std::cout<<"Saliendo del programa..."<<std::endl;
    default:
        break;
    }
    } while(opc!=6);
    std::cin.clear();
    Pause();
    return 0;
}

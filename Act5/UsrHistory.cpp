#include <iostream>
#include <fstream>
#include "UsrHistory.h"

void clear_screen(){std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"<<std::endl;}

inline void Pause(){
    std::string dummy;
    std::cout << "Presione Entrar para continuar..." << std::endl;
    getline(std::cin, dummy);
}

UsrHistory hist;

void UsrHistory::Menu(){
    int sel;
    do{
    std::cout<<"Menu de Historial de Usuario"<<std::endl;
    std::cout<<"1. Captura una nueva actividad de usuario" <<std::endl;
    std::cout<<"2. Muestra el historial de actividades de usuarios" <<std::endl;
    std::cout<<"3.-Modifica una actividad del historial"<<std::endl;
    std::cout<<"4.-Elimina una actividad del historial" <<std::endl;
    std::cout<<"5.-Busca una orden existente"<<std::endl;
    std::cout<<"6.-Salir del programa"<<std::endl;
    std::cout<<"Ingresa la opcion: ";
    std::cin>>sel;
    switch (sel)
    {
    case 1:
        clear_screen();
        hist.Add();
        break;
    case 2:
        clear_screen();
        hist.Show();
        break;
    case 3:
        clear_screen();
        hist.Modify();
        break;
    case 4:
        clear_screen();
        hist.Delete();
        break;
    case 5:
        clear_screen();
        hist.Search();
        break;
    case 6:
        std::cout<<"Saliendo del programa..."<<std::endl;
    default:
        break;
    }
    }while(sel!=6);
    std::cin.ignore();
    Pause();
}

void UsrHistory::Add(){
    clear_screen();
    std::ofstream wbFile("HistorialUsuarios.bin", std::ios::binary);
    std::cout<<"Nombre del usuario de la actividad: ";
    std::cin.ignore();
    std::cin.getline(username, 20); 
    std::cout<<"Tipo de actividad (Login, Checkin, Logout): ";
    std::cin.getline(activity, 20);
    std::cout<<"Fecha y Hora de la actividad (DD/MM/AAAA - HH:MM): ";
    std::cin.getline(act_time, 24);
    wbFile.write((char*)&hist,sizeof(hist));
    wbFile.close();
}

void UsrHistory::Show(){
    char username[20], activity[20], act_time[24];
    int band=0;
    std::ifstream rbFile("HistorialUsuarios.bin", std::ios::binary);
    clear_screen();
    if(!rbFile.good()) std::cout<<"\n Archivo no encontrado."<<std::endl;
    else{
        std::cout<<std::endl<<"\tOrdenes de Compra"<<std::endl;
        while(!rbFile.eof()){
            rbFile.read((char*)&hist,sizeof(hist));
            if(rbFile.eof()) break;
            std::cout<<std::endl<<"Usuario: "<<hist.username<<std::endl;
            std::cout<<"Actividad: "<<hist.activity<<std::endl;
            std::cout<<"Fecha y Hora: "<<hist.act_time<<std::endl;
        }
        rbFile.close();
    }
    std::cout<<std::endl;
}
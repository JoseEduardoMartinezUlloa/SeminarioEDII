#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"

using namespace std;


class Productos
{
    public:
        char codigo[10], descripcion[35], precio[15];

    void Agregar();
	void Mostrar();
	void Modificar();
	void Eliminar();
	void Buscar();
	void menu();
}pr;

int dim1, dim2, dim3, opc = 0;


void Productos::Agregar()
{
    cout<<"ESCRIBE EL CODIGO DEL PRODUCTO: ";
    cin.getline(codigo, 10);
    cin.getline(codigo, 10);
    cout<<"ESCRIBE LA DESCRIPCION: ";
    cin.getline(descripcion,35);
    cout<<"ESCRIBE EL PRECIO NETO: ";
    cin.getline(precio,15);
    ofstream Archivo("Productos.txt",ios::app);
    dim1 = strlen(codigo);
    dim2 = strlen(descripcion);
    dim3 = strlen(precio);
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&codigo, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&descripcion, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&precio, dim3);

    Archivo.close();

}
void Productos::Mostrar()
{
	system("cls");

    ifstream archivo("Productos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
			archivo.read((char*)&dim1, sizeof(int));
			archivo.read((char*)&codigo, dim1);
			codigo[dim1] = '\0';
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&precio, dim3);
			precio[dim3] = '\0';
            cout << codigo << "  " << descripcion << "  " << precio << endl;
		}
	}
    archivo.close();
}


void Productos::Modificar()
{
    int band = 0;
    char codigo2[10];

	ifstream archivo("Productos.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "escribe el codigo del producto: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&codigo, dim1);
            codigo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&precio, dim3);
            precio[dim3] = '\0';

            if(strcmp(codigo2, codigo) == 0)
            {
                cout << codigo << "  " << descripcion << "  " << precio << endl;
                band = 1;
                cout<<"DESEA MODIFICAR?\n1.SI\n0.NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Productos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&codigo, dim1);
            codigo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&precio, dim3);
            precio[dim3] = '\0';

            if(strcmp(codigo2, codigo) == 0)
            {
                cout<<"ESCRIBE EL CODIGO DEL PRODUCTO: ";
                cin.getline(codigo, 10);
                cin.getline(codigo, 10);
                cout<<"ESCRIBE LA DESCRIPCION: ";
                cin.getline(descripcion,35);
                cout<<"ESCRIBE EL PRECIO NETO: ";
                cin.getline(precio,15);
                dim1 = strlen(codigo);
                dim2 = strlen(descripcion);
                dim3 = strlen(precio);
            }//condicion
            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&codigo, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&descripcion, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&precio, dim3);
        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Productos.txt");
	rename("temporal.txt", "Productos.txt");
	}//condicional de la opcion

    }// else

}

void Productos::Eliminar()
{
int band = 0;
    char codigo2[10];

	ifstream archivo("Productos.txt");
	if(!archivo.good()){
			cout<<"\nEl archivo no existe...";
	}
	else
	{
	    cout << "CODIGO QUE QUIERES ELIMINAR: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&codigo, dim1);
            codigo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&precio, dim3);
            precio[dim3] = '\0';

            if(strcmp(codigo2, codigo) == 0)
            {
                cout << codigo << "  " << descripcion << "  " << precio << endl;
                band = 1;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opc;
            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Productos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&codigo, dim1);
            codigo[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&descripcion, dim2);
            descripcion[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&precio, dim3);
            precio[dim3] = '\0';

            if(strcmp(codigo2, codigo) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&codigo, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&descripcion, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&precio, dim3);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Productos.txt");
	rename("temporal.txt", "Productos.txt");
	}//condicional de la opcion

    }//

}

void Productos::Buscar()
{
    char codigo2[10];
    int band = 0;
    system("cls");

    ifstream archivo("Productos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "escribe el codigo del producto que quieres buscar: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&codigo, dim1);
			codigo[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&descripcion, dim2);
			descripcion[dim2] = '\0';
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&precio, dim3);
			precio[dim3] = '\0';
			if( strcmpi(codigo2, codigo) == 0)
            {
                cout << codigo << "  " << descripcion << "  " << precio << endl;
                band = 1;
            }
		}
		if (!band)
            cout << "NO SE ENCUENTRA EL PRODUCTO..." << endl;
	}
    archivo.close();
}
int main()
{

	cout<<"\n\n\t\tBIENVENIDO AL MENU PRODUCTOS\n\n";
	do{
		cout<<"\n\tSELECCIONE LA OPCION DESEADA\n1.- AGREGAR\n2.- MOSTRAR\n3.- BUSCAR\n4.- MODIFICAR\n5.- ELIMINAR\n6.- SALIR\n>: ";
		cin>>opc;
		switch(opc) {
		  case 1:
			pr.Agregar();
			break;
		  case 2:
			pr.Mostrar();
			break;
          case 3:
			pr.Buscar();
			break;
		  case 4:
            pr.Modificar();
			//empleado.Datos();
			break;
          case 5:
			pr.Eliminar();
			break;
          default:
            cout << "OPCION INCORRECTA...."<<endl;
        }
        system("Pause");
    }while(opc != 6);
}

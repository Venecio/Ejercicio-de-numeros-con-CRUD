#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h> //Para las tildes
#define MAX 100

using namespace std;

/* Consignas Ejercicio N�
1)Usuario asigna el tama�o del array.
2)Llenar:
        1)Usuario llena arreglo
        2)llenar con numeros impares.
        3)Llenar con numeros pares.
        4)Numeros aleatorios.
3)Buscar
4)mostrar elemento
5)ordenar > <
6)insertar/modificar/eliminar.
        1)1�
        2)medio.
        3)ultimo
7)Mostrar todo.
*/
void Menu();
void SubMenuLlenar();
void SubMenuPMU();
bool arrayVacio(int dimensionArray);
void LlenarArray(int opcionDeLLenado, int dimensionArray);
void MostrarTodosLosValoresDelVector(int dimensionArray);
void MostrarElementoEnUnaPosicion(int dimensionArray);
void BuscarUnValorDelArray(int dimensionArray);
void OrdenarArray(int dimensionArray);
int IME (int dimensionArray);
void SubMenuAcciones();

int arreglo[MAX]; //Arreglo Global

int main()
{
    setlocale(LC_CTYPE, "Spanish"); //para las tildes.
    char opcionSeguir;
    int dimensionArray = 0, opcionMenu;

    do
    {
        cout<<"\nINTRODUCIR LA DIMENSI�N DEL ARRAY ANTES DE REALIZAR CUALQUIER OTRA OPERACI�N"<<endl;
        Menu();
        cout << "Elija una opci�n del menu: ";
        cin >>opcionMenu;
        switch(opcionMenu){
        case 1:
            system("cls");
            cout << "Asignando tama�o del array.." << endl;
            if(arrayVacio(dimensionArray) == true)
                system("cls");
            {
                cout<<"\nDigite tama�o del array :";
                cin>>dimensionArray;
            }
            break;
        case 2: // Insertar Valores en el array
            system("cls");
            cout << "Insertando valores del array.." << endl;
            if(arrayVacio(dimensionArray) == false)
                system("cls");
            {
                cout<<"\nElija una opci�n para llenar el arreglo: " << endl;
                SubMenuLlenar();
                cin>>opcionMenu;
                LlenarArray(opcionMenu, dimensionArray);
            }
            break;


        case 3:// buscar un valor dentro del array
            system("cls");
            if(arrayVacio(dimensionArray) == false){
                BuscarUnValorDelArray(dimensionArray);
            }
            break;

        case 4: // mostrar una posicion dentro del array
            system("cls");
            if(arrayVacio(dimensionArray) == false){
                MostrarElementoEnUnaPosicion(dimensionArray);
            }
            break;

        case 5: // Ordenar de mayor a menor
            system("cls");
            if(arrayVacio(dimensionArray) == false){
                OrdenarArray(dimensionArray);
            }
        break;
    case 6: //Insertar / modificar / eliminar
            system("cls");
            if(arrayVacio(dimensionArray) == false){
                dimensionArray = IME(dimensionArray);

            }
        break;
    case 7:
        system("cls");
        MostrarTodosLosValoresDelVector(dimensionArray);
        break;
    default:
        cout << "La opci�n elegida no existe."<< endl;
        break;
    };

    cout<<"\n\nDesea realizar otra operaci�n? <s/n>: ";
    fflush( stdin );
    cin>>opcionSeguir;
    fflush( stdin ); fflush( stdout );
    system("cls");
}while((opcionSeguir == 's') || (opcionSeguir == 'S') );

system ("PAUSE");
}


// 2 - Funcion de llenado de array
void LlenarArray(int opcionDeLLenado, int dimensionArray)
{
    int guardarValor;
    switch(opcionDeLLenado){  //Opciones del subMenuLlenar
    case 1:
        for(int i= 0; i< dimensionArray; i++)
        {
            cout<<"\nIngrese el valor de la posici�n  " << i+1 << " : ";
            cin>>guardarValor;
            arreglo[i] = guardarValor;
        }
        break;
    case 2:
        system("cls");
        cout<<"\nN�meros impares aleatorios generados, volver a la opci�n 7 para ver los cambios realizados en el array.";
        for(int i= 0; i< dimensionArray; i++)
        {
            guardarValor = rand();
            if(guardarValor % 2 == 0)
            {
                while(guardarValor % 2 == 0)
                {
                    guardarValor = rand();
                }
            }
            arreglo[i] = guardarValor;
        }
        break;
    case 3:
        cout<<"\nN�meros pares aleatorios, volver a la opci�n 7 para ver los cambios realizados en el array.";
        for(int i= 0; i< dimensionArray; i++)
        {
            guardarValor = rand();
            if(guardarValor % 2 != 0)
            {
                while(guardarValor % 2 != 0)
                {
                    guardarValor = rand();
                }
            }
            arreglo[i] = guardarValor;
        }
        break;
    case 4:
        cout<<"\nN�meros aleatorios generados, volver a la opci�n 7 para ver los cambios realizados en el array.";
        for(int i= 0; i< dimensionArray; i++)
        {
            arreglo[i] = 1+rand()%51;
        }
        break;
    default:
        break;
    }
}

    //3 - Buscar un valor dentro del vector
void BuscarUnValorDelArray(int dimensionArray){
    int aux;
    bool valorEncontrado = false;
    cout<<"Ingrese el valor que desea buscar en el array: ";cin>>aux;

    for (int i=0; i<dimensionArray; i++){
        if(arreglo[i]==aux){
            cout<<"El valor "<< aux <<" fue encontrado en la posici�n "<< i+1 << endl;
            valorEncontrado = true;
        }
    }
    if (valorEncontrado == false){
        cout<< "El valor " << aux << " no fue encontrado en el array."<<endl;
    }
}


    //4 - Muestra un elemento del vector segun la posicion (buscar)
void MostrarElementoEnUnaPosicion(int dimensionArray){
    int posicion;
        cout<<"Ingrese la posici�n que desea ver del array: "; cin>>posicion;
        fflush(stdin);

        if(posicion < dimensionArray){
            cout<<"El valor en la posici�n " << posicion << " es " << arreglo[posicion-1] <<endl;
        } else {
            cout << "La posici�n ingresada no existe. El arreglo solo tiene una dimensi�n de : " << dimensionArray << endl;
        }
}


    // 5 - Ordenar array
void OrdenarArray(int dimensionArray){
    int aux;
    cout<<"\nN�meros ordenados, volver a la opci�n 7 para ver los cambios realizados en el array."<<endl;
    for(int i=0; i<dimensionArray; i++){
        for(int j=0; j<dimensionArray-1; j++){
            if(arreglo[j]> arreglo[j+1]){
                aux= arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = aux;
            }
        }
    }
}

    // 6 - Insertar / modificar / eliminar
int IME (int dimensionArray){
    int accion, posicion, valorAgregar;
    int arregloAux[MAX];
    SubMenuAcciones();
    cout << "Ingrese la acci�n que desea realizar sobre el array: ";
    cin >> accion; fflush( stdin );
    if (accion > 0 && accion < 4 ){
        cout << "La dimensi�n del array actual es de: " << dimensionArray << endl; fflush( stdin );
    }

    switch(accion){
        case 1: //Insertar

                cout << "La dimensi�n del nuevo array luego de la insersi�n sera de: " << dimensionArray+1 << endl;
                cout << "Ingrese el valor que desea agregar: "; cin >> valorAgregar;

                cout << "Ingrese la posici�n que desea afectar: "; cin >> posicion;

            if(posicion > 0 && posicion <= dimensionArray+1 ){
                //Haciendo copia de seguridad del viejo array
                for (int i = 0; i < dimensionArray; i++){
                    arregloAux[i] = arreglo[i];
                }

                //Para generar el nuevo array
                for (int i = 0; i < dimensionArray+1; i++){
                    if(i == posicion-1){
                        arreglo[i] = valorAgregar;
                    }
                    if(i > posicion-1){
                        arreglo[i] = arregloAux[i-1];
                    }
                }
                dimensionArray = dimensionArray+1;
            }else {
                cout << "La posici�n a insertar esta fuera de rango." << endl;
            }
            break;
        case 2: //Modificar

                cout << "Ingrese el valor que desea agregar: "; cin >> valorAgregar;

                cout << "Ingrese la posicion que desea afectar: "; cin >> posicion;

            if(posicion > 0 && posicion <= dimensionArray ){
                //Para generar el nuevo array
                for (int i = 0; i < dimensionArray; i++){
                    if(i == posicion-1){
                        arreglo[i] = valorAgregar;
                    }
                }
            }else {
                cout << "La posici�n a modificar est� fuera de rango." << endl;
            }
            break;

        case 3: // Eliminar
                cout << "La dimensi�n del nuevo array sera de " << dimensionArray-1<<endl ; fflush(stdin);
                cout << "Ingrese la posici�n que desea eliminar el valor: " ; cin >> posicion; fflush(stdin);

            if(posicion > 0 && posicion <= dimensionArray ){
                //Haciendo copia de seguridad del viejo array
                for (int i = 0; i < dimensionArray; i++){
                    arregloAux[i] = arreglo[i];
                }
                //Para generar el nuevo array
                for (int i = 0; i < dimensionArray-1; i++){
                    if(dimensionArray != posicion){
                        if(i >= posicion-1){
                            arreglo[i] = arregloAux[i+1];
                        }
                    }
                }

                dimensionArray = dimensionArray-1;
            }else {
                cout << "La posici�n a eliminar esta fuera de rango." << endl;
            }

            break;
        default:
            cout << "La acci�n ingresada no es valida." << endl;
            break;
    }
        return dimensionArray;
}



    //7 - Muestra  todos los elementos del vector
void MostrarTodosLosValoresDelVector(int dimensionArray)
{
    cout<< "Imprimiendo todos los valores del array"<<endl;
    for(int i = 0; i < dimensionArray; i++){
        printf("\n\t -> Posicion [%d]: %d", i, arreglo[i]);
    }
}


    // Funcion validacionDeDimensionDeArray
bool arrayVacio(int dimensionArray)
{
    if(dimensionArray <= 0)
    {
        cout<<"\nEl arreglo esta vacio."<<endl;
        return true;
    }
    else
    {
        return false;
    }
}


// Funciones de menus
void Menu()
{
    cout<<"1)Asignar el tama�o del array:"<<endl;
    cout<<"2)Llenar el array:"<<endl;
    cout<<"3)Buscar un valor dentro del array."<<endl;
    cout<<"4)Mostrar el elemento."<<endl;
    cout<<"5)Ordenar el array de > <"<<endl;
    cout<<"6)Insertar / Modificar / Eliminar "<<endl;
    cout<<"7)Mostrar todos los valores del array.\n"<<endl;
}
void SubMenuLlenar()
{
    cout<<"\t1)LLenar array de forma manual"<<endl;
    cout<<"\t2)Llenar array con n�meros impares."<<endl;
    cout<<"\t3)Llenar array con n�meros pares."<<endl;
    cout<<"\t4)Llenar array con n�meros aleatorios.\n"<<endl;
}

void SubMenuPMU()
{
    cout<< "Elija una opci�n que desee aplicarle la accion: " << endl;
    cout<<"\t1) Primero"<<endl<<"\t2) Medio."<<endl<<"\t3) Ultimo\n"<<endl;
}

void SubMenuAcciones(){
    cout << "\nElija una de las siguientes opciones: "<< endl;
    cout << "\t1) Ingresar nuevo elemento en el array"<< endl;
    cout << "\t2) Modificar elemento existente del array" << endl;
    cout << "\t3) Eliminar un elemento del array"<< endl;
}

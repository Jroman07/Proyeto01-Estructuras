#include <iostream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include "Cajero.h"
//#include "pedido.h"
using namespace std;

Cajero* listaCajero = NULL;
Cajero::Cajero() {}
Cajero::~Cajero() {}

int cont_Caja = 0; //6
string Cajas[] = { "Caja#1","Caja#2","Caja#3","Caja#4","Caja#5", "Caja#6" };
//						1  ,	2 ,		 8,		7,			5,		9	 

int esEntero(const string& str) {
    stringstream ss(str);

    int numero;
    char c;

    if (ss >> numero && !(ss >> c)) {
        int convertir = stoi(str);
        if (convertir < 0)
        {
            return -1;
        }
        else
            return convertir;
    }

    return -1;
}

int CajasTotales = 0;
int CajasDisponibles = 6;



//void Cajero::ingresarCajero() {
//    if (cont_Caja >= 6) {
//        cout << "No se pueden agregar mas cajeros por el momento!!\n";
//    }
//    else {
//        Cajero* nuevo = new Cajero();
//        string id;
//
//        cout << "Ingrese el ID del cajero: ";
//        cin >> id;
//        if (esEntero(id) == -1) {
//            cout << "Solo ingresar numeros enteros!!";
//            delete nuevo;
//        }
//        else {
//            nuevo->Id = esEntero(id);
//            cin.ignore(); cout << "Ingrese el nombre del cajero: ";
//            getline(cin, nuevo->nombre);
//            string numCaja;
//            cout << "Ingrese el nmumero de caja (1-6): "; cin >> numCaja;
//            if ((esEntero(numCaja) == -1) && (esEntero(numCaja) > 6 || esEntero(numCaja) < 1)) {
//                cout << "Solo ingresar numeros enteros o un numero de caja disponible!!";
//                delete nuevo;
//            }
//            else {
//                nuevo->numCaja = esEntero(numCaja);
//                if (listaCajero == NULL) { //lista vacia
//                    listaCajero = nuevo;
//                }
//                else {
//                    Cajero* aux = listaCajero;//lista no vacia
//                    bool encontrado = false;
//
//                    while (aux != nullptr) {
//                        if (aux->numCaja == nuevo->numCaja) {
//                            encontrado = true;
//                            cout << "Numero de Caja ya Ocupada\n";
//                            delete nuevo;
//                        }
//                        aux = aux->despues;
//                    }
//                }
//            }
//
//        }
//    }
//
//}//fin del metodo agregar Cajero

//
//
//
//



void Cajero::mostrarCajero() {
    Cajero* p = listaCajero;
    if (p == NULL)
    {
        cout << "Cajero no existe, o no esta disponible" << endl;
    }
    while (p != NULL) {
        cout << "----------------CAJERO----------------" << endl;
        cout << "ID: " << p->Id << endl;
        cout << "Nombre del cajero: " << p->nombre << endl;
        cout << "Numero de cajero: " << p->numCaja << endl;
        p = p->despues;
    }
    cout << endl;
} //fin m�todo listar cajeros

void Cajero::ingresarCajero()
{
    Cajero *nuevoCajero = new Cajero();
    if (listaCajero==nullptr)
    {
        cout << "Ingrese ID: ";
        cin >> nuevoCajero->Id;
        cout << "Ingrese Nombre: ";
        cin >> nuevoCajero->nombre;
        while (true)
        {
            cout << "Ingrese Numero de Caja: ";
            cin >> nuevoCajero->numCaja;
            if (nuevoCajero->numCaja > CajasDisponibles)
                cout << "Solo existen " <<CajasDisponibles <<" cajas\n";
            else
                break;
        }
        
        listaCajero = nuevoCajero;
        listaCajero->despues = nullptr;
        listaCajero->atras = nullptr;
		listaCajero->inicio = nullptr;
        CajasTotales++;
        cout << "Cajero Creado con Exito\n";
    }
    
    else
    {
        if (CajasTotales > 6)
        {
            cout << "No hay Cajas Disponibles\n";
            return;
        }
        else
        {
            cout << "Ingrese ID: ";
            cin >> nuevoCajero->Id;

            Cajero *aux = listaCajero;
            bool encontrado = false;

            
            while (aux != nullptr)
            {
                if (nuevoCajero->Id == aux->Id)
                {
                    cout << "Cajero ya Existente\n";
                    delete nuevoCajero;
                    encontrado = true;
                    break;
                }
                aux = aux->despues;
            }

            if (!encontrado)
            {
                cout << "Ingrese Nombre: ";
                cin >> nuevoCajero->nombre;
                cout << "Cajas Disponibles\n";
        
                int contador = 1;

                while (contador <= CajasDisponibles)
                {
                    Cajero *aux2 = listaCajero;
                    bool disponible = true;

                    while (aux2 != nullptr)
                    {
                        if (aux2->numCaja == contador)
                        {
                            disponible = false;
                            break;
                        }
                        aux2 = aux2->despues;
                    }

                    if (disponible)
                        cout << contador << ") Disponible.\n";
                    else
                        cout << contador << ") No Disponible.\n";

                    contador++;
                }

                cout << "Ingrese Caja: ";
                cin >> nuevoCajero->numCaja;

                Cajero *aux3 = listaCajero;
                encontrado = false;
                
                while (aux3 != nullptr)
                {
                    if (aux3->numCaja == nuevoCajero->numCaja)
                    {
                        encontrado = true;
                        cout << "Numero de Caja ya Ocupada\n";
                        delete nuevoCajero;
                        return;
                    }
                    aux3 = aux3->despues;
                }

                
                if (!encontrado)
                {
                    nuevoCajero->despues = nullptr;
                    nuevoCajero->atras = nullptr;
                    nuevoCajero->inicio = nullptr;

                    aux3 = listaCajero;
                    
                    while (aux3->despues != nullptr)
                        aux3 = aux3->despues;
                                        
                    aux3->despues = nuevoCajero;
                    nuevoCajero->atras = aux3;
                    
                    cout << "Cajero agregado\n";
                }
            }
        }
    }
}

void Cajero::eliminarCajero(int id) {
    Cajero* actual = listaCajero;

    //Lista vacia?
    if (listaCajero == nullptr) {
        cout << "Lista e cajeros est� vac�a.\n";
    }
    //Busqueda de nodo 
    while (actual != nullptr && actual->Id != id) {
        actual = actual->despues;
    }
    //si no se encuentra 
    if (actual == nullptr) {
        cout << "Id de cajero " << id << " no encontrado.\n";
    }
    // si esta primero en la lista
    if (actual == listaCajero) {
        listaCajero = actual->despues;// actualiza el inicio 

        if (listaCajero != nullptr) {
            listaCajero->atras = nullptr;//Si la lista no queda vac�a, actualizamos el puntero atr�s del nuevo primero
        }
    }
    else {
        if (actual->atras != nullptr) {
            actual->atras->despues = actual->despues;
        }
        if (actual->despues != nullptr) {
            actual->despues->atras = actual->atras;
        }
    }

    delete actual;
    cout << "Eliminado correctamente...!!!\n";
}

void Cajero::modificarCajero()
{
    if (listaCajero == nullptr)
    {
        cout << "No hay Cajeros\n";
    }
    else
    {
        Cajero* aux = listaCajero;
        int id;
        bool encontrado = false;

        while (true)
        {
            cout << "Ingrese ID del Cajero a Modificar: ";
            cin >> id;
            if (cin.fail() || id < 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                cout << "Entrada inv�lida. Por favor ingrese un n�mero entero.\n";
            }
            else
                break;
        }

        while (aux != nullptr)
        {
            if (aux->Id == id)
            {
                encontrado = true;
                int opcion;

                do {
                    cout << "1. Modificar Nombre\n";
                    cout << "2. Modificar Numero de Caja\n";
                    cout << "3. Salir\n";
                    cout << "Ingrese una Opcion: ";
                    cin >> opcion;

                    switch (opcion) {
                    case 1: {
                        cout << "Ingrese Nuevo Nombre: ";
                        cin >> aux->nombre;
                        break;
                    }

                    case 2: {
                        cout << "Cajas Disponibles\n";
                        int contador = 1;

                        while (contador <= CajasDisponibles)
                        {
                            Cajero* aux2 = listaCajero;
                            bool disponible = true;

                            while (aux2 != nullptr)
                            {
                                if (aux2->numCaja == contador)
                                {
                                    disponible = false;
                                    break;
                                }
                                aux2 = aux2->despues;
                            }

                            if (disponible)
                                cout << contador << ") Disponible.\n";
                            else
                                cout << contador << ") No Disponible.\n";

                            contador++;
                        }

                        int NuevoNumCaja = 0;

                        while (true)
                        {
                            cout << "Ingrese Nueva Caja: ";
                            cin >> NuevoNumCaja;
                            if (cin.fail() || NuevoNumCaja < 0)
                            {
                                cin.clear();
                                cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                                cout << "Entrada inv�lida. Por favor ingrese un n�mero entero.\n";
                            }
                            else
                                break;
                        }

                        Cajero* aux3 = listaCajero;
                        bool numCajaEncontrado = false;

                        while (aux3 != nullptr)
                        {
                            if (aux3->numCaja == NuevoNumCaja)
                            {
                                numCajaEncontrado = true;
                                cout << "Numero de Caja ya Ocupada\n";
                                return;
                            }
                            aux3 = aux3->despues;
                        }

                        if (!numCajaEncontrado)
                        {
                            aux->numCaja = NuevoNumCaja;
                            cout << "Datos actualizados\n";
                        }

                        break;
                    }

                    case 3: {
                        cout << "saliste\n";
                        return;
                        break;
                    }

                    default:
                        cout << "opcion invalida\n";
                        break;
                    }
                } while (opcion != 3);
            }
            aux = aux->despues;
        }
        if (!encontrado)
            cout << "Cajero no encontrado\n";
    }
}
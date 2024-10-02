#include <iostream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<ctime>
#include "Cliente.h"

using namespace std;

Cliente* listaCliente = NULL;
Cliente::Cliente() {}
Cliente::~Cliente() {}

int contTypeA = 1;
int contTypeC = 1;

int Entero(const string& str) {
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

void Cliente::mostrarCliente()
{
    cout << "_________________________________\n";
    cout << "Lista de clientes: \n";
    Cliente* p = listaCliente;

    // Crear una estructura para almacenar el tiempo local
    tm tiempoLocal;

    // Usar localtime_s en lugar de localtime
    localtime_s(&tiempoLocal, &p->fecha);
    while (p != NULL) {

        cout << "Nombre Cliente: " << p->nombre << endl;
        cout << "Edad: " << p->edad << endl;
        cout << "Ficha Cliente: " << p->fichaCliente << endl;
        cout << "Fecha: " << tiempoLocal.tm_mday << "/" << (tiempoLocal.tm_mon + 1) << "/" << (tiempoLocal.tm_year + 1900) << endl;
        cout << "Hora:  " << tiempoLocal.tm_hour << ":" << tiempoLocal.tm_min << ":" << tiempoLocal.tm_sec << endl;
        p = p->despues;
    }
    cout << endl;
}

void Cliente::ingresarCliente() {
	Cliente* nuevo = new Cliente();

    cin.ignore();
    cout << "Ingrese el nombre del cliente: ";
    getline(cin, nuevo->nombre);
    
    string _edad;
    cout << "Ingrese la edad del cliente:   "; cin >> _edad;
    if ( Entero(_edad) == -1) {
        cout << "Ingrese solo numeros enteros en este campo!!\n";
    }
    else {
		nuevo->edad = Entero(_edad);
        if (nuevo->edad >= 65) {
            nuevo->fichaCliente = "A" + to_string(contTypeA);
            contTypeA++;
        }
     
        else {
            nuevo->fichaCliente = "C" + to_string(contTypeC);
			contTypeC++;
        }

        nuevo->fecha = time(nullptr);

        if (listaCliente == nullptr) {
            listaCliente = nuevo;
        }
        else {
            Cliente* aux = listaCliente;
            Cliente* aux2 = nullptr;

            while (aux != nullptr && aux->fichaCliente < nuevo->fichaCliente) {
                aux2 = aux;
                aux = aux->despues;
            }
            if (aux2 == nullptr) {
                nuevo->despues = listaCliente;
                listaCliente = nuevo;
            }
            else {
                aux2->despues = nuevo;
                nuevo->despues = aux;
            }
        }
        cout << "Cliente agregado correctamente!!\n";
    }
}

void Cliente::eliminarCliente(string id) {

    if (listaCliente != nullptr) {
        Cliente* aux_borrar;
        Cliente* Atras = nullptr;
        aux_borrar = listaCliente;

        while ((aux_borrar != NULL) && (aux_borrar->nombre != id)) {
            Atras = aux_borrar;
            aux_borrar = aux_borrar->despues;
        }
        // Elemento no ha sido encontrado 
        if (aux_borrar == NULL) {
            cout << "Elemento no ha sido encontrado";
        }
        //Primer elemento es el que vamos a eliminar
        else if (Atras == nullptr) {
            listaCliente = listaCliente->despues;
            delete aux_borrar;
        }
        //Elemento está en la lista pero no es el primer elemento 
        else {
            Atras->despues = aux_borrar->despues;
            delete aux_borrar;
        }
    }

}

void Cliente::atendiendoCliente() {

}
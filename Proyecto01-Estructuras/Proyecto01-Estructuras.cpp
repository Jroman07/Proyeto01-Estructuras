#include <iostream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include<ctime> 
#include "Cajero.h"
#include "Cliente.h"
using namespace std;

int main() {
    Cajero c;
    Cliente cliente;

    c.ingresarCajero();
    c.ingresarCajero();
    c.ingresarCajero();
    c.modificarCajero();
    cout << "\n\n";
    c.mostrarCajero();
    cout << "\n\n";
    c.eliminarCajero(2);
    cout << "\n\n";
    c.mostrarCajero(); 

        cliente.ingresarCliente();
    cliente.ingresarCliente();
    cliente.ingresarCliente();
    cout << "\n\n";
    cliente.mostrarCliente();
    cliente.eliminarCliente("Samuel");
    cout << "\n\n";
    cliente.mostrarCliente(); 
}
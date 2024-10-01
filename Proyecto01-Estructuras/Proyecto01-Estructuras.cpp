#include <iostream>
#include<stdlib.h>
#include<sstream>
#include<string>
#include "Cajero.h"
using namespace std;

int main() {
	Cajero c;
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
}
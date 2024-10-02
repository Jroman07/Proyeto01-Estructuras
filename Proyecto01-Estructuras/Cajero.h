#ifndef Cajero_H
#define Cajero_H
#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

class Cajero {
public:
	int Id;
	string nombre;
	int numCaja;
	int numClientes;
	class Cajero* despues;
	class Cajero* atras;

	class Cliente* inicio; // para unir los pedidos

public:
	Cajero();
	~Cajero();

	void ingresarCajero();
	void mostrarCajero();
	void modificarCajero();
	void eliminarCajero(int);
	void asignarCliente();
};

#endif
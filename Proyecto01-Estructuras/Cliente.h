#ifndef Cliente_H
#define Cliente_H
#include <iostream>
#include <string>
#include <ctime>
//#include "pedido.h"
using namespace std;

class Cliente {
public:
	string fichaCliente;
	string nombre;
	time_t fecha;
	int edad;

	class Cliente* despues;

public:
	Cliente();
	~Cliente();

	void ingresarCliente();
	void eliminarCliente(int);
	void atendiendoCliente(int);
};

#endif
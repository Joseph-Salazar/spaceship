#pragma once
#include <iostream>
#include "CNave.h"
#include "CNaveEnemigo.h"
#include "CNaveJugador.h"


using namespace std;
class NaveJugador;

template<typename T>
struct Nodo {
	T *dato;
	Nodo *next;
	Nodo(T* enemy, Nodo* next)
	{
		this->dato = enemy;
		this->next = next;
	}

	Nodo(T *enemy)
	{
		this->dato = dato;
		this->next = nullptr;
	}
	Nodo() 
	{

	}
};

template <typename F>
class Lista {
public:
	Nodo<F> *primero;
	Nodo<F> *atras;
	int lon;
	Lista() { 
		primero = nullptr;
		lon = 0;
	}
	~Lista() {};

	void Agregar(Nodo<F> *dato) 
	{
		dato = new Nodo<F>();

		if (primero == nullptr)
		{
			lon++;
			primero = dato;
			return;
		}
		else
		{
			atras->next = dato;
			lon++;
		}
		atras = dato;
	}

	void eliminar(Nodo<F> *dato)
	{
		dato = primero;
		primero = primero->next;
		lon--;
		delete dato;
	}

	void Agregar(F *dato) {
		primero = new Nodo<F>(dato, primero);
		lon++;
	}

	//Funcion Recursiva
	void MoverEnemigos(Nodo<F> *actual)
	{
		if (actual == nullptr)
			return;
		else
		{
			actual->dato->Mover();
			MoverEnemigos(actual->next);
		}
	}

	void MoverEnemigos() {
		MoverEnemigos(primero);
	}

	F *getDato() {
		return dato;
	}

	Nodo<F> *getPrimero() {
		return primero;
	}

	int getLon() { return lon; }
};
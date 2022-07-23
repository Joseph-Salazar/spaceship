#pragma once
#include<iostream>

using namespace std;

template<typename T>
struct QNode {
	T *dato;
	QNode *next;

	QNode(T *dato)
	{
		this->dato = dato;
		this->next = nullptr;
	}
};

template<typename T>
class Queue
{
	QNode<T> *primero;
	QNode<T> *ultimo;
	QNode<T> *prev;
	QNode<T> *temp;

	bool isEmpty()
	{
		return primero == NULL;
	}
public:
	Queue()
	{
		primero = ultimo = nullptr;
	}

	QNode<T> *getPrimero() { return primero; }

	void Encolar(T *dato)
	{
		temp = new QNode<T>(dato);
		if (isEmpty())
		{
			primero = temp;
			ultimo = temp;
		}
		else
		{
			prev = ultimo;
			ultimo->next = temp;
			ultimo = temp;
		}
	}

	void Desencolar()
	{
		temp = primero;
		primero = primero->next;
		delete temp;
	}
	
	//Funcion Recursiva
	void MoverBalas(QNode<T> *nodo)
	{
		if (nodo == nullptr)
			return;
		else
		{
			nodo->dato->Mover();
			MoverBalas(nodo->next);
		}
	}

	void MoverBalas()
	{
		MoverBalas(primero);
	}
};

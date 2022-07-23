#pragma once
#include "CProyectil.h"
#include "CNaveJugador.h"
#include "CNaveEnemigo.h"
#include "Queue.h"
#include "BalaJugador.h"

using namespace std;
using namespace System;

class NaveEnemiga : public Nave {
private:
	Queue<Bala> *listaDeBalas2;
	Bala *nuevaBala4;
	bool dead = false;
public:
	NaveEnemiga(int x, int y, int dx, int dy, int vid) 
	{
		this->vidas = vidas;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		listaDeBalas2 = new Queue<Bala>();

		Bala *nuevaBala4 = new Bala(x, y + 2, 'o');
		listaDeBalas2->Encolar(nuevaBala4);
	}

	void Mostrar()
	{
		Console::ForegroundColor = ConsoleColor::Red;
		Console::SetCursorPosition(x - 1, y);
		cout << "|" << char(207) << "|";
	}

	void Ocultar()
	{
		Console::SetCursorPosition(x - 1, y);
		cout << "   ";
	}

	void Mover() {
		if (!dead)
		{
			Ocultar();
			if (x + dx - 1 < 0 || x + dx + 7 > 119) {
				dx *= -1;
			}
			x += dx;
			Mostrar();
		}
	}

	void MoverBalasAlJugador()
	{
		if (!dead)
		{
			QNode<Bala> *actual;
			actual = listaDeBalas2->getPrimero();

			while (actual != nullptr)
			{
				actual->dato->AtacarJugador();
				if (actual->dato->getY() >= 29)
				{
					actual->dato->setX(x);
					actual->dato->setY(y);
				}
				actual = actual->next;
			}
		}
	}

	QNode<Bala> *getListaBalas()
	{
		return listaDeBalas2->getPrimero();
	}

	void setDead(bool dead) { this->dead = dead; }
};
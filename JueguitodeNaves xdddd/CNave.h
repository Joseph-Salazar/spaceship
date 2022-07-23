#pragma once
#include "CNave.h"
#include "CNaveEnemigo.h"
#include "Lista.h"
#include "MainJuego.h"
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

class Nave {
protected:
	long x;
	long y;
	int dx;
	int dy;
	long long combustible;
	int vidas;
	bool dead = false;
public:

	virtual auto Ocultar()->void {
		if (!dead) {
			Console::SetCursorPosition(x, y);
			cout << " ";
		}
	}

	virtual auto Mostrar()->void {
		if (!dead) {
			Console::SetCursorPosition(x, y);
			cout << "*";
		}
		else
		{
			Console::SetCursorPosition(x, y);
			cout << " ";
		}
	}

	virtual void Destruir()
	{
		dead = true;
		Console::SetCursorPosition(x, y);
		cout << " ";
	}

	virtual int getX() { return x; }
	virtual int getY() { return y; }
	virtual int getDx() { return dx; }
	virtual int getDy() { return dy; }
	virtual int getVid() { return vidas; }
	virtual bool getDeath() { return dead; }

	virtual void setVid(int vidas) { this->vidas = vidas; }
	virtual void setDeath(bool dead) { this->dead = dead; }
	virtual void setX(int x) { this->x = x; }
	virtual void setY(int y) { this->y = y; }
	virtual void setDx(int dx) { this->dx = dx; }
	virtual void setDy(int dy) { this->dy = dy; }
};


class Bala : public Proyectil {
	int dx, dy;
public:
	Bala(int x, int y, char signo) {
		this->x = x;
		this->y = y;
		this->signo = signo;
		dx = 1;
		dy = 1;
	}

	void Mover() {
		if (y > 0) {
			Ocultar();
			y--;
			Mostrar();
		}
		if (y<3)
		{
			Ocultar();
			y++;
			Ocultar();
		}
	}

	void AtacarJugador()
	{
		if (y < 29)
		{
			Ocultar();
			y += dy;
			Mostrar();
		}
		if (y >= 29) {
			Ocultar();
		}
	}
};
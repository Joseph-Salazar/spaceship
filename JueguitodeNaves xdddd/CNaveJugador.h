#pragma once
#include "CNave.h"
#include "Todo.h"
#include "BalaJugador.h"
#include "Queue.h"

using namespace std;
using namespace System;


class NaveJugador : public Nave {
private:

	Queue<Bala> *listaDeBalas;
	Bala *nuevaBala;
	long numBalas;
	long balasDisparadas;
	bool Dead;
public:

	NaveJugador(int x, int y, int dx, int dy, int vidas, int combustible) 
	{
		this->combustible = combustible;
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->dy = dy;
		this->vidas = vidas;
		listaDeBalas = new Queue<Bala>();
		numBalas = 1;
		balasDisparadas = 0;
		Dead = false;
	}

	void ShowDead()
	{
		Console::SetCursorPosition(x-1, y);
		cout << " ** " << endl;
		Console::SetCursorPosition(x - 1, y);
		cout << "**** " << endl;
		Console::SetCursorPosition(x - 1, y);
		cout << " ** " << endl;
		_sleep(120);
		Console::SetCursorPosition(x - 1, y);
		cout << "*  *" << endl;
		Console::SetCursorPosition(x - 1, y);
		cout << " ** " << endl;
		Console::SetCursorPosition(x - 1, y);
		cout << "*  *" << endl;
	}

	void Mostrar()
	{
		if (!dead)
		{
			Console::ForegroundColor = ConsoleColor::Blue;
			Console::SetCursorPosition(x - 1, y);
			cout << "|(" << char(207) << ")|";
		}
	}

	void Ocultar()
	{
		if (!dead)
		{
			Console::SetCursorPosition(x - 1, y);
			cout << "     ";
		}
	}

	auto MoverJugador()->void {
		Ocultar();
		if (_kbhit()) {
				char tecla = _getch();
				switch (tecla) {
				case 'a':
					x--; 
					if (x <= 0)
					{
						x++;
					}
					combustible = combustible - 3; 
					break;
				case 'd':
					x++;
					if (x > 120)
					{
						x--;
					}
					combustible = combustible - 3;
					break;
				case 'w': break;
				case 's': break;
				case 'f':
					Disparar();
					balasDisparadas++;
					numBalas--;
					break;
				case 'r':
					Recargar(); break;
				case 'q':
					x = x - 10;
					if (x < 5)
					{
						x = x + 10;
					}
					combustible = combustible - 50; 
					break;
				case 'e':
					x = x + 10;
					if (x > 115)
					{
						x = x - 10;
					}
					combustible = combustible - 50; 
					break;
				default: break;
				}
		}
		combustible--;
		listaDeBalas->MoverBalas();
		Mostrar();
	}
	
	void Recargar()
	{
		numBalas = 1;
	}

	auto Disparar()->void {
		if (numBalas > 0)
		{
			char signo = '|';
			nuevaBala = new Bala(x, y, '|');
			listaDeBalas->Encolar(nuevaBala);
		}
		if (numBalas <= 0)
		{
			numBalas = 0;
		}
	}

	QNode<Bala> *getListaBalas()
	{
		return listaDeBalas->getPrimero();
	}
	int getCombustible(){return combustible;}
	int getBalasDisparadas() { return balasDisparadas; }
	int getnumBalas() { return numBalas; }
	void setCombustible(int comb) { this->combustible = comb; }
	void setBalas(long balas) { this->numBalas = balas; }
	void setDisparadas(long disp) { this->balasDisparadas = disp; }
};
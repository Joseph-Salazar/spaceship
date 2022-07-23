#pragma once
#include "CNave.h"
#include "CNaveJugador.h"

using namespace std;
using namespace System;

class NaveMuerta : public Nave 
{
	bool muerte;
	bool offensive;
public:
	NaveMuerta(int x, int y)
	{
		this->x = x;
		this->y = y;
		offensive = true;
		muerte = false;
	}
	~NaveMuerta() {}

	void Mostrar()
	{
		Console::ForegroundColor = ConsoleColor::DarkRed;
		Console::SetCursorPosition(x, y);
		cout << "|" << char(207) << "|";
	}

	void Ocultar()
	{
		Console::SetCursorPosition(x, y);
		cout << "   ";
	}

	void Inmolar(NaveJugador *&player)
	{

			if (y < 30)
			{
				Ocultar();
				if (offensive)
				{
					if (y == player->getY() && x == player->getX()-1 ||
						y == player->getY() && x == player->getX()+1 ||
						y == player->getY() && x == player->getX()+2 ||
						y == player->getY() && x == player->getX()+3 ||
						y == player->getY() && x == player->getX()+4)
					{
						player->setVid(player->getVid() - 1);
					}
				}
				if (x <= player->getX() && y < player->getY())
				{
					x++;
					y++;
				}
				if (x >= player->getX() && y < player->getY())
				{
					x--;
					y++;
				}
				if (y >= player->getY())
				{
					offensive = false;
					Ocultar();
				}
				Mostrar();
			}

	}

	void setMuerte (bool dead) { this->muerte = dead; }

};
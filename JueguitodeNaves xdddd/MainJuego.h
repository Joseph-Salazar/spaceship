#pragma once
#include "BalaJugador.h"
#include "CNave.h"
#include "Lista.h"
#include "CNaveEnemigo.h"
#include "CNaveJugador.h"
#include "CProyectil.h"
#include "NaveMuerta.h"
#include <fstream>

using namespace std;
using namespace System;

class Juego {
private:
	NaveJugador *Jugador;

	bool m1, m2, m3, m4, m5, m6, m7, m8;

	NaveMuerta *muerto1;
	NaveMuerta *muerto2;
	NaveMuerta *muerto3;
	NaveMuerta *muerto4;
	NaveMuerta *muerto5;
	NaveMuerta *muerto6;
	NaveMuerta *muerto7;
	NaveMuerta *muerto8;

	NaveEnemiga *enemigo1;
	NaveEnemiga *enemigo2;
	NaveEnemiga *enemigo3;
	NaveEnemiga *enemigo4;
	NaveEnemiga *enemigo5;
	NaveEnemiga *enemigo6;
	NaveEnemiga *enemigo7;
	NaveEnemiga *enemigo8;

	Lista<NaveEnemiga> *Enemigos;
	Lista<NaveMuerta> *Muertos;


public:
	Juego()
	{
		
		m1 = false;
		m2 = false;
		m3 = false;
		m4 = false;
		m5 = false;
		m6 = false;
		m7 = false;
		m8 = false;

		Muertos = new Lista<NaveMuerta>();


		enemigo1 = new NaveEnemiga(8, 10, 1, 1,50);
		enemigo2 = new NaveEnemiga(15, 4, 1, 1,50);
		enemigo3 = new NaveEnemiga(22, 6, 1, 1,50);
		enemigo4 = new NaveEnemiga(35, 8, 1, 1,50);
		enemigo5 = new NaveEnemiga(44, 3, 1, 1,50);
		enemigo6 = new NaveEnemiga(19, 5, 1, 1,50);
		enemigo7 = new NaveEnemiga( 9, 7, 1, 1, 50);
		enemigo8 = new NaveEnemiga(107, 9, 1, 1,50);

		Jugador = new NaveJugador(60, 25, 1, 1, 5, 4000);
		Enemigos = new Lista<NaveEnemiga>();
		
		Enemigos->Agregar(enemigo1);
		Enemigos->Agregar(enemigo2);
		Enemigos->Agregar(enemigo3);
		Enemigos->Agregar(enemigo4);
		Enemigos->Agregar(enemigo5);
		Enemigos->Agregar(enemigo6);
		Enemigos->Agregar(enemigo7);
		Enemigos->Agregar(enemigo8);
	}

	void Cinematica() {
		Jugador->MoverJugador();
		Enemigos->MoverEnemigos();
	}

	void ColisionBala()
	{
		QNode<Bala>*actual  = enemigo1->getListaBalas();
		QNode<Bala>*actual2 = enemigo2->getListaBalas();
		QNode<Bala>*actual3 = enemigo3->getListaBalas();
		QNode<Bala>*actual4 = enemigo4->getListaBalas();
		QNode<Bala>*actual5 = enemigo5->getListaBalas();
		QNode<Bala>*actual6 = enemigo6->getListaBalas();
		QNode<Bala>*actual7 = enemigo7->getListaBalas();
		QNode<Bala>*actual8 = enemigo8->getListaBalas();
		
		while (actual != nullptr)
		{
			if (enemigo1->getListaBalas()->dato->getX() == Jugador->getX() && enemigo1->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo1->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo1->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo1->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo1->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo1->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo1->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo1->getListaBalas()->dato->getX() == Jugador->getX() + 3&& enemigo1->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}

			actual = actual->next;
		}

		while (actual2 != nullptr)
		{
			if (enemigo2->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo2->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo2->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo2->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo2->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo2->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo2->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo2->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo2->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo2->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual2 = actual2->next;
		}
		while (actual3 != nullptr)
		{
			if (enemigo3->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo3->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo3->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo3->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo3->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo3->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo3->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo3->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo3->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo3->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual3 = actual3->next;
		}
		while (actual4 != nullptr)
		{
			if (enemigo4->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo4->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo4->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo4->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo4->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo4->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo4->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo4->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo4->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo4->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual4 = actual4->next;
		}
		while (actual5 != nullptr)
		{
			if (enemigo5->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo5->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo5->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo5->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo5->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo5->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo5->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo5->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo5->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo5->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual5 = actual5->next;
		}
		while (actual6 != nullptr)
		{
			if (enemigo6->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo6->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo6->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo6->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo6->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo6->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo6->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo6->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo6->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo6->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual6 = actual6->next;
		}
		while (actual7 != nullptr)
		{
			if (enemigo7->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo7->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo7->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo7->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo7->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo7->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo7->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo7->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo7->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo7->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual7 = actual7->next;
		}
		while (actual8 != nullptr)
		{
			if (enemigo8->getListaBalas()->dato->getX() == Jugador->getX() + 0 && enemigo8->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo8->getListaBalas()->dato->getX() == Jugador->getX() - 1 && enemigo8->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo8->getListaBalas()->dato->getX() == Jugador->getX() + 1 && enemigo8->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo8->getListaBalas()->dato->getX() == Jugador->getX() + 2 && enemigo8->getListaBalas()->dato->getY() == Jugador->getY() ||
				enemigo8->getListaBalas()->dato->getX() == Jugador->getX() + 3 && enemigo8->getListaBalas()->dato->getY() == Jugador->getY())
			{
				Jugador->setVid(Jugador->getVid() - 1);
			}
			actual8 = actual8->next;
		}
	}

	void ColisionBalasJugadorEnemigos()
	{
		QNode<Bala> *actual = Jugador->getListaBalas();
		
		while (actual != nullptr)
		{
			if (actual->dato->getX() == enemigo1->getX() && actual->dato->getY() == enemigo1->getY())
			{
				enemigo1->setVid(enemigo1->getVid() - 1);
				if (enemigo1->getVid() <= 0)
				{
					enemigo1->setDead(true);
					enemigo1->Ocultar();

					if (!m1)
					{
						muerto1 = new NaveMuerta(enemigo1->getX(), enemigo2->getY());
						Muertos->Agregar(muerto1);
						m1 = true;
					}
					muerto1->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo2->getX() && actual->dato->getY() == enemigo2->getY())
			{
				enemigo2->setVid(enemigo2->getVid() - 1);
				if (enemigo2->getVid() <= 0)
				{
					enemigo2->setDead(true);
					enemigo2->Ocultar();

					if (!m2)
					{
						muerto2 = new NaveMuerta(enemigo2->getX(), enemigo2->getY());
						Muertos->Agregar(muerto2);
						m2 = true;
					}
					muerto2->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo3->getX() && actual->dato->getY() == enemigo3->getY())
			{
				enemigo3->setVid(enemigo3->getVid() - 1);
				if (enemigo3->getVid() <= 0)
				{
					enemigo3->setDead(true);
					enemigo3->Ocultar();

					if (!m3)
					{
						muerto3 = new NaveMuerta(enemigo3->getX(), enemigo3->getY());
						Muertos->Agregar(muerto3);
						m3 = true;
					}
					muerto3->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo4->getX() && actual->dato->getY() == enemigo4->getY())
			{
				enemigo4->setVid(enemigo4->getVid() - 1);
				if (enemigo4->getVid() <= 0)
				{
					enemigo4->setDead(true);
					enemigo4->Ocultar();

					if (!m4)
					{
						muerto4 = new NaveMuerta(enemigo4->getX(), enemigo4->getY());
						Muertos->Agregar(muerto4);
						m4 = true;
					}
					muerto4->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo5->getX() && actual->dato->getY() == enemigo5->getY())
			{
				enemigo5->setVid(enemigo5->getVid() - 1);
				if (enemigo5->getVid() <= 0)
				{
					enemigo5->setDead(true);
					enemigo5->Ocultar();

					if (!m5)
					{
						muerto5 = new NaveMuerta(enemigo5->getX(), enemigo5->getY());
						Muertos->Agregar(muerto5);
						m5 = true;
					}
					muerto5->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo6->getX() && actual->dato->getY() == enemigo6->getY())
			{
				enemigo6->setVid(enemigo6->getVid() - 1);
				if (enemigo6->getVid() <= 0)
				{
					enemigo6->setDead(true);
					enemigo6->Ocultar();

					if (!m6)
					{
						muerto6 = new NaveMuerta(enemigo6->getX(), enemigo6->getY());
						Muertos->Agregar(muerto6);
						m6 = true;
					}
					muerto6->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo7->getX() && actual->dato->getY() == enemigo7->getY())
			{
				enemigo7->setVid(enemigo7->getVid() - 1);
				if (enemigo7->getVid() <= 0)
				{
					enemigo7->setDead(true);
					enemigo7->Ocultar();

					if (!m7)
					{
						muerto7 = new NaveMuerta(enemigo7->getX(), enemigo7->getY());
						Muertos->Agregar(muerto7);
						m7 = true;
					}
					muerto7->Inmolar(Jugador);
				}
			}
			if (actual->dato->getX() == enemigo8->getX() && actual->dato->getY() == enemigo8->getY())
			{
				enemigo8->setVid(enemigo8->getVid() - 1);
				if (enemigo8->getVid() <= 0)
				{
					enemigo8->setDead(true);
					enemigo8->Ocultar();

					if (!m8)
					{
						muerto8 = new NaveMuerta(enemigo8->getX(), enemigo8->getY());
						Muertos->Agregar(muerto8);
						m8 = true;
					}
					muerto8->Inmolar(Jugador);
				}
			}
			actual = actual->next;
		}

	}

	void EnemigosDisparar()
	{
		Nodo<NaveEnemiga>*actual = Enemigos->getPrimero();

		while (actual != nullptr)
		{
			actual->dato->MoverBalasAlJugador();
			actual = actual->next;
		}
	}

	void InmolarMuertos()
	{
		Nodo<NaveMuerta> *actual = Muertos->getPrimero();
		while(actual!=nullptr)
		{
			actual->dato->Inmolar(Jugador);

			if (actual->dato->getY() >= Jugador->getY())
			{
				actual->dato->Ocultar();
			}

			actual = actual->next;
		}
	}

	void Datos()
	{
		Console::SetCursorPosition(0, 0);
		cout << "Vidas: " << Jugador->getVid() << "  Combustible: " << Jugador->getCombustible() << "  Balas: " << Jugador->getnumBalas() << "    Balas Disparadas: " << Jugador->getBalasDisparadas();
	}

	void sCoordenadasEnemigos()
	{
		ofstream guardarEnemigos;
		guardarEnemigos.open("Enemigos.txt", ios::out);
		if (guardarEnemigos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
		else
		{
			Nodo<NaveEnemiga> *actual = Enemigos->getPrimero();
			int i = 0;
			while (actual != nullptr && i <= Enemigos->getLon())
			{
				long x, y;

				x = actual->dato->getX();
				y = actual->dato->getY() % 10 + 2;
				
				if (i != Enemigos->getLon())
				{
					guardarEnemigos << x << " " << y << " ";
				}
				else
				{
					guardarEnemigos << x << " " << y;
				}
				actual = actual->next;
				i++;
			}
		}
		guardarEnemigos.close();
	}

	void sCoordenadasJugador()
	{
		ofstream guardarJugador;
		guardarJugador.open("Jugador.txt", ios::out);
		if (guardarJugador.fail())
		{
			cout << "No se pudo abrir el archivo " << endl;
		}
		else
		{
			guardarJugador << Jugador->getX() << " " << Jugador->getY()<<" ";
			guardarJugador << Jugador->getVid() << " " << Jugador->getCombustible() << " " << Jugador->getnumBalas() << " " << Jugador->getBalasDisparadas();
		}
	}

	void rDatosPartida()
	{
		ifstream cargarEnemigos, cargarJugador;
		cargarEnemigos.open("Enemigos.txt", ios::in);
		if (cargarEnemigos.fail())
		{
			cout << "No se pudo abrir el archivo" << endl;
		}
		else
		{
			Nodo<NaveEnemiga>*actual = Enemigos->getPrimero();

			while (!cargarEnemigos.eof() && actual!=nullptr)
			{
				int x, y;
				cargarEnemigos >> x >> y;
				actual->dato->setX(x); actual->dato->setY(y);
				actual = actual->next;
			}
		}
		cargarEnemigos.close();

		cargarJugador.open("Jugador.txt", ios::in);
		if (cargarJugador.fail())
		{
			cout << "No se pudo abrir el archivo " << endl;
		}
		else
		{
			int x, y, vid, comb, balas, balasdisparadas;

			cargarJugador >> x >> y>> vid >> comb >> balas >> balasdisparadas;

			Jugador->setX(x); Jugador->setY(y); Jugador->setVid(vid); Jugador->setCombustible(comb); Jugador->setBalas(balas); Jugador->setDisparadas(balasdisparadas);

		}
		cargarJugador.close();

		JuegoGo();
	}

	void JuegoGo()
	{
		auto espacio = []()
		{
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(1, 4);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(5, 9);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(23, 12);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(49, 25);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(115, 29);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(82, 17);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(13, 3);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(55, 21);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(72, 6);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(95, 27);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(19, 12);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(34, 29);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(84, 14);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(52, 17);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(99, 15);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(11, 5);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(24, 22);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(71, 28);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(33, 25);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(44, 21);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(55, 4);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(97, 9);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(1, 13);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(22, 14);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(88, 15);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(99, 23);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(84, 29);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(92, 25);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(45, 15);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(83, 5);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(51, 14);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(41, 6);
			cout << "*";
			Console::ForegroundColor = ConsoleColor::Cyan;
			Console::SetCursorPosition(21, 9);
			cout << "*";

		};
		auto gameOver = []()
		{
			_getch();
			_sleep(500);

			Console::Clear();

			Console::SetCursorPosition(32, 8);
			cout << "#####   ###### #     # #####" << endl;
			Console::SetCursorPosition(32, 9);
			cout << "#       #    # ### ### #    " << endl;
			Console::SetCursorPosition(32, 10);
			cout << "#   ##  ###### #  #  # #####" << endl;
			Console::SetCursorPosition(32, 11);
			cout << "#    #  #    # #     # #    " << endl;
			Console::SetCursorPosition(32, 12);
			cout << "######  #    # #     # #####" << endl;
			cout << endl;

			Console::SetCursorPosition(32, 14);
			cout << "#######  #      # ###### ######" << endl;
			Console::SetCursorPosition(32, 15);
			cout << "#     #   #    #  #      #    #" << endl;
			Console::SetCursorPosition(32, 16);
			cout << "#     #   #   #   #####  #####" << endl;
			Console::SetCursorPosition(32, 17);
			cout << "#     #    # #    #      #  # " << endl;
			Console::SetCursorPosition(32, 18);
			cout << "#######     #     ###### #    #" << endl;
		};

		for (int i = 0; i < 120; i++)
		{
			Console::SetCursorPosition(i, 1);
			cout << char(205);
		}

		while (Jugador->getVid() > 0 && Jugador->getCombustible() >= 0)
		{
			Console::CursorVisible = false;
			Datos();
			InmolarMuertos();
			ColisionBala();
			ColisionBalasJugadorEnemigos();
			EnemigosDisparar();
			Cinematica();
			espacio();

			if (_kbhit())
			{
				char tecla = _getch();

				if (tecla == 'p' || tecla == 'P')
				{
					sCoordenadasEnemigos();
					sCoordenadasJugador();
				}
			}
			_sleep(80);
		}

		Jugador->ShowDead();
		
		gameOver();
		_getch();
	}

};
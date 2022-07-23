#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Proyectil {
protected:
	int x;
	int y;
	char signo;
public:

	virtual void Mostrar()
	{
		Console::ForegroundColor = ConsoleColor::Yellow;
		Console::SetCursorPosition(x, y);
		cout << signo;
	}
	virtual void Ocultar()
	{
		Console::SetCursorPosition(x, y);
		cout << " ";
	}

	virtual char getS() { return signo; }
	virtual void setS(char signo) { this->signo = signo; }

	virtual int getX() { return x; }
	virtual int getY() { return y; }
	virtual void setX(int x) { this->x = x; }
	virtual void setY(int y) { this->y = y; }
};
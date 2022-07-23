#include "MainJuego.h"
#include <ctime>
using namespace std;
using namespace System;

int main() {
	Juego *juego = new Juego();
	srand(time(nullptr));
	auto menu = [juego]()
	{
		int op;
		bool gamestart = false;
		Console::SetCursorPosition(32, 8);
		cout << "#     # ###### #       # ###### ######   " << endl;
		Console::SetCursorPosition(32, 9);
		cout << "##    # #    #  #     #  #      #        " << endl;
		Console::SetCursorPosition(32, 10);
		cout << "# #   # #    #  #     #  #      #        " << endl;
		Console::SetCursorPosition(32, 11);
		cout << "#  #  # ######  #     #  ####   ######   " << endl;
		Console::SetCursorPosition(32, 12);
		cout << "#   # # #    #   #   #   #           #   " << endl;
		Console::SetCursorPosition(32, 13);
		cout << "#    ## #    #    # #    #           #   " << endl;
		Console::SetCursorPosition(32, 14);
		cout << "#     # #    #     #     ###### ######   " << endl;
		cout << endl;
		Console::SetCursorPosition(32, 16);
		cout << "1. Iniciar" << endl;
		Console::SetCursorPosition(32, 17);
		cout << "2. Cargar Partida";
		Console::SetCursorPosition(32, 18);
		cout << "3. Instrucciones" << endl;
		cin >> op;

			do {
				switch (op)
				{
				case 1:
					Console::Clear();
					juego->JuegoGo(); break;
				case 2:
					Console::Clear();
					juego->rDatosPartida();
					break;
				case 3:
					Console::Clear();
					int a;
					cout << "Utiliza las teclas W, A, S, D para moverte hacia arriba, izquierda, abajo, derecha, respectivamente, consumen 3 de combustible." << endl;
					cout << "Con la tecla F, dispara. R para recargar." << endl;
					cout << "Con Q y E, te desplazarás 5 unidades a la izquierda, o a la derecha, respectivamente, consumen cincuenta de combustible." << endl;
					cout << "Elimina todos los enemigos que puedas." << endl << endl;
					cout << "Presione 1 para empezar";
					do {
						cin >> a;
					} while (a != 1);
					Console::Clear();
					juego->JuegoGo();
				}
			} while (op < 1 || op>2);
	};
	menu();
	_getch();
}
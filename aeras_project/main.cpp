#include "general.h"
#include "inicialize.h"
#include "menu.h"

#include <vector>
#include <string>

using namespace std;

int main() {
	int choice;
	bool running = true;
	bool seleccionado = false;
	vector<string> options = {
	"Seleccionar Aeropuerto",
	"Ver bitacora",
	"Pasar al siguiente día"
	"Ayuda"
	};

	loadData();
	displayLogo();
	showProgressBar(1);

	while (running) {
		displayMenu(options, getCurrentDate(), getPaisEnLetras(leerPais()), getRutaEnLetras());
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Bye........" << endl;
			exit(0);
			break;
		case 1:
			seleccionado = seleccionarAeropuerto();

			if (seleccionado) {
				system("CLS");
				seleccionado = seleccionarRuta();
			
				if (seleccionado) {
					system("CLS");
					obtenerAvionesDisponibles();
				}

			}

			break;
		case 2:
			system("CLS");
			openLogs();
			break;
		case 3:
			actualizarFecha();
			break;
		default:
			cout << "Selecciona una opcion del menu."  << endl;
		}
		system("pause");
	}

	return 0;
}

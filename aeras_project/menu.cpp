#include "menu.h"
#include "general.h"
#include "inicialize.h"


#include <vector>
#include <string>

bool seleccionarAeropuerto() {

	int choice;
	bool running = true;

	vector<string> options = {
	"GT",
	"MX",
	"PA",
	"Regresar"
	};

	while (running) {
		displayMenu(options, getCurrentDate(), getPaisEnLetras(leerPais()));
		cin >> choice;

		if (choice >= 1 && choice <= 3) {
			cambiarPais(choice);
			return true;
		}
		else if (choice == 4) {
			return false; 
		}
		else {
			cout << "Selecciona una opción del menú." << endl;
		}
	}

}

bool seleccionarRuta() {
	int choice;
	bool running = true;

	vector<string> options = {};

	switch (leerPais())
	{
	case 1:
		options = { "MX", "PA" };
		break;

	case 2:
		options = { "GT" };
		break;

	case 3:
		options = { "GT" };
		break;
	}

	while (running) {
		displayMenu(options, getCurrentDate(), getPaisEnLetras(leerPais()));
		cin >> choice;

		if (choice >= 1 && choice <= options.size()) {

			if (leerPais() == 1) {
				cambiarRuta(choice);
			}
			else if (leerPais() == 2) {
				cambiarRuta(3);
			}
			else {
				cambiarRuta(4);
			}

			return true;
		}
		else {
			cout << "Selecciona una opción del menú." << endl;
		}
	}

}
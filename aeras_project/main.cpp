#include "general.h"
#include <vector>
#include <string>

using namespace std;

int main() {
	int choice;
	bool running = true;

	vector<string> options = {
	"Seleccionar Aeropuerto",
	"Ver bitacora",
	"Ayuda"
	};

	displayLogo();
	showProgressBar(1);

	system("cls");

	while (running) {
		displayMenu(options);
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Bye........" << endl;
			break;
		case 1:
			cout << "opt 1." << endl;
			break;
		case 2:
			cout << "opt 2" << endl;
			break;
		case 3:
			cout << "opt 3." << endl;
			break;
		default:
			cout << "Selecciona una opcion del menu."  << endl;
		}
		system("pause");
	}

	return 0;
}
#include "general.h"
#include "inicialize.h"

#include <vector>
#include <string>

using namespace std;

int main() {
	int choice;
	bool running = true;

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
		displayMenu(options, getCurrentDate());
		cin >> choice;

		switch (choice) {
		case 0:
			cout << "Bye........" << endl;
			exit(0);
			break;
		case 1:
			cout << "opt 1." << endl;
			break;
		case 2:
			system("CLS");
			openLogs();
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
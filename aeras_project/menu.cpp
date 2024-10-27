#include "menu.h"
#include "general.h"
#include "inicialize.h"
#include <vector>
#include <string>
#include <iomanip> // Para std::setw
#include <cctype>

int boletosTotales, boletosPrimeraClase, av767Usados = 0;
bool tienePrimeraClase = false;
const int filasPrimeraClase = 6;
const int columnasPrimeraClase = 2; // 2x2
const int filasEconomica = 20;       // 20 filas en 3x3
const int filasEconomicaExtendida = 26; // 26 filas en 3x2x3

vector<vector<bool>> primeraClase(filasPrimeraClase, vector<bool>(columnasPrimeraClase, false));
vector<vector<bool>> economica(filasEconomica, vector<bool>(3, false));
vector<vector<bool>> economicaExtendida(filasEconomicaExtendida, vector<bool>(8, false)); // 3x2x3


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
			cout << "Selecciona una opción del menU." << endl;
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
			cout << "Selecciona una opción del menU." << endl;
		}
	}

}

bool esNumeroValido(const string& input) {
	for (char c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

bool seleccionarBoletos() {
	 tienePrimeraClase = obtenerNumeroAleatorio() == 1;

	do {
		cout << "CUANTOS BOLETOS TOTAL DESEAS COMPRAR: ";
		string input;
		cin >> input;

		if (!esNumeroValido(input)) {
			cout << "ERROR: INGRESO INVÁLIDO. SOLO SE ACEPTAN NUMEROS MAYORES A 0.\n";
			continue;
		}

		boletosTotales = stoi(input);

		if (boletosTotales <= 0) {
			cout << "ERROR: EL NUMERO DE BOLETOS DEBE SER MAYOR A 0.\n";
		}
	} while (boletosTotales <= 0);

	if (tienePrimeraClase) {
		av767Usados++;
		do {
			cout << "CUANTOS BOLETOS DE PRIMERA CLASE DESEAS: ";
			string input;
			cin >> input;

			if (!esNumeroValido(input)) {
				cout << "ERROR: INGRESO INVÁLIDO. SOLO SE ACEPTAN NUMEROS MAYORES O IGUALES A 0.\n";
				continue;
			}

			boletosPrimeraClase = stoi(input);

			if (boletosPrimeraClase < 0) {
				cout << "ERROR: LA CANTIDAD NO PUEDE SER NEGATIVA.\n";
			}
			else if (boletosPrimeraClase > boletosTotales) {
				cout << "ERROR: EL NUMERO DE BOLETOS EN PRIMERA CLASE NO PUEDE EXCEDER EL TOTAL DE BOLETOS.\n";
			}
		} while (boletosPrimeraClase < 0 || boletosPrimeraClase > boletosTotales);
	}

	return true;
}

void mostrarAsientos(bool mostrarPrimeraClase) {
    if (tienePrimeraClase && boletosPrimeraClase > 0 && mostrarPrimeraClase) {
        // Mostrar Primera Clase (6 filas 2x2)
        cout << "Asientos de Primera Clase (6 filas 2x2):\n";
        for (int i = 0; i < filasPrimeraClase; ++i) {
            cout << "Fila " << (i + 1) << ": ";
            for (int j = 0; j < columnasPrimeraClase; ++j) {
                cout << (primeraClase[i][j] ? "X" : "O") << " ";
            }
            cout << endl;
        }

        // Mostrar Clase Económica en 3x3
        cout << "\nAsientos en Clase Económica (20 filas 3x3):\n";
        for (int i = 0; i < filasEconomica; ++i) {
            cout << "Fila " << (i + 1) << ": ";
            for (int j = 0; j < 3; ++j) {
                cout << (economica[i][j] ? "X" : "O") << " ";
            }
            cout << endl;
        }
    }
    else if (tienePrimeraClase && boletosPrimeraClase == 0) {
        // Solo Clase Económica en 3x3
        cout << "Asientos en Clase Económica (20 filas 3x3):\n";
        for (int i = 0; i < filasEconomica; ++i) {
            cout << "Fila " << (i + 1) << ": ";
            for (int j = 0; j < 3; ++j) {
                cout << (economica[i][j] ? "X" : "O") << " ";
            }
            cout << endl;
        }
    }
    else {
        // Clase Económica en 3x2x3
        cout << "Asientos en Clase Económica (26 filas 3x2x3):\n";
        for (int i = 0; i < filasEconomicaExtendida; ++i) {
            cout << "Fila " << (i + 1) << ": ";
            for (int j = 0; j < 8; ++j) {
                if (j == 3 || j == 5) cout << "   "; // Espacio entre los bloques de asientos
                cout << (economicaExtendida[i][j] ? "X" : "O") << " ";
            }
            cout << endl;
        }
    }
}

bool asignarAsiento(char letra, int fila, bool esPrimeraClase) {
    int filaIndex = fila - 1;
    int columnaIndex = letra - 'A';

    if (esPrimeraClase) {
        if (filaIndex >= 0 && filaIndex < filasPrimeraClase && columnaIndex >= 0 && columnaIndex < columnasPrimeraClase) {
            if (!primeraClase[filaIndex][columnaIndex]) {
                primeraClase[filaIndex][columnaIndex] = true;
                return true;
            }
            else {
                cout << "ERROR: El asiento ya está ocupado.\n";
            }
        }
        else {
            cout << "ERROR: Asiento fuera del rango de Primera Clase.\n";
        }
    }
    else {
        if (tienePrimeraClase) {
            if (filaIndex >= 0 && filaIndex < filasEconomica && columnaIndex >= 0 && columnaIndex < 3) {
                if (!economica[filaIndex][columnaIndex]) {
                    economica[filaIndex][columnaIndex] = true;
                    return true;
                }
                else {
                    cout << "ERROR: El asiento ya está ocupado.\n";
                }
            }
        }
        else {
            if (filaIndex >= 0 && filaIndex < filasEconomicaExtendida && columnaIndex >= 0 && columnaIndex < 8) {
                if (!economicaExtendida[filaIndex][columnaIndex]) {
                    economicaExtendida[filaIndex][columnaIndex] = true;
                    return true;
                }
                else {
                    cout << "ERROR: El asiento ya está ocupado.\n";
                }
            }
            else {
                cout << "ERROR: Asiento fuera del rango para Clase Económica Extendida.\n";
            }
        }
    }
    return false;
}

void asignarBoletos() {
    char letra;
    int fila;

    if (boletosPrimeraClase > 0) {
        cout << "\nAsignando boletos de Primera Clase:\n";
        for (int i = 0; i < boletosPrimeraClase; ++i) {
            do {
                cout << "Ingrese la letra y el número del asiento de Primera Clase (ej. A1): ";
                cin >> letra >> fila;
                letra = toupper(letra);
            } while (!asignarAsiento(letra, fila, true));
        }
    }

    cout << "\nAsignando boletos de Clase Económica:\n";
    for (int i = 0; i < boletosTotales - boletosPrimeraClase; ++i) {
        do {
            cout << "Ingrese la letra y el número del asiento de Clase Económica (ej. A1): ";
            cin >> letra >> fila;
            letra = toupper(letra);
        } while (!asignarAsiento(letra, fila, false));
    }

    mostrarAsientos(boletosPrimeraClase > 0);
}

void initAsientos() {
    mostrarAsientos(boletosPrimeraClase > 0);
    asignarBoletos();
    mostrarAsientos(boletosPrimeraClase > 0);
}
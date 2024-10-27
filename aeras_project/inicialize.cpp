#include "inicialize.h"
#include <sys/stat.h>  
#include <direct.h> 
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>
#include <filesystem> 
#include <windows.h> 

using namespace std;

int avDisponibles = 0;
int avDisponiblesGT = 0;
int avDisponiblesMX = 0;
int avDisponiblesPA = 0;


void loadData() {
	string path = "C:\\aeras";
	bool exist = existDirectory(path);

	if (exist) {
		initLogs();
		crearCarpetas();
		obtenerAvionesDisponibles();

	}
}

string getCurrentDate() {

	ifstream archivoLectura("C:\\aeras\\currentDate.txt");

	if (archivoLectura) {
		string fecha;
		getline(archivoLectura, fecha);
		archivoLectura.close();
		return fecha;
	}
	else {
		ofstream archivoEscritura("C:\\aeras\\currentDate.txt");
		if (!archivoEscritura) {
			cerr << "Error al crear el archivo 'currentDate'." << endl;
			return "";
		}

		time_t t = time(nullptr);
		tm fechaActual;
		localtime_s(&fechaActual, &t);

		string fecha = to_string(fechaActual.tm_year + 1900) + '-' +
			(fechaActual.tm_mon + 1 < 10 ? "0" : "") + to_string(fechaActual.tm_mon + 1) + '-' +
			(fechaActual.tm_mday < 10 ? "0" : "") + to_string(fechaActual.tm_mday);

		archivoEscritura << fecha << endl;
		archivoEscritura.close();
		return fecha;
	}
}


bool existDirectory(const string& path) {
	struct stat info;

	if (stat(path.c_str(), &info) != 0) {
		if (_mkdir(path.c_str()) == 0) {
			cout << "Carpeta creada exitosamente: " << path << endl;
			return true;
		}
		else {
			cerr << "Error al crear la carpeta: " << path << endl;
			return false;
		}
	}
	else if (info.st_mode & S_IFDIR) {
		cout << "La carpeta ya existe: " << path << endl;
		return true;
	}
}

void initLogs() {
	ifstream archivo("C:\\aeras\\logs.txt");

	if (archivo.is_open()) {
		cout << "El archivo logs.txt ya existe en la ruta: " << "C:\\aeras\\logs.txt" << endl;
		archivo.close();
	}
	else {
		ofstream archivoNuevo("C:\\aeras\\logs.txt");
		if (archivoNuevo.is_open()) {
			cout << "Archivo logs.txt creado en la ruta: " << "C:\\aeras\\logs.txt" << endl;
			archivoNuevo.close();
		}
		else {
			cerr << "Error: No se pudo crear el archivo logs.txt en la ruta: " << "C:\\aeras\\logs.txt" << endl;
		}
	}
}

void verificarOCrearCarpeta(const string& ruta) {
	struct stat info;
	if (stat(ruta.c_str(), &info) != 0) {
		if (_mkdir(ruta.c_str()) == 0) {
			cout << "Carpeta creada: " << ruta << endl;
		}
		else {
			cerr << "Error al crear la carpeta: " << ruta << endl;
		}
	}
	else {
		cout << "La carpeta ya existe: " << ruta << endl;
	}

	string rutaArchivo = ruta + "\\currentLocation.txt";
	ifstream archivo(rutaArchivo);
	if (!archivo.is_open()) {
		ofstream archivoNuevo(rutaArchivo);
		if (archivoNuevo.is_open()) {
			archivoNuevo.close();
		}
		else {
			cerr << "Error al crear el archivo 'currentLocation.txt' en: " << ruta << endl;
		}
	}
	else {
		cout << "El archivo 'currentLocation.txt' ya existe en: " << ruta << endl;
		archivo.close();
	}
}

void crearCarpetas() {
	string basePath = "C:\\aeras\\";

	for (int i = 1; i <= 10; ++i) {
		string numero = (i < 10 ? "0" : "") + to_string(i);
		string folderName = "AV-" + numero + "-737";
		string fullPath = basePath + folderName;
		verificarOCrearCarpeta(fullPath);
	}

	for (int i = 1; i <= 4; ++i) {
		string numero = (i < 10 ? "0" : "") + to_string(i);

		string folderName = "AV-" + numero + "-767";
		string fullPath = basePath + folderName;
		verificarOCrearCarpeta(fullPath);
	}
}

void actualizarFecha() {
	ifstream inputFile("C:\\aeras\\currentDate.txt");
	if (!inputFile) {
		cerr << "Error al abrir el archivo para lectura." << endl;
		return;
	}

	string fechaActual;
	getline(inputFile, fechaActual);
	inputFile.close();

	tm fecha = {};
	istringstream ss(fechaActual);
	ss >> get_time(&fecha, "%Y-%m-%d");

	if (ss.fail()) {
		cerr << "Error al analizar la fecha: " << fechaActual << endl;
		return;
	}

	fecha.tm_mday += 1;
	mktime(&fecha);

	ofstream outputFile("C:\\aeras\\currentDate.txt");
	if (!outputFile) {
		cerr << "Error al abrir el archivo para escritura." << endl;
		return;
	}

	outputFile << put_time(&fecha, "%Y-%m-%d") << endl;
	outputFile.close();

	cout << "La nueva fecha es: " << put_time(&fecha, "%Y-%m-%d") << endl;
}

void obtenerAvionesDisponibles() {
    int avDisponibles = 0, avDisponiblesGT = 0, avDisponiblesMX = 0, avDisponiblesPA = 0;
    vector<wstring> ubicaciones;
    WIN32_FIND_DATAW findFileData;
    HANDLE hFind;

    wstring path = L"C:\\aeras\\*";
    hFind = FindFirstFileW(path.c_str(), &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        wcout << L"Error al acceder a la ruta: " << L"C:\\aeras" << endl;
        return;
    }

    do {
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            wstring folderName = findFileData.cFileName;
            if (folderName != L"." && folderName != L"..") {
                wstring folderPath = L"C:\\aeras\\" + folderName + L"\\currentLocation.txt";

                wifstream inputFile(folderPath);
                if (inputFile) {
                    wstring ubicacion;
                    getline(inputFile, ubicacion);
                    inputFile.close();

                    if (ubicacion.empty()) {       
                        avDisponibles++;
                    }
                    else if (ubicacion == L"1") {
                        avDisponiblesGT++;
                    }
                    else if (ubicacion == L"2") {
                        avDisponiblesMX++;
                    }
                    else if (ubicacion == L"3") {
                        avDisponiblesPA++;
                    }
                }
                else {
                    wcout << L"No se pudo abrir el archivo: " << folderPath << endl;
                }
            }
        }
    } while (FindNextFileW(hFind, &findFileData) != 0);

    FindClose(hFind);


}





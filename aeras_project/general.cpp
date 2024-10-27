#include "general.h"
#include <iostream>
#include <thread> 
#include <chrono>
#include <fstream>  
#include <string>

using namespace std;

#define RESET   "\033[0m"       // Amarillo
#define RED     "\033[31m"      // Rojo
#define GREEN   "\033[32m"      // Verde
#define YELLOW  "\033[33m"      // Amarillo
#define BLUE    "\033[34m"      // Azul
#define RESET   "\033[0m"       // Reset


int pais = 0;
int ruta = 0;


int leerPais() {
    return pais;
}

string getPaisEnLetras(int idPais) {
    switch (idPais)
    {
    case 1:
        return "GT";
    case 2:
        return "MX";
    case 3:
        return "PA";
    default: 
        return "";
    }
}

void cambiarPais(int nuevoValor) {
    pais = nuevoValor;
}

int leerRuta() {
    return ruta;
}

string getRutaEnLetras() {
    switch (ruta)
    {
    case 1:
        return "GT-MX";
    case 2:
        return "GT-PA";
    case 3:
        return "MX-GT";
    case 4:
        return "PA-GT";
    default:
        return "";
    }
}

void cambiarRuta(int nuevoValor) {
    ruta = nuevoValor;
}

int obtenerNumeroAleatorio() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distribucion(1, 2);
    return distribucion(gen);
}

void displayMenu(const vector<string>& options, string date, string country, string ruta) {
    system("cls");  

    cout << YELLOW;
    cout << "                                       ===================Aeras====================" << endl;
    cout << "                                                        |" << country << "|"  << ruta << "|" << endl;
    cout << "                                                        "<< date << endl;
    cout << "                                                           MENU" << endl;
    cout << "                                       ============================================" << endl << RESET;

    for (size_t i = 0; i < options.size(); ++i) {
        cout << "                                                       " << i + 1 << ". " << options[i] << endl;
    }

    cout << "                                                       0. Salir" << endl;
    cout << "                                       ============================================" << endl;
    cout << "                                                       Ingrese la opcion: ";
    cout << RESET;

}

void displayLogo() {
    system("cls");
    cout << YELLOW;
    cout << R"(         

                                                                 
                           .8.          8 8888888888   8 888888888o.            .8.            d888888o.   
                          .888.         8 8888         8 8888    `88.          .888.         .`8888:' `88. 
                         :88888.        8 8888         8 8888     `88         :88888.        8.`8888.   Y8 
                        . `88888.       8 8888         8 8888     ,88        . `88888.       `8.`8888.     
                       .8. `88888.      8 888888888888 8 8888.   ,88'       .8. `88888.       `8.`8888.    
                      .8`8. `88888.     8 8888         8 888888888P'       .8`8. `88888.       `8.`8888.   
                     .8' `8. `88888.    8 8888         8 8888`8b          .8' `8. `88888.       `8.`8888.  
                    .8'   `8. `88888.   8 8888         8 8888 `8b.       .8'   `8. `88888.  8b   `8.`8888. 
                   .888888888. `88888.  8 8888         8 8888   `8b.    .888888888. `88888. `8b.  ;8.`8888 
                  .8'       `8. `88888. 8 888888888888 8 8888     `88. .8'       `8. `88888. `Y8888P ,88P' 

    )" << endl;
    cout << RESET;

}

void showProgressBar(int duration) {
    int barWidth = 50;
    cout << "                       Cargando: [";

    for (int i = 0; i <= barWidth; i++) {
        this_thread::sleep_for(chrono::milliseconds(duration * 1000 / barWidth));
        cout << "*";
    }
    cout << "]" << endl;
}


void openLogs() {
    system("cls");

    ifstream archivo("C:\\aeras\\logs.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo " << endl;
    }
    else {
        string contenido, linea;
        while (getline(archivo, linea)) {
            contenido += linea + "\n";
        }

        archivo.close();

        cout << contenido;
    }

}
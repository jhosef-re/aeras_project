#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

extern int pais; // Variable que almacena el país
extern int ruta; // Variable que almacena la ruta


void displayMenu(const vector<string>& options, string date, string country = "", string ruta = "");
void displayLogo();
void showProgressBar(int duration);
void openLogs();
int obtenerNumeroAleatorio();

int leerPais();
string getPaisEnLetras(int idPais);
void cambiarPais(int nuevoValor);

int leerRuta();
string getRutaEnLetras();
void cambiarRuta(int nuevoValor);

#endif
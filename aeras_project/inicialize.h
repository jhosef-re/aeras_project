#ifndef INICIALIZE_H
#define INICIALIZE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

extern int avDisponibles; 
extern int avDisponiblesGT;
extern int avDisponiblesMX;
extern int avDisponiblesPA;


void loadData();
string getCurrentDate();
bool existDirectory(const string& path);
void initLogs();
void crearCarpetas();
void verificarOCrearCarpeta(const string& ruta);
void actualizarFecha();
void obtenerAvionesDisponibles();

#endif
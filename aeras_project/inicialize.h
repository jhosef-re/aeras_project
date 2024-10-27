#ifndef INICIALIZE_H
#define INICIALIZE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void loadData();
string getCurrentDate();
bool existDirectory(const string& path);
void initLogs();
void crearCarpetas();
void verificarOCrearCarpeta(const string& ruta);

#endif
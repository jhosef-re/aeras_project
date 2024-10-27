#ifndef MENU_H
#define MENU_H

using namespace std;

extern int boletosTotales, boletosPrimeraClase, av767Usados;
extern bool tienePrimeraClase;

bool seleccionarAeropuerto();
bool seleccionarRuta();
bool seleccionarBoletos();
void initAsientos();
void mostrarAsientos(bool esPrimeraClase);
void asignarBoletos();
bool asignarAsiento(char letra, int fila, bool esPrimeraClase);
#endif
#include <iostream>
#include <thread> 
#include <chrono>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      // Rojo
#define GREEN   "\033[32m"      // Verde
#define YELLOW  "\033[33m"      // Amarillo
#define BLUE    "\033[34m"

void displayLogo();
void displayMenu();
void showProgressBar(int duration);

int main() {
    int choice;
    bool running = true;

    displayLogo();
    showProgressBar(1); 

    system("cls");

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "You chose to Add Books." << endl;
            break;
        case 2:
            cout << "You chose to Delete a Book." << endl;
            break;
        case 3:
            cout << "You chose to Search for a Book." << endl;
            break;
        case 4:
            cout << "You chose to View Book List." << endl;
            break;
        case 5:
            cout << "You chose to Edit Book Record." << endl;
            break;
        case 6:
            cout << "You chose to Change Password." << endl;
            break;
        case 7:
            cout << "Exiting the application." << endl;
            running = false;
            break;
        default:
            cout << RED << "Invalid choice. Please try again." << RESET << endl;
        }

        // Agregar una pequeña pausa antes de actualizar el menú
        system("pause");
    }

    return 0;
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

void displayMenu() {
    system("cls");

    cout << YELLOW;
    cout << "                                       ===================Aeras====================" << endl << RESET;
    cout << "                                                           MENU                    " << endl << YELLOW;
    cout << "                                       ============================================" << endl << RESET;
    cout << "                                                       1. Seleccionar Aeropuerto" << endl;
    cout << "                                                       2. Ver bitacora" << endl;
    cout << "                                                       3. Ayuda" << endl;
    cout << "                                                       7. Salir" << endl;
    cout << "                                       ============================================" << endl;
    cout << "                                                       Ingrese la opcion: ";
    cout << RESET;
}

void showProgressBar(int duration) {
    int barWidth = 50;
    cout << "                       Cargando: [";

    for (int i = 0; i <= barWidth; i++) {
        this_thread::sleep_for(chrono::milliseconds(duration * 1000 / barWidth));
        cout << "=";
    }
    cout << "]" << endl;
}

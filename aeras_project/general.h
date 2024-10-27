#ifndef GENERAL_H
#define GENERAL_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMenu(const vector<string>& options, string date); 
void displayLogo();
void showProgressBar(int duration);
void openLogs();

#endif
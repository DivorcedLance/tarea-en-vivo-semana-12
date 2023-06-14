/*
3)     investigue:
numero de archivos que pueden abrirse al mismo tiempo
EN EL SISTEMA OPERATIVO QUE ESTA USANDO.
*/

#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <direct.h>

using namespace std;

// Para calcular el numero pedido se intenta abrir archivos en bucle hasta que la operación de apertura falle
int main() {
    const string FOLDERNAME = "files3"; 

    _mkdir(FOLDERNAME.c_str());

    vector<ofstream> files;
    int i = 0;

    while (true) {
        ofstream file(FOLDERNAME + "/file" + to_string(i));
        if (!file) {
            break;
        }
        files.push_back(move(file));
        ++i;
    }

    cout << "Maximo numero de archivos que se pueden abrir al mismo tiempo en tu sistema operativo: " << i << endl;

    cout << "Cerrando y eliminando todos los archivos, espere un momento..." << endl;

    for (int j = 0; j < i; ++j) {
        files[j].close();
        remove((FOLDERNAME + "/file" + to_string(j)).c_str());
    }
    _rmdir(FOLDERNAME.c_str());
    cout << "Listo!" << endl;

    return 0;
}


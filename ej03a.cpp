#include <windows.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <direct.h>
#include <string>
#include <sstream>

using namespace std;

// Para calcular el numero pedido se intenta abrir archivos en bucle hasta que la operacion de apertura falle
int main() {
    const string FOLDERNAME = "files3"; 

    _mkdir(FOLDERNAME.c_str());

    vector<ofstream*> files;
    int i = 0;

    while (true) {
        stringstream ss;
        ss << i;
        string filename = FOLDERNAME + "/file" + ss.str();
        files.push_back(new ofstream(filename.c_str()));
        if (!files[i]->is_open()) {
            break;
        }
        ++i;
    }

    cout << "Maximo numero de archivos que se pueden abrir al mismo tiempo en tu sistema operativo: " << i << endl;

    cout << "Cerrando y eliminando todos los archivos, espere un momento..." << endl;

    for (int j = 0; j < i; ++j) {
        files[j]->close();
        delete files[j];
        stringstream ss;
        ss << j;
        string filename = FOLDERNAME + "/file" + ss.str();
        remove(filename.c_str());
    }
    _rmdir(FOLDERNAME.c_str());
    cout << "Listo!" << endl;

    return 0;
}
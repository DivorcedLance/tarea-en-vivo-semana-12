/*
1)     escriba un
programa que declare los objetos como objetos ifstream y los luego los abra
como archivos de entrada de texto: 
enDatos.txt , precios.txt , boletos.dat 
y experi.dat
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  ifstream enDatos, precios, boletos, experi;

  enDatos.open("files1/enDatos.txt");
  precios.open("files1/precios.txt");
  boletos.open("files1/boletos.dat", ios::binary);
  experi.open("files1/experi.dat", ios::binary);

  return 0;
}

/*
Si se quisiera revisar que los archivos se abrieron correctamente, se puede hacer lo siguiente:
  if (!enDatos) {
    cout << "No se pudo abrir el archivo enDatos.txt" << endl;
  } else {
    cout << "Se abrio el archivo enDatos.txt" << endl;
  }
  if (!precios) {
    cout << "No se pudo abrir el archivo precios.txt" << endl;
  } else {
    cout << "Se abrio el archivo precios.txt" << endl;
  }
  if (!boletos) {
    cout << "No se pudo abrir el archivo boletos.dat" << endl;
  } else {
    cout << "Se abrio el archivo boletos.dat" << endl;
  }
  if (!experi) {
    cout << "No se pudo abrir el archivo experi.dat" << endl;
  } else {
    cout << "Se abrio el archivo experi.dat" << endl;
  }
*/
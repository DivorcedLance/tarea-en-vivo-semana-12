/*
2)     haga
1)  como una sola instruccion
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main() {
  ifstream enDatos("files1/enDatos.txt"), precios("files1/precios.txt"), boletos("files1/boletos.dat", ios::binary), experi("files1/experi.dat", ios::binary);
  
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
/*
4)     Usar el metodo
put() de la clase fstream  para grabar un
archivo (.dat) e interpretar 2 caracteres y 2 numeros

A -----   41
B -----   42

a ------   61
b ------   62

31 ------ 1
32 ------ 2
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <direct.h>
using namespace std;

int hexa_to_deci(string hexa) {
  int deci = 0;
  int base = 1;
  int len = hexa.length();
  for (int i = len - 1; i >= 0; i--) {
    if (hexa[i] >= '0' && hexa[i] <= '9') {
      deci += (hexa[i] - 48) * base;
      base = base * 16;
    } else if (hexa[i] >= 'A' && hexa[i] <= 'F') {
      deci += (hexa[i] - 55) * base;
      base = base * 16;
    }
  }
  return deci;
}

// NOTA: Esta funcion es solo para llenar el archivo encoded.dat con el string que se pasa como parametro
void fill_file(string path, string content) {
  ofstream ofile(path.c_str(), ios::binary);
  for (int i=0; i<content.length(); i++) {
    ofile.put(content[i]);
  }
  ofile.close();
}

int main()
{
  
  const string FOLDERNAME = "files4";

  // NOTA: Los archivos de entrada y salida son distintos y deben estar en los siguientes path:
  string encoded_path = FOLDERNAME + "/encoded.dat";
  string decoded_path = FOLDERNAME + "/decoded.dat";

  // Crear carpeta files4 si no existe
  _mkdir(FOLDERNAME.c_str());

  /*  NOTA: Para probar el programa, se llena el archivo encoded.dat con el string
  Para probar otro texto codificado, se puede cambiar el string que se 
  pasa como parametro a la funcion  fill_file o comentar la siguiente linea y
  llenar el archivo directamente */
  fill_file(encoded_path, "46757369626C65732033392E3935ODOA426F6D62696C6C617320332E3232ODOA416C666F6D6272617320312E3038ODOA");

  ifstream ifile(encoded_path.c_str(), ios::binary);
  ofstream ofile(decoded_path.c_str(), ios::binary);

  if (ofile.fail() || ifile.fail())
  {
    cout << "Los archivos " << encoded_path << " o " << decoded_path << " no se abrieron exitosamente" << endl;
  }
  else
  {
    cout << "Los archivos " << encoded_path << " y " << decoded_path << " se abrieron exitosamente" << endl;
  }
  
  string hexString = "";
  char c;
  while (ifile.get(c)) {
    hexString += c;
  }

  for (int i=0; i<hexString.length(); i+=2) {
    string hexa = hexString.substr(i, 2);
    int deci = hexa_to_deci(hexa);
    ofile.put(deci);
  }

  ofile.close();

  return 0;
}


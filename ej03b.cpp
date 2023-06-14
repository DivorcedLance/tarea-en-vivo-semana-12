/*
3)     investigue:
numero maximo de caracteres con que puede nombrarse a un archivo 
EN EL SISTEMA OPERATIVO QUE ESTA USANDO.
*/
#include <windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int getPathLenght();
void deleteFile(string);
bool tryCreateFile(int);
void createFile(int);

// Para calcular el numero pedido se intenta crear archivos con cada vez mas caracteres en el nombre hasta que la operación de creación falle

int main() {
  int pathLen = getPathLenght();
  if (pathLen == -1) {
    return 1;
  } else {
    int maxLen=1;
    while (tryCreateFile(maxLen)) {
      maxLen++;
    }
    // Nota: Se toma en cuenta la longitud del path absoluto de la carpeta actual dado a que el limite maximo que permite el sistema operativo también lo incluye
    cout << "El numero maximo de caracteres que puede tener un archivo en tu sistema operativo es: " << pathLen + maxLen << endl;
  }
  return 0;
}

int getPathLenght() {
  /*
    Devuelve la longitud del path absoluto de la carpeta actual
  */
  const char* relativePath = ".";
  char absolutePath[MAX_PATH];

  if (GetFullPathName(relativePath, MAX_PATH, absolutePath, NULL)) {
      string t = absolutePath;
      return t.length();
  } else {
      cerr << "Error resolving absolute path" << endl;
      return -1;
  }
}

void deleteFile(string path) {
  remove(path.c_str());
}

bool tryCreateFile(int n) {
  /*
  Intenta crear un archivo con nombre de n caracteres
    Si no puede, devuelve false
    Si puede lo elimina y devuelve true
 */
  
  string fileName(n, 'a');
  ofstream file(fileName.c_str());
  if (!file) {
    // cout << "No se pudo abrir el archivo " << endl;
    return false;
  } else {
    // cout << "Se abrio el archivo " << endl;
    file.close();
    deleteFile(fileName.c_str());
    return true;
  }
}
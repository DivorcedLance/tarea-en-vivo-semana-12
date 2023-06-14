# tarea-en-vivo-semana-12

## Ejercicio 01	

Escriba un programa que declare los objetos como objetos ifstream y los luego los abra
como archivos de entrada de texto:  enDatos.txt , precios.txt , boletos.dat y experi.dat

```cpp
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
```

## Ejercicio 02

Haga 1)  como una sola instrucción

```cpp
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
```

## Ejercicio 03 Parte 1

Investigue: número de archivos que pueden abrirse al mismo tiempo EN EL SISTEMA OPERATIVO QUE ESTÁ USANDO.

```cpp
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
```

### Consola

```console
Maximo numero de archivos que se pueden abrir al mismo tiempo en tu sistema operativo: 509
Cerrando y eliminando todos los archivos, espere un momento...
Listo!

--------------------------------
Process exited after 0.197 seconds with return value 0
Press any key to continue . . .
```

## Ejercicio 03 Parte 2

Investigue: número máximo de caracteres con que puede nombrarse a un archivo EN EL SISTEMA OPERATIVO QUE ESTÁ USANDO.

```cpp
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
```

### Consola

```console
El numero maximo de caracteres que puede tener un archivo en tu sistema operativo es: 259

--------------------------------
Process exited after 0.2183 seconds with return value 0
Press any key to continue . . .
```

## Ejercicio 04



```cpp
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
```

### Consola

```console
Los archivos files4/encoded.dat y files4/decoded.dat se abrieron exitosamente

--------------------------------
Process exited after 0.07651 seconds with return value 0
Press any key to continue . . .
```

### encoded.dat

``` dat
46757369626C65732033392E3935ODOA426F6D62696C6C617320332E3232ODOA416C666F6D6272617320312E3038ODOA
```

### decoded.dat

``` dat
Fusibles 39.95
Bombillas 3.22
Alfombras 1.08
```

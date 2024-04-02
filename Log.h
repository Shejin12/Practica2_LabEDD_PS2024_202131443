#ifndef PRACTICA_2_LOG_H
#define PRACTICA_2_LOG_H

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class Logger {
public:
    void log(const string& message) {
        cout << message << endl;
        ofstream file("./Reportes/Contactos.log", ios::app);
        if (file.is_open()) {
            time_t now = time(nullptr);
            char timestamp[20];
            strftime(timestamp, sizeof(timestamp), "%d-%m-%H:%M:%S", localtime(&now));
            file << timestamp << endl;
            file << message << endl;
            file << endl;
            file.close();
        }
    }

    void crearCarpeta(string nombre){
        string SH_CMD = "mkdir " + nombre;
        string POWERSHELL = "New-Item -ItemType Directory -Name " + nombre;
        system(SH_CMD.c_str());
        system(POWERSHELL.c_str());
    }

    void guardar(const string& nombreArchivo, const string& contenido) {
        ofstream archivo(nombreArchivo + ".ct");
        if (archivo.is_open()) {
            archivo << contenido;
            archivo.close();
            cout << "Archivo creado y contenido guardado exitosamente." << endl;
        } else {
            cout << "No se pudo abrir el archivo." << endl;
        }
    }
};

#endif //PRACTICA_2_LOG_H

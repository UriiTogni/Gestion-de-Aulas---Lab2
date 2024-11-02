#ifndef CLSDIAS_H_INCLUDED
#define CLSDIAS_H_INCLUDED

class Dias{
private:
    int dia;
    int mes;
    int anio;

public:
    Dias(int d=0, int m=0, int a=0)
    {
        dia = d;
        mes = m;
        anio = a;
    }
    void setDia(int d){dia = d;}
    void setMes(int m){mes = m;}
    void setAnio(int a){anio = a;}
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void Cargar()
    {
        cout << "Ingrese el dia: ";
        cin >> dia;
        cout << "Ingrese el mes: ";
        cin >> mes;
        cout << "Ingrese el anio: ";
        cin >> anio;
    }
    void Mostrar()
    {
        cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    }
    void mostrarActual()
    {
        std::time_t t = std::time(nullptr);
        std::tm* tm_info = std::localtime(&t);
        anio = tm_info->tm_year + 1900;
        mes = tm_info->tm_mon + 1;
        dia = tm_info->tm_mday;
        cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    }
};

#endif // CLSDIAS_H_INCLUDED

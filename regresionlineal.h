#ifndef REGRESION_LINEAL_H
#define REGRESION_LINEAL_H
#include <vector>

using namespace std;

struct Datos {
    vector<double> x;
    vector<double> y;
    int n;
};

Datos* crearDatos(int n);
void liberarDatos(Datos* datos);
void calcularRegresion(Datos* datos, double& m, double& b, double alpha, int epochs);

#endif // REGRESION_LINEAL_H
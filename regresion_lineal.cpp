#include <iostream>
#include "regresionlineal.h"
#include <cmath>
#include <iomanip>

using namespace std;

Datos *creardatos(int n)
{
  Datos *datos = new Datos;
  datos->x.resize(n);
  datos->y.resize(n);
  datos->n = n;
  return datos;
}

void liberarDatos(Datos *datos)
{
  delete datos;
}

void CalcularRegresion(Datos *datos, double &m, double &b, int epocas, double alpha)
{
  double db, dm, pred, error, mse;

  //Creamos un ciclo para iterar dependiendo de las epocas elegidas.
  for (int epo = 0; epo < epocas; ++epo) 
  {
    //Inicializamos los valores de db y dw en 0, los cuales van a acumular el valor de las derivadas del error respecto a el intercepto (b)
    //y la pendiente (m) en cada epoca.
    
      db = 0;
      dm = 0;
    
    //Inicializamos el valor de mse en 0, el cual va a acumular el valor del error cuadratico medio en cada epoca.
      mse = 0;

      for (int i = 0; i < datos->n; ++i) 
      {
        //Calculamos el valor de y_pred, variable encargada de almacenar el valor de la prediccion de la recta.
          pred = b + m * datos->x[i];
        //Calculamos el error entre el valor real y la prediccion.
          error = datos->y[i] - pred;
        //Acumulamos el valor de la derivada del error respecto a al intercepto(b).
          db += error;
        //Acumulamos el valor de la derivada del error respecto a la pendiente(m).
          dm += error * datos->x[i];
        //Acumulamos el valor del error cuadratico medio.
          mse += error * error;
      }

    //Actualizamos los parametros del modelo segun el gradiente obtenido para la siguiente epoca.
    mse /= datos-> n;
    b += alpha * db / datos->n;
    m += alpha * dm / datos->n;

    // Imprimimos la tabla en la consola utilizando el script enseñado por el profesor en clase.
    cout << "Epoca: " << epo + 1 << "\n";
    cout << left << setw(10) << "X" << setw(10) << "Y" << setw(10) << "Y_pred" << setw(15) 
        << "Y - Y_pred" << setw(15) << "Error_Cuad" << endl;
    for (int i = 0; i < datos->n; ++i) 
    {
        pred = b + m * datos->x[i];
        error = datos->y[i] - pred;
        cout << setw(10) << datos->x[i] << setw(10) << datos->y[i] << setw(10) 
            << pred << setw(15) << error << setw(15) << error * error << endl;
    }
    cout << "MSE: " << mse << "\n" << endl;

  }
}

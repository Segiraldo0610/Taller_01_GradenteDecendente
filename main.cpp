#include <iostream>
#include "regresionlineal.h" 

using namespace std;

int main ()
{
  int n = 5;
  Datos *datos= crearDatos (n);

  // Usamos los datos de la tabla de excel.
  datos-> x = {1,2,3,4,5};
  datos-> y ={3.01, 5.11, 7.01, 8.95,10.89};

  double m= 0, b = 0; 
  double alpha = 0.01;
  int epocas = 500;

  calcularRegresion(datos, m, b, epocas, alpha);
  
  cout << "Pendiente (m)" << m << endl;
  cout << "Inteseccion (b)" << b << endl;

  delete (datos);
  
  return 0; 
  
  


  
}


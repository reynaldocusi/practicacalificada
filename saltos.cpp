#include <iostream>

using namespace std;

// Definimos una constante que representa el infinito 
#define INF 100000

/**
 *  Para resolver este problema haremos uso de programacion dinamica,
 *  por lo que ocuparemos una estructura adicional para guardar las soluciones,
 *  en este caso basta con un array que indique el numero minimo de saltos necesarios
 *  para llegar desde la posicion del indice hasta el final,
 *  por ejemplo, minimo_saltos[n-1] siempre sera 0, pues ya se encuentra en el final 
 * */
const int n = 11;
int minimo_saltos[n] = {0};

/**
 *  En esta funcion devolveremos el numero minimo de saltos necesarios para
 *  llegar al final desde la posicion inicial 
 * */
int obtiene_minimo_saltos(int *array)
{
  /**
   *  Entonces, como es programacion dinamica tendremos que llenar nuestro arreglo
   *  de soluciones(minimo_saltos), lo llenaremos de derecha a izquierda porque
   *  ya sabemos cuantos saltos se necesitan para llegar desde el final
   *  hasta el final, osea 0 
   * */
  for (int i = n - 2; i >= 0; i--)
  {
    int minimum = INF;
    /**
     *  En cada iteracion del ciclo hallaremos el valor de minimo_saltos[i],
     *  para lo cual verificaremos el numero minimo de saltos de las posiciones
     *  a las que podemos llegar desde nuestra posicion actual, estamos en la posicion i,
     *  por lo que las posiciones a las que podemos llegar son array[i],
     *  la condicion (i+j+1<n) solo sirve para evitar que nos salgamos de los limites
     *  del arreglo 
     * */
    for (int j = 0; j < array[i] && (i + j + 1 < n); j++)
    {
      /**
       *  si el numero minimo de saltos de la posicion i+j+1 es menor al minimo de saltos,
       *  actualizamos el valor minimo 
       * */
      if (minimo_saltos[i + j + 1] < minimum)
      {
        minimum = minimo_saltos[i + j + 1];
      }
    }

    /**
     *  una vez encontramos el numero minimo de saltos para llegar al final desde
     *  la posicion i, simplemente le asignamos el valor de 1 + minimum,
     *  se le suma 1 porque tenemos que contar el salto que da para llegar a la posicion
     *  donde se encuentra el minimo 
     * */
    minimo_saltos[i] = 1 + minimum;
  }

  /**
   *  Finalmente, como ya tenemos el numero minimo de saltos para llegar al final
   *  desde cualquier posicion, simplemente retornamos el numero minimo de saltos
   *  del primer elemento 
   * */
  return minimo_saltos[0];
}

int main()
{
  // Creamos el array de entrada
  int array[n] = {3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 3};
  cout << obtiene_minimo_saltos(array) << endl;
  return 0;
}
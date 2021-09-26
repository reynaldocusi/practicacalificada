#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 *  Esta funcion permite unir 2 arreglos que ya estan ordenados en 1 arreglo
 *  ordenado de manera lineal 
 * */
vector<int> merge(vector<int> a, vector<int> b)
{
  /**
   *  Utilizamos 2 indices para recorrer ambos arreglos
   *  al mismo tiempo 
   * */
  int i, j;
  i = j = 0;
  
  // en este vector result guardaremos el arreglo ordenado 
  vector<int> result;

  /**
   *  Avanzaremos los indices i y j por sus respectivos arreglos,
   *  y hallaremos cual es menor, si a[i] es menor que b[j], entonces
   *  agregamos a[i] a result e incrementamos el valor de i, la misma
   *  idea se cumpliria para b[j] 
   * */
  while (i < a.size() && j < b.size())
  {
    if (a[i] < b[j])
      result.push_back(a[i++]);
    else
      result.push_back(b[j++]);
  }

  /**
   *  Uno 2 iteradores terminará antes
   *  su arreglo antes que el otro, por lo que simplemente tendremos
   *  que agregar los elementos que faltan del iterador que aun no
   *  termino de recorrer su arreglo  
   * */
  while (i < a.size())
    result.push_back(a[i++]);

  while (j < b.size())
    result.push_back(b[j++]);

  return result;
}

/**
 *  sort_arrays sera nuestra funcion recursiva que actuara como
 *  la funcion recursiva del merge sort, la idea es dividir los
 *  k arreglos en 2 mitades k/2 arreglos, estas mitades seran left y right,
 *  una vez tenemos las mitades llamamos a la funcion de manera recursiva,
 *  pero le pasamos los arreglos de la izquierda y la derecha a la funcion merge,
 *  que es la que se encarga de juntarlos 
 * */
vector<int> sort_arrays(vector<vector<int>> arrays)
{
  /**
   *  las funciones recursivas siempre necesitan condiciones de parada,
   *  caso contrario se ejecutarian infinitamente, en este caso
   *  la condicion de parada esta dada cuando el arreglo de arreglos
   *  solo contiene 1 arreglo, lo que indicaria que ya esta ordenado,
   *  la otra condicion de parada es cuando contiene 2 arreglos, en este caso
   *  tendremos que unir estos 2 arreglos con la funcion merge() 
   * */
  if (arrays.size() == 1)
    return arrays[0];

  if (arrays.size() == 2)
    return merge(arrays[0], arrays[1]);

  /**
   *  en esta parte se crean los arreglos de arreglos para la mitad izquierda
   *  y la mitad derecha 
   * */
  vector<vector<int>> left;
  vector<vector<int>> right;

  // Agregamos los arreglos a su respectiva mitad a la que pertenecen 
  for (int i = 0; i < arrays.size(); i++)
    if (i < arrays.size() / 2)
      left.push_back(arrays[i]);
    else
      right.push_back(arrays[i]);

  return merge(sort_arrays(left), sort_arrays(right));
}

int main()
{
  // creamos el arreglo de arreglos 
  vector<vector<int>> arrays;

  arrays.push_back({1, 5, 9, 21});
  arrays.push_back({-1, 0});
  arrays.push_back({-124, 81, 121});
  arrays.push_back({-3, 6, 2, 20, 150});

  vector<int> sorted = sort_arrays(arrays);
  for (int i = 0; i < sorted.size(); i++)
    cout<<sorted[i]<<" ";
  cout<<endl;
}
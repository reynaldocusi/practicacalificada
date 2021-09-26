#include <iostream>

using namespace std;

// Clase nodo para la lista enlazada 
struct NodoLista
{
  int value;
  NodoLista *next = NULL;
  NodoLista(int value)
  {
    this->value = value;
  }
};

/**
 *  Función para imprimir una lista enlazada, entra en un
 *  bucle infinito si la lista contiene ciclos 
 * */
void print_list(NodoLista *head)
{
  NodoLista *it = head;
  while (it)
  {
    cout << it->value << endl;
    it = it->next;
  }
}

/**
 *  Función que busca un ciclo en una lista enlazada,
 *  si contiene un ciclo devuelve un puntero al nodo en el que
 *  el ciclo empieza, caso contrario retorna nulo 
 * */
NodoLista* find_cycle(NodoLista *head)
{
  /***
   *  Para ejecutar este algoritmo en espacio de memoria constante,
   *  no podemos utilizar una estructura adicional para ir guardando
   *  los nodos que ya visitamos, por lo que recurriremos al
   *  algoritmo de Floyd para búsqueda de ciclos
   * 
   *  El algoritmo de Floyd consta de 2 punteros que recorreran la lista enlazada,
   *  un puntero avanzará más rápido que el otro, si lo vemos como una analogía
   *  el puntero más rápido será el conejo y el puntero más lento será una tortuga 
   * 
   *  La idea de que un puntero avance más rápido que el otro, implica que si existe
      algún ciclo en la lista enlazada, estos punteros en algún momento tendrán que encontrarse 
   * */
  NodoLista *turtle = head;
  NodoLista *rabbit = head->next;

  /***
   *  Entonces tenemos 2 condiciones de parada, si turtle == rabbit, osea que ambos
   *  punteros se encontraron, el otro caso sería que el conejo no tenga
   *  un nodo siguiente, lo que indicaría que la lista enlazada no contiene ciclos 
   * */
  while (turtle != rabbit && rabbit->next)
  {
    /**
     *  Aca se representa la idea de un puntero más rápido que el otro,
     *  pues la tortuga solo avanza un nodo, mientras que el conejo
     *  avanza 2 nodos 
     * */
    turtle = turtle->next;
    rabbit = rabbit->next->next;
  }

  /**
   *  Si al terminar de avanzar con los punteros, estos son iguales, 
   *  entonces para hallar donde empezo este ciclo tendremos que mover
   *  a la tortuga a la posicion inicial de la lista, osea al head, y 
   *  el conejo lo haremos avanzar 1 paso, ya que antes lo inicializamos
   *  con 1 paso mas adelante que la tortuga 
   * */
  if (turtle == rabbit)
  {
    turtle = head;
    rabbit = rabbit->next;
    /**
     *  Despues de mover a la tortuga al inicio, haremos que el conejo
     *  y la tortuga avancen 1 nodo a la vez, finalmente el nodo en el que
     *  se encuentren indicara el inicio del ciclo, esto tiene una demostracion
     *  matematica de por que funciona 
     * */
    while (turtle != rabbit)
    {
      turtle = turtle->next;
      rabbit = rabbit->next;
    }
    // Finalmente se retorna el nodo en el que se encontraron 
    return turtle;
  }
  else
    return NULL;
}

int main()
{
  // Creamos nuestra lista enlazada 
  NodoLista NodoLista0 = NodoLista(0);
  NodoLista NodoLista1 = NodoLista(1);
  NodoLista NodoLista2 = NodoLista(2);
  NodoLista NodoLista3 = NodoLista(3);
  NodoLista NodoLista4 = NodoLista(4);
  NodoLista NodoLista5 = NodoLista(5);
  NodoLista NodoLista6 = NodoLista(6);
  NodoLista NodoLista7 = NodoLista(7);
  NodoLista NodoLista8 = NodoLista(8);
  NodoLista NodoLista9 = NodoLista(9);

  NodoLista0.next = &NodoLista1;
  NodoLista1.next = &NodoLista2;
  NodoLista2.next = &NodoLista3;
  NodoLista3.next = &NodoLista4;
  NodoLista4.next = &NodoLista5;
  NodoLista5.next = &NodoLista6;
  NodoLista6.next = &NodoLista7;
  NodoLista7.next = &NodoLista8;
  NodoLista8.next = &NodoLista9;
  NodoLista9.next = &NodoLista4;

  //print_list(&NodoLista0);  //Recorrido de lista sin control, genera bucle
  
  cout << "Existe bucle ?" << endl;
  if(find_cycle(&NodoLista0)){
    cout<<"Si existe: "<<endl;
    cout<<find_cycle(&NodoLista0)->value<<endl;
  }else{
    cout<<"no cycle found"<<endl;
  }
  return 0;
}
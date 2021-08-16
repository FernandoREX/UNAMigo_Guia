#include <iostream>
#include <string.h>
#include <queue>
#include <list>
#include <stack>
#include <fstream>

using namespace std;
using std::deque;

class Arista;

class Vertice
{
	Vertice* siguienteV;	//Puntero al siguiente vertice
	Arista* adyacenteV;		//Conexion entre dos vertices 

	string Nom_Ruta;		//Nombre de la estacion 
	size_t Ruta;			//Numero de la ruta

	friend class Grafo;		//Amiga de la clase grafo
};

class Arista
{
	Arista* siguienteA;		//Apuntados a la siguiente arista
	Vertice* adyacenteA;	//Apuntador al vertice adyacente

	size_t Tiempo;			//Tiempo que tarda en llegar de un ponto a otro

	friend class Grafo;		//Amiga de la clase grafo
};

class Grafo
{

	Vertice* h;

public:

	void Inicializa();															//Inicializa el Grafo
	bool Vacio();																//Comprueba si esta vacion el grafo
	Vertice* GetVertice(string NOMBRE);											//Regresa la direccion del vertice, usando su nombre
	void IncertarArista(Vertice* origen, Vertice* destino, size_t tiempo);		//Conecta a los vertices usando su direccion
	void IncertaVertice(string NOMBRE, size_t Ruta);							//Crea erl vertice con el nombre asignado 
	void Imprimir();															//Imprime el grafo como una lista de adyacencia
	void Camino_Rapido(Vertice* origen,  Vertice* destino);						//Buscar el recorrido mas corto
	void Almacenar(Vertice* a);

};
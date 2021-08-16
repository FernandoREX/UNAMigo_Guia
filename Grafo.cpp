#include "Grafo.hpp"

void Grafo::Inicializa()
{
	h = nullptr;
}

bool Grafo::Vacio()
{
	if (h == nullptr)		//Si h es NULL entonces esta vacion y regresa un true
	{						//Si h no esta vacio regresa un false
		return true;
	}
	return false;
}

Vertice* Grafo::GetVertice(string NOM) //Regresa la direccion del vertice segun su nombre
{
	Vertice* aux;
	aux = h;
	while (aux != nullptr)			   //Recorremos el grafo y comparar si NOM es igual
	{								   //al nombre del vertice donde estamos
		if (aux->Nom_Ruta == NOM)
		{
			return aux;
		}
		aux = aux->siguienteV;
	}
	return nullptr;
}

void Grafo::IncertaVertice(string NOMBRE, size_t Ruta)
{
	Vertice* nuevo = new Vertice; //Declaramos un vertice nuevo e inicializamos 

	nuevo->Nom_Ruta = NOMBRE;
	nuevo->Ruta = Ruta;
	nuevo->adyacenteV = nullptr;
	nuevo->siguienteV = nullptr;

	if (Vacio())				  
	{
		h = nuevo;
	}
	else
	{
		Vertice* aux;
		aux = h;
		while (aux->siguienteV != nullptr)
		{
			aux = aux->siguienteV;
		}
		aux->siguienteV = nuevo;
	}
}

void Grafo::IncertarArista(Vertice* origen, Vertice* destino, size_t tiempo)
{
	Arista* nuevo = new Arista;		//Declaramos un Arista e inicializamos
	nuevo->Tiempo = tiempo;
	nuevo->adyacenteA = nullptr;
	nuevo->siguienteA = nullptr;

	Arista* aux;       //Necesitamos un Puntero de tipo Arista que sirva como auxiliar

	aux = origen->adyacenteV;

	if (aux == nullptr)
	{
		origen->adyacenteV = nuevo;
		nuevo->adyacenteA = destino;
	}
	else
	{
		while (aux->siguienteA != nullptr)
		{
			aux = aux->siguienteA;
		}
		aux->siguienteA = nuevo;
		nuevo->adyacenteA = destino;
	}

}

void Grafo::Imprimir()
{
	Vertice* VerAux;
	Arista*  AriAux;
	VerAux = h;
	while (VerAux != nullptr)
	{
		cout << "Nombre: " << VerAux->Nom_Ruta << endl;
		cout << "Ruta  : " << VerAux->Ruta << "	  --> ";
		AriAux = VerAux->adyacenteV;
		while (AriAux != nullptr)
		{

			cout << AriAux->adyacenteA->Nom_Ruta;
			cout << "[Tiempo: " << AriAux->Tiempo << " min]";
			cout << " --> ";

			AriAux = AriAux->siguienteA;
		}
		cout << "NULL"<< endl;
		cout << endl;

		VerAux = VerAux->siguienteV;
	}

}

bool Comparacion(pair<Vertice*, int> a, pair<Vertice*, int> b)
{
	return a.second < b.second;
}
    
void inicio()
{
	ofstream DataBase;
	DataBase.open("DataBase.json", ios::out);
	DataBase << "{"<<endl << "    \"Instrucciones\" : \"La ruta se lee de DERECHA a IZQUIERDA\", " << endl;
	DataBase << "    \"Ruta\" : \"";
	DataBase.close();
}

void Grafo::Almacenar(Vertice* a) //Almacenar toda la informacion de la ruta a seguir en un documento json
{
	ofstream DataBase;
	DataBase.open("DataBase.json", ios::app);
	DataBase << a->Nom_Ruta <<" <-- ";
	DataBase.close();
}

void Fin(int t)
{
	ofstream DataBase;
	DataBase.open("DataBase.json", ios::app);
	DataBase << "Inicio \"," << endl;
	DataBase << "    \"Tiempo\" : \"Tiempo promedio: " << t << " Minutos\"" << endl;
	DataBase << "}";
	DataBase.close();
}

void Grafo::Camino_Rapido(Vertice* origen, Vertice* destino)
{
	int CostActual = 0, band, band2 = 0;
	Vertice* VerActual, *DesActual;
	Arista* aux;
	typedef pair<Vertice*, int> VerCostos;
	typedef pair<Vertice*, Vertice*> VerVer;

	list<VerCostos> ListCostos;
	list<VerCostos> ListOrdenada;
	list<VerCostos>::iterator i, j;

	stack<VerVer> pila;
	 
	ListCostos.push_back(VerCostos(origen, 0));
	ListOrdenada.push_back(VerCostos(origen, 0));

	inicio();

	while (!ListOrdenada.empty())
	{
		VerActual = ListOrdenada.front().first;
		CostActual = ListOrdenada.front().second;
		ListOrdenada.pop_front();

		if (VerActual == destino)
		{
			band2 = 1;
			DesActual = destino;
			while (!pila.empty())
			{
				cout << DesActual->Nom_Ruta << "<--";
				Almacenar(DesActual);

				while (!pila.empty() && pila.top().second != DesActual)
				{
					pila.pop();
				}
				if (!pila.empty())
				{
					DesActual = pila.top().first;
				}
			}
			break;
		}

		aux = VerActual->adyacenteV;
		while (aux != nullptr)
		{
			band = 0;
			CostActual = CostActual + aux->Tiempo; //Jugamos con el tiempo

			for (i = ListCostos.begin(); i != ListCostos.end(); i++)
			{
				if (aux->adyacenteA == i->first)
				{
					band = 1;
					if (CostActual < i->second)
					{
						(*i).second = CostActual;
						for (j = ListOrdenada.begin(); j != ListOrdenada.end(); j++)
						{
							if (j->first == aux->adyacenteA)
							{
								(*j).second = CostActual;
							}
						}
						ListOrdenada.sort(Comparacion);
						pila.push(VerVer(VerActual, aux->adyacenteA));
						CostActual = CostActual - aux->Tiempo; //jugamos con el tiempo restando

					}
				}
			}
			if (band == 0)
			{
				ListCostos.push_back(VerCostos(aux->adyacenteA, CostActual));
				ListOrdenada.push_back(VerCostos(aux->adyacenteA, CostActual));
				ListOrdenada.sort(Comparacion);
				pila.push(VerVer(VerActual, aux->adyacenteA));
				CostActual = CostActual - aux->Tiempo; //jugamos con el tiempo restando
			}
			aux = aux->siguienteA;
		}
	}
	if (band2 == 0)
	{
		cout << "NOruta" << endl;
	}
	Fin(CostActual);
	cout << "inicio" << endl << "Tiempo promedio: " << CostActual << "Minutos"<< endl;
	
}
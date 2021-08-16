//Instruccion para compilar: g++ -Wall -std=c++11 -o a.out UNAMigoGuia.cpp Grafo.cpp
//Instruccion para ejecutar: ./a.out
#include "Grafo.hpp"

int ImprimirMenu()
{
    int menu;
    cout << "UNAMigo Guia :)" << endl << "Nota: Escribir ubicacion y destino como esta escrito en Ver nombres " << endl;
    cout << "Menu" << endl << "[1] -> Ver nombres" << endl;
    cout << "[2] -> Indicaciones" << endl << "[3] -> Salir" << endl;
    cin >> menu;
    return menu;
}

int main()
{
    Grafo G;
    G.Inicializa();

    G.IncertaVertice("Metro_cu", 1);
    G.IncertaVertice("CENDI", 1);
    G.IncertaVertice("Psiquiatria_SaludMental", 1);
    G.IncertaVertice("F_Quimica", 1);
    G.IncertaVertice("ENALLT", 1);
    G.IncertaVertice("F_Ingenieria", 1);
    G.IncertaVertice("F_Arquitectura", 1);
    G.IncertaVertice("Rectoria", 1);
    G.IncertaVertice("Psicologia", 1);
    G.IncertaVertice("F_Filosofia", 1);
    G.IncertaVertice("F_Derecho", 1);
    G.IncertaVertice("F_Economia", 1);
    G.IncertaVertice("F_Odontologia", 1);
    G.IncertaVertice("F_Medicina", 1);
    G.IncertaVertice("F_M_Veterinaria", 1);
    G.IncertaVertice("Instituto_Geofisica", 1);
    G.IncertaVertice("Quimica_Conjunto_E_y_D", 1);

    G.IncertaVertice("F_Ciencias_Alumnos", 1);
    G.IncertaVertice("F_Ciencias_Profesores", 1);
    G.IncertaVertice("F_Contaduria_y_Administracion", 1);
    G.IncertaVertice("Escuela_de_Trabajo_Social", 1);
    G.IncertaVertice("Base_Metrobus_CU", 1);
    G.IncertaVertice("Educacion_a_Distancia", 1);
    G.IncertaVertice("DGTIC", 1);
    G.IncertaVertice("F_Ciencias", 1);

    G.IncertaVertice("Tienda_UNAM_2", 1);
    G.IncertaVertice("F_Ciencias_Politicas", 1);
    G.IncertaVertice("Investigaciones_Juridicas_2", 1);
    G.IncertaVertice("Biblioteca_Nacional_2", 1);
    G.IncertaVertice("Zona_Cultural", 1);
    G.IncertaVertice("Unidad_de_Posgrado", 1);
    G.IncertaVertice("Posgrado_Economia", 1);
    G.IncertaVertice("DGIRE", 1);
    G.IncertaVertice("DGAPA", 1);
    G.IncertaVertice("Archivo_General", 1);
    G.IncertaVertice("AV_Iman", 1);
    G.IncertaVertice("Investigaciones_filosoficas", 1);
    G.IncertaVertice("Investigaciones_fiologicas", 1);
    G.IncertaVertice("Coordinacion_de_Humanidades", 1);
    G.IncertaVertice("UNIVERSUM", 1);
    G.IncertaVertice("Teatro_y_Danza", 1);
    G.IncertaVertice("MUAC", 1);
    G.IncertaVertice("Biblioteca_Nacional", 1);
    G.IncertaVertice("Espacio_Escultorico", 1);
    G.IncertaVertice("Investigaciones_Juridicas", 1);
    G.IncertaVertice("TV_UNAM", 1);
    G.IncertaVertice("CUEC", 1);
    G.IncertaVertice("DGSA", 1);
    G.IncertaVertice("Tienda_UNAM", 1);

    G.IncertarArista(G.GetVertice("Metro_cu"), G.GetVertice("CENDI"), 7);
    G.IncertarArista(G.GetVertice("CENDI"), G.GetVertice("Psiquiatria_SaludMental"), 9);
    G.IncertarArista(G.GetVertice("Psiquiatria_SaludMental"), G.GetVertice("F_Quimica"), 5);
    G.IncertarArista(G.GetVertice("F_Quimica"), G.GetVertice("ENALLT"), 3);
    G.IncertarArista(G.GetVertice("ENALLT"), G.GetVertice("F_Ingenieria"), 3);
    G.IncertarArista(G.GetVertice("F_Ingenieria"), G.GetVertice("F_Arquitectura"), 3);
    G.IncertarArista(G.GetVertice("F_Arquitectura"), G.GetVertice("Rectoria"), 5);
    G.IncertarArista(G.GetVertice("Rectoria"), G.GetVertice("Psicologia"), 6);
    G.IncertarArista(G.GetVertice("Psicologia"), G.GetVertice("F_Filosofia"), 3);
    G.IncertarArista(G.GetVertice("F_Filosofia"), G.GetVertice("F_Derecho"), 2);
    G.IncertarArista(G.GetVertice("F_Derecho"), G.GetVertice("F_Economia"), 2);
    G.IncertarArista(G.GetVertice("F_Economia"), G.GetVertice("F_Odontologia"), 3);
    G.IncertarArista(G.GetVertice("F_Odontologia"), G.GetVertice("F_Medicina"), 4);
    G.IncertarArista(G.GetVertice("F_Medicina"), G.GetVertice("F_M_Veterinaria"), 7);
    G.IncertarArista(G.GetVertice("F_M_Veterinaria"), G.GetVertice("Instituto_Geofisica"), 5);
    G.IncertarArista(G.GetVertice("Instituto_Geofisica"), G.GetVertice("Quimica_Conjunto_E_y_D"), 7);
    G.IncertarArista(G.GetVertice("Quimica_Conjunto_E_y_D"), G.GetVertice("Metro_cu"), 5);

    G.IncertarArista(G.GetVertice("Metro_cu"), G.GetVertice("Quimica_Conjunto_E_y_D"), 6);
    G.IncertarArista(G.GetVertice("Quimica_Conjunto_E_y_D"), G.GetVertice("F_Ciencias_Alumnos"), 3);
    G.IncertarArista(G.GetVertice("F_Ciencias_Alumnos"), G.GetVertice("F_Ciencias_Profesores"), 4);
    G.IncertarArista(G.GetVertice("F_Ciencias_Profesores"), G.GetVertice("F_Contaduria_y_Administracion"), 6);
    G.IncertarArista(G.GetVertice("F_Contaduria_y_Administracion"), G.GetVertice("Escuela_de_Trabajo_Social"), 3);
    G.IncertarArista(G.GetVertice("Escuela_de_Trabajo_Social"), G.GetVertice("Base_Metrobus_CU"), 2);
    G.IncertarArista(G.GetVertice("Base_Metrobus_CU"), G.GetVertice("Educacion_a_Distancia"), 6);
    G.IncertarArista(G.GetVertice("Educacion_a_Distancia"), G.GetVertice("DGTIC"), 4);
    G.IncertarArista(G.GetVertice("DGTIC"), G.GetVertice("F_Ciencias"), 5);
    G.IncertarArista(G.GetVertice("F_Ciencias"), G.GetVertice("Metro_cu"), 7);

    G.IncertarArista(G.GetVertice("Quimica_Conjunto_E_y_D"), G.GetVertice("Tienda_UNAM_2"), 6);
    G.IncertarArista(G.GetVertice("Tienda_UNAM_2"), G.GetVertice("F_Ciencias_Politicas"), 3);
    G.IncertarArista(G.GetVertice("F_Ciencias_Politicas"), G.GetVertice("Investigaciones_Juridicas_2"), 3);
    G.IncertarArista(G.GetVertice("Investigaciones_Juridicas_2"), G.GetVertice("Biblioteca_Nacional_2"), 9);
    G.IncertarArista(G.GetVertice("Biblioteca_Nacional_2"), G.GetVertice("Zona_Cultural"), 3);
    G.IncertarArista(G.GetVertice("Zona_Cultural"), G.GetVertice("Unidad_de_Posgrado"), 7);
    G.IncertarArista(G.GetVertice("Unidad_de_Posgrado"), G.GetVertice("DGIRE"), 3);
    G.IncertarArista(G.GetVertice("DGIRE"), G.GetVertice("DGAPA"), 4);
    G.IncertarArista(G.GetVertice("DGAPA"), G.GetVertice("Archivo_General"), 6);
    G.IncertarArista(G.GetVertice("Archivo_General"), G.GetVertice("AV_Iman"), 3);
    G.IncertarArista(G.GetVertice("AV_Iman"), G.GetVertice("Investigaciones_filosoficas"), 6);
    G.IncertarArista(G.GetVertice("Investigaciones_filosoficas"), G.GetVertice("Investigaciones_fiologicas"), 2);
    G.IncertarArista(G.GetVertice("Investigaciones_fiologicas"), G.GetVertice("Coordinacion_de_Humanidades"), 2);
    G.IncertarArista(G.GetVertice("Coordinacion_de_Humanidades"), G.GetVertice("UNIVERSUM"), 4);
    G.IncertarArista(G.GetVertice("UNIVERSUM"), G.GetVertice("Teatro_y_Danza"), 5);
    G.IncertarArista(G.GetVertice("Teatro_y_Danza"), G.GetVertice("MUAC"), 4);
    G.IncertarArista(G.GetVertice("MUAC"), G.GetVertice("Biblioteca_Nacional"), 5);
    G.IncertarArista(G.GetVertice("Biblioteca_Nacional"), G.GetVertice("Espacio_Escultorico"), 3);
    G.IncertarArista(G.GetVertice("Espacio_Escultorico"), G.GetVertice("Investigaciones_Juridicas"), 5);
    G.IncertarArista(G.GetVertice("Investigaciones_Juridicas"), G.GetVertice("TV_UNAM"), 5);
    G.IncertarArista(G.GetVertice("TV_UNAM"), G.GetVertice("CUEC"), 3);
    G.IncertarArista(G.GetVertice("CUEC"), G.GetVertice("DGSA"), 3);
    G.IncertarArista(G.GetVertice("DGSA"), G.GetVertice("Tienda_UNAM"), 3);
    G.IncertarArista(G.GetVertice("Tienda_UNAM"), G.GetVertice("Metro_cu"), 4);

    int menu = 0;
    while (menu < 3 && menu > -1)
    {
        menu = ImprimirMenu();
        if (menu == 1)
        {
            G.Imprimir();
        }
        if (menu == 2)
        {
            string inicio, final, numeroTEL;
            int desicion;
            cout << "    Ingresa tu ubicacion" << endl;
            cin >> inicio;
            cout << "    Ingresa tu destino" << endl;
            cin >> final;
            cout << "La ruta se lee de DERECHA a IZQUIERDA" << endl;
            G.Camino_Rapido(G.GetVertice(inicio), G.GetVertice(final));
            cout << endl << "   Desa obtener la ruta en tu celular?" << endl << "[1] -> SI" << endl << "[2] -> NO" << endl;
            cin >> desicion;
            if (desicion == 1)
            {
                cout << "   Ingresa tu numero de celular de 10 digitos" << endl;
                cin >> numeroTEL;
                system(("py BotR.py " + numeroTEL).c_str());
            }
        }
    }

}




#include <iostream>
#include "AlbumReader.h"
#include "Sticker.h"
#include "Category.h"
#include "List.h"
#include "LinkedList.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

/*
ARCHIVO INICIAL DE ALBUM: C:\Users\ashle\Downloads\read.csv
C:\Users\ashle\Downloads\wiwi.csv
*/

using namespace std;
List<Sticker>* Album;
bool Sticker_marker(string codigo_unico);
bool Sticker_unmarker(string codigo_unico);
void Menu_Principal();
void Guardar_Archivo(string direccion_archivo, string para_guardar);

void File_Marker(string ubicacion_archivo) 
{
    vector<string> Lista_codigos;
    fstream archivo(ubicacion_archivo, ios::in);
    string line, word;
    if (archivo.is_open())
    {
        while (getline(archivo, line))
        {
            stringstream str(line);
            while (getline(str, word, ','))
            {
                Lista_codigos.push_back(word);
            }
        }
    }
    for (int i = 0; i < Lista_codigos.size(); i++)
    {
        if (Sticker_marker(Lista_codigos[i]) == true)
        {
            cout << "Se marco: " + Lista_codigos[i] + " exitosamente ;) \n";
        }
        else
        {
            cout << "El codigo" + Lista_codigos[i] + " no se encontro \n";
        }
    }
}

void File_Unmarker(string ubicacion_archivo)
{
    vector<string> Lista_codigos;
    fstream archivo(ubicacion_archivo, ios::in);
    string line, word;
    if (archivo.is_open())
    {
        while (getline(archivo, line))
        {
            stringstream str(line);
            while (getline(str, word, ','))
            {
                Lista_codigos.push_back(word);
            }
        }
    }
    for (int i = 0; i < Lista_codigos.size(); i++)
    {
        if (Sticker_unmarker(Lista_codigos[i]) == true)
        {
            cout << "Se desmarco: " + Lista_codigos[i] + " exitosamente ;) \n";
        }
        else
        {
            cout << "El codigo" + Lista_codigos[i] + " no se encontro \n";
        }
    }
}


bool Sticker_marker(string codigo_unico)
{
    for (int i = 0; i < Album->get_size(); i++)
    {
        if (codigo_unico == Album->get(i)->get_code()) 
        {
            Album->get(i)->mark();
            return true;
        }
    }
    return false;
}

bool Sticker_unmarker(string codigo_unico)
{
    for (int i = 0; i < Album->get_size(); i++)
    {
        if (codigo_unico == Album->get(i)->get_code())
        {
            Album->get(i)->unmark();
            return true;
        }
    }
    return false;
}

void Filtrar_Estampa_Seleccion(string code)
{
    string respuesta;
    string direccion_archivo;
    string Filtro_Estampa_Seleccion;
    Filtro_Estampa_Seleccion = "Codigo, Nombre, marcada, #repeticiones \n";
    for (int i = 0; i < Album->get_size(); i++)
    {
        if (code == Album->get(i)->get_category()->get_code()) //el nombre de la categoria de la categoria del sticker
        {
            Filtro_Estampa_Seleccion += Album->get(i)->get_code() + "," + Album->get(i)->get_name() + "," + Album->get(i)->is_marked() + "," + to_string(Album->get(i)->get_repeat()) + "\n";
        }
    }
    cout << Filtro_Estampa_Seleccion;
    cout << "Desea guardarlo? (escriba si o no) \n";
    getline(cin, respuesta);
    if (respuesta == "si") 
    {
        cout << "Ingrese la direccion del archivo \n";
        getline(cin, direccion_archivo);
        Guardar_Archivo(direccion_archivo, Filtro_Estampa_Seleccion);
        cout << "Se guardo exitosamente \n";
    }
    else
    {
        cout << "Presione cualquier tecla para continuar \n";
    }
        
}

void Filtrar_Estampa_Repeticion(string code)
{
    string respuesta;
    string direccion_archivo;
    string Filtro_Estampa_Repeticion;
    Filtro_Estampa_Repeticion = "Codigo, Nombre, marcada, #repeticiones \n";
    for (int i = 0; i < Album->get_size(); i++)
    {
        if (Album->get(i)->get_repeat()>0) //el nombre de la categoria de la categoria del sticker
        {
            Filtro_Estampa_Repeticion += Album->get(i)->get_code() + "," + Album->get(i)->get_name() + "," + Album->get(i)->is_marked() + "," + to_string(Album->get(i)->get_repeat()) + "\n";
        }
    }
    cout << Filtro_Estampa_Repeticion;
    cout << "Desea guardarlo? (escriba si o no) \n";
    getline(cin, respuesta);
    if (respuesta == "si")
    {
        cout << "Ingrese la direccion del archivo \n";
        getline(cin, direccion_archivo);
        Guardar_Archivo(direccion_archivo, Filtro_Estampa_Repeticion);
        cout << "Se guardo exitosamente \n";
    }
    else
    {
        cout << "Presione cualquier tecla para continuar \n";
    }

}

void Filtrar_Estampa_Seleccion_Repeticion(string code)
{
    string respuesta;
    string direccion_archivo;
    string Filtro_Estampa_Seleccion_Repeticion;
    Filtro_Estampa_Seleccion_Repeticion = "Codigo, Nombre, marcada, #repeticiones \n";
    for (int i = 0; i < Album->get_size(); i++)
    {
        if (code == Album->get(i)->get_category()->get_code() && Album->get(i)->get_repeat() > 0) 
        {
            Filtro_Estampa_Seleccion_Repeticion += Album->get(i)->get_code() + "," + Album->get(i)->get_name() + "," + Album->get(i)->is_marked() + "," + to_string(Album->get(i)->get_repeat()) + "\n";
        }
    }
    cout << Filtro_Estampa_Seleccion_Repeticion;
    cout << "Desea guardarlo? (escriba si o no) \n";
    getline(cin, respuesta);
    if (respuesta == "si")
    {
        cout << "Ingrese la direccion del archivo \n";
        getline(cin, direccion_archivo);
        Guardar_Archivo(direccion_archivo, Filtro_Estampa_Seleccion_Repeticion);
        cout << "Se guardo exitosamente";
    }
    else
    {
        cout << "Presione cualquier tecla para continuar \n";
    }

}

void Guardar_Archivo(string direccion_archivo, string para_guardar)
{
    ofstream archivo;
    archivo.open(direccion_archivo);
    archivo << para_guardar;
    archivo.close();
}

void Busqueda_Nombre(string nombre)
{
    string busqueda_nombre;
    busqueda_nombre = "Codigo, nombre, repetida, #repeticiones \n";

    for (int i = 0; i < Album->get_size(); i++)
    {
        if (nombre == Album->get(i)->get_name())
        {
            busqueda_nombre += Album->get(i)->get_code() + "," + Album->get(i)->get_name() + "," + to_string(Album->get(i)->get_repeat());
            cout << busqueda_nombre;
        }
    }
    return;
}

void Busqueda_Codigo(string code)
{
    string busqueda_codigo;
    busqueda_codigo = "Codigo, nombre, repetida, #repeticiones \n";

    for (int i = 0; i < Album->get_size(); i++)
    {
        if (code == Album->get(i)->get_code())
        {
            busqueda_codigo += Album->get(i)->get_code() + "," +Album->get(i)->get_name() + "," + to_string(Album->get(i)->get_repeat());
            cout << busqueda_codigo;
        }
        
    }
    return;

}

void Contador_Faltantes()
{
    int faltantes = 0;

    for (int i = 0; i < Album->get_size(); i++)
    {
        
        if(Album->get(i)->get_appeareances() == 0)
        {
            faltantes++;
        }
    }
    cout << "Contador faltantes: ";
    cout << faltantes;
}

void Contador_Marcadas()
{
    int marcadas = 0;

    for (int i = 0; i < Album->get_size(); i++)
    {
        if (Album->get(i)->get_appeareances() > 0)
        {
            marcadas++;
        }
    }

    cout << "Contador marcadas: ";
    cout << marcadas;
    
}

void Menu_Busqueda()
{
    string opcion;
    int opcion_num;
    string code;
    string name;

    do {
        system("cls");
        cout << "ingrese modo de busqueda \n";
        cout << "opcion 1: Buscar por nombre de estampa \n";
        cout << "opcion 2: Buscar por codigo unico de estampa \n";
        cout << "opcion 3: volver \n";

        getline(cin, opcion);
        opcion_num = stoi(opcion);

        switch (opcion_num)
        {
        case 1:
            cout << "Buscar por nombre de estampa \n";
            cout << "Ingrese nombre de estampa \n";
            getline(cin, name);
            Busqueda_Nombre(name);
            getwchar();
            break;

        case 2:
            cout << "Buscar por codigo unico de estampa \n";
            cout << "Ingrese codigo \n";
            getline(cin, code);
            Busqueda_Codigo(code);
            getwchar();
            break;

        case 3:
            Menu_Principal();
            getwchar();
            break;
        }
    } while (opcion_num != 5);
}

void menu_marcar() 
{
    string opcion; 
    int opcion_num;
    string codigo_unico;
    string nombre_archivo;

    do {
        system("cls");
        cout << "ingrese la opcion que desee: \n";
        cout << "opcion 1: Marcar estampas individualmente \n";
        cout << "opcion 2: Desmarcar individualmente \n";
        cout << "opcion 3: Marcar estampas por archivo \n";
        cout << "opcion 4: Desmarcar estampas por archivo \n";
        cout << "opcion 5: Volver \n";

        getline(cin, opcion);
        opcion_num = stoi(opcion);
        

        switch (opcion_num)
        {
        case 1:
            cout << "Marcar estampas individualmente \n";
            cout << "Ingrese codigo unico \n";
            getline(cin, codigo_unico);
            if(Sticker_marker(codigo_unico) == true) 
            {
                cout << "Sticker marcado c: \n";
            }
            else
            {
                cout << "Sticker no encontrado :c \n";
            }
            cout << "Presione cualquier tecla para continuar \n";
            getwchar();
            break;

        case 2:
            cout << "Desmarcar individualmente \n";
            cout << "Ingrese codigo unico \n";
            getline(cin, codigo_unico);
            if (Sticker_unmarker(codigo_unico) == true)
            {
                cout << "Sticker desmarcado c: \n";
            }
            else
            {
                cout << "Sticker no encontrado :c \n";
            }
            cout << "Presione cualquier tecla para continuar \n";
            getwchar();
            break;

        case 3:
            cout << "Marcar estampas por archivo \n";
            cout << "Ingrese direccion archivo: \n";
            getline(cin, nombre_archivo);
            File_Marker(nombre_archivo); /* C:\Users\ashle\Downloads\wiwi.csv */
            getwchar();
            break;

        case 4:
            cout << "Desmarcar estampas por archivo \n";
            cout << "Ingrese direccion del archivo: \n";
            getline(cin, nombre_archivo);
            File_Unmarker(nombre_archivo); /* C:\Users\ashle\Downloads\wiwi.csv */
            getwchar();
            break;

        case 5:
            Menu_Principal();
            getwchar();
            break;
        }
    } while (opcion_num != 5);
}

void Menu_Filtrar_Estampas()
{
    string opcion;
    int opcion_num;
    string code;

    do {
        system("cls");
        cout << "ingrese como desea filtrar: \n";
        cout << "opcion 1: Seleccion \n";
        cout << "opcion 2: Repeticion \n";
        cout << "opcion 3: Seleccion - Repeticion \n";
        cout << "opcion 4: volver \n";

        getline(cin, opcion);
        opcion_num = stoi(opcion);

        switch (opcion_num)
        {
        case 1:
            cout << "Filtrar por seleccion \n";
            cout << "Ingrese codigo \n";
            getline(cin,code);
            Filtrar_Estampa_Seleccion(code);
            getwchar();
            break;

        case 2:
            cout << "Filtrar por repeticion \n";
            cout << "Ingrese codigo \n";
            getline(cin, code);
            Filtrar_Estampa_Repeticion(code);
            getwchar();
            break;

        case 3:
            cout << "Filtrar por seleccion - repeticion \n";
            cout << "Ingrese codigo \n";
            getline(cin, code);
            Filtrar_Estampa_Seleccion_Repeticion(code);
            getwchar();
            break;

        case 4:
            Menu_Principal();
            getwchar();
            break;
        }
    } while (opcion_num != 5);
}



void Menu_Principal()
{
    string opcion;
    int opcion_num;

    do {
        system("cls");
        cout << "Album del Mundial \n";
        cout << "opcion 1: Marcar Estampas \n";
        cout << "opcion 2: Contador de faltantes \n";
        cout << "opcion 3: Contador de marcadas \n";
        cout << "opcion 4: Filtrar estampas \n";
        cout << "opcion 5: Buscar estampas \n";
        cout << "opcion 6: Salir \n";

        getline(cin, opcion);
        opcion_num = stoi(opcion);

        switch (opcion_num)
        {
        case 1:
            menu_marcar();
            getwchar();
            break;

        case 2:
            Contador_Faltantes();
            getwchar();
            break;

        case 3:
           
            Contador_Marcadas();
            getwchar();
            break;

        case 4:
            Menu_Filtrar_Estampas();
            getwchar();
            break;

        case 5:
            Menu_Busqueda();
            break;

        case 6:
            exit(0);
            getwchar();
            break;
        }
        
    } while (opcion_num != 5);
}


int main()
{
    AlbumReader Lector_Album;
    string nombre_archivo;

    cout << "ingrese direccion del archivo del album: \n";
    getline(cin, nombre_archivo);
    
    Album = Lector_Album.read_album(nombre_archivo); //C:\Users\ashle\Downloads\read.csv

    Menu_Principal();
}

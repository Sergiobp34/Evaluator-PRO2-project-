/** @file Curso.cc
    @brief Implementación de la clase Curso
*/

#include "Curso.hh"

Curso::Curso()
{}

void Curso::llenar_curso(int& n)
{
    string a;
    for(int i = 0; i<n; ++i){
        cin>>a;
        sesiones.push_back(a);
    }
}

void Curso::llenar_curso_i(int& n, const Cjt_sesiones &cjts)
{
    string a;
    for(int i = 0; i<n; ++i){
        cin>>a;
        sesiones.push_back(a);
        Sesion se = cjts.buscar_sesion(a);
        map<string, string>::iterator itend = problemas.end();
        for(int i =se.numero_problemas()-1; i>=0; --i){
            if (problemas.find(se.consultar_problema(i)) != itend){
                interseccion = true;
                i = -1;
            } 
            else problemas.insert({se.consultar_problema(i), a});
        }
    }
}

void Curso::usuario_inscrito()
{
    ++u_inscritos;
}

void Curso::usuario_completado()
{
    ++u_completado;
    --u_inscritos;
}

void Curso::baja_usuario_c()
{
    --u_inscritos;
}

int Curso::consultar_u_completado() const
{
    return u_completado;
}

int Curso::consultar_u_inscritos() const
{
    return u_inscritos;
}

int Curso::consultar_n_sesiones() const
{
    return sesiones.size();
}

string Curso::consultar_problema_sesion(const string &p, const Cjt_sesiones &cjts)
{
    if(problemas.empty()){
    for(int y = sesiones.size()-1; y>=0; --y){
    Sesion se = cjts.buscar_sesion(sesiones[y]);
        for(int i = se.numero_problemas()-1; i>=0; --i){
            problemas.insert({se.consultar_problema(i), sesiones[y]});
        }
    }
    }
    map<string, string>::const_iterator it = problemas.find(p);
    if(it != problemas.end()) return (*it).second;
    else return "-1";
}

void Curso::listar_datos_curso() const
{
    cout<<u_completado<<' '<<u_inscritos<<' '<<sesiones.size()<<' '<<'(';
    int x = sesiones.size();
    cout<<sesiones[0];
    
    for(int i = 1; i<x; ++i){
        cout<<' ';
        cout<<sesiones[i];
    }
    cout<<')';
}

bool Curso::interseccion_problemas()
{
    return interseccion;
}

string Curso::nombre_sesion(const int &x) const
{
    return sesiones[x];
}
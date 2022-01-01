/** @file Cjt_sesiones.cc
    @brief Implementación de la clase Cjt_sesiones
*/

#include "Cjt_sesiones.hh"

Cjt_sesiones::Cjt_sesiones(const int& x, const Cjt_problemas &cjtp)
{
    string s;
    for(int i = 0; i<x; ++i){
        cin>>s;
        cjts.insert({s, Sesion(cjtp)});
    }
}

void Cjt_sesiones::nueva_sesion(const string &s, const Cjt_problemas &cjtp)
{
    map<string, Sesion>::const_iterator itend = cjts.end();
    if(cjts.find(s) != itend) cout<<"error: la sesion ya existe"<<endl;
    else {
        cjts.insert({s, Sesion(cjtp)});
        cout<<cjts.size()<<endl;
    }
}

void Cjt_sesiones::listar_sesiones() const
{
    map<string, Sesion>::const_iterator itend = cjts.end();
    map<string,Sesion>::const_iterator it = cjts.begin();
    while(it != itend){
        cout<<(*it).first<<' ';
        cout<<(*it).second.numero_problemas()<<' ';
        (*it).second.escribir_postorden();
        cout<<endl;
        ++it;
    }
}

void Cjt_sesiones::escribir_sesion(const string& s)
{
    map<string, Sesion>::iterator it = cjts.find(s);
    map<string, Sesion>::const_iterator itend = cjts.end();
    if(it == itend) cout<<"error: la sesion no existe";
    else {
        cout<<s<<' '<<(*it).second.numero_problemas()<<' ';
        (*it).second.escribir_postorden();
    }
    cout<<endl;
}

Sesion Cjt_sesiones::buscar_sesion(const string &s) const
{
    return (*cjts.find(s)).second;
}
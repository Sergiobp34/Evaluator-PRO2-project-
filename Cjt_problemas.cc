/** @file Cjt_problemas.cc
    @brief Implementación de la clase Cjt_problemas
*/

#include"Cjt_problemas.hh"


Cjt_problemas::Cjt_problemas(int& x)
{
    string s;
    for(int i=0; i<x; ++i) {
        cin>>s;
        cjtp.insert({s, Problema()});
    }
}

void Cjt_problemas::nuevo_problema(string& s)
{
    pair<map<string, Problema>::iterator,bool> res;
    res = cjtp.insert(make_pair(s, Problema()));
        if(not res.second) cout<<"error: el problema ya existe"<<endl;
        else cout<<cjtp.size()<<endl;
}

void Cjt_problemas::nuevo_problema_sinvalor(string &s)
{
    pair<map<string, Problema>::iterator,bool> res;
    res = cjtp.insert(make_pair(s, Problema()));
}

void Cjt_problemas::borrar(const string &s)
{
    cjtp.erase(s);
}

void Cjt_problemas::cambiar_val_p(string &s, Problema &p)
{
    (*cjtp.find(s)).second = p;
}

void Cjt_problemas::anadir_p_env(string &p)
{
    (*cjtp.find(p)).second.anadir_p_enviado();
}

void Cjt_problemas::pro_ex(string &p)
{
    (*cjtp.find(p)).second.anadir_p_exito();
}

void Cjt_problemas::listar_problemas() const
{
    map<string ,Problema>::const_iterator itbegin = cjtp.begin();
    map<string ,Problema>::const_iterator itend = cjtp.end();
    vector<pair<Problema, string>> v;
    for(map<string ,Problema>::const_iterator it = itbegin; it != itend; ++it){
        pair<Problema, string> l;
        l.first = (*it).second;
        l.second = (*it).first;
        v.push_back(l);
    }
    sort(v.begin(), v.end(), ordenar_problemas);
    int p = cjtp.size();
    for(int i = 0; i<p; ++i) cout<<v[i].second<<'('<<v[i].first.entregas_totales()<<','
    <<v[i].first.entregas_exito()<<','<<v[i].first.consultar_ratio()<<')'<<endl;
}

void Cjt_problemas::escribir_problema(const string& s) const
{
    map<string ,Problema>::const_iterator itend = cjtp.end();
    map<string ,Problema>::const_iterator it = cjtp.find(s);
    if(it == itend) cout<<"error: el problema no existe"<<endl;
    else cout<<s<<'('<<(*it).second.entregas_totales()<<','<<(*it).second.entregas_exito()
    <<','<<(*it).second.consultar_ratio()<<')'<<endl;
}

bool Cjt_problemas::problema_existe(const string &s) const
{
    map<string ,Problema>::const_iterator itend = cjtp.end();
    return cjtp.find(s) != itend;
}

Problema Cjt_problemas::buscar_problema(const string &p)
{
    return (*cjtp.find(p)).second;
}

int Cjt_problemas::tamano() const
{
    return cjtp.size();
}

void Cjt_problemas::listar_problemas_simple() const
{
    map<string ,Problema>::const_iterator itbegin = cjtp.begin();
    map<string ,Problema>::const_iterator itend = cjtp.end();
    for(map<string ,Problema>::const_iterator it = itbegin; it!=itend; ++it)
    cout<<(*it).first<<'('<<(*it).second.entregas_totales()<<')'<<endl;
}
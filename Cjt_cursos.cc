/** @file Cjt_cursos.cc
    @brief Implementación de la clase Cjt_cursos
*/

#include "Cjt_cursos.hh"

Cjt_cursos::Cjt_cursos(int& N)
{
    int x;
    for(int i = 1; i<=N; ++i){
        cin>>x;
        Curso c;
        c.llenar_curso(x);
        cjtc.push_back(c);
    }
}

void Cjt_cursos::nuevo_curso(const Cjt_sesiones &cjts)
{
    int x;
    cin>>x;
    Curso c;
    c.llenar_curso_i(x, cjts);

    if(not c.interseccion_problemas()){
        cjtc.push_back(c);
        cout<<cjtc.size()<<endl;
    } 
    else cout<<"error: curso mal formado"<<endl;
}

void Cjt_cursos::incribir_curso_curso(const int &c)
{
    cjtc[c-1].usuario_inscrito();
}

void Cjt_cursos::quitar_u_inscrito(const int &c)
{
    cjtc[c-1].baja_usuario_c();
}

void Cjt_cursos::sesion_problema(const int &c, const string &p, const Cjt_problemas &cjtp, const Cjt_sesiones &cjts)
{
    if(c > cjtc.size() or c<=0) cout<<"error: el curso no existe"<<endl;
    else if(not cjtp.problema_existe(p)) cout<<"error: el problema no existe"<<endl;
    else{
        string s = cjtc[c-1].consultar_problema_sesion(p, cjts);
        if(s == "-1") cout<<"error: el problema no pertenece al curso"<<endl;
        else cout<<s<<endl;
    } 
}

void Cjt_cursos::listar_cursos() const
{
    int x = cjtc.size();
    for(int i = 0; i<x; ++i){
        cout<<i+1<<' ';
        cjtc[i].listar_datos_curso();
        cout<<endl;
    }
}

void Cjt_cursos::escribir_curso(const int &c) const
{
    if(c > cjtc.size() or c<=0) cout<<"error: el curso no existe"<<endl;
    else{
        cout<<c<<' ';
        cjtc[c-1].listar_datos_curso();
        cout<<endl;
    }
}

bool Cjt_cursos::buscar_curso(const int &c) const
{
    if(c > cjtc.size() or c <= 0) return false;
    else return true;
}

void Cjt_cursos::escribir_u_curso(const int &c) const
{
    cout<<cjtc[c-1].consultar_u_inscritos()<<endl;
}

Curso Cjt_cursos::dev_curso(const int &c)
{
    return cjtc[c-1];
}

int Cjt_cursos::tamano() const
{
    return cjtc.size();
}

void Cjt_cursos::u_completado(const int &c)
{
    cjtc[c-1].usuario_completado();
}
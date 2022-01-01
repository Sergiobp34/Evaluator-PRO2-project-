/** @file Cjt_usuarios.cc
    @brief Implementación de la clase Cjt_usuarios
*/

#include "Cjt_usuarios.hh"

Cjt_usuarios::Cjt_usuarios(int &M)
{
    string s;
    for(int i = 0; i<M; ++i){
        cin>>s;
        cjtu.insert({s, Usuario()});
    }
}

void Cjt_usuarios::alta_usuario(const string &u)
{
    map<string,Usuario>::iterator itend = cjtu.end();
    if(cjtu.find(u) == itend){
        cjtu.insert({u, Usuario()});
        cout<<cjtu.size()<<endl;
    } 
    else cout<<"error: el usuario ya existe"<<endl;
}

void Cjt_usuarios::baja_usuario(const string &u, Cjt_cursos &cjtc)
{
    map<string, Usuario>::iterator it = cjtu.find(u);
    map<string,Usuario>::iterator itend = cjtu.end();
    if(it != itend){
        if((*it).second.consultar_curso() <= cjtc.tamano() and (*it).second.consultar_curso() > 0) cjtc.quitar_u_inscrito((*it).second.consultar_curso());
        cjtu.erase(u);
        cout<<cjtu.size()<<endl;
    } 
    else cout<<"error: el usuario no existe"<<endl;
}

void Cjt_usuarios::inscribir_curso(const string &u, const int &c, Cjt_cursos &cjtc, const Cjt_sesiones &cjts)
{
    map<string, Usuario>::iterator it = cjtu.find(u);
    map<string,Usuario>::iterator itend = cjtu.end();
    if(it == itend) cout<<"error: el usuario no existe"<<endl;
    else if(not cjtc.buscar_curso(c))cout<<"error: el curso no existe"<<endl;
    else if((*it).second.consultar_curso() != 0) cout<<"error: usuario inscrito en otro curso"<<endl;
    else{
        (*it).second.inscribir_curso_usuario(c, cjtc, cjts);
        cjtc.incribir_curso_curso(c);
        cjtc.escribir_u_curso(c);
    }
}

void Cjt_usuarios::envio(const string &u, string &p, const int& r, const Cjt_sesiones &cjts, Cjt_problemas &cjtp, Cjt_cursos &cjtc)
{   
    cjtp.anadir_p_env(p); 
    map<string, Usuario>::iterator it_u = cjtu.find(u);
    (*it_u).second.anadir_p_intentado(p);
    if(r == 1){
        Curso c = cjtc.dev_curso((*it_u).second.consultar_curso());
       (*it_u).second.problema_res(p, c, cjts);
        cjtp.pro_ex(p);
    }
    else{
        (*it_u).second.problema_no_res(p);
    }
    if((*it_u).second.consultar_n_p_env() == 0) {
        cjtc.u_completado((*it_u).second.consultar_curso());
        (*it_u).second.curso_completado();
    }
}

void Cjt_usuarios::curso_usuario(const string &u) const
{
    map<string,Usuario>::const_iterator it = cjtu.find(u);
    map<string,Usuario>::const_iterator itend = cjtu.end();
    if(it != itend) cout<<(*it).second.consultar_curso()<<endl;
    else cout<<"error: el usuario no existe"<<endl;
}

void Cjt_usuarios::problemas_resueltos(const string &u) const
{
    map<string,Usuario>::const_iterator itend = cjtu.end();
    map<string,Usuario>::const_iterator it = cjtu.find(u);
    if(it == itend) cout<<"error: el usuario no existe"<<endl;
    else (*it).second.listar_p_res();
}

void Cjt_usuarios::problemas_enviables(const string &u) const
{
    map<string,Usuario>::const_iterator itend = cjtu.end();
    map<string,Usuario>::const_iterator it = cjtu.find(u);
    if(it == itend) cout<<"error: el usuario no existe"<<endl;
    else if((*it).second.consultar_curso() == 0) cout<<"error: usuario no inscrito en ningun curso"<<endl;
    else (*it).second.listar_p_env();
}

void Cjt_usuarios::listar_usuarios() const
{
    map<string,Usuario>::const_iterator itend = cjtu.end();
    for(map<string,Usuario>::const_iterator it = cjtu.begin(); it!=itend; ++it){
        cout<<(*it).first<<'('<<(*it).second.consultar_envios_tot()<<
        ','<<(*it).second.consultar_n_p_res()<<','<<(*it).second.consultar_p_intentados()<<
        ','<<(*it).second.consultar_curso()<<')'<<endl;
    }
}

void Cjt_usuarios::escribir_usuario(const string &u) const
{
    map<string,Usuario>::const_iterator itend = cjtu.end();
    map<string,Usuario>::const_iterator it = cjtu.find(u);
    if(it != itend){
        cout<<(*it).first<<'('<<(*it).second.consultar_envios_tot()<<
        ','<<(*it).second.consultar_n_p_res()<<','<<(*it).second.consultar_p_intentados()<<
        ','<<(*it).second.consultar_curso()<<')'<<endl;
    }
        else cout<<"error: el usuario no existe"<<endl;
}
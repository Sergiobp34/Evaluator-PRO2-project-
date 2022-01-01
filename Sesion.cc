/** @file Sesion.cc
    @brief Implementación de la clase Sesion
*/

#include "Sesion.hh"

Sesion::Sesion(const Cjt_problemas &cjtp)
{
    leer_sesion(a_p, cjtp, problemas);
}

int Sesion::numero_problemas()const
{
    return problemas.size();
}

void Sesion::escribir_postorden() const
{
    bintreeOut_postorden(a_p);
}

bool Sesion::problema_en_sesion(const string &p) const
{
    set<string>::const_iterator itend = problemas.end();
    if(problemas.find(p) != itend) return true;
    else return false;
}

string Sesion::consultar_problema(const int &i) const
{
    set<string>::iterator it = problemas.begin();
    for(int x = i; x>0; --x) ++it;
    return (*it);
}

void Sesion::actualizar_p_envs(Cjt_problemas &p_res, Cjt_problemas &p_env)
{
    act_p_env(a_p, p_res, p_env);
}
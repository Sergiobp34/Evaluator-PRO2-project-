/** @file Problema.cc
    @brief Implementación de la clase Problema
*/

#include "Problema.hh"

Problema::Problema(){}


void Problema::anadir_p_enviado()
{
    t = t+1;
}

void Problema::anadir_p_exito()
{
    e = e+1;
}

int Problema::entregas_totales() const
{
    return t;
}

int Problema::entregas_exito() const
{
    return e;
}

double Problema::consultar_ratio() const
{
    return (double(t)+1)/(e+1);
}
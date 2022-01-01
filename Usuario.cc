/** @file Usuario.cc
    @brief Implementación de la clase Usuario
*/

#include "Usuario.hh"

Usuario::Usuario()
{
    curso = 0;
    e_totales = 0;
}

void Usuario::inscribir_curso_usuario(const int &c, Cjt_cursos &cjtc, const Cjt_sesiones &cjts)
{
    curso = c;
    Curso f = cjtc.dev_curso(c);
    actualizar_p_enviables(f, cjts);
}

void Usuario::anadir_p_intentado(const string &p)
{
    ++e_totales;
    if(p_intentados.find(p) == p_intentados.end()) p_intentados.insert(p);
}

void Usuario::problema_res(string &p, Curso &c, const Cjt_sesiones &cjts)
{
    p_env.anadir_p_env(p);
    p_res.nuevo_problema_sinvalor(p);
    Problema prob = p_env.buscar_problema(p);
    p_res.cambiar_val_p(p,prob);
    p_env.borrar(p);
    actualizar_p_enviables(c, cjts);
}

void Usuario::problema_no_res(string &p)
{
    p_env.anadir_p_env(p);
}

void Usuario::curso_completado()
{
    curso = 0;
}

int Usuario::consultar_curso() const
{
    return curso;
}

int Usuario::consultar_envios_tot() const
{
    return e_totales;
}

int Usuario::consultar_n_p_res() const
{
    return p_res.tamano();
}

int Usuario::consultar_p_intentados() const
{
    return p_intentados.size();
}

int Usuario::consultar_n_p_env() const
{
    return p_env.tamano();
}

void Usuario::listar_p_res() const
{
    p_res.listar_problemas_simple();
}

void Usuario::listar_p_env() const
{
    p_env.listar_problemas_simple();
}


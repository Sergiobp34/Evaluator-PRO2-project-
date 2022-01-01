/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef _USUARIO_HH_
#define _USUARIO_HH_

#include "Cjt_cursos.hh" // ver explicación en Cjt_cursos.hh
#include "Cjt_problemas.hh" // ver explicación en Cjt_problemas.hh
#include "Cjt_sesiones.hh" // ver explicación en Cjt_sesiones.hh

#ifndef NO_DIAGRAM  
#include <map>
#include <set>
#endif

/** @class Usuario
    @brief Representa un usuario

        Un usuario se identifica con un string y es un conjunto de curso, sus sesiones pertinentes, 
        los problemas resueltos, problemas que puede resolver y los envios totales.
            */
class Usuario
    {
public:
    //Constructoras

    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un usuario.
      \pre <b>Cierto</b>.
      \post El resultado es un usuario inicializado.
    */
    Usuario();

    //Modificadoras

    /** @brief Modificadora del curso del usuario.

      \pre <b>c</b> existe.
      \post Asigna el curso <b>c</b> a el usuario.
    */
    void inscribir_curso_usuario(const int &c, Cjt_cursos &cjtc, const Cjt_sesiones &cjts);

    /** @brief Modificadora de un problema enviado por el usuario.

      \pre Cierto.
      \post Añade un problema enviado y lo añade a los problemas intentados si el problema 
            no lo había intentado ya.
    */
    void anadir_p_intentado(const string &p);

    /** @brief Modificadora de un problema resuelto por el usuario.

      \pre Cierto.
      \post Actualiza los datos del problema y añade un problema resuelto y actualiza 
            los problemas enviables del usuario. Si el usuario acaba el curso,
            el curso del usuario pasa a ser 0.
    */
    void problema_res(string &p, Curso &c, const Cjt_sesiones &cjts);

    /** @brief Modificadora de un problema no resuelto por el usuario.

      \pre Cierto.
      \post Actualiza los datos del problema y del problema dentro de problemas enviables 
            del usuario.
    */
    void problema_no_res(string &p);

    /** @brief Modificadora al completar un curso por el usuario.

      \pre Cierto.
      \post El curso del usuario pasa a ser 0.
    */
    void curso_completado();

    //Consultoras

    /** @brief Consultora del curso de un usuario

      \pre El parámetro implicito está inicializado.
      \post Retorna el curso del usuario.
    */
    int consultar_curso() const;

    /** @brief Consultora del número de envios de un usuario

      \pre El parámetro implicito está inicializado.
      \post Retorna el número de envios del usuario.
    */
    int consultar_envios_tot() const;

    /** @brief Consultora del número de problemas resueltos de un usuario

      \pre El parámetro implicito está inicializado.
      \post Retorna el número de problemas resueltos del usuario.
    */
    int consultar_n_p_res() const;

    /** @brief Consultora del número de problemas intentados de un usuario

      \pre El parámetro implicito está inicializado.
      \post Retorna el número de problemas intentados del usuario.
    */
    int consultar_p_intentados() const;

    /** @brief Consultora del número de problemas enviables de un usuario

      \pre El parámetro implicito está inicializado.
      \post Retorna el número de problemas enviables del usuario.
    */
    int consultar_n_p_env() const;

    /** @brief Consultora de los problemas intentados de un usuario

      \pre El parámetro implicito está inicializado.
      \post Imprime en pantalla los problemas resueltos por el usuario 
            en orden creciente por el nombre de problema seguido de el 
            número de envios realizados a cada problema.
    */
    void listar_p_res() const;

    /** @brief Consultora de los problemas enviables de un usuario

      \pre El parámetro implicito está inicializado.
      \post Imprime en pantalla los problemas enviables en orden creciente por 
            por el nombre del problema que el usuario puede enviar seguido de 
            el número de envios realizados a cada problema. 
    */
    void listar_p_env() const;

private:
    /** @brief Función para actualizar los problemas enviables del usuario*/
    void actualizar_p_enviables(Curso &c, const Cjt_sesiones &cjts) 
    {
        int x = c.consultar_n_sesiones()-1;
        while(x>=0){
          Sesion p = cjts.buscar_sesion(c.nombre_sesion(x));
          p.actualizar_p_envs(p_res, p_env);
          --x;
        }
    }

    int curso = 0;    //Curso del usuario
    Cjt_problemas p_res; //problemas resueltos
    Cjt_problemas p_env; //problemas enviables
    set<string> p_intentados;  //set con los problemas intentados
    int e_totales = 0;   //num. de envios totales
    
};
#endif
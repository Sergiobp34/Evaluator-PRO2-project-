/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef _CURSO_HH_
#define _CURSO_HH_

#include"Cjt_sesiones.hh"  //Ver explicación en Cjt_sesiones.hh.

#ifndef NO_DIAGRAM
#include <vector>
using namespace std;
#endif

/** @class Curso
    @brief Representa un curso

        Un curso viene definido por una secuencia de sesiones.
            */
class Curso
    {
public:
    //Constructoras

    /** @brief Creadora por defecto 

      Se ejecuta automáticamente al declarar un curso.
      \pre  Las sesiones que se quieren añadir tienen que ser válidas y
            sin repeticiones.
      \post El resultado es un curso con un número <b>v</b> que lo 
            identifica junto con una secuéncia de sesiones válidas en una lista.
  */  
    Curso();

    //Modificadoras
    /** @brief Llenar curso

      \pre  Las sesiones que se quieren añadir tienen que ser válidas y
            sin repeticiones.
      \post El resultado es un curso con un número <b>n</b> de secuéncia de 
            sesiones válidas en una lista.
  */  
    void llenar_curso(int& n);

    /** @brief Llenar curso mirando intersección

      \pre  Cierto.
      \post El resultado es un curso con un número <b>n</b> de secuéncia de 
            sesiones válidas en una lista. Si hay intersección entre los problemas, 
            el bool intersección es cierto.
  */  
    void llenar_curso_i(int& n, const Cjt_sesiones &cjts);

    /** @brief Modificadora del número de usuarios inscritos al curso

      \pre  Cierto.
      \post Modifica el valor de <b>u_inscritos</b> sumandole 1.
  */ 
    void usuario_inscrito();

    /** @brief Modificadora del número de usuarios que han completado el curso

      \pre  Cierto.
      \post Resta 1 al valor de <b>u_inscritos</b> y le suma 1 al valor de <b>u_completado</b>.
  */ 
    void usuario_completado();

    /** @brief Modificadora del número de usuarios que están inscritos al curso

      \pre  Cierto.
      \post Resta 1 al valor de <b>u_inscritos</b>.
  */ 
    void baja_usuario_c();

    //Consultoras:

     /** @brief Consultora del numero de usuarios que han completado el curso

      \pre  Cierto.
      \post Devuelve el valor <b>u_completado</b>.
  */ 
    int consultar_u_completado() const;

     /** @brief Consultora del numero de usuarios inscritos al curso

      \pre  Cierto.
      \post Devuelve el valor <b>u_inscritos</b>.
  */ 
    int consultar_u_inscritos() const;

     /** @brief Consultora del numero de sesiones del curso

      \pre  Cierto.
      \post Devuelve el valor <b>n_sesiones</b>.
  */ 
    int consultar_n_sesiones() const;

    /** @brief Consultora de una sesion del curso.

      \pre  Cierto.
      \post Devuelve el nombre de la sesión en la que està el problema. Si 
            el problema no existe o si el problema no pertenece al curso se 
            imprime un mensaje de error.
  */ 
    string consultar_problema_sesion(const string &p, const Cjt_sesiones &cjts);

    /** @brief Consultora de los datos de un curso.

      \pre  Cierto.
      \post Imprime en pantalla el número de usuarios que lo han 
            completado, el número de usuarios inscritos actualmente, 
            el número de sesiones que lo forman y los identificadores 
            de las sesiones en el orden en el que se leyeron.
    */ 
    void listar_datos_curso() const;

    /** @brief Consultora de la intersección de problemas de un curso.

      \pre  Cierto.
      \post Devuelve cierto si el curso tiene intersección de problemas, si no hay 
            intersección devuelve falso.
    */
    bool interseccion_problemas();

  /** @brief Consultora del nombre de una sesión de un curso.

      \pre  <b>x</b>>0 y <b>x</b><= número de sesiones.
      \post Devuelve el nombre de una sesión marcada por el valor <b>x</b>.
    */     
    string nombre_sesion(const int &x) const;

private:
    map<string, string> problemas;  //map con problema sesion.
    bool interseccion = false;  //bool que indica si hay inersección de problemas.
    int u_completado = 0; //num. de usuarios que han completado el curso.
    int u_inscritos = 0;  //num. de usuarios inscritos en el curso
    vector<string> sesiones; //vector con nombre de sesion

};
#endif
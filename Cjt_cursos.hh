/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos
*/

#ifndef _CJT_CURSOS_HH_
#define _CJT_CURSOS_HH_

#include "Curso.hh" // ver explicacion en Curso.hh

#ifndef NO_DIAGRAM  
#include <vector>
#endif

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos

        Un conjunto de cursos está ordenado según se vayan añadiendo
        nuevos cursos.
            */
class Cjt_cursos
    {
public:
    //Constructoras

    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de cursos.
      \pre <b>N>0</b>.
      \post El resultado es un conjunto de <b>N</b> cursos identificados en el 
            orden en que se leen.
  */
    Cjt_cursos(int& N);

    //Modificadoras

    /** @brief Añade un curso al conjunto de cursos

      \pre  La secuencia de sesiones del nuevo curso no tiene 
            intersección de problemas entre las sesiones del curso a añadir
            y no existe otro curso igual (con las mismas sesiones). 
      \post El resultado es el conjunto de cursos con el nuevo curso con 
            identificador <b>N+1</b> e impreso su identificador. 
            */
    
    void nuevo_curso(const Cjt_sesiones &cjts);

    /** @brief Incribe un usuario cualquiera a un curso

      \pre  El parámetro implícito está inicializado.
      \post El resultado es un usuario cualquiera inscrito en el curso 
            <b>c</b> del conjunto de cursos.
            */
    void incribir_curso_curso(const int &c);

    /** @brief Quita un usuario cualquiera de un curso

      \pre  El curso <b>c</b> existe.
      \post El resultado el curso <b>c</b> sin un usuario cualquiera.
            */
    void quitar_u_inscrito(const int &c);

    /** @brief Añade un usuario completado cualquiera a un curso

      \pre  El curso <b>c</b> existe.
      \post El resultado el curso <b>c</b> con un usuario menos inscrito en el curso y 
            un usario mas en usuarios completado.
            */
    void u_completado(const int &c);

    //Consultoras

    /** @brief Consultora de la sesión a la que pertenece un problema en un curso 

      \pre El parámetro implícito está inicializado.
      \post Imprime en pantalla el identificador de la sesión en 
            la que el problema está en ese curso. Si el curso <b>c</b> no existe o 
            si el problema <b>p</b> no existe o <b>cp</b> no pertence al curso se muestra un 
            mensaje de error.
    */
    void sesion_problema(const int &c, const string &p, const Cjt_problemas &cjtp, const Cjt_sesiones &cjts);

     /** @brief Consultora del conjunto de cursos

         \pre El parámetro implícito está inicializado.
         \post Imprime en pantalla todos los cursos, en orden creciente por su 
               identificador, y mostrando en cada uno el número de usuarios inscritos 
               actualmente, número de sesiones de cada curso y los identificadores de 
               cada sesión (en el mismo orden en el que se leyeron cuando se creó el curso).
     */
    void listar_cursos() const;

    /** @brief Consultora de un curso del conjunto de cursos

      \pre El parámetro implícito está inicializado.
      \post Imprime en pantalla el identificador del curso, mostrando el número 
            de usuarios inscritos actualmente, número de sesiones de cada curso y 
            los identificadores de cada sesión (en el mismo orden en el que se leyeron 
            cuando se creó el curso). Si el curso no existe, se muestra un error. 
        */
    void escribir_curso(const int &c) const;

    /** @brief Consultora para mirar si un curso está en el conjunto de cursos

      \pre Cierto
      \post Devuelve cierto si el curso <b>c</b> está en el conjunto de cursos, si no, devuelve falso. 
        */
    bool buscar_curso(const int &c) const;

    /** @brief Consultora del número de usuarios incritos en un curso

      \pre  <b>c</b> está en el conjunto de cursos.
      \post Imprime en pantalla el número de usuarios incritos en el curso <b>b</b>.
     */
    void escribir_u_curso(const int &c) const;
      
    /** @brief Consultora de un curso del conjunto

      \pre  <b>c</b> está en el conjunto de cursos.
      \post Devuelve el curso <b>c</b>.
     */ 
    Curso dev_curso(const int &c);

    /** @brief Consultora del tamaño del conjunto de cursos

      \pre  Cierto
      \post Devuelve el tamaño del conjunto de cursos.
     */ 
    int tamano() const;

private:
    vector<Curso> cjtc;
};
#endif
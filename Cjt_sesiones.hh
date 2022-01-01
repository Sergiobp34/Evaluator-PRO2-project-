/** @file Cjt_sesiones.hh
    @brief Especificación de la clase Cjt_sesiones
*/

#ifndef _CJT_SESIONES_HH_
#define _CJT_SESIONES_HH_

#include "Sesion.hh" // ver explicacion en Sesion.hh

#ifndef NO_DIAGRAM  
#include <map>
#endif

/** @class Cjt_sesiones
    @brief Representa un conjunto de sesiones

        Las sesiones se irán ordenando mientras se añaden. 
        Un conjunto de sesiones no puede tener dos sesiones iguales.
            */
class Cjt_sesiones
    {
public:
    //Constructoras

    /** @brief Creadora por defecto
 
        Se ejecuta automáticamente al declarar un conjunto de sesiones.
        \pre <b>x>0</b>.
        \post El resultado es un conjunto con Q sesiones.
    */
    Cjt_sesiones(const int &x, const Cjt_problemas &cjtp);

    //Modificadoras

    /** @brief Añade una sesion al conjunto de sesiones
 
        \pre Cierto.
        \post El resultado es el conjunto de sesiones con la nueva sesión
              implementada e impreso el número de sesiones. Si la sesión ya existia, se imprime 
              un error.
    */
    void nueva_sesion(const string &s, const Cjt_problemas &cjtp);

    //Consultoras

    /** @brief Consultora del conjunto de sesiones

        \pre El parámetro implícito está inicializado.
        \post Imprime en pantalla las sesiones del conjunto ordenadas crecientemente
              por su identificador y mostrando, para cada sesión, el número de problemas
              que la forman, siguiendo su estructura de prerequisitos en postorden.
    */    
    void listar_sesiones() const;

    /** @brief Consultora de una sesión del conjunto de sesiones

        \pre Cierto.
         \post Imprime en pantalla el nombre de la sesion <b>s</b> del conjunto y
              el número de problemas que la forman, siguiendo su estructura de 
              prerequisitos en postorden. Si la sesión no existe se imprime un error.
    */
    void escribir_sesion(const string& s);

    /** @brief Consultora de una sesión del conjunto de sesiones (devuelve la sesión)

        \pre La Sesion con nombre <b>s</b> está en el conjunto de sesiones.
         \post Devuelve la Sesion con nombre <b>s</b>.
    */

    Sesion buscar_sesion(const string &s) const;
    

private:
map<string, Sesion> cjts; //map con nombre sesión, Sesion

};
#endif
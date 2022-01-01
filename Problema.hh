/** @file Problema.hh
    @brief Especificación de la clase Problema 
*/

#ifndef _PROBLEMA_HH_
#define _PROBLEMA_HH_

#ifndef NO_DIAGRAM 
#include <iostream>
#endif

using namespace std;

/** @class Problema
    @brief Representa el contenido de un problema

        Un problema viene definido por su identificador y por dos valores <b>t</b>(veces intentado) y 
        <b>e</b>(veces resuelto exitosamente).
            */
class Problema
    {
public:
  //Constructoras

    /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un problema.
      \pre <b>Cierto</b>
      \post El resultado es un problema con nombre s 
            y con <b>t = 0</b> y <b>e = 0</b>;
    */
    Problema();

  //Modificadoras:
    /** @brief Suma 1 a la variable </b>t</b> del problema </b>p</b>. 

      \pre <b>p</b> existe.
      \post El resultado es el problema con la variable t+1. 
    */
    void anadir_p_enviado();

    /** @brief Suma 1 a la variable </b>e</b> del problema </b>p</b>. 

      \pre <b>p</b> existe.
      \post El resultado es el problema con la variable e+1. 
    */
    void anadir_p_exito();

  //Consultoras

    /** @brief Consultora de entregas totales. 
     
      \pre <b>Cierto</b>.
      \post Devuelve el numero total de entregas del problema.
    */
     int entregas_totales() const;

    /** @brief Consultora de entregas con éxito. 

      \pre <b>Cierto</b>.
      \post Devuelve el numero de entregas con exito del problema.
    */
     int entregas_exito() const;

    /** @brief Consultora del ratio del problema. 

      \pre <b>Cierto</b>.
      \post Devuelve el ratio del problema.
    */
     double consultar_ratio() const;


private:
  int t = 0; //num. de envios totales.
  int e = 0; //num. de envios con éxito
};
#endif
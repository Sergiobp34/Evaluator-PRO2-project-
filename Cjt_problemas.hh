/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas
*/

#ifndef _CJT_PROBLEMAS_HH_
#define _CJT_PROBLEMAS_HH_

#include "Problema.hh" // ver explicacion en Problema.hh

#ifndef NO_DIAGRAM  
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#endif

/** @class Cjt_problemas
    @brief Representa un conjunto de problemas

        Un conjunto de problemas no puede tener dos problemas con nombres iguales.
            */

class Cjt_problemas
    {
public:
  //Constructoras

   /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un conjunto de problemas.
      \pre <b>P>0</b>.
      \post El resultado es un conjunto ordenado con P problemas.
  */  
    Cjt_problemas(int &P);
    Cjt_problemas() = default;

 //Modificadoras

    /** @brief Añade un problema al conjunto de problemas.

          \pre Cierto.
          \post El resultado es el conjunto de problemas con el nuevo problema <b>s</b> 
                implementado e impreso el número de problemas. Si el problema <b>s</b> ya 
                existia se muestra un error. 
        */
    void nuevo_problema(string &s);

    /** @brief Añade un problema al conjunto de problemas sin imprimir el contador.

          \pre Cierto.
          \post El resultado es el conjunto de problemas con el nuevo problema <b>s</b>.
        */
    void nuevo_problema_sinvalor(string &s);

    /** @brief Añade un problema al conjunto de problemas sin imprimir el contador.

          \pre <b>s</b> existe en el conjunto.
          \post El resultado es el conjunto de problemas con el problema <b>s</b> eliminado.
        */
    void borrar(const string &s);

    /** @brief Intercambiadora de valores de dos problemas.

          \pre <b>s</b> existe en el conjunto.
          \post El resultado es el conjunto de problemas con el problema <b>s</b> modificado con el valor del Problema <b>p</b>.
        */
    void cambiar_val_p(string &s, Problema &p);

    /** @brief Añade un problema enviado al problema con identificador <b>s</b>.

          \pre <b>s</b> existe en el conjunto.
          \post El resultado es el conjunto de problemas con el problema <b>s</b> con un envio mas.
        */
    void anadir_p_env(string &p);

        /** @brief Añade un problema enviado exitosamente al problema con identificador <b>s</b>.

          \pre <b>s</b> existe en el conjunto.
          \post El resultado es el conjunto de problemas con el problema <b>s</b> con un envio exitoso mas.
        */
    void pro_ex(string &p);

 //Consultoras

     /** @brief Consultora del conjunto de problemas

         \pre El parámetro implícito está inicializado.
         \post Imprime en pantalla los problemas del conjunto indicando en cada
               uno cuantos envios se han hecho en total <b>t</b>, cuantos han
               tenido éxito <b>e</b> y el ratio (<b>t</b> + 1)/(<b>e</b> + 1), 
               todos problemas estan ordenados segun un orden creciente de ratio.
     */
    void listar_problemas() const;

    /** @brief Consultora de un problema del conjunto de problemas.

      \pre El parámetro implícito está inicializado.
      \post Imprime en pantalla el problema con identificador <b>s</b> del conjunto indicando en él
            cuantos envios se han hecho en total <b>t</b>, cuantos han
            tenido éxito <b>e</b> y el ratio (<b>t</b> + 1)/(<b>e</b> + 1). Si el problema no existe, se 
            muestra un error.
        */
    void escribir_problema(const string &s) const;

    /** @brief Consultora para ver si un problema está conjunto de problemas.

      \pre <b>Cierto</b> 
      \post Devuelve cierto si el problema con nombre <b>s</b> pertenece al conjunto de problemas, 
            si no devuelve falso.
      */
    bool problema_existe(const string &s) const;

    /** @brief Consultora que devuelve un Problema del conjunto.

      \pre El problema <b>s</b> está en el conjunto.
      \post Devuelve el Problema con identificador <b>s</b>.
      */
    Problema buscar_problema(const string &p);

    /** @brief Consultora del tamaño de un conjunto.

      \pre Cierto.
      \post Devuelve el tamño del conjunto de Problemas.
      */
    int tamano() const;

    /** @brief Consultora del conjunto de problemas

         \pre El parámetro implícito está inicializado.
         \post Imprime en pantalla los problemas del conjunto indicando en cada
               uno cuantos envios se han hecho en total <b>t</b> en orden alfabetico por identificador.
     */
    void listar_problemas_simple() const;

private:
/** @brief Función para ordenar problemas por ratio*/
    static bool ordenar_problemas(const pair<Problema, string> &a, const pair<Problema, string> &b) 
    {
        if(a.first.consultar_ratio() != b.first.consultar_ratio()) return a.first.consultar_ratio() < b.first.consultar_ratio();
        else return a.second < b.second;
    }

    map<string, Problema> cjtp; //map de nombre de problema, Problema
};
#endif
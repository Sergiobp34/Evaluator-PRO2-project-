/** @file Sesion.hh
    @brief Especificación de la clase Sesion 
*/

#ifndef _SESION_HH_
#define _SESION_HH_

#include "Cjt_problemas.hh" // Ver explicacion en Cjt_problemas.hh
#include "BinTree.hh"       // Ver explicacion en BinTreeIO.hh


#ifndef NO_DIAGRAM 
#include <set>
#endif


/** @class Sesion
    @brief Representa una sesión

        Una sesión es una secuencia de problemas con lectura en preorden.
            */
class Sesion
    {
public:

  //Constructora
    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar una sesión.
      \pre Cierto.
      \post El resultado es una sesión con un arbol
            binario de problemas leidos en preorden.
            Además se crea un conjunto con el mismo identificador
            y la misma sequencia de problemas.
  */  
    Sesion(const Cjt_problemas &cjtp);
    Sesion() = default;

 //Consultora
    /** @brief Consultora del numero de problemas de una sesión

      \pre Cierto.
      \post Devuelve la cantidad de problemas de una sesión.
  */
    int numero_problemas()const;

    /** @brief Consultora para mirar si un problema está en una sesión.

      \pre Cierto.
      \post Devuelve cierto si el problema <b>p</b> está en la sesión, 
            alternativamente devuelve falso.
  */
    bool problema_en_sesion(const string &p) const;

    /** @brief Consultora de los problemas de una sesión.

      \pre Cierto.
      \post Imprime en pantalla los problemas de la sesión en postorden.
  */
    void escribir_postorden() const;

    //devuelve problema en la posición i.
    string consultar_problema(const int &i) const;

    /** @brief Consultora de los problemas de una sesión para actualizar los problemas enviables de un usuario.

      \pre Cierto.
      \post Actualiza los problemas enviables en función de los problemas resueltos siguiendo el orden del arbol de 
            problemas de la sesión.
  */
    void actualizar_p_envs(Cjt_problemas &p_res, Cjt_problemas &p_env);

private:
    /** @brief Lectora del arbol de problemas*/
    void leer_sesion(BinTree<string> &a, const Cjt_problemas &cjtp, set<string> &problemas) 
    {
        BinTree<string> a1;
        BinTree<string> a2;
        string s;
        cin>>s;

        bool p_existe = cjtp.problema_existe(s);
        if(s != "0"){
            if(not p_existe) cout<<"error: el problema no existe en el conjunto de problemas"<<endl;
            else{
            problemas.insert(s);
            leer_sesion(a1, cjtp, problemas);
            leer_sesion(a2, cjtp, problemas);
            a = BinTree<string> (s, a1, a2);
            }
        }
    }

    /** @brief Escritora del arbol de problemas (postorden)*/
    void bintreeOut_postorden(const BinTree<string> &a) const  
    {
    if(not a.empty()){
        cout<<'(';
        string s = a.value();
        BinTree<string> a1 = a.left();
        bintreeOut_postorden(a1);
        BinTree<string> a2 = a.right();
        bintreeOut_postorden(a2);
        cout<<s<<')';
    }
    }

    /** @brief función que actualiza los problemas enviables de un usuario*/
    void act_p_env(const BinTree<string> &a, Cjt_problemas &p_res, Cjt_problemas &p_env) 
    {
        if(not a.empty()){
            string s = a.value();
             if(not p_res.problema_existe(s)) p_env.nuevo_problema_sinvalor(s);

            else{
                BinTree<string> a1 = a.left();
                act_p_env(a1, p_res, p_env);
                BinTree<string> a2 = a.right();
                act_p_env(a2, p_res, p_env);
            }
         }
    }

    set<string> problemas; //set con todos los problemas de la sesión
    BinTree<string> a_p;   //arbol binario con los problemas de la sesión
};

#endif
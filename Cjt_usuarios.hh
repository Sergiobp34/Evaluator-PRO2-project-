/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios 
*/

#ifndef _CJT_USUARIOS_HH_
#define _CJT_USUARIOS_HH_

#include "Usuario.hh" //Ver explicación en Usuario.hh

#ifndef NO_DIAGRAM  
#include <map>
#endif

/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios

        Un conjunto de usuarios está representado con un numero M y por una sucesión de 
        usuarios.
            */
class Cjt_usuarios
    {
public:
    //Constructoras

    /** @brief Creadora por defecto

      Se ejecuta automáticamente al declarar un conjunto de usuarios.
      \pre <b>M>0</b>.
      \post El resultado es un conjunto de <b>M</b> usuarios identificados en el 
            orden en que se leen.
  */
    Cjt_usuarios(int& M);

    //Modificadoras

    /** @brief Da de alta un nuevo usuario

      \pre  Cierto.
      \post El resultado es el conjunto de usuarios con el nuevo usuario 
            <b>u</b> e impreso el número de usuarios. Si el usuario 
            ya estaba en el conjunto, se imprime un mensaje de error.
     */
    void alta_usuario(const string &u);

    /** @brief Da de baja un usuario

      \pre  Cierto. 
      \post El resultado es el conjunto de usuarios sin el nuevo usuario 
            <b>u</b> e impreso el número de usuarios. Si el usuario no 
            existia se imprime un mensaje de error.
     */
    void baja_usuario(const string &u, Cjt_cursos &cjtc);

    /** @brief Inscribe un usuario a un curso

      \pre  Cierto
      \post El resultado es el usuario con identificador <b>u</b> añadido al curso <b>c</b>
            e impreso en pantalla el número de usuarios inscritos en el curso. Si el curso no existe o 
            si el usuario no existe o si el usuario ya está inscrito en otro curso se imprime un mensaje de error.
     */
    void inscribir_curso(const string &u, const int &c, Cjt_cursos &cjtc, const Cjt_sesiones &cjts);

    
    /** @brief Envio de un problema hecho por un usuario

      \pre  El usuario <b>u</b> y el problema <b>p</b> existen, <b>p</b>
            pertenece al curso al cual el usuario está registrado y <b>u</b>
            ha cumplido los prerequisitos de <b>p</b>.
      \post Actualiza las estadisticas del usuario(problemas intentados) y del 
            problema(entregas totales). Además, si r = 1 (problema acertado)
            se actualizan además las entregas con éxito del problema y se actualizan
            los problemas resueltos y enviables por el usuario. Y si el usuario ha
            terminado el curso deja de estar inscrito en él.
         */
    void envio(const string &u, string &p, const int& r, const Cjt_sesiones &cjts, Cjt_problemas &cjtp, Cjt_cursos &cjtc);

    //Consultoras

    /** @brief Consultora del curso del usuario
     
      \pre  Cierto.
      \post Se imprime el curso actual del usuario. Si el usuario no existe se imprime un error.
     */
    void curso_usuario(const string &u) const;

    /** @brief Consultora de los problemas resueltos por el usuario
     
      \pre  Cierto.
      \post Se listan en orden creciente por identificador los problemas solucionados con
            éxito del usuario <b>u</b>(del curso en el que está ahora incrito(o no) y de 
            los cursos anteriores). También junto a cada identificador de cada problema 
            se imprime la cantidad de envíos realizados. Si el usuario no existe, se imprime un error.
     */
    void problemas_resueltos(const string &u) const;

    /** @brief Consultora de los problemas enviables por el usuario

      \pre  Cierto.
      \post Se listan en orden creciente por identificador los problemas que el usuario
            todavia no ha resuelto en el curso en el que se encuentra(solo los problemas 
            que pueda resolver por haber cumplido los prerequisitos). Además se imprime 
            junto al identificador del problema la cantidad de envíos hechos por el usuario 
            en cada problema. Si el usuario no existe, se imprime un error.
     */
    void problemas_enviables(const string &u) const;

    /** @brief Consultora del conjunto de usuarios
     
      \pre  El parámetro implícito está inicializado.
      \post Se listan los usuarios registrados actualmente en la plataforma, ordenados crecientemente
            por su nombre y mostrando, para cada usuario, cuántos envíos en total ha realizado, cuántos 
            problemas ha resuelto con éxito, cuántos problemas ha intentado resolver, y el identificador 
            del curso en el que está inscrito o un cero si no está inscrito en ninguno.
     */
    void listar_usuarios() const;

    /** @brief Consultora de un usuario del conjunto de usuarios

      \pre  Cierto.
      \post Se muestra en pantalla el usuario junco con cuántos envíos en total ha realizado, cuántos 
            problemas ha resuelto con éxito, cuántos problemas ha intentado resolver, y el identificador 
            del curso en el que está inscrito o un cero si no está inscrito en ninguno. Si el usuario no existe, 
            se imprime un error.
     */
    void escribir_usuario(const string &u) const;

    
private:
    map<string,Usuario> cjtu; //map con nombre de usuario, Usuario
};
#endif
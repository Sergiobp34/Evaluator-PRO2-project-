/** @author Sergio Blanco Palomares
    @mainpage
    Programa de la plataforma EVALUATOR. EVALUATOR es una plataforma para evaluar los conocimientos de 
    programación de un usuario que integra una colección de problemas de programación, un repositorio 
    de sesiones compuestas por problemas de dicha colección, un conjunto de cursos formados por una o 
    mas sesiones, y un conjunto de usuarios registrados.
*/

/** @file program.cc
    @brief Programa principal
*/

#include "Cjt_usuarios.hh"
#include "Cjt_cursos.hh"
#include "Cjt_problemas.hh"
#include "Cjt_sesiones.hh"

int main(){

    int P, Q, N, M;

    cin>>P;
    Cjt_problemas conjP(P);

    cin>>Q;
    Cjt_sesiones conjQ(Q, conjP);

    cin>>N;
    Cjt_cursos conjN(N);

    cin>>M;
    Cjt_usuarios conjM(M);

    string comando;
    cin>>comando;

    while(comando != "fin"){
        
        if(comando == "np" or comando == "nuevo_problema"){
            string s;
            cin>>s;
            cout<<'#'<<comando<<' '<<s<<endl;
            conjP.nuevo_problema(s);
        }

        else if(comando == "ns" or comando == "nueva_sesion"){
            string s;
            cin>>s;
            cout<<'#'<<comando<<' '<<s<<endl;
            conjQ.nueva_sesion(s, conjP);
        }

        else if(comando == "nc" or comando == "nuevo_curso"){
            cout<<'#'<<comando<<endl;
            conjN.nuevo_curso(conjQ);
        }

        else if(comando == "a" or comando == "alta_usuario"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.alta_usuario(u);
        }

        else if(comando == "b" or comando == "baja_usuario"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.baja_usuario(u, conjN);
        }

        else if(comando == "i" or comando == "inscribir_curso"){
            int c;
            string u;
            cin>>u>>c;
            cout<<'#'<<comando<<' '<<u<<' '<<c<<endl;
            conjM.inscribir_curso(u, c, conjN, conjQ);
        }

        else if(comando == "cu" or comando == "curso_usuario"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.curso_usuario(u);
        }

        else if(comando == "sp" or comando == "sesion_problema"){
            string u;
            int c;
            cin>>c>>u;
            cout<<'#'<<comando<<' '<<c<<' '<<u<<endl;
            conjN.sesion_problema(c, u, conjP, conjQ);
        }

        else if(comando == "pr" or comando == "problemas_resueltos"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.problemas_resueltos(u);
        }

        else if(comando == "pe" or comando == "problemas_enviables"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.problemas_enviables(u);
        }

        else if(comando == "e" or comando == "envio"){
            string u, p;
            int r;
            cin>>u>>p>>r;
            cout<<'#'<<comando<<' '<<u<<' '<<p<<' '<<r<<endl;
            conjM.envio(u, p, r, conjQ, conjP, conjN);
        }

        else if(comando == "lp" or comando == "listar_problemas"){
            cout<<'#'<<comando<<endl;
            conjP.listar_problemas();
        }

        else if(comando == "ep" or comando == "escribir_problema"){
            string p;
            cin>>p;
            cout<<'#'<<comando<<' '<<p<<endl;
            conjP.escribir_problema(p);
        }

        else if(comando == "ls" or comando == "listar_sesiones"){
            cout<<'#'<<comando<<endl;
            conjQ.listar_sesiones();
        }

        else if(comando == "es" or comando == "escribir_sesion"){
            string s;
            cin>>s;
            cout<<'#'<<comando<<' '<<s<<endl;
            conjQ.escribir_sesion(s);
        }

        else if(comando == "lc" or comando == "listar_cursos"){
            cout<<'#'<<comando<<endl;
            conjN.listar_cursos();
        }

        else if(comando == "ec" or comando == "escribir_curso"){
            int n;
            cin>>n;
            cout<<'#'<<comando<<' '<<n<<endl;
            conjN.escribir_curso(n);
        }

        else if(comando == "lu" or comando == "listar_usuarios"){
            cout<<'#'<<comando<<endl;
            conjM.listar_usuarios();
        }

        else if(comando == "eu" or comando == "escribir_usuario"){
            string u;
            cin>>u;
            cout<<'#'<<comando<<' '<<u<<endl;
            conjM.escribir_usuario(u);
        }
        
        cin>>comando;
    }
}
OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Cjt_usuarios.o Usuario.o Cjt_cursos.o Curso.o Cjt_sesiones.o Sesion.o Cjt_problemas.o Problema.o
	g++ -o program.exe *.o 

program.o: Cjt_cursos.hh Cjt_problemas.hh Cjt_usuarios.hh Cjt_sesiones.hh
	g++ -c program.cc

Problema.o: Problema.cc Problema.hh
	g++ -c Problema.cc

Cjt_problemas.o: Cjt_problemas.cc Cjt_problemas.hh Problema.hh
	g++ -c Cjt_problemas.cc

Sesion.o: Sesion.cc Sesion.hh Cjt_problemas.hh BinTree.hh
	g++ -c Sesion.cc

Cjt_sesiones.o: Cjt_sesiones.cc Cjt_sesiones.hh Sesion.hh
	g++ -c Cjt_sesiones.cc

Curso.o: Curso.cc Curso.hh Cjt_sesiones.hh
	g++ -c Curso.cc

Cjt_cursos.o: Cjt_cursos.cc Cjt_cursos.hh Curso.hh
	g++ -c Cjt_cursos.cc

Usuario.o: Usuario.cc Usuario.hh Cjt_cursos.hh Cjt_problemas.hh Cjt_sesiones.hh
	g++ -c Usuario.cc  

Cjt_usuarios.o: Cjt_usuarios.cc Cjt_usuarios.hh Usuario.hh
	g++ -c Cjt_usuarios.cc 

clean:
	rm -f *.exe
	rm -f *.o

practica.tar:
	tar -cvf practica.tar program.cc Cjt_usuarios.cc Cjt_usuarios.hh Cjt_cursos.cc Cjt_cursos.hh Cjt_problemas.hh Cjt_problemas.cc Cjt_sesiones.hh Cjt_sesiones.cc Usuario.hh Usuario.cc Curso.hh Curso.cc Sesion.hh Sesion.cc Problema.hh Problema.cc BinTree.hh Makefile

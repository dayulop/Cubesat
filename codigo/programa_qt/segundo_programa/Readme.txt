Para utilizar la DLL de QCustomPlot se debe, crear un archivo .txt con el siguiente nombre "Local_config.txt".
Una vez hecho eso:
1) Dentro del archivo escribir la ubicacion de la dll y luego la ubicacion de la carpeta que contiene
el archivo ".h" de la siguiente manera:

		LIBS += -L"C:/Users/TuNombre/Desktop/milibreria/lib" -lmilibreria
		INCLUDEPATH += "C:/Users/TuNombre/Desktop/milibreria/include"

2) Guardar el .txt, modificar el tipo de archivo de ".txt" a ".pri", este deberia quedar de la siguiente manera: 
"Local_config.pri"

IMPORTANTE: al realizar un commit en git hub incluir el archivo "Local_config.pri" en .gitignore evitando publicar la 
direccion de la carpeta de su pc.

3) en el archivo ".pro" de su proyecto de QT debe de agregar la siguiente linea "include(local_config.pri)" luego compilar
y verificar que no existan errores. 
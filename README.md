La carpera Original contiene los archivos fuentes originales y la carpeta resolution contiene la resolución de los ejercicios propuestos.
autor: Juan Camilo Rada

1. helloword.c

    - Interacción 1. Se ejecutan 4 hilos que escriben en consola
        - hello (2) world (2)
        - hello (3) world (3)
        - hello (1) world (1)
        - hello (0) world (0)

    - Interacción 2. Se ejecutan 5 hilos que escriben en consola
        - hello (4) world (4)
        - hello (0) world (0)
        - hello (1) world (1)
        - hello (3) world (3)
        - hello (2) world (2)
    
2. Pi. Para la ejecución se utilizo la setencia  #pragma omp parallel que permite la ejecución paralela de ciclos. Declarando la variable x como privada para cada hilo. 
3. Montecarlo. Para la ejecución se utilizo la setencia  #pragma omp parallel que permite la ejecución paralela de ciclos. Declarando la variable x, y y test como privada para cada hilo.
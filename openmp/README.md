La carpera Original contiene los archivos fuentes originales y la carpeta resolution contiene la resolución de los ejercicios propuestos.

autores: Juan Camilo Rada - Federico Lopez

1. helloword.c

    - Interacción 1. ¿Cuántos hilos se ejecutan? R/ Se ejecutan 4 hilos que escriben en consola
        - hello (2) world (2)
        - hello (3) world (3)
        - hello (1) world (1)
        - hello (0) world (0)

    - Interacción 2. ¿Cuántos hilos se ejecutan? ¿Difiere el número de hilos con relación al anterior? ¿Por qué? R/ Se ejecutan 5 hilos. Sí difiere con relación al anterior ya que en la interacción anterior no se definía de forma explícita el número de hilos necesarios para correr el segmento paralelizado del programa. Los 5 hilos ejecutado escriben en pantalla:
        - hello (4) world (4)
        - hello (0) world (0)
        - hello (1) world (1)
        - hello (3) world (3)
        - hello (2) world (2)
    
2. Pi. Para la ejecución se utilizo la setencia  #pragma omp parallel que permite la ejecución paralela de ciclos. Declarando la variable x como privada para cada hilo. 
3. Montecarlo. Para la ejecución se utilizo la setencia  #pragma omp parallel que permite la ejecución paralela de ciclos. Declarando la variable x, y y test como privada para cada hilo.

- En este ejercicio particular fue necesario generar semillas iniciales para cada hilo, de este modo se garantiza que cada hilo comience una secuencia aleatoria que de cierto modo es compartida por los demás hilos y de este modo se asegura que el resultado será el mismo para una misma cantidad de iteraciones sin importar el número de hilos. Este método de generación de múltiples semillas pseudo-aleatorias que pertenecen a una misma serie se llama Leap Frog y es uno de varios métodos usados en la generación paralela de números pseudo-aleatorios. Para la generación de semillas iniciales se utilizo la anotiación #pragma omp single que hace que una instrucción sea ejecutada por un único hilo y además bloquea la ejecución de los demás hilos hasta que el bloque anotado con la directiva single sea ejecutado. El programa basicamente genera una cantidad de semillas correspondientes al número de hilos y los almacena en un array que después es leído por cada hilo para asignar en una variable privada la semilla pseudo-aleatoria correspondiente.


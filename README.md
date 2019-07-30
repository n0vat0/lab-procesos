# PRÁCTICA 1 - PROCESOS #

## 1. Objetivos ##
1. Familiarizarse con las diferentes estructuras y funciones relacionadas con el manejo de procesos en linux.
2. Codificar programas que hagan uso del API de procesos.

## 2. Actividades previas al laboratorio ##

Asignadas en la práctica anterior.
Leer el capítulo 5 del libro guía y comprender las diapositivas de clase asociadas a este capitulo.

## 3. Actividades en el laboratorio ##

Realizar los siguientes ejercicios:

1. Escriba un programa que llame un ```fork()```. Antes del llamado del ```fork()```, declare una variable de acceso (por ejemplo, ```x```) y asígnele un valor (por ejemplo, ```100```). Responda las siguientes preguntas:
  * ¿Cuál es el valor de la variable en el proceso hijo?
  El mismo que en el proceso padre
  * ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de ```x```?
  La variable toma el valor dado en cada uno de los procesos.
2. Escriba un programa que abra un archivo (con la llamada ```open()```) y entonces llame a ```fork()```. **Nota**: El siguiente [enlace](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/) puede ser de utilidad para entender la llamada ```open()```.
  * ¿Pueden el padre y el hijo acceder al file descriptor retornado por ```open()```? 
  Si, por que la llamada se realiza antes del fork y queda disponible en ambos contextos.
  * ¿Qué pasa si ellos empiezan a escribir el archivo de manera concurrente, es decir, a la misma vez?
  Los dos escriben en el archivo correctamente, pero no sabemos en que orden de prioridad quedan los procesos de acuerdo al 
  scheduler.
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? Si es posible para este programa en particular, usando sleep() para cambiar prioridad en el scheduler, pero no podemos garantizarlos para programas más complejos.
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica? Encontramos la siguiente informaci'on que explica el porqué de las diferentes funciones:
Las llamadas con v en el nombre toman un parámetro de matriz para especificar la matriz argv [] del nuevo programa.

Las llamadas con l en el nombre toman los argumentos del nuevo programa como una lista de argumentos de longitud variable para la función en sí.

Las llamadas con e en el nombre toman un argumento adicional para proporcionar el entorno del nuevo programa; de lo contrario, el programa hereda el entorno del proceso actual. [https://stackoverflow.com/questions/20823371/what-is-the-difference-between-the-functions-of-the-exec-family-of-system-calls]

Las llamadas con p en el nombre buscan la variable de entorno PATH para encontrar el programa si no tiene un directorio (es decir, no contiene un carácter /). De lo contrario, el nombre del programa siempre se trata como una ruta al ejecutable.
3. Escriba un programa usando ```fork()```. El proceso hijo imprimirá ```"Hello"```; el proceso padre imprimirá ```"goodbye"```. Usted deberá asegurar que el proceso hijo imprima en primer lugar; ¿usted podría hacer esto sin llamar ```wait()``` en el padre? 
4. Escriba un programa que llame ```fork()``` y entonces llame alguna forma de ```exec()``` para correr el programa ```/bin/ls```. Intente probar todas las variaciones de la familia de funciones ```exec()``` incluyendo (en linux) ```execl()```, ```execle()```, ```execlp()```, ```execv()```, ```execvp()``` y ```execvpe()```. ¿Por qué piensa usted que existen tantas variaciones para la misma llamada básica?
5. Escriba ahora un programa que use ```wait()``` para esperar que el proceso hijo finalice su ejecución. ¿Cuál es el valor de retorno de la función ```wait()```?, ¿Qué pasa si usted usa la función ```wait``` en el hijo?
6. Haga un programa, como el del ejercicio anterior, con una breve modificación, la cual consiste en usar ```waitpid()``` en lugar de ```wait()```. ¿Cuándo podría ser ```waitpid()``` útil?
7. Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (```STDOUT FILENO```). ¿Qué pasa si el hijo llama ```printf()``` para imprimir alguna salida después de cerrar el descriptor?

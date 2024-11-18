# Systems Engineering

Siempre he creído que las personas autodidactas son las que cambian el mundo, porque tienen la capacidad de tomar sus propias observaciones de su aprendizaje. Por eso, he decidido compartir todos mis recursos, para que quienes quieran aprender puedan acceder a ellos y estudiarlos libremente. En este repositorio encontrarás todo lo que estoy utilizando para formarme como Ingeniero de Software. Actualmente estoy en tercer año, por lo que la lista irá creciendo a medida que avance en mi carrera y complete nuevas materias.

Aunque es posible que no necesites profundizar tanto como yo en las materias básicas, considero que son fundamentales. Aunque a veces se subestiman, son la base sólida sobre la cual se construye cualquier tecnología que usamos hoy en día. Por eso, creo que tener acceso a estos materiales puede marcar una gran diferencia en tu aprendizaje. De todos modos, todo lo que necesitas, está aquí.

¡Mucha suerte!

---

<h2>Cómo Funciona</h2>
<p>
Voy a ir dejando los recursos sobre cada año en el que fui cursando. Además, voy a dejar un espacio adicional donde, en cada materia, iré subiendo cosas que fui aprendiendo por mi cuenta. Si querés dejar algún recurso en este repositorio, podés hacer un fork.
</p>

---

<h2>Primer Año</h2>
<ul>
  <li><a href="#algoritmos-y-estructura-de-datos">Algoritmos y estructura de datos</a></li>
  <li><a href="#arquitectura-de-computadoras">Arquitectura de Computadoras</a></li>
  <li><a href="#algebra-y-geometria-analitica">Álgebra y Geometría Analítica</a></li>
  <li><a href="#fisica-1">Física 1</a></li>
  <li><a href="#analisis-matematico-1">Análisis Matemático 1</a></li>
  <li><a href="#logica-y-estructuras-discretas">Lógica y Estructuras Discretas</a></li>
  <li><a href="#sistemas-y-procesos-de-negocio">Sistemas y Procesos de Negocio</a></li>
</ul>

---

<h2>Segundo Año</h2>
<ul>
  <li><a href="#sintaxis-y-semantica">Sintaxis y Semántica de los Lenguajes</a></li>
  <li><a href="#">Paradigmas de la Programación</a></li>
  <li><a href="#">Física 2</a></li>
  <li><a href="#">Análisis Matemático 2</a></li>
  <li><a href="#">Sistemas Operativos</a></li>
  <li><a href="#">Análisis de Sistemas de Información</a></li>
  <li><a href="#">Ingeniería y Sociedad</a></li>
</ul>

---

<h2>Tercer Año</h2>
<p>En progreso...</p>

---

<a name="algoritmos-y-estructura-de-datos"></a>
<h2>Algoritmos y Estructura de Datos</h2>
<details>
  <summary><strong>Teoría</strong></summary>
  <br>
  <details>
  <summary><strong>1. Uso de Variables y Operaciones</strong></summary>
  <h4>Objetivo</h4>
  <p> 
    El propósito es que los estudiantes desarrollen sus primeros pseudocódigos comprendiendo los conceptos de secuencia y variable. Se destaca la importancia del tipo de datos como un determinante en los valores y operaciones aplicables en pseudocódigo para manejar variables.
  </p>
  <p>
    Para crear un programa, primero se debe analizar el problema. En problemas grandes, el proceso sigue un diseño descendente, refinándose hasta construir el algoritmo en pseudocódigo. Luego, una vez verificado el algoritmo, se podría codificar en un lenguaje específico como Pascal.
  </p>
  <p>
    <strong>Nota:</strong> A lo largo del curso se evita enseñar un lenguaje específico, enfocándose en la descripción de soluciones que puedan ser codificadas en cualquier lenguaje de programación.
  </p>
  
  <h4>Definición de Variables y Operaciones</h4>
  <p>
    <strong>Variables:</strong> Son espacios de almacenamiento en los que se guardan datos (en espacio de memoria) que pueden cambiar durante la ejecución de un programa. Cada variable tiene un nombre (identificador), un tipo de dato (como entero, cadena o booleano) y un valor asignado.
  </p>
  <p>
    <strong>Operaciones:</strong>
    <ul>
      <li><strong>Aritméticas:</strong> Suma (+), resta (-), multiplicación (*), división (/).</li>
      <li><strong>Lógicas:</strong> AND, OR, NOT, utilizadas para evaluar condiciones.</li>
      <li><strong>Asignación:</strong> Asignar un valor a una variable (por ejemplo, <code>x = 5</code>).</li>
      <li><strong>Relacionales:</strong> Mayor que (>), menor que (<), igual a (==), utilizadas para comparar valores.</li>
    </ul>
  </p>
  
  <h4>Ejemplos</h4>
  <p><strong>Primer intento: A grandes rasgos</strong></p>
  <pre>
Inicio
  Obtener un número entero
  Obtener otro número entero
  Calcular la suma de los números obtenidos
  Imprimir dicha suma
Fin
  </pre>
  <p><strong>Segundo intento: Detallado</strong></p>
  <pre>
Inicio
  Leer A // obtener el primer número
  Leer B // obtener el otro
  Calcular la suma de A y B y guardarla en C
  Imprimir C
Fin
</pre>
<b>Programa En Pseudocódigo:</b> 
El programa que se implementa a continuación tiene una típica estructura secuencial, es decir que consta de instrucciones que se van ejecutando una a continuación de la otra, en el orden en que fueron escritas de arriba hacia abajo. Debe notarse que las instrucciones utilizadas no alteran esa secuencia, como sucederá en las siguientes prácticas al introducir condiciones que expresen ejecuciones alternativas o ciclos repetitivos.
Además, en este código se introducen algunas cuestiones de estilo que tienen que ver con una buena práctica en la codificación de programas y que se consideran importantes a la hora de integrar equipos de trabajo. Por ello la secuencia de comentarios al comienzo y antes de cada tramo importante del programa, así como los carteles que se muestran al usuario y el manejo de los espacios en blanco para alinear las instrucciones (este manejo suele llamarse indentación).

<pre>
  Programa Sumas // Este es el primer programa en PSEUDOCODIGO
 // Programa escrito por: Gustavo
 // Fecha: 11 de Abril del 2020
 // Versión: 04
 // Nombre del archivo: Sumas
 // Este programa permite sumar dos números enteros
   Variables // definición de las variables
   A, B, C: Entero 5
   Hacer // Comienzo del programa
     // Ingreso de datos
     Imprimir: 'Ingrese el primer valor: '
     Leer: A
     Imprimir: 'Ingrese el segundo valor: '
     Leer: B
     // Cálculo de los resultados
     C:= A+B
     // Salida de la información
     Imprimir: 'La suma de los dos valores dados es: ', C
     (* Fin del programa *)
   Fin Hacer
 Fin Programa Sumas
</pre>

![image](https://github.com/user-attachments/assets/2c4cc4b2-9fde-47ca-b4ba-0a872bdabcb9)
![image](https://github.com/user-attachments/assets/da65ed4d-54c4-4992-baf1-f03e7b028597)
![image](https://github.com/user-attachments/assets/aea55f9b-2373-49a5-9e42-9d2ee60eda94)
![image](https://github.com/user-attachments/assets/220be88d-a451-4343-998e-ccd5e7aaf6df)
<details>
  <summary><strong><b>Introduccion a C</b></strong></summary>
  
  ![image](https://github.com/user-attachments/assets/173bb3d5-5cd3-4679-9d3e-00478f42adc4)
  ![image](https://github.com/user-attachments/assets/e6d9ae0a-ed26-44fe-86d5-9aff0add8a37)
  ![image](https://github.com/user-attachments/assets/d1a35abb-3e54-4a18-b86b-ec979435cd2f)

</details>
</details>

<details>
  <summary><strong>2. Estructura de control de decisión</strong></summary>
  <h4>Objetivo</h4>
  <p>
     Que los estudiantes puedan tomar decisiones en los pseudocódigos que construyen para la resolución de problemas. </p>
  <p>
     La primera fase de la resolución de un Problema con Pseudocódigo es el Análisis del Problema. Esta fase requiere comprender con claridad el problema, de modo que permita dar una clara definición de todos los aspectos involucrados para de ese modo llegar a una solución. </p>
  <p>  
    A continuación deben estudiarse las características de esa solución a fin de encontrar la mejor manera de llevarla adelante. De eso se encarga la fase del Diseño, cuyo producto final es el Pseudocódigo. Para obtenerlo, también se precisan especificaciones detalladas de las Entradas y Salidas. Así, las tareas a realizar pueden resumirse en:
</p>
  ![ayed1](https://github.com/user-attachments/assets/f9a6b20f-7c5b-422f-9794-69ba1a8a0512)
 <p> En problemas de pequeña o mediana envergadura, lo anterior puede llevarse a cabo respondiendo a las siguientes preguntas: </p>
 <p>¿Qué Entradas se requieren? (Tipo y Cantidad)</p>
 <p>¿Cuál es la Salida deseada? (Tipo y Cantidad)</p>
 <p>¿Qué debe hacerse para lograr la Salida deseada a partir de los datos disponibles?</p>
 <p>Ejemplo:</p>
 <p>Determinar si la suma de cualquier pareja de tres números dados es igual al tercero. Si se cumple esta condición, escribir “Iguales” y, caso contrario, escribir “Distintos”. Análisis del Problema: </p>
 <p><b>¿Qué Entradas se requieren? (Tipo y Cantidad)</b> Tres números Reales </p>
 <p><b>¿Cuál es la Salida deseada? (Tipo y Cantidad)</b> Un mensaje</p>
 <b>¿Qué método produce la Salida deseada?</b> La comparación de las suma de las parejas de números con el número que queda</p>
 <p><b>Primer intento: a grandes rasgos</b></p>
  <pre>
    Obtener tres números reales
    Calcular las sumas dos en dos de los números obtenidos
    Si alguna de ellas es igual al tercer número, mostrar el cartel “Iguales” y terminar; de lo contrario, mostrar
    Si cartel “Distintos” y terminar.
 Fin
  </pre>
 <p><b>Segundo intento: buscando los detalles</b></p>
  <pre>
Inicio
 // Obtener los tres números reales
   Leer A
   Leer B
   Leer C
 // Calcular cada suma y compararla con el tercer número
   Si A+B = C
     Imprimir “Iguales”
   Terminar
   Si A+C = B
     Imprimir “Iguales”
   Terminar
   Si B+C = A
     Imprimir “Iguales”
   Terminar
   Imprimir “Distintas “
   // Terminar
  </pre>

  <p><b>Tercer intento</b></p>
  <pre>
Programa Pares
 // Programa escrito por: XXXX
 // Fecha: 26 de Abril de 2009
 // Versión: 05
 // Nombre del archivo: Pares
 // Este programa suma tres números de a pares y compara con el número restante.
 // Se utilizan SI anidados.
   Variables
   A, B, C: Real 5,2
   Hacer // Comienzo del programa
   // Ingreso de datos
    Imprimir: 'Ingrese el primer valor: '
    Leer: A
    Imprimir: 'Ingrese el segundo valor: '
    Leer: B
    Imprimir: 'Ingrese el tercer valor: '
    Leer: C
 // Se aplican SI anidados para comparar
   SI (A+B)=C ENTONCES
     Imprimir: ‘ Son Iguales....! ‘
   SINO
     SI (A+C)=B ENTONCES
     Imprimir: ‘ Son Iguales....! ‘
   SINO
     SI (B+C)=A ENTONCES
     Imprimir: ‘ Son Iguales....! ‘
   SINO
     Imprimir: ‘ Son Distintos...! ‘
   FIN SI
 FIN SI
 FIN SI
 Fin Hacer
 Fin Programa Pares
  </pre>

</details>

<details>
  <summary><strong>3. Estructuras de Control de Repetición Incondicional (fija) y Repetición Condicional</strong></summary>
  <h4>Objetivo</h4>
  <p> Utilizar la Repetición Incondicional y Condicional en la resolución de problemas con Pseudocódigo.</p>

Las **estructuras de control de repetición** permiten ejecutar un conjunto de instrucciones varias veces, ya sea con un número predefinido de iteraciones o dependiendo de una condición lógica.

---

## **1. Estructuras de Control de Repetición**

Las estructuras de repetición son fundamentales en programación, ya que nos permiten realizar tareas repetitivas de manera eficiente. Pueden dividirse en:

1. **Repetición Incondicional (Fija)**: El número de iteraciones es fijo y se conoce antes de ejecutar el ciclo.
2. **Repetición Condicional**: El número de iteraciones depende de una condición que se evalúa durante la ejecución.

---

### **A. Repetición Incondicional (Fija)**

La repetición fija o incondicional ejecuta un bloque de instrucciones un número específico y conocido de veces antes de iniciar la ejecución.

#### **Características:**
- El número de iteraciones se define de antemano.
- No depende de condiciones variables durante la ejecución.
- Se utiliza en tareas donde el número de repeticiones es fijo.

#### **Estructuras Comunes:**
- **For**: Muy usado en lenguajes como Python, C, Java, entre otros.
- **Repeat...Until**: Disponible en algunos lenguajes.

  <b>Ejemplo, Con Repetición Incondicional (Fija):</b>
  <p>Se desea visualizar la Tabla de Multiplicación de un número dado por los números del 1 al 20. La Tabla debe visualizarse con el siguiente formato, por ejemplo: ' 2 x 3 = 6'.</p>
  <p><b>¿Qué Entradas se requieren? (Tipo y Cantidad)</b> Un número entero</p>
  <p><b>¿Cuál es la Salida deseada? (Tipo y Cantidad)</b> La Tabla en el formato pedido</p>
  <b>¿Qué método produce la Salida deseada?</b> Multiplicar el número entero dado con cada Número entre 1 y 20.</p>

  <b>Primer intento: a grandes rasgos</b>
  <pre>
  inicio
    Leer el número entero Num
    Repetir 20 veces
    // Calculo de la Multiplicación
    Imprimo los números a multiplicar en el formato pedido
    // El índice es el contador de iteraciones
    Realizo la multiplicación entre el Num y el Índice
    Imprimo resultado
  Fin
  </pre>

  <b>Segundo intento:</b>
  <pre>
  // Programa escrito por: XXXX
  // Fecha: 30 de Mayo de 2011
  // Versión: 1.1
  // Nombre del archivo: Tablas_de_Multiplicar
  // Este programa multiplica un numero por índice que se incrementa 20 veces de a uno
  Variables // definición de las variables
  Num, Indice: Entero 2
  Tabla: Entero 4
  Hacer // Comienzo del programa //
  // Ingreso de datos
  Imprimir: 'Ingrese un Número para Generar su Tabla de Multiplicar: '
  Leer: Num
  // Inicio la Generación de la Tabla de Multiplicar
  Imprimir: ' Tabla del ‘, Num
  REPETIR PARA Índice:= 1, 20, 1
  Tabla:= Num * Indice // calculo el valor del resultado
  // Imprimo en el formato pedido
  Imprimir: Num , ' x ' , Indice , ' = ' , Tabla
  FIN REPETIR PARA
  Fin Hacer
  Fin Programa Tablas_de_Multiplicar
  </pre>

  ![image](https://github.com/user-attachments/assets/b258200b-251b-403b-9fad-4086f4bde6d5)

</details>

<details>
  <summary><strong>4. Funciones y Procedimientos</strong></summary>
  <h4>Objetivo</h4>
  <p>Utilizar en los pseudocódigos las herramientas de modularización de programas y comunicación entre módulos</p>
  
---

<p>Hemos visto que al construir programas resulta muy útil pensar que el problema puede descomponerse en subproblemas a partir de cuyas soluciones se obtiene una solución al problema original. Hasta ahora, eso nos sirvió para darle forma al código de nuestros programas en segmentos que podían ser bien diferenciados (usando comentarios). Sin embargo, en ocasiones estos segmentos pueden ser un poco largos y llevar a que al ver el programa en su conjunto, se pierda de vista la distinción y el código se vuelve confuso. Esto se nota particularmente bien en programas de mediana o gran envergadura, aunque puede ocurrir también en algunos más pequeños. Así, los procedimientos y funciones (en general subprogramas) vienen a ayudarnos a organizar la programación, pues nos permiten que esos segmentos de código que podían resultar confusos se codifican por separado con algunas ventajas adicionales: </p>

- se les asocia un nombre, por lo que si el segmento de código debía repetirse en diferentes partes del programa, ahora puede reemplazarse todo el segmento por su nombre en cada uno de los lugares donde antes se repetía el segmento completo, permitiendo además que el código termine siendo más breve y por tanto más ágil para la lectura; en el lugar donde está el nombre del subprograma se dice que hay una invocación al mismo;

- en ocasiones, las repeticiones no eran totalmente idénticas, sino que había ciertos datos que cambiaban de una a otra: a los subprogramas se les pueden asociar parámetros, es decir datos que pueden cambiar de valor de una invocación a otra; los valores que se asocian con los parámetros en cada invocación del subprograma suelen conocerse como argumentos, y la correspondencia se da por cantidad y posición: el primer argumento que se indica en la invocación corresponde al valor que se asigna al primer parámetro del procedimiento, el segundo argumento corresponde al valor asignado al segundo parámetros, y así hasta el último, por lo que debe haber tantos argumentos en la invocación como parámetros se definieron en la declaración del subprograma.

<p>La introducción de subprogramas en la codificación de los programas lleva a introducir algunos conceptos relacionados con el uso de variables: los subprogramas tienen la misma estructura interna que un programa completo, de modo que pueden declararse variables que ayuden a lograr lo que se pretende pero que solo sirven para ese subprograma: son variables locales al subprograma, y tienen la característica fundamental de que los valores que tomen sólo se conocen dentro del subprograma. Por su parte, las que se declaran a nivel del programa principal (el único que codificábamos hasta ahora, son globales para los subprogramas: cualquier subprograma puede hacer uso de ellas y cualquier cambio que un subprograma (o el principal) haga a una de ellas, afectará al resto de los subprogramas que la utilicen o al mismo programa principal en cualquier ejecución posterior al cambio.</p>

<b>El subprograma (o el programa principal) que hace una invocación a otro subprograma se conoce como el llamador.</b>

<p>Los parámetros de un subprograma pueden ser de dos clases, por ahora: por valor o por referencia. Los parámetros por valor son variables locales al procedimiento cuyo valor se asigna en la invocación, y por ser variables locales su cambio no se nota fuera del subprograma. Los parámetros por valor constituyen datos de entrada para el subprograma y los argumentos correspondientes pueden estar dados como constantes o variables. En cambio, los parámetros por referencia sólo pueden estar asociados con argumentos variables, pues cualquier alteración de los mismos en el subprograma afectará el valor asociado a la variable argumento del llamador; la principal utilidad de estos parámetros es la de poder hacer referencia a dichos valores con un nombre que resulta significativo dentro del subprograma,independientemente de cómo se lo conozca en el resto. Los parámetros por referencia, pueden ser de entrada o de salida para el subprograma.</p>

<p>Como se dijo, hay dos clases de subprogramas: los procedimientos y las funciones:</p>

- Las funciones sólo admiten parámetros por valor y siempre tienen un valor asociado (el resultado), pues están pensadas para ser utilizadas como parte de una expresión (igual que las funciones primitivas). Así, solo pueden devolver valores de tipos simples, como los que hemos utilizado hasta ahora.

- Los procedimientos admiten parámetros de ambas clases, por lo que podrían tene varias salidas. No pueden formar parte de expresiones, su invocación se realiza como si fuesen una instrucción más en el lenguaje.

<p>En ocasiones, hay un grupo de subprogramas que pueden considerarse relacionados entre sí por algún criterio, pudiendo eventualmente compartir algunos datos (o no). Dichos subprogramas forman un módulo y aparecen con frecuencia al resolver problemas de mediana o gran envergadura.</p>

<b>Características:</b>
- Tienen un **nombre** que las identifica.
- Pueden aceptar **parámetros** (datos de entrada).
- Siempre **devuelven un valor**.
- Facilitan la reutilización del código.

<b>Estructura General de una Función:</b>
```
def nombre_funcion(parámetros):
    # Código que realiza la tarea
    return valor
```

<b>Diferencias entre Funciones y Procedimientos</b>

| **Aspecto**             | **Función**                              | **Procedimiento**                        |
|-------------------------|------------------------------------------|------------------------------------------|
| **Devuelve un valor**    | Sí, siempre devuelve un valor mediante `return`. | No devuelve un valor directamente.       |
| **Propósito principal**  | Calcular y devolver un resultado.        | Ejecutar una acción o tarea específica.  |
| **Estructura típica**    | Incluye la instrucción `return`.         | No incluye la instrucción `return`.      |
| **Uso común**            | Cálculos matemáticos, procesamiento de datos. | Mostrar mensajes, modificar variables globales. |
| **Parámetros**           | Puede recibir parámetros opcionales o requeridos. | Puede recibir parámetros opcionales o requeridos. |
| **Estado de salida**     | Finaliza cuando devuelve un valor.       | Finaliza después de ejecutar todas sus instrucciones. |
| **Interacción externa**  | Generalmente no modifica variables globales. | Puede modificar variables globales.     |

</details>
<p>Ejercicios sugeridos para trabajar en clase en el material teorico.</p>
<p><b>Material Teórico: <a href="https://modsfire.com/c18PhtG354235T8" target="_blank">Descargar</a></b></p>



</details>
<a name="algebra-y-geometria-analitica"></a>
<h2>Álgebra y Geometría Analítica</h2>
<p>Contenido en desarrollo...</p>

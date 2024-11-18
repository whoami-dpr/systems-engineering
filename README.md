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
  <p>Material Teórico: <a href="https://modsfire.com/c18PhtG354235T8" target="_blank">Descargar</a></p>

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
<p>Ejercicios sugeridos para trabajar en clase en el material teorico.</p>
</details>
<a name="algebra-y-geometria-analitica"></a>
<h2>Álgebra y Geometría Analítica</h2>
<p>Contenido en desarrollo...</p>

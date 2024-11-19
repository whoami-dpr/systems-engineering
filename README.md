# Ingenieria en Sistemas

Siempre he creído que las personas autodidactas son las que cambian el mundo, porque tienen la capacidad de tomar sus propias observaciones de su aprendizaje. Por eso, he decidido compartir todos mis recursos, para que quienes quieran aprender puedan acceder a ellos y estudiarlos libremente. En este repositorio encontrarás todo lo que estoy utilizando para formarme como Ingeniero en Sistemas. Actualmente estoy en tercer año, por lo que la lista irá creciendo a medida que avance en mi carrera y complete nuevas materias.

Aunque es posible que no necesites profundizar tanto como yo en las materias básicas, considero que son fundamentales. Aunque a veces se subestiman, son la base sólida sobre la cual se construye cualquier tecnología que usamos hoy en día. Por eso, creo que tener acceso a estos materiales puede marcar una gran diferencia en tu aprendizaje. De todos modos, todo lo que necesitas, está aquí.

¡Mucha suerte!

---

<h2>Cómo Funciona</h2>
<p>
Voy a ir dejando los recursos sobre cada año en el que fui cursando. Además, voy a dejar un espacio adicional donde, en cada materia, iré subiendo cosas que fui aprendiendo por mi cuenta. Es de esperar que no tenga todo el contenido que exista, por lo que si quieres colaborar de alguna forma puedes hacer un pull request.
</p>

<h2>Creditos</h2>
<p>
Todos los creditos van para todas las personas que ayudaron, colaboraron e hicieron que este repositorio tenga los contenidos que tiene.
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
  <li><a href="#sistemas-operativos">Sistemas Operativos</a></li>
  <li><a href="#">Análisis de Sistemas de Información</a></li>
  <li><a href="#">Ingeniería y Sociedad</a></li>
</ul>

---

<h2>Tercer Año</h2>
<p>En progreso...</p>

---

<a name="algoritmos-y-estructura-de-datos"></a>
# Algoritmos y Estructura de Datos
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

<details>

<summary>Programación modular</summary>
La usamos para resolver el problema en pequeños subproblemas, un proyecto de algoritmos normalmente se compone de un programa principal y de un conjunto de subprogramas que se invocan o llaman desde el principal.

Utilizamos la estrategia antes mencionada de top-down, diseño descendente o modular, divide y venceras. El proceso de subdividir se llama refinamiento sucesivo.

Los subprogramas son unidades de programa que hacen una tarea especifica. Pueden ser procedimientos o funciones

- Procedimiento: subprograma que puede recibir cero o mas valores desde la unidad que lo llama y lo activa, y devolver cero o mas valores a dicha unidad llamadora. Admiten parametros de ambas clases por lo que pueden tener varias salidas. No pueden formar parte de una expresion, se las invoca como una instruccion del programa principal.
- Funcion: es un subprograma que recibe cero o mas valores pero siempre devuelve un solo resultado y de tipo estandar: entero, real, caracter o booleano, en su nombre. Solo admiten parametros por valor y siempre tiene un valor asociado (el resultado) porque estan pensadas para usarse en una expresion.
- Parametros: es el conjunto de datos que se envia como comunicacion entre las unidades de programa.

Para que un programa pueda utilizar un subprograma este tiene que estar declarado y definido dentro del mismo. Para declarar un subprograma se debe especificar el tipo (funcion o proocedimiento), su nombre y la lista de parametros (si corresponde)

Para su invocacion, los procedimientos se invocan a traves de su nombre acompañado, si corresponde, de la lista de parametros actuales. Las funciones se invocan a traves de su nombre, acompañado o no de la lista de parametros actuales, segun corresponda, pero SOLO se invocan dentro de otra expresion aritmetico-logica o de una impresion.

<details>

<summary>Procedimientos</summary>

![image](https://github.com/user-attachments/assets/508855a8-7f52-426d-9d78-1616a105b97f)
![image](https://github.com/user-attachments/assets/f6f40de1-019e-4195-9bbc-1888201119a9)

</details>

<details>

<summary>Funciones</summary>

![image](https://github.com/user-attachments/assets/22f9a449-f13e-4b2c-a5dc-93ff956abcd6)
![image](https://github.com/user-attachments/assets/1054b17b-2e4f-475b-a15e-63c1422897fc)
![image](https://github.com/user-attachments/assets/00984225-b214-4a54-97bb-f97079edc7dd)

</details>

<details>

<summary>Representación grafica</summary>

![image](https://github.com/user-attachments/assets/65de740e-4db3-4efa-98a8-f4d854f6d3f1)
![image](https://github.com/user-attachments/assets/2adbecf1-c2a0-41d3-8c7b-ec5f41ef0433)
![image](https://github.com/user-attachments/assets/5984ecc1-a016-41df-b758-68413285fe46)
![image](https://github.com/user-attachments/assets/530a54c3-6d18-4e3c-9e0d-6ef5ec325d54)
![image](https://github.com/user-attachments/assets/ca151f52-8e8f-4842-a94b-d5fe3ac67eb3)

</details>
</details>
</details>

<details>

<summary><strong>5. Tipos de datos definidos por el usuario</strong></summary>
</br>
Los datos que no puedan representarse mediante un tipo estándar se definirán utilizando tipos de datos personalizados. Para crearlos, es necesario especificar su nombre y estructura. Estos datos se declaran en una sección específica llamada tipos estructurados.

El nombre de un tipo personalizado debe ser único y no coincidir con los tipos predefinidos del lenguaje. Su definición se basa en la combinación de tipos estándar y/o otros tipos definidos previamente por el usuario.

Tipos de datos estándar o simples: permiten definir variables individuales con valores únicos.
Tipos de datos definidos por el usuario: posibilitan la creación de variables compuestas que agrupan valores relacionados de manera lógica bajo un mismo identificador.
Al resolver un problema, es crucial identificar el conjunto de datos que forman parte de su universo. Los datos básicos extraídos del problema, junto con aquellos deducidos de su análisis, se conectan de forma lógica para definir diversas estructuras de datos.

Estructura de datos: un esquema o mecanismo para organizar y almacenar datos.
Estas estructuras pueden clasificarse según:
Cantidad de datos que gestionan: simples o compuestos.
Tipo de datos: homogéneos o heterogéneos.
Tiempo en memoria: temporales o permanentes.
Modo de asignación de memoria: estáticas o dinámicas.
Ubicación de almacenamiento: internas (RAM) o externas (almacenamiento secundario).

<details>
  
<summary>Estructuras de datos compuestas</summary>

- Una estructura de datos compuesta es un grupo de datos agrupados bajo un único nombre, organizados de manera específica y con un conjunto definido de operaciones permitidas.
- Para su análisis, se clasifican en homogéneas y heterogéneas:
  - Homogéneas: contienen únicamente datos de un mismo tipo (por ejemplo, todos los elementos del conjunto son números reales o enteros).
  - Heterogéneas: permiten combinar datos de diferentes tipos en un mismo conjunto.

</details>
</details>
<details>
  <summary><strong>6. Estructuras homogéneas - Arreglos</strong></summary>

</details>

</details>
<p>Ejercicios sugeridos para trabajar en clase en el material teorico.</p>
<p><b>Material Teórico: <a href="https://modsfire.com/c18PhtG354235T8" target="_blank">Descargar</a></b></p>
</details>

<a name="algebra-y-geometria-analitica"></a>
# Álgebra y Geometría Analítica
<p>Contenido en desarrollo...</p>

<a name="sistemas-operativos"></a>
# Sistemas Operativos

<details>
  <summary><b>Teoría</b></summary>
</br>
  <details>
    <summary><b>Módulo 1</b></summary>
    </br>
    <details>
      <summary><b>Clase 1 (Software libre, licencias y distribuciones)</b></summary>
      <br>
      <p>¿Que significa <b>Software Libre</b>?</p>
      
  ![image](https://github.com/user-attachments/assets/01f884e3-7118-46e5-9210-00bac40cff41)
  ![image](https://github.com/user-attachments/assets/ca083ff2-bfcf-4ed6-a27d-fb7bb4d8d34f)
  ![image](https://github.com/user-attachments/assets/996d7195-f41b-45f6-8aad-979295d150fa)
  ![image](https://github.com/user-attachments/assets/6f12f294-d87d-4985-bd78-8c996b1fb517)
  ![image](https://github.com/user-attachments/assets/54ab721d-19cd-4b69-8bac-9dcdc0ee4c67)
  ![image](https://github.com/user-attachments/assets/f5822d94-c8e3-4c09-b502-11389b792e42)
  ![image](https://github.com/user-attachments/assets/bb0dd18f-8d03-4271-957b-e47b9697b73d)
  ![image](https://github.com/user-attachments/assets/350d7f87-4fda-406b-a0ff-e644fefc3c53)
  ![image](https://github.com/user-attachments/assets/cf3f7d21-3a94-4534-aad3-e5d4028add38)
  </details>
  
  <details>
    </br>
    <summary><b>Clase 2 (Sistemas Operativos)</b></summary>  
    <p>Un <b>Sistema Operativo (SO)</b> es un conjunto de programas de un sistema informático que <b>gestiona los recursos del hardware y provee servicios a los programas de aplicación de software</b>. Este mismo se encarga de actuar como intermediario entre el hardware y las aplicaciones.</p>
    <p>Podemos analizar los tres componentes principales involucrados en el entorno de los sistemas operativos: <b>hardware, software y personas</b>.</p>
    <p>El <b>Hardware</b> incluye todos los componentes físicos de la computadora que el sistema operativo administra. El sistema operativo actúa como un puente entre el hardware y la aplicaciones que lo utilizan. El <b>Software</b> en el contexto de sistemas operativos incluye tanto el propio sistema operativo como las aplicaciones que interactúan con él. En cuanto a las <b>Personas</b> se incluyen los usuarios y administradores que interactúan con el sistema operativo, así como los desarrolladores que crean software para él.</p>
    <p>Entonces el sistema operativo se divide en:
    </p>
    
- Hardware: Componentes físicos como memoria, disco duro, etc.
- Software: Incluye el núcleo (kernel) y aplicaciones.
- Personas: Usuarios, administradores y desarrolladores.
 
<p>El sistema operativo se divide en capas: hardware, núcleo, aplicaciones, interfaz, etc.</p>
    
<img src="https://github.com/user-attachments/assets/e86c0f8a-65c5-4a58-98ef-e4b32bd28f53" alt="Descripción de la imagen" width="600">
</br>
<img src="https://github.com/user-attachments/assets/beb89d78-c67b-4c99-9617-31b797ec4601" alt="Descripción de la imagen" width="600">
 <p>El Sistema Operativo tiene <b>2</b> roles principales:</p>

 - <b>Interfaz con el hardware: </b>
    - Añade características no existentes en el HW.
    - Oculta características/inconvenientes del HW.
    - Ofrece una máquina extendida.
- <b>Administrador de recursos: </b>
    - Concede recursos de forma segura, justa y eficiente.
    - No realiza trabajo productivo o función útil por si mismo.
 </br>
<p>Principalmente el Sistema Operativo funciona como una interfaz entre el usuario, las aplicaciones, y el hardware de un sistema computacional. Este actúa como mediador, proporcionando un entorno en el cual las aplicaciones pueden ejecutarse y el hardware puede ser utilizado de manera eficiente y segura. <b>Lo vemos como una capa que envuelve al hardware.</b></p>

<img src="https://github.com/user-attachments/assets/f5348bc8-7126-48e3-bf00-fd2765f56a59" alt="Descripción de la imagen" width="400">

- <b>Nos ofrece una maquina abstracta con otras características:</b>
    - Oculta detalles incomodos del hardware.
    - Amplia características no presentes en el hardware.

- <b>¿Qué aspecto tiene la interfaz?</b>
    - Texto <b>(CLI = Command Line Interface).</b>
    - Gráfica <b>(GUI = Graphical User Interface).</b>
    - <b>Servicios de programación (API)</b>
    
<details>
    <summary><b>Ejemplo de CLI</b></summary>
    </br>

<img src="https://github.com/user-attachments/assets/b1ddfd9f-e017-4cb5-8ba8-bb058ee9e878" alt="Descripción de la imagen" width="400">

</details>

<details>
    <summary><b>Ejemplo de GUI</b></summary>
    </br>
    
<img src="https://github.com/user-attachments/assets/313ee92b-afea-40c4-89ec-1758d1f4ccd8" alt="Descripción de la imagen" width="400">

</details>

- <b>Qué ganamos interponiendo esta interfaz entre los programas y el hardware</b>
    - <b>Usabilidad</b>: La interfaz es más cómoda que el HW
    - <b>Seguridad</b>: Se ocultan vulnerabilidades del interior del hardware
    - <b>Portabilidad</b>: Independencia del hardware
    - <b>Interoperabilidad</b>:** Podemos compartir información con otros sistemas que usen la misma interfaz
    - <b>Mantenibilidad</b>: Podemos hacer mejoras o adaptaciones dentro del SO sin obligar a hacer cambios en los programas de usuario
    - <b>Productividad</b>: por todo lo anterior

**📝 Nota:** Los sistemas operativos como Windows se comenzaron a programar en C para que sean más portables.

El <b>Sistema Operativo (SO)</b> como administrador de recursos:
- Procesos y Recursos:
    - Procesos : Es una entidad dinámica.
    - Recursos: Puede ser algo físico o virtual, (requiere de un proceso)
- Los Recursos son escasos, los proceso compiten entre ellos.
- El SO actúa como <b>arbitro/mediador</b>, asigna recursos en forma <b>segura y eficiente.</b>
- El SO debe determinar a quien le entrega recursos, cantidad, en que momento, por cuanto tiempo.
- Por todo estos puntos debemos tener: <b>Políticas de gestión de recursos</b>.

 </details>
  
 </details>

 <details>
    <summary><b>Módulo 2</b></summary>
    </br>
    
  </details>

  <details>
    <summary>Apuntes</summary>
    </br>
    
  </details>
</details>

<details>
  <summary><b>Práctica</b></summary>
</br>
  <details>
    <summary><b>TP1: Manejo de comandos, directorios y archivos</b></summary>
    <!-- Contenido del TP1 -->
  </details>

  <details>
    <summary><b>TP2: Scripts</b></summary>
    <!-- Contenido del TP2 -->
  </details>

  <details>
    <summary><b>TP3: Scripts</b></summary>
    <!-- Contenido del TP3 -->
  </details>

  <details>
    <summary><b>TP4: Administración de CPU – Procesos</b></summary>
    <!-- Contenido del TP4 -->
  </details>

  <details>
    <summary><b>TP5: Semáforos – Hilos – Administración de Memoria</b></summary>
    <!-- Contenido del TP5 -->
  </details>

  <details>
    <summary><b>TP6: Administración e instalación de servicios en Linux</b></summary>
    <!-- Contenido del TP6 -->
  </details>

  <details>
    <summary><b>TP7: File System</b></summary>
    <!-- Contenido del TP7 -->
  </details>

  <details>
    <summary><b>Parciales</b></summary>
    <!-- Contenido de Parciales -->
  </details>
</details>

<details>
  <summary><b>Videos de las clases</b></summary>
  </br>
  <!-- Enlaces o notas relacionadas con los videos -->
    <p>Canal de la <b>teoría</b> Sistemas Operativos UTN FRLP: <a href="https://www.youtube.com/@rodriguezlisardoluis3893/videos" target="_blank"><b>Ver</b></a></p>
    <p>Canal de la <b>practica</b> Sistemas Operativos UTN FRLP: <a href="https://www.youtube.com/@sistemasoperativosutnfrlp4917" target="_blank"><b>Ver</b></a></p>
</details>

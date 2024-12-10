

---

## SINCRONIZACION:


Cuando hablamos de procesos cooperativos vamos a empezar a tener una serie de problemas, ya que va a haber una serie de procesos que van a estar ejecutando, compartiendo cosas, y ese compartimiento trae consigo algunos problemas. Por eso empezamos a hablar de Sincronización de Procesos, que son métodos para la resolución de estos problemas presentados, ya que tenemos :

< Procesos comparten recursos  ||  y de esos recursos, en algún momento puede ser que ambos o varios procesos necesiten de esos o ese recurso ( tiene que ver con la ejecución de procesos concurrentes )  ||
< Pueden ser adquiridos por mas de uno
< Procesos en ejecución concurrente
< Procesos que corren en multi CPU

EJEMPLO:
Supongamos que hay un recurso compartido en un sistema determinado. Ese recurso  que es una variable, como ejemplo puede ser "stock-PC" 
- Vamos a suponer que estamos en un negocio, que vende artículos de computación, tenemos a stock-cp que es una variable global, cuando viene un cliente ve una maquina que le gusta, entonces el vendedor se la vende, factura y no hay problema, descuenta el stock.  Ahora, se agranda el negocio, con otros puestos de venta. Viene una persona a comprar x cosa y pregunta al vendedor, entonces el vendedor la busca en el sistema, mientras que por otro lado también otro vendedor busca el mismo articulo. Se las factura a ambos compradores,  entonces hicieron dos facturas de un solo articulo en especial. Ese problema se llama :

##### CONDICION DE CARRERA: 
Característica que se da cuando un recurso es accedido por mas de un proceso, estos compiten por el recurso. 

El resultado de una operación depende del orden en que se ejecuten las instrucciones de los procesos.

##### SECCION CRITICA: 
Parte del código de un programa en la cual se va a acceder y modificar un recurso compartido, donde no puede acceder mas de un proceso a la vez.

antes como bloque de código tenemos "Actividades Preliminares" y luego "Actividades Posteriores".

- En un programa puede haber varias secciones criticas.

En un lenguaje a bajo nivel, una instrucción de alto nivel se va a descomponer en varias sentencias de bajo nivel.   Se tiene en cuenta porque si un proceso esta en ejecucion , tiene registros cargados, tiene el stock cargado por ejem, o leido, y si hay una interrumpción habrá un cambio de contexto xq entró otro proceso. Puede agarrar ese recurso el otro proceso y modificarlo, luego vuelve el proceso anterior y como ya tenia leido el stock y quiera hacer una operacion, vamos a tener un problema.


< Existen distintas soluciones a este problema 

-- Debemos definir un Protocolo
-- Debemos saber si estamos en sistemas mono CPU o multiple CPU
-

###### EXCLUSION MUTUA  -  MUTEX - ( uno solo en la S.C )
- Hacemos lo que se denomina un "Cerrojo" para proteger esa Seccion critica 
- Funciona para una cola FIFO
- Planteo de (Stallings -Tanenbaum)
- Que pasa si el recurso se asigna por prioridad ? - Planteo de "Silberschatz"
- Puede ocurrir un caso de "inanición"

actividades preeliminares: actividades antes o posteriores a la S.C.

###### PROGRESO (Silberchatz):
Solo participan del recurso compartido los procesos que están en la cola (no lo que estan en actividades preeliminares). Cuando tenemos  un algoritmo preeliminar.

###### ESPERA LIMITADA (Silberchatz):
Ningun proceso puede esperar ilimitadamente la entrada a la seccion critica y Ningún proceso puede entrar ilimitadamente a la sección crítica si existe por lo menos un proceso que haya hecho la solicitud de entrar. Si solamente van a participar los que estan en la cola. En algun momento van a entrar todos por mas que haya algoritmo de prioridad. 

### SOLUCIONES AL PROBLEMA DE LA S.C

#### < A nivel de Software:
###### Algoritmo de Peterson (Primera solucion planteada - en el libro):
algoritmo de programación concurrente para exclusión mutua que utiliza sólo memoria compartida para la comunicación.Usa un contador  banderas para ver que proceso estaen la s.c . Pero no se usa hoy en dia.

#### < A nivel de Hardware (Instrucciones a nivel procesador):
###### Test-And-Set:
Instruccion a nivel codigo de maquina (verificar y colocar el valor). Provoca que no se pueda interrupir el proceso en la s.c, bloquea todo el procesador y no lo deja interrumpir.
###### SWAP:
Tambien bloquea el procesador, la puede realizar en un solo ciclo de instruccion en toda la operacion.

#### < A nivel de S.O:

##### - SEMÁFORO:
Herramientas de la sincronizacion que nos permite solucionar el problema de la s.c implementado a nivel de s.o , es un tipo de variable especial y tipo abstracto de dato protegido que pertenece al dominio de los enteros y es manejado por el SO. Cuyas operaciones son: 
    
#Inicializar se inicializa con la cant de buffer que se van a estar disponibles.

###### #Pedir el recurso (Wait/Down): 
función que pide el recurso y si no está disponible permanece en un ciclo infinito. Si está disponible no entra en el ciclo y decrementa la variable del semáforo.

###### #Liberar el recurso (Signal/Up): 
función que libera el recurso tomado y que incrementa el valor del semáforo o despierta el proceso que está esperando a acceder.

##### - Tipos de Semáforos: 
    
###### - Binarios (MUTEX)/ cerrojos MUTEX: 
toman los valores 0 y 1 únicamente. Solucionan el problema de la sección crítica al tener múltiples procesos.
    
###### - Contador: 
toman valores enteros, tienen una cola donde la cantidad de procesos en la misma es representada por resultados negativos del semáforo.
    
##### - Tipos de Espera:
    
###### - Espera Activa: 
cuando el semáforo se queda en cero se produce un bucle infinito donde consecutivamente el proceso se quedará activo, esperando, solicitando pedir el recurso (wait) para entrar a la sección crítica.
    
###### - Espera no activa: 
cuando los procesos quedan en una cola de espera siendo representados por valores negativos del semáforo.

#### < A nivel de compiladores de lenguajes de alto nivel:

##### - MONITORES: 
tipo de variable abstracta y un método que se invoca (sucesión de sentencias) y encapsula todas las operaciones que se hacen sobre un recurso compartido, que se usa cuando tenemos varios procesos de códigos distintos, distintos sistemas hechos por distintos programadores. 
    
#Lo único que me garantice que esto funcione es que el monitor esté bien programado.

#Un solo proceso va a estar en la sección del monitor, varios procesos o hilos pueden llamarlo invocando el método monitor, pero uno solo va a entrar y los demás deberán esperar.

#Encapsula todos los procedimientos: consulta, invocación, desplazamiento, incremento de una variable, grabar sobre el recurso.

#Los monitores tienen su variable exclusiva llamada ==condition== que se declara dentro del monitor, sincroniza al mencionado y posee las operaciones wait y signal.

- Wait: suspende el proceso para entrar al monitor.
    

- Signal: despertar al proceso que estaba suspendido.
    

---

## INTERBLOQUEOS

#### Interbloqueo/Deadlock/abrazo mortal: 
suceso que se da cuando en un conjunto de procesos todos están esperando un suceso que solo puede producirse como consecuencia de la acción de otro proceso del conjunto.

---
**Condiciones Necesarias que se dan para Generar un Interbloqueo:**

###### - Exclusión Mutua:
al menos un recurso debe estar retenido en modo no compartible.
###### - Retención y Espera:
al menos un proceso está reteniendo un recurso y está esperando adquirir otros recursos para poder continuar su ejecución y ese recurso esta siendo ocupado. El S.O debe ser permisivo    
###### - No Apropiación:
 cuando un proceso tiene mayor prioridad que otro, el SO no debe permitir que este se apropie del recurso que está reteniendo el otro. 
###### - Espera Circular: 
Cuando dos procesos están reteniendo un recurso pero están solicitando adquirir el del otro generando que estos se cuelguen.


### 3 Políticas Generales de la Ingeniería para Evitar que Esto pase:

#### - Que no ocurra: 
-tomar las medidas necesarias para evitarlos. Es prevenir y evitar
    
##### - Prevenir:

 - En el caso de la *Exclusión Mutua* no se puede hacer nada cuando los recursos no son compartibles ya que justamente esa esa es su característica y se debe esperar.

- En el caso de *Retención y Espera* 
	- El sistema debe ser transaccional.
	- Dejar que se retrotraiga todo al principio (rollback).
	- Se espera un determinado tiempo.
	- Si esta en wait mucho tiempo le quita todo.

- En el caso de la *No Apropiación* 
     - Podría permitir la Expropiación.
     - Procesos con mayor prioridad.
     - Puede ser que un proceso expropie (Tiempo Real).
     - En algunos sistemas, este debe ser transaccional.

- En el caso de la *Espera Circular* debemos evitar el surgimiento de ciclos implementando un algoritmo que recorra el grafo, y así anotar los procesos que retienen a ciertos recursos.

##### - Evitar ( Política de que no pase ):

- Una forma de resolver esto es determinar si el proceso está en estado *seguro* o *inseguro*; estando en estado inseguro no quiere decir que se de un interbloqueo, pero para estar **seguro** debo asignar todos los recursos antes de solicitarlos y no empiezo a ejecutar hasta que tenga todo. Si otro necesita algun recurso deberá ir a la lista de espera.

#### - Tener un Plan:
##### - Evitar ( Política de tener un Plan ):

- ==Detectar==
- ==Recuperar==

- detectar,  no es simple. Necesitamos un algoritmo matemático que trabaje con grafos. Luego hago el grafo de asignación de recursos, dejo que pase y puedo tomar una de las siguientes decisiones:

- Mato a todos los procesos que se retrotraigan.
- Matar de a uno y ver que pasa.
- Decidir cual mato aplicando prioridad.
- Modificar las condiciones del SO para que permita la expropiación de recursos.
- Dejarlo en mano del usuario.

#### - No Hacer Nada: 
puede pasar? bueno que pase 

---

## ADMINISTRACION DE LA MEMORIA


### MEMORIA PRINCIPAL ( RAM ):
Espacio de memoria donde residen tanto el código a ejecutar como los datos del proceso en ejecución. Memoria de trabajo de acceso indistinto. Es donde están definidos los segmentos de datos y de código.

Otra def - memoria que almacena temporalmete datos e instrucciones que el procesador necesita para ejecutar programas. Es vólatil, esto quiere decir que su contenido se pierde al apagar o reiniciar el sistema, tambien es muy rapida y puede acceder a cualquier posicion de memoria sin recorrer otras previas.

###### MEMORIAS SECUNDARIAS: 
por ej: disco rigido/solido

###### MEMORIAS TERCIARIAS:
Aquellas que no estan permanentemente en el sistema, como dvd, pen-drive, memorias que uno coloca y saca.

#### Memoria Periférica:
donde guardamos con mayor o menor grado de permanencia, programas, datos, el código fuente, los documentos de textos, etc.

### Características de la Memoria Principal: 

Una de las características esenciales de la memoria principal, es que ..

- La podemos direccionar a nivel de palabra de memoria. Y así acceder a cada posición con su dirección (que hace referencia/almacena a un byte).

	 *PALABRA* *DE* *MEMORIA* : Es la unidad de informacion que la memoria puede procesar en una sola operacion. Una palabra de memoria tiene un tamaño fijo, que depende del diseño de la arqui del sistm. por ej: sistema de 32 bits, una palabra de memoria tiene 32 bits (4 bytes), una de 64 bits tiene 64 bits (8 bytes) . Tambien en lo que es division o alineacion, donde la ram esta organizada en celdas o direcciones, y cada direccion puede almacenar una palabra. por ej si la memoria tiene 4GB de capacidad y cada palabra es de 4 bytes, habra 4.294.97.296 / 4 = 1.073.741.824 palabras de memoria, es decir direcciones o celdas de memoria
    
- La velocidad de acceso a cada dirección es la misma
    
- Cada acceso a la RAM es unívoca.
    
Podemos hacer una diferencia:

- Byte lógico (8 bits).
    
- Byte físico (más de 8, de 9, de 10).
    
- ==Longitud de Dirección de Memoria:== 
	La **longitud de la dirección** depende del espacio de direcciones del sistema (cuánta memoria puede direccionar). posee 16 bits, define la capacidad de direccionamiento (2^16 = 64k de un segmento). Basicamente la longitud de una direccion de memoria es es el **número de dígitos (tamaño) que necesitas para escribir el número de un cajón/casillero (celda de memoria)**. Depende del tamaño total de memoria del sistema, pero cada direccion sigue apuntando a un byte.
    
- Las computadoras después tuvieron registros de cpu de 32 bits. Sólo podemos direccionar hasta 4 gb de memoria (2^32).
    


### DIRECCIONES DE MEMORIA:


##### Dirección Simbólica: 
definición de una variable en el programa. De la que se encarga el compilador, ensamblador o intérprete

##### Dirección física: 
dirección de una variable en la memoria RAM. Direccion Real. Cuando arranca la máquina arranca el SO por lo que nunca arrancará de cero.

##### Dirección lógica: 
la que es emitida por la CPU, que usada como referencia, en momento de ejecución, se transforma en dirección física por el SO. Se llama lógica porque arrancamos en la ejecución del programa desde la dirección 0. Es la que arranca de cero (o 0000h), cuando un programa compila. *//*  Es una dirección virtual que forma parte del espacio de direcciones del programa y no necesariamente corresponde a una ubicación real en la memoria física. *//*

##### Dirección base: 
donde arranca el marco o segmento de memoria, a partir de donde se puede cargar un proceso que tiene como proposito ayudar a traducir direcciones logicas a fisicas .


#### Producción de Dirección Lógica: 
se produce en tres momentos distintos (compilación, carga y ejecución).

###### - En Compilación: 
- El compilador conocía la dirección física donde había que empezar a cargar la memoria. Por lo tanto en tiempo de compilación las dirección física y lógica son iguales. El problema de esto es que a la hora de tener que compartir el programa hay que pasar el código fuente.
    
###### - En Carga: 
- La transformación de DL a DF, va a arrancar el código en absoluto de dirección 0000h. El compilador lee y conoce lo que se llama Dirección Base una constante K que puede ser de 256 Kbytes por ejemplo.
    
- El cargador lee del disco y le suma a cada DL la constante K, creando así las direcciones físicas. 
    
DF = DL + K.

- Entonces la CPU emite una dirección lógica, el SO calcula la dirección física sumando la constante K (Dirección Base). A esto se le denomina el ==Código Reubicable==. Era como funcionaba el DOS (de disco, sin interfaz gráfica). 
    
###### - En Ejecución: 
- En tiempo de ejecución se le sigue sumando la constante K, la dirección base o de relocalización.
    
- La CPU: Hardware de administración de memoria.
    
#### - La MMU: 
 -   parte de Hardware, la unidad de administración de memoria. Quien tenía cargado la dirección base y calcula la dirección física (Transforma la direccion logica en fisica) .   ¿donde seencontraba? - esta integrado en la CPU
    
- La CPU emite la dirección lógica y la MMU la transforma en dirección física.
    
- Ya no lo hace el SO.
    
- Aquí es donde explotó la industrialización del software. Ya que al compilar yo ya poseía el ejecutable del código.
    
- Registro de Reubicación: se almacena la dirección base. El registro base se llama el registro de ubicación. Ahora la constante K pasa a llamarse de esta forma.

---

#### Espacio de Memoria:
conjunto de direcciones de memoria. Que se puede dividir en dos conceptos.

- *Espacio de direccionamiento:* 
	el conjunto de direcciones posibles. Que define la cantidad de bits que tiene la longitud de palabra de direccionamiento. (si tengo 4 bits de direccionamiento poseo 16 direcciones de memoria). 
    
- *Espacio de direcciones:*
	subconjunto de todo el espacio de direccionamiento que representa todas las direcciones que estoy usando. Que pasa cuando incorporamos librerias?? bueno va a haber otro espacio de direcciones

---

A mediados de los 60 cuando IBM lansa la 360, aparece la multiprogramacion, y con ella la programacion concurrente y cambio la forma de administrar la memoria. La primer tecnica fue la "Asignacion contigua de memoria"..

### Asignación Contigua de Memoria:
la memoria se divide en lo que es el SO y los procesos de usuario. Definido un espacio, con ya la multiprogramación presente, podíamos cargar varios procesos de usuario en la memoria.  *//*  Es una técnica de administración de memoria en la que a cada proceso se le asigna un bloque único y contiguo (sin interrupciones) de direcciones de memoria.. Metodo desarrollado por IBM (360/OS)  *//*

- Hay dos formas de administracion de memoria en lo que denominamos asignacion contigua.

##### < MFT (multiprogramacion con numero fijo de tareas):
- Cuando arranca la máquina y el SO, la memoria se divide en particiones fijas (predefinidas), que no quiere decir que sean todas iguales, a través de un comando del SO usado por el operador del equipo (el que decidía el tamaño de las particiones), para los procesos a través de un operador de consola.

- Dos métodos: una cola para cada partición o una cola para todas las particiones.

	VENTAJAS: 
	- Simplicidad en la implementación.
	- La asignación y liberación son rápidas.
	
	DESVENTAJAS :
	- **Fragmentación interna:** Espacio desperdiciado dentro de las particiones cuando los procesos no llenan completamente su espacio asignado.
	- La cantidad y tamaño de las particiones limitan la flexibilidad.

##### < MVT (Multiprogramación con un número variable de tareas):

- Cuando las particiones son variables o dinámicas, se le asignan y se definían los procesos de forma dinámica.
    
- Se divide la RAM en particiones de longitud variable.
    
- El tamaño de cada partición se define en base al tamaño del proceso.
    
- Fue utilizado por Batch o Sistemas por lotes.
    
- Donde aparece el planificador de largo plazo y las divisiones en particiones ya no las hacía el operador, sino que las definía el SO.
    
- Se divide el hueco cuando llega un nuevo proceso para asignarle una parte de la memoria.
    

En este caso se genera fragmentación externa.

###### Swapping (Intercambio): 
Los procesos pueden ser intercambiados temporalmente entre la memoria principal y la memoria virtual, cuando el proceso está en la RAM en ejecución. Solicitamos de un periférico para la ejecución, el proceso pasaba a manos del controlador del periférico.

#### Fragmentación Interna: 
pérdida de un recurso por estar asignado a un proceso que no lo utiliza. Cuando una parte de la memoria asignada a un proceso no es utilizada por el mismo, es decir que a un proceso le sobra cierto recurso, ej: a un proceso le das 70kb de espacio y solo usa 50kb, entonces ahi se esta produciendo fragmentacion interna.  otro ej: el restaurant
  
#### Fragmentación Externa: 
pérdida de un recurso por no estar asignado a ningún proceso, porque este recurso no alcanza a satisfacer las necesidades que requieren otros procesos. Cuando los procesos ocupan la memoria de manera tal que van dejando huecos de memoria entre uno y otro cuando terminan de procesar. Esos huecos se le denominan la fragmentación externa.


##### Técnicas para evitar la fragmentación: 

- Primer Ajuste: 
	asigna el primero lo suficientemente grande.
    
- Mejor Ajuste: 
	el más pequeño lo suficientemente grande.
    
- Peor Ajuste:
	asigna el hueco más grande.


---

### PAGINACION SIMPLE:
- Tecnica por la cual un proceso no esta en forma contigua en la memoria, sino que esta disperso en esta.
- La **paginación simple** es una técnica de administración de memoria que divide tanto la memoria principal como los procesos en bloques de tamaño fijo llamados **páginas** (para los procesos) y **marcos de página** (para la memoria física). Estos bloques tienen el mismo tamaño, lo que facilita la asignación de memoria sin necesidad de que los bloques sean contiguos.

**Páginas:**   (parte logica)

- Divisiones lógicas del proceso (en la memoria virtual).
- Ejemplo: Un proceso de 8 KB se divide en dos páginas de 4 KB cada una. (512 o 1k)

**Marcos de Página:**  (parte fisica)

- Divisiones físicas de la memoria principal, del mismo tamaño que las páginas.
- Ejemplo: La memoria física tiene varios marcos de 4 KB.

**Tabla de Páginas:**

- Estructura que mantiene un registro de qué marco de memoria física contiene cada página de un proceso.
- Ayuda a traducir las direcciones lógicas a direcciones físicas.
	La tabla de páginas traduce el número de página al marco correspondiente, y el desplazamiento se suma para obtener la dirección física.
- Una dirección lógica generada por el programa se divide en dos partes - num de pag y desplazamiento.
- En la tabla de pagina tenemos el num de pagina y la tabla de pagina, y la administra la mmu( ==reside en los registros de la MMU== ).
-  En principio la tabla está cargada en memoria, cuando el proceso está en ejecución el cargador (loader) arma la tabla de página y la carga en la MMU. Para que solo tenga un acceso a memoria para conocer la dirección de la página y para poder calcular la memoria física (sino necesitaríamos dos, una para cada paso mencionado).

El tamaño de pagina lo decide el HW

**Evita la Fragmentación Externa pero Puede haber Fragmentación Interna en la ultima pagina** debido a que por ejemplo si las paginas son de 1k , en la ultima se uso la mitad del espacio quizas y puede llegar a queda hueco de memoria sin utilizar


¿Que ocurrio cuando empezaron a haber muchos mas procesos en la asignacion contigua de memoria,tanto con la mvt y mft? - Comenza a haber mucha fragmentacion tanto interna como externa

Como la cantidad de procesos aumento, la cantidad de paginas aumento
###### PTBR (Registro base de la tabla de páginas): 

- Más adelante nos empezó a sobrar RAM, 
    
- Entonces se decide colocar la Tabla de Páginas de los procesos en la RAM, en un espacio de memoria que le pertenece al Kernel, ya no en los registros de la MMU
    
- Entonces los registros de la MMU (registros de CPU) se quedaron para poseer la PTBR, donde están las direcciones donde comienzan las direcciones de cada tabla de página en memoria. 
    
- Teníamos que tener dos accesos a la memoria lo que retrasaba mucho los procesos.
    
- El compilador deja la Tabla de Páginas, luego el cargador coloca la MMU, algunas de estas llegaron a colocar registros para más de un proceso. 
    
- La longitud de los registros era del tamaño de la palabra de datos de la CPU. Ya teníamos registros de 32 bits donde teníamos memoria de sobra, un problema más.


###### TLB (Asociativos o Buffers de Traducción de Vista Lateral/ Buffer de Búsqueda de Traducción): 

La TLB es una solución al problema de tener memoria de sobra, es un caché especial (no buffer, porque no hay datos repetidos) que es parte del HW, una memoria asociativa y de rápido acceso, que tiene los datos del proceso que está en ejecución, y hace una comparación del número de página con los que ya tiene cargado. Hace el cálculo de memoria física mucho más rápido.

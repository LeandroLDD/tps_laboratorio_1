#include "Jugador.h"
#include "Seleccion.h"
#include "Gentilicio.h"

/**
 * @brief Carga una lista de jugadores desde un archivo texto
 * @param path Ruta del archivo
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario extendio. -1. Error en parametros | 0. No se pudo leer el archivo | 1. Funciono correctamente
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/**
 * @brief Carga una lista de jugadores desde un archivo binario
 * @param path Ruta del archivo
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario extendio. -1. Error en parametros | 0. No se pudo leer el archivo | 1. Funciono correctamente
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/**
 * @brief Agrega un jugador vacio a la lista de jugadores
 * @param pArrayListJugador Lista de jugadores
 * @return Retorna el indice en lista en el que se guardó al jugador
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/**
 * @brief Pide elegir un jugador para editar sus valores en una lista de jugadores
 * @param pArrayListJugador Lista de jugadores
 * @return Retorna el indice en lista del jugador elegido
 */
int controller_editarJugador(LinkedList* pArrayListJugador);

/**
 * @brief De una lista de jugadores pide uno y desplega un menu de opciones disponibles para editar
 * @param pArrayListJugador Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se edito al jugador | 1. Se edito al jugador
 */
int controller_menuEditarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio);

/**
 * @brief Pide elegir un jugador para remover de una lista de jugadores
 * @param pArrayListJugador Lista de jugadores
 * @return Retorna el indice en lista del jugador elegido
 */
int controller_removerJugador(LinkedList* pArrayListJugador);

/**
 * @brief Imprime en pantalla una lista de jugadores con unicamente sus datos
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_listarJugadores(LinkedList* pArrayListJugador);

/**
 * @brief Imprime en pantalla una lista de jugadores con sus datos e informacion de seleccion
 * @param pArrayListJugador Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_listarJugadoresTodosLosDatos(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @brief Imprime en pantalla una filtrada lista de jugadores con sus datos e informacion de seleccion
 * @param pFunc Condicion a cumplir para realizar el filtro
 * @param pArrayListJugador Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario extendido. -1. Error en parametros | 0. No encontro ningun jugador a filtrar | 1. Correcto funcionamiento
 */
int controller_listarJugadoresTodosLosDatosFiltro(int (*pFunc)(Jugador* ),LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @brief Imprime en pantalla una ordenada lista de jugadores con unicamente sus datos
 * @param pArrayListJugador Lista de jugadores
 * @param ordenamiento Condicion de ordenamiento
 * @param orden 1. Menor a mayor | 0. Mayor a menor | Otro. Pregunta al usuario
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_listarJugadoresOrdenados(LinkedList* pArrayListJugador, int (*ordenamiento)(void*,void*), int orden);

/**
 * @brief Imprime en pantalla un jugador con sus datos e informacion de seleccion
 * @param pJugador un jugador
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_mostrarUnJugador(Jugador* pJugador, LinkedList* pArrayListSeleccion);

/**
 * @brief Imprime en pantalla un jugador con informacion de seleccion
 * @param pJugador un jugador
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_mostrarPaisSiConvocado(Jugador* pJugador ,LinkedList* pArrayListSeleccion);

/**
 * @brief De una lista de selecciones convoca un jugador de una lista de jugadores filtrados por pais
 * @param pArrayListSeleccion Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorno binario extendido. -2. Error en parametros | -1. El pais elegido no puede convocar | 0. No hay jugadores del pais elegido | 1. Correcto funcionamiento
 */
int controller_convocarJugador(LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugador, LinkedList* pArrayListGentilicio);

/**
 * @brief De una lista de selecciones desconvoca un jugador de una lista de jugadores filtrados por pais
 * @param pArrayListJugador de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario extendido. -1. Error en parametros | 0. No convoco | 1. Correcto funcionamiento
 */
int controller_menuDesconvocarJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @brief Desconvoca un jugador de su seleccion
 * @param pJugador Un jugador
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_desconvocarJugador(Jugador* pJugador, LinkedList* pArrayListSeleccion);

int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/**
 * @brief Guarda los datos de una lista de jugadores en un archivo de texto
 * @param path Ruta del archivo
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/**
 * @brief Guarda los datos de una lista de jugadores en un archivo binario
 * @param path Ruta del archivo
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/**
 * @brief Guarda los datos de una lista filtrada de jugadores en un archivo binario
 * @param path Ruta del archivo
 * @param pArrayListJugador Lista de jugadores
 * @param criterio Criterio del filtro
 * @param pFunc Metodo de filtracion
 * @return Retorno binario. -1. Error en parametros | 0. No filtró | 1. Correcto funcionamiento
 */
int controller_guardarJugadoresFiltradosModoBinario(char* path , LinkedList* pArrayListJugador, void* criterio, int (*pFunc)(LinkedList*,int indice, void*));

/**
 * @brief Carga los datos de un archivo de texto a una lista de selecciones
 * @param path Ruta del archivo
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/**
 * @brief Imprime en pantalla una lista de selecciones
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/**
 * @brief Imprime en pantalla una lista de selecciones
 * @param pArrayListSeleccion Lista de selecciones
 * @param ordenamiento Metodo de ordenamiento
 * @param orden 1. Menor a mayor | 0. Mayor a menor | Otro. Pregunta al usuario
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_listarSeleccionOrdenadas(LinkedList* pArrayListSeleccion, int (*ordenamiento)(void*,void*), int orden);

int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/**
 * @brief Guarda los datos de una lista de selecciones a un archivo de texto
 * @param path Ruta del archivo
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. -1. Error en parametros | 0. No se pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/**
 * @brief Gestiona la creacion y alta de un jugador
 * @param pArrayListJugador Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @param pArrayListGentilicio Lista de gentilicios
 * @param id Variable que se asignara como ID
 * @return Retorno binario. -1. Error en parametros | 0. No se pudo crear al jugador | 1. Correcto funcionamiento
 */
int controller_darDeAltaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion,LinkedList* pArrayListGentilicio, int *id);

/**
 * @brief Gestiona la eliminacion y baja de un jugador
 * @param pArrayListJugador Lista de jugadores
 * @param pArrayListSeleccion Lista de selecciones
 * @return Retorno binario. -1. Error en parametros | 0. No se elimino al jugador| 1. Correcto funcionamiento
 */
int controller_darDeBajaJugador(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/**
 * @brief Pide seleccionar la ID de un jugador en una lista
 * @param pArrayListJugador Lista de jugadores
 * @param msj Mensaje de pedido por consola
 * @param imprJugadores 1. Imprime la lista de jugadors | Otro. No imprime la lista de jugadores
 * @return Retorna la id seleccionada | Caso contrario -1
 */
int controller_pedirJugadorPorID(LinkedList* pArrayListJugador, char* msj, int imprJugadores);

/**
 * @brief Valida que la id este asociada a algun jugador de una lista
 * @param pArrayListJugador Lista de jugadores
 * @param id ID a validar
 * @return Retorno binario. 0. Jugador no encontrado | 1. Jugador encontrado
 */
int controller_validarJugadorPorID(LinkedList* pArrayListJugador, int id);

/**
 * @brief Obtiene un jugador asociada a una ID en una lista de jugadores
 * @param pArrayListJugador Lista de jugadores
 * @param id ID a validar
 * @return Retorna un puntero del jugador encontrado | Caso contrario NULL
 */
Jugador* controller_obtenerJugadorPorID(LinkedList* pArrayListJugador, int id);

/**
 * @brief Pide por consola el nombre completo de un jugador
 * @param this Un Jugador
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_pedirJugadorNombreCompleto(Jugador* this);

/**
 * @brief Pide por consola la edad de un jugador
 * @param this Un Jugador
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_pedirJugadorEdad(Jugador* this);

/**
 * @brief Pide por consola la posicion de un jugador
 * @param this Un Jugador
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_pedirJugadorPosicion(Jugador* this);

/**
 * @brief Pide por consola la nacionalidad de un jugador
 * @param this Un Jugador
 * @param pArrayListSeleccion Lista de selecciones
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorno binario extendido. -1. Error en parametros | 0. No se pudo aplicar el gentilicio, se aplicó el nombre del pais | 1. Correcto funcionamiento
 */
int controller_pedirJugadorNacionalidad(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio);

/**
 * @brief Pide por consola todos los datos de un jugador
 * @param this Un Jugador
 * @param pArrayListSeleccion Lista de selecciones
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorno binario extendido. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_pedirJugadorDatos(Jugador* this, LinkedList* pArrayListSeleccion, LinkedList* pArrayListGentilicio);

/**
 * @brief Valida que haya jugadores convocados en una lista de jugadores
 * @param pArrayListJugador Lista de jugadores
 * @return Retorno binario. 0. No hay jugadores convocados | 1. Hay jugadores convocados
 */
int controller_hayJugadoresConvocados(LinkedList* pArrayListJugador);

/**
 * @brief Compara alfabeticamente la nacionalidad de 2 jugadores
 * @param unJugador Primer jugador
 * @param otroJugador Segundo jugador
 * @return Retorna la comparacion. < 0. otroJugador es mayor a unJugador | 0. Son iguales | > 0. unJugador es mayor a otroJugador
 */
int controller_cmpJugadorNacionalidad(void* unJugador, void* otroJugador);

/**
 * @brief Compara la edad de 2 jugadores
 * @param unJugador Primer jugador
 * @param otroJugador Segundo jugador
 * @return Retorna la comparacion. < 0. otroJugador es mayor a unJugador | 0. Son iguales | > 0. unJugador es mayor a otroJugador
 */
int controller_cmpJugadorEdad(void* unJugador, void* otroJugador);

/**
 * @brief Compara alfabeticamente el nombre de 2 jugadores
 * @param unJugador Primer jugador
 * @param otroJugador Segundo jugador
 * @return Retorna la comparacion. < 0. otroJugador es mayor a unJugador | 0. Son iguales | > 0. unJugador es mayor a otroJugador
 */
int controller_cmpJugadorNombre(void* unJugador, void* otroJugador);

/**
 * @brief Compara alfabeticamente la confederacion de 2 jugadores
 * @param unJugador Primer jugador
 * @param otroJugador Segundo jugador
 * @return Retorna la comparacion. < 0. otroJugador es mayor a unJugador | 0. Son iguales | > 0. unJugador es mayor a otroJugador
 */
int controller_cmpSeleccionConfederacion(void* unaConfederacion, void* otraConfederacion);

/**
 * @brief Valida si un jugador fue convocado o no
 * @param pArrayListJugador Lista de jugadores
 * @param indiceArray indice del pArrayListJugador del jugador a validar
 * @param convocadoCtr 0. Valida NO convocado | 1. Valida SI convocado
 * @return Retorno binario extendido. -1. Error en parametros | 1. Se cumplio la condicion | 0. NO cumplio la condicion
 */
int controller_esJugadorConvocado(LinkedList* pArrayListJugador,int indiceArray, void* convocadoCtr);

/**
 * @brief Valida si un jugador tiene asociada una idSeleccion o no
 * @param pArrayListJugador Lista de jugadores
 * @param indiceArray indice del pArrayListJugador del jugador a validar
 * @param idSeleccionCtr idSeleccion a validar
 * @return Retorno binario extendido. -1. Error en parametros | 1. Se cumplio la condicion | 0. NO cumplio la condicion
 */
int controller_esJugadorIdSeleccion(LinkedList* pArrayListJugador,int indiceArray, void* idSeleccionCtr);

/**
 * @brief Valida si un jugador tiene una nacionalodad o no
 * @param pArrayListJugador Lista de jugadores
 * @param indiceArray indice del pArrayListJugador del jugador a validar
 * @param nacionalidadCtr Nacionalidad a validar
 * @return Retorno binario extendido. -1. Error en parametros | 1. Se cumplio la condicion | 0. NO cumplio la condicion
 */
int controller_esJugadorNacionalidad(LinkedList* pArrayListJugador,int indiceArray, void* nacionalidadCtr);

/**
 * @brief Pide por consola la ID de una seleccion en lista
 * @param pArrayListSeleccion Lista de selecciones
 * @param msj Mensaje de pedido por consola
 * @return Retorna la ID elegida | Caso contrario -1
 */
int controller_pedirSeleccionPorID(LinkedList* pArrayListSeleccion, char* msj);

/**
 * @brief Valida que una ID este asociada a una seleccion en lista
 * @param pArrayListSeleccion Lista de selecciones
 * @param id ID a validar
 * @return Retorno binario. 0. Seleccion no encontrada | 1. Seelccion encontrada
 */
int controller_validarSeleccionPorID(LinkedList* pArrayListSeleccion, int id);

/**
 * @brief Busca una ID que este asociada a una seleccion en lista
 * @param pArrayListSeleccion Lista de selecciones
 * @param id ID a buscar
 * @return Retorna un puntero de la seleccion encontrada | Caso contrario NULL
 */
Seleccion* controller_obtenerSeleccionPorID(LinkedList* pArrayListSeleccion, int id);

/**
 * @brief Valida si una seleccion tiene convocados o no
 * @param pArrayListSeleccion Lista de selecciones
 * @param indiceArray indice del pArrayListSeleccion del jugador a validar
 * @param validConvocados 1. Valida SI tiene convocados | 0. Valida NO tiene convocados
 * @return Retorno binario extendido. -1. Error en parametros | 1. Se cumplio la condicion | 0. NO cumplio la condicion
 */
int controller_esSeleccionConvocados(LinkedList* pArrayListSeleccion, int indiceArray, void* validConvocados);

/**
 * @brief Leé un archivo de tipo txt y retorna la ID
 * @param pathID Ruta del archivo de IDs
 * @param idRetorno Retorno por parametro de la ID
 * @return Retorno binario extendido. -1. Error en parametros | 0. No pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_leerIDDesdeTXT(char* pathID, int* idRetorno);

/**
 * @brief Escribe una ID en un archivo de tipo txt
 * @param pathID Ruta del archivo de IDs
 * @param id ID a escribir
 * @return Retorno binario extendido. -1. Error en parametros | 0. No pudo abrir el archivo | 1. Correcto funcionamiento
 */
int controller_escribirIDEnTXT(char* pathID, int id);

/**
 * @brief Aumenta una ID y luego la devuelve
 * @param id ID a asignar
 * @return Retorna la id aumentada | Caso contrario -1
 */
int controller_IDAsignar(int* id);

/**
 * @brief Ordenada una lista
 * @param ordenamiento Metodo de ordenamiento
 * @param orden 1. Menor a mayor | 0. Mayor a menor
 * @return Retorno binario. 0. Error en parametros | 1. Correcto funcionamiento
 */
int controller_ordenarLista(LinkedList* pArrayList, int (*ordenamiento)(void*,void*), int orden);

/**
 * @brief Carga los datos de un archivo de texto a una lista de gentilicios
 * @param path Ruta del archivo
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorno binario extendio. -1. Error en parametros | 0. No se pudo leer el archivo | 1. Funciono correctamente
 */
int controller_cargarGentiliciosDesdeTexto(char* path, LinkedList* pArrayListGentilicio);

/**
 * @brief Busca un gentilicio en una lista asociada una idSeleccion
 * @param idSeleccion ID a validar
 * @param pArrayListGentilicio Lista de gentilicios
 * @return Retorna un puntero al gentilicio encontrado | Caso contrario NULL
 */
Gentilicio* controller_obtenerGentilicioPorID(int idSeleccion, LinkedList* pArrayListGentilicio);

/**
 * @brief Valida que una Lista exista y tenga datos cargados
 * @param pArrayList Lista
 * @return Retorno binario. 0. No existe o no tiene datos cargados | 1. Todo correcto
 */
int controller_validarLinkedList(LinkedList* pArrayList);

/**
 * @brief Obtiene una lista filtrada
 * @param pArrayList Lista
 * @param pArrayListRetorno Lista donde se retornara la pArrayList filtrada
 * @param pFunc Metodo de filtracion
 * @param criterio Criterio de filtracion
 * @return Retorno binario extendido. -1. Error en parametros | 0. No filtro | 1. Correcto funcionamiento
 */
int controller_obtenerLinkedListFiltro(LinkedList* pArrayList, LinkedList* pArrayListRetorno, int (*pFunc)(LinkedList*,int indice, void*), void* criterio);

/**
 * @brief Valida una lista filtrada
 * @param pArrayList Lista
 * @param pFunc Metodo de filtracion
 * @param criterio Criterio de filtracion
 * @return Retorno binario extendido. -1. Error en parametros | 0. No filtro | 1. Correcto funcionamiento
 */
int controller_validarLinkedListFiltro(LinkedList* pArrayList, int (*pFunc)(LinkedList*,int indice, void*), void* criterio);

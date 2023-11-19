# philosophers
![Philo|100](https://github.com/ediaz-c/philosophers/blob/main/philo/img/philo_dinner.jpg)
## Descripción
Este proyecto simula una escena en la que uno o más filósofos se sientan alrededor de una mesa redonda con un gran bol de espaguetis en el centro. Los filósofos pueden realizar tres acciones: comer, pensar o dormir, pero con restricciones. La simulación se detiene cuando un filósofo muere por inanición, y el objetivo es garantizar que todos los filósofos coman y nunca mueran de hambre.

## Reglas del Proyecto
- Cada filósofo debe ser un hilo
- Hay un tenedor entre cada filósofo, por lo que cada filósofo tiene un tenedor a su izquierda y otro a su derecha.
- Los filósofos deben tomar los tenedores de la derecha y de la izquierda para comer cómodamente.
- Se deben utilizar mutex para protefer los estados de los tenedores.

## Argumentos del Programa
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- **number_of_philosophers:** Número de filósofos y tenedores.
- **time_to_die:** Tiempo en milisegundos antes de que un filósofo muera si no comienza a comer.
- **time_to_eat:** Tiempo en milisegundos que un filósofo tiene para comer.
- **time_to_sleep:** Tiempo en milisegundos que un filósofo tiene para dormir.
- **number_of_times_each_philosopher_must_eat (opcional):** Número de veces que cada filósofo debe comer para que salga de la simulación.

## Compilación
El programa se compila utilizando el makefile:
```
make
```
El ejecutable es **philo**. Para ejecutar el programa, utiliza los argumentos mencionados.
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

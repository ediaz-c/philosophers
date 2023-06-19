#include <stdio.h>
#include <pthread.h>

void *print_message(void *message) {
    char *msg = (char *)message;
    printf("Mensaje del hilo: %s\n", msg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread_id;
    char *message = "Hola desde el hilo";

    if (pthread_create(&thread_id, NULL, print_message, (void *)message) != 0) {
        fprintf(stderr, "Error al crear el hilo.\n");
        return 1;
    }

    // Espera a que el hilo termine su ejecución
    pthread_join(thread_id, NULL);

    printf("Mensaje del hilo principal: Fin del programa\n");

    return 0;
}

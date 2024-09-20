#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Función que simula la reproducción de un archivo de audio
void* reproducir_audio(void* arg) {
    char* archivo = (char*)arg;
    printf("Reproduciendo archivo: %s\n", archivo);
    sleep(5); // Simula el tiempo de reproducción
    printf("Finalizó la reproducción del archivo: %s\n", archivo);
    return NULL;
}

int main() {
    pthread_t hilo_audio1, hilo_audio2;

    char* archivo1 = "audio1.mp3";
    char* archivo2 = "audio2.mp3";

    // Crear hilos para reproducir audio
    pthread_create(&hilo_audio1, NULL, reproducir_audio, archivo1);
    pthread_create(&hilo_audio2, NULL, reproducir_audio, archivo2);

    // Esperar a que los hilos terminen de reproducir
    pthread_join(hilo_audio1, NULL);
    pthread_join(hilo_audio2, NULL);

    return 0;
}

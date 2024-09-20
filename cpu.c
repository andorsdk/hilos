#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Función para monitorizar la CPU
void* monitorizar_cpu(void* arg) {
    while (1) {
        FILE* fp = fopen("/proc/stat", "r");
        if (fp) {
            char buffer[256];
            fgets(buffer, sizeof(buffer), fp);  // Leer la primera línea que tiene info de la CPU
            printf("CPU Usage: %s", buffer);
            fclose(fp);
        }
        sleep(1);
    }
    return NULL;
}

// Función para monitorizar la memoria
void* monitorizar_memoria(void* arg) {
    while (1) {
        FILE* fp = fopen("/proc/meminfo", "r");
        if (fp) {
            char buffer[256];
            fgets(buffer, sizeof(buffer), fp);  // Leer la primera línea que tiene info de la memoria
            printf("Memoria: %s", buffer);
            fclose(fp);
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t hilo_cpu, hilo_memoria;

    // Crear hilos
    pthread_create(&hilo_cpu, NULL, monitorizar_cpu, NULL);
    pthread_create(&hilo_memoria, NULL, monitorizar_memoria, NULL);

    // Mantener el programa corriendo
    pthread_join(hilo_cpu, NULL);
    pthread_join(hilo_memoria, NULL);

    return 0;
}

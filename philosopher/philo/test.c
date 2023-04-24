#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 5 // number of philosophers and forks

pthread_mutex_t forks[N]; // mutex array for forks

// function to simulate philosopher actions
void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_fork = id;
    int right_fork = (id + 1) % N;

    while (1) {
        // think for a random amount of time
        printf("Philosopher %d is thinking.\n", id);
        sleep(rand() % 5);

        // take left fork
        pthread_mutex_lock(&forks[left_fork]);
        printf("Philosopher %d has taken fork %d.\n", id, left_fork);

        // take right fork
        pthread_mutex_lock(&forks[right_fork]);
        printf("Philosopher %d has taken fork %d.\n", id, right_fork);

        // eat for a random amount of time
        printf("Philosopher %d is eating.\n", id);
        sleep(rand() % 5);

        // release right fork
        pthread_mutex_unlock(&forks[right_fork]);
        printf("Philosopher %d has released fork %d.\n", id, right_fork);

        // release left fork
        pthread_mutex_unlock(&forks[left_fork]);
        printf("Philosopher %d has released fork %d.\n", id, left_fork);
    }
}

int main() {
    pthread_t philosophers[N];
    int ids[N];

    // initialize mutexes for forks
    for (int i = 0; i < N; i++) {
        pthread_mutex_init(&forks[i], NULL);
    }

    // create philosopher threads
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // wait for philosopher threads to finish (never happens in this case)
    for (int i = 0; i < N; i++) {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}

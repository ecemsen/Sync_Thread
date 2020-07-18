#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

sem_t a, b, c, d, e, f, g, h, i, j, k, l, m;

void* A(void* arg) {
	printf("job0 is done\n");
	sleep(2);
	sem_post(&a);
	sem_post(&b);
	sem_post(&h);
}
void* B(void* arg) {
	printf("job1 waiting for job0 \n");
	sem_wait(&b);
	printf("Job1 is done\n");
	sleep(2);
	sem_post(&c);
	sem_post(&d);
	sem_post(&f);
}
void* C(void* arg) {
	printf("job2 is done\n");
	sleep(2);
	sem_post(&g);
	sem_post(&j);
	sem_post(&i);

}
void* D(void* arg) {
	printf("job3 waiting for job0 and job1\n");
	sem_wait(&a);
	sem_wait(&c);
	printf("job3 is done\n");
	sleep(2);
	sem_post(&e);
}
void* E(void* arg) {
	printf("job4 waiting for job0 and job2\n");
	sem_wait(&i);
	sem_wait(&h);
	printf("job4 is done\n");
	sleep(2);
	sem_post(&l);

}
void* F(void* arg) {
	printf("job5 waiting for job1 and job2\n");
	sem_wait(&d);
	sem_wait(&g);
	printf("job5 is done\n");
	sleep(2);
	sem_post(&k);
}
void* G(void* arg) {
	printf("job6 waiting for job1,job2 and job5\n");
	sem_wait(&k);
	sem_wait(&f);
	sem_wait(&j);
	printf("job6 is done\n");
	sleep(2);
}
void* H(void* arg) {
	printf("job7 waiting for job3\n");
	sem_wait(&e);
	printf("job7 is done\n");
	sleep(2);
}

void* I(void* arg) {
	printf("job8 waiting for job4\n");
	sem_wait(&l);
	printf("job8 is done\n");
	sleep(2);
	sem_post(&m);
}

void* J(void* arg) {
	printf("job9 waiting for job8\n");
	sem_wait(&m);
	printf("job9 is done\n");
	sleep(2);
}


int main(int argc, char const* argv[]) {

	pthread_t a0, b1, c2, d3, e4, f5, g6, h7, i8, j9;
	void* thread_result;

	sem_init(&a, 0, 0);
	sem_init(&b, 0, 0);
	sem_init(&c, 0, 0);
	sem_init(&d, 0, 0);
	sem_init(&e, 0, 0);
	sem_init(&f, 0, 0);
	sem_init(&g, 0, 0);
	sem_init(&h, 0, 0);
	sem_init(&i, 0, 0);
	sem_init(&j, 0, 0);
	sem_init(&k, 0, 0);
	sem_init(&l, 0, 0);
	sem_init(&m, 0, 0);


	pthread_create(&a0, NULL, A, NULL);
	pthread_create(&b1, NULL, B, NULL);
	pthread_create(&c2, NULL, C, NULL);
	pthread_create(&d3, NULL, D, NULL);
	pthread_create(&e4, NULL, E, NULL);
	pthread_create(&f5, NULL, F, NULL);
	pthread_create(&g6, NULL, G, NULL);
	pthread_create(&h7, NULL, H, NULL);
	pthread_create(&i8, NULL, I, NULL);
	pthread_create(&j9, NULL, J, NULL);


	pthread_join(a0, &thread_result);
	pthread_join(b1, &thread_result);
	pthread_join(c2, &thread_result);
	pthread_join(d3, &thread_result);
	pthread_join(e4, &thread_result);
	pthread_join(f5, &thread_result);
	pthread_join(g6, &thread_result);
	pthread_join(h7, &thread_result);
	pthread_join(i8, &thread_result);
	pthread_join(j9, &thread_result);


	sem_destroy(&a);
	sem_destroy(&b);
	sem_destroy(&c);
	sem_destroy(&d);
	sem_destroy(&e);
	sem_destroy(&f);
	sem_destroy(&g);
	sem_destroy(&h);
	sem_destroy(&i);
	sem_destroy(&j);
	sem_destroy(&k);
	sem_destroy(&l);
	sem_destroy(&m);


	return 0;
}
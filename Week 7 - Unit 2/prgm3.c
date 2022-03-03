// program to demonstrate semaphores
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>

sem_t mutex;   //semaphore name
void *my_thread1(void *args)
{
	char s[]="abcdef";
	int l=strlen(s);
	
	for(int i=0;i<l;i++)
	{
		sem_wait(&mutex);
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
		
		//signal
		sem_post(&mutex);
	}

}

void *my_thread2(void *args)
{
	char s[]="ABCDEF";	
	int l=strlen(s);
	
	for(int i=0;i<l;i++)
	{
		sem_wait(&mutex);
		putchar(s[i]);
		fflush(stdout);
		sleep(2);
		
		//signal
		sem_post(&mutex);
	}

}

int main()
{
	pthread_t t1,t2;
	sem_init(&mutex,0,1);		//0 means resources can't be shared  ->only threads present inside the process can access the resource
	pthread_create(&t1,NULL,my_thread1,NULL);
	sleep(2);
	pthread_create(&t2,NULL,my_thread2,NULL);
	pthread_join(t1,NULL);      //main thread t1 shd finish it's execution    (NULL-> how much time it has to wait)
	pthread_join(t2,NULL);
	//sem_destroy(&mutex);
	return 0;
}

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<string.h>
//to see which variables can a thread modify, local, global, static 
int g=0;
void *test(void *arg){

	int *id=(int*)arg;
	static int s=0;
	int l=0;
	++l;
	++s;
	++g;
	printf("Thread id: %d,local:%d,static:%d,Global:%d",*id,l,s,g);
}

int main()
{
	pthread_t tid;
	for(int i=0;i<3;i++){
		pthread_create(&tid,NULL,test,(void*)&tid);
		pthread_join(tid,NULL); //parent thread has to wait until child threads finish its execution.
		printf("\n");
	}
	return 0;

}

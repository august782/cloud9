#include <klee/klee.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void klee_make_symbolic(void *addr, size_t nbytes, const char *name) __attribute__((weak));
void klee_assume(uintptr_t condition) __attribute__((weak));


int val=0;

void *func(void* threadid){
  unsigned seconds;
  klee_make_symbolic(&seconds, sizeof(int), "seconds");
  klee_assume(seconds>0 & seconds<=5);

  switch (seconds) {
  case 1: sleep(1);
    break;
  case 2: sleep(2) ;
    break;
  case 3: sleep(3) ;
    break;
  case 4: sleep(4) ;
    break;
  case 5: sleep(5) ;
    break;
  default: break;
  }

  //  sleep(seconds);
  val=5;
  pthread_exit(NULL);
}

void test_func(){
  pthread_t thread;
  int id=1;
  time_t start, stop;
  time(&start);
  pthread_create(&thread, NULL, func, (void *)id);
  pthread_join(thread, NULL);
  time(&stop);
  //wait for func to change the value
  double diff=difftime(stop, start);
  assert(diff<4);
  //  sleep(20);
  //assert that value was changed to 5
  assert(val==5);
}

int main(int argc, char **argv) {
  test_func();
}

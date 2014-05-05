#include <klee/klee.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void klee_make_symbolic(void *addr, size_t nbytes, const char *name) __attribute__((weak));
void klee_assume(uintptr_t condition) __attribute__((weak));

int getRandom(int low, int high){
  int random;
  klee_make_symbolic(&random, sizeof(int), "random");
  klee_assume(random>=low & random<=high);
  
  return random;
}

void test_random(){
  int random = getRandom(0,5);
  assert(random!=0);
}

int main(int argc, char **argv) {
  test_random();
}

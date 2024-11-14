#include <stdio.h>
#include <unistd.h>

int main()
{
  int i;
  printf("hello\n");
  // // int f = fork(); // 2 processes, the code below will be duplicate
  // printf("%d\n", f); 

  // if (f < 0) { // this will not be run, therefore it is irrelevant
  //   printf("%d\n", f); 
  //   fork();
  // }
  
  for (i = 0; i <= 1; i++) { // this will run 3 times
    int k = fork();
    // printf("%d\n", f + i);
    
    if (k == 0) {
      fork();
      printf("ha\n");  
    } // if the process is a child, create one more child => 
    else {
      printf("hi\n");
      printf("ho\n");
    }
  }

  printf("hi\n");

  return 0;
}
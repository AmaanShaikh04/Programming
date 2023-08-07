#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main ()
{
pid_t x;
x = fork ();
if (x > 0) {
printf("Parent process id is %d\n",getpid());
}
else {
printf("The current process id of the Parent is %d\n",getppid()); //Original Parent id sleep(2); // Orphan Process
printf("The new process id of the Parent is %d\n",getppid()); // Parent id after new parent is assigned.
}
return 0;
}

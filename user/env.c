#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"


void
print(const char *s)
{
  write(1, s, strlen(s));
}

int main(int argc, char *argv[])
{
  int waits = 10;
  int time = get_time();
  int pid = fork();
  int j = 0;
  while(j < 1000)
  {
    j++;
    print("jlopp\n");
  }
  get_time();
  if(pid != 0)
  {
    wait(&pid);
    for(int i = 0; i< 4;i++){
      int i = 0;
      while(i < 10000)
     {
        i++;
        if(i % 2 == 0)
         i = (i * 2 / 2);
     }
      print("im main going to sleep\n");
      print("\n");
      sleep(3);
      while(time + waits > get_time());
      print("im awake, im awake\n");
      print_proc(0);
    }
    
    print_proc(1);
    exit(0);
  }
  else
  {
    for(int i = 0; i< 4;i++){
      print("im the son "); print(" going to sleep now\n");
      print("\n");
      int i = 0;
      while(i < 10000)
      {
        i++;
        if(i % 2 == 0)
         i = (i * 2 / 2);
     }
      sleep(2);
      while(time + waits*2 > get_time());
      print("sunshine lollipops and rainbows\n");
      print_proc(0);
    }
  }
exit(0);
}
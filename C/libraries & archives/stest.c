
 #include<stdio.h>
#include<dlfcn.h>

typedef int (* print_func) (int a);

print_func print;
int main ()
{
  void *lib_handle = NULL;
  int a = 1;
  lib_handle = (void *)dlopen("./slib.so", RTLD_LAZY); 
  if(lib_handle) 
  {
    printf("dlopen returns %p\n", lib_handle);
    print = dlsym(lib_handle, "Foo");
    if(print)
    {
      printf("dlsym returns print = %p\n", print);
      print(a);
    }
    else
    {
      printf("Function entry not found in DLL");
    }
    dlclose(lib_handle);
  }
  else
  {
    printf("Unable to open DLL");
  }
} 

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <signal.h>
#include <error.h>

void error_quit( const char *str )
{
    fprintf(stderr,"%s\n",str);
    exit(1);
}

int main()
{
    void *plib;
    typedef void (*FUN_HELLO)();
    typedef int(*FUN_ADD)(int,int);
    FUN_HELLO funHello = NULL;
    FUN_ADD funAdd = NULL;

    // open the so file
    plib = dlopen("./libtest.so",RTLD_NOW | RTLD_GLOBAL);
    if(NULL==plib)
        error_quit("open so error");
    funHello = dlsym(plib,"PrintHello");
    funAdd = dlsym(plib ,"Add");
    if(NULL == funAdd || NULL == funHello)
        error_quit("load function error");

    funHello();
    printf("1+1 = %d\n",funAdd(1,1));
    dlclose(plib);
    return 0;
}

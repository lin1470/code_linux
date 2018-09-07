#include <stdio.h>
#include <pwd.h>
#include <string.h>

int main()
{

    struct passwd *ptr = NULL;
    setpwent();
    while((ptr = getpwent()) != NULL)
    {
        printf("current user in the passwd is %s\n",ptr->pw_name);
    }
    endpwent();
    printf("Hello world\n");
    return 0;
}


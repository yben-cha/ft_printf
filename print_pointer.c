#include<unistd.h>
void    print_pointer(void *p)
{
        char    *s;
        s=(char *)p;
        if(!s)
        {
                write(1,"(null)",6);
                return ;
        }
        long n=(long)s;
        write(1,"0x",2);
        print_hex_low(n);
}

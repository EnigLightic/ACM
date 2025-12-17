#include <stdio.h>
#include <string.h>

int Hash(const char *Key,int sz) {
    unsigned int H=0;  
    while(*Key!='\0') {
        H=(H<<5)+(*Key++-'a');
    }
    return H%sz;
}

int main() {
    char s[15];
    int m;
    scanf("%s %d",s,&m);
    printf("%d\n",Hash(s,m));
    return 0;
}

#include <stdio.h> 
#include <string.h> 
int main(){
    char a[100],c[200];
    int i=0,k=0;
    printf("Enter the string: "); 
    scanf("%s",a);
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='D' && a[i+1] == 'L' && a[i+2] == 'E'){  
            c[k++] = 'D';
            c[k++] = 'L';
            c[k++] = 'E';
            c[k++] = 'D';
            i += 2;
        }
        else{ 
            c[k++] = a[i];
        }
    }
    c[k] = '\0';
    printf("DLESTX%sDLEETX\n",c);
    return 0;
}
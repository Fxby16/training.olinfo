/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * This template uses "old style" C strings.
 * If you are more comfortable using the String class in C++, please
 * look at the template specific for C++.
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

// constraints
#define MAXN 100
#define MAXL 1000
#define MAXC 100

// input data
int N, i;
char contacts[MAXN][MAXL+1];  // +1 is for string terminator
char contactssol[MAXN][MAXL+1];  // +1 is for string terminator
char codes[10][MAXC+1];  // +1 is for string terminator

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
int k,pos=0;
    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%s", contacts[i]));
    for(i=0; i<10; i++)
        assert(1 == scanf("%s", codes[i]));

    char *p,*p2,*end;
    for(i=0;i<N;i++)
    {
        k=0;
        p=&contacts[i][0];
        end=p+strlen(contacts[i]);
        while(p<end)
        {
            if((strstr(p,codes[k]))==p)
            {
                p+=strlen(codes[k]);
                contactssol[i][pos]=k+'0';
                k=0;
                pos++;
            }
            else
            {
                k++;
            }
        }
        contactssol[i][pos]='\0';
        pos=0;
    }
    for(i=0;i<N;i++)
        printf("%s\n",contactssol[i]);
   
    return 0;
}
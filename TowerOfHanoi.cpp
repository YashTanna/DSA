#include<iostream>
#include<string>
using namespace std;

static int count = 0;

void hanoi(int n,char source,char destination,char auxiliary)
{
    if(n!=1)
    {
        hanoi(n-1,source,auxiliary,destination);

    }
    count++;
    printf("%d : %c -> %c\n",count,source,destination);
    if(n!=1)
    {
        hanoi(n-1,auxiliary,destination,source);

    }
}

main()
{
    hanoi(3,'A','C','B');
    return 0;
}
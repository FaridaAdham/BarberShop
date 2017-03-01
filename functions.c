#include"functions.h"

void sortarray(int a[], int size)
{
    int i,j,c;
    for (i=0; i<(size-1); ++i)
    {
        for (j=0; j<size-1-i; ++j )
        {
            if (a[j]>a[j+1])
            {
                c=a[j+1];
                a[j+1]=a[j];
                a[j]=c;
            }
        }
    }
}

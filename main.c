#include <stdio.h>
#include <stdlib.h>
#include"queue.h"

int main()
{
    system("COLOR 4f");
    int nc,st,bwt,cd,r,rnum,i,x,y,z,sw,ot,bf,op,cl,whm;
    float cawt,open,close,ope,clo,wh;
    queue at;
    printf("\n\t\t Welcome To The Barber's Customers Co-Simulation ^_^");
    printf("\n\t\t*****************************************************");
    printf("\n\t      ---------------------------------------------------------");
    printf("\n\n Please Enter The Open Time Of The Barber *(A.M)* : ");
    scanf("%f",&open);
    printf("\n Please Enter The Close Time Of The Barber *(P.M)* : ");
    scanf("%f",&close);
    printf("\n Please Enter Number Of Customers Per Hour : ");
    scanf("%d",&nc);
    printf("\n Please Enter The Service Time Of Each Customer(In Minutes) : ");
    scanf("%d",&st);
    op=open;
    cl=close;
    ope=open-(op*1.0);
    clo=close-(cl*1.0);
    whm=(((cl*60)+(clo*100))+720)-((op*60)+(ope*100));
    wh=(whm*1.0)/60;
    r=whm;
    cd=wh*nc;
    initialize(&at,cd);
    int old= -1;
    while(!isfull(&at))
    {
        rnum=rand()%r;
        if(rnum!=old)
        {
            enqueue(&at,rnum);
            old=rnum;
        }
    }
    int a[cd];
    for(i=0; i<cd; i++)
    {
        a[i]=dequeue(&at);
    }
    sortarray(a,cd);
    i=0;
    while(!isfull(&at))
    {
        x=a[i];
        enqueue(&at,x);
        i++;
    }

    int w[cd],f[cd],bw[cd];
    y=dequeue(&at);
    bw[0]=y;
    f[0]=y+st;
    w[0]=0;
    z=gethead(&at);
    if(f[0]>=z)
    {
        w[1]=f[0]-z;
        bw[1]=0;
    }
    else if(f[0]<z)
    {
        bw[1]=z-f[0];
        w[1]=0;
    }
    for(i=0; i<cd; i++)
    {
        y=dequeue(&at);
        if(f[i]>=y)
        {
            w[i+1]=f[i]-y;
            bw[i+1]=0;
        }
        else if(f[i]<y)
        {
            bw[i+1]=y-f[i];
            w[i+1]=0;
        }
        f[i+1]=y+w[i+1]+st;
    }

    sw=bwt=0;
    for(i=0; i<cd; i++)
    {
        sw=sw+w[i];
        bwt=bwt+bw[i];
    }
    cawt=sw/(cd*1.0);
    if(r>f[cd-1])
        bf=r-f[cd-1];
    ot=f[cd-1]-r;
    printf("\n Detailed Co-Simulation:-");
    printf("\n==========================\n");
    printf("\n-->The Number Of Customers Today : %d ",cd);
    printf("\n++++++++++++++++++++++++++++++++++++++\n");
    for(i=0; i<cd; i++)
    {
        if(w[i]==0)
            printf("\n Customer Number : %d\n Arrived After %d Minutes.\n finished after %d Minutes.\n Hasn't Waited.",i+1,a[i],f[i]);
        else
            printf("\n Customer Number : %d\n Arrived After %d Minutes.\n Finished After %d Minutes.\n Waited For %d Minutes.",i+1,a[i],f[i],w[i]);
        printf("\n______________________________________\n");
    }
    printf("\n-->The Total Time The Barber Will Wait Is %d Minutes.\n",bwt);
    printf("\n-->The Total Time All The Customers Will Wait Is %d Minutes.\n",sw);
    printf("\n-->The Customers Average Waiting Time Is %.3f Minutes.\n",cawt);
    if(ot<0)
        printf("\n-->The Barber Will Finish His Work Before The Close Time By %d Minutes.\n",bf);
    else if (ot==0)
        printf("\n-->The Barber Will Finish His Work Exactly At The Close Time.\n");
    else
        printf("\n-->The Barber Will Work For %d Minutes As An Over Time.\n",ot);
    printf("\n\t\t //** Thanks For Using Our Program **\\\\ ^_^");
    printf("\n\t\t********************************************");
    printf("\n\t      -----------------------------------------------");
}

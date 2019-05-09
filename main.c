#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int b[30];int c[4][10];float a[40];int count1=4;
void genran()
{
    int b;
    float r;
    for(b=0;b<40;b++)
    {
        r = (float)rand()/RAND_MAX;
        a[b]=r;

    }


}

void genran1()
{
    int i;
    for(i=0;i<30;i++)
   {
    b[i]=rand()%631;
    while(b[i]==0)
    b[i]=rand()%631;
   }

   for(i=0;i<30;i++)
   printf("%d\t",b[i]);

   printf("\n");


}


void start()
{
int i,j,temp[4];

for(i=0;i<4;i++)
  temp[i]=b[i];

for(i=0;i<4;i++)
{
    for(j=9;j>=0;j--)
    {
        c[i][j]=temp[i]%2;
        temp[i]=temp[i]/2;
    }
}
 for(i=0;i<4;i++)
    {
    for(j=0;j<10;j++)
    printf("%d",c[i][j]);
    printf("\n");
    }
    convert();

}



void convert()
{
    int sum[4],i,j,k;
    float l;
    float sum1[4]={0,0,0,0};


    for(i=0;i<4;i++)
    sum[i]=0;

    for(i=0;i<4;i++)
    {
    k=0;
    for(j=9;j>=0;j--)
    {
     l=pow(2,k);
     sum[i]+=c[i][j]*l;
     k++;
    }

    }

    for(i=0;i<4;i++)
    {
       sum1[i]=(float)sum[i]/100;
        printf("%f\n",sum1[i]);
    }
    calc(sum1);

}
void calc(float x[])
{
int i=0;
float y[4];
 for(i=0;i<4;i++)
 {
     y[i]=62.83*(2*x[i]+(0.91*pow(x[i],-0.2)));
     printf("%f\n",y[i]);
 }

 sorting(y);

}

void sorting(float x[])
{
  float a; int pos1,pos2,i,j,k,temp1;
  for (i = 0; i < 4; i++)
  {
  for (j = i + 1; j < 4; j++)
  {
  if (x[i] > x[j])
  {
  pos1=i;
  pos2=j;
  a =  x[i];
  x[i] = x[j];
  x[j] = a;
  for(k=0;k<10;k++)
  {
      temp1=c[pos1][k];
      c[pos1][k]=c[pos2][k];
      c[pos2][k]=temp1;
  }


  }
  }
  }

   for(i=0;i<4;i++)
    {
    for(j=0;j<10;j++)
    printf("%d",c[i][j]);
    printf("\n");
    }
    take();
    mating();
}

void take()
{
    int sum[4],i,j,k,temp=0,ct=0,ct1=0,ct2=0;
    float l;
    float sum1[4]={0,0,0,0};

    for(i=0;i<4;i++)
    sum[i]=0;

    for(i=0;i<4;i++)
    {
    k=0;
    for(j=9;j>=0;j--)
    {
     l=pow(2,k);
     sum[i]+=c[i][j]*l;
     k++;
    }
    }
     for(j=9;j>=0;j--)
    {
        c[3][j]=b[count1]%2;
        b[count1]=b[count1]/2;
    }
    count1++;
    if(count1==40)
    {
        genran1();
        count1=4;
    }
     k=0;
     for(j=9;j>=0;j--)
    {
     l=pow(2,k);
     temp+=c[3][j]*l;
     k++;
    }
    sum[3]=temp;

    if(temp==sum[0])
    ct++;
     if(temp==sum[1])
    ct1++;
    if(temp==sum[2])
    ct2++;

    while(ct==1||ct1==1||ct2==1)
    {

    for(j=9;j>=0;j--)
    {
        c[3][j]=b[count1]%2;
        b[count1]=b[count1]/2;
    }
     count1++;
      if(count1==40)
    {
        genran1();
        count1=4;
    }
     k=0;temp=0;
     for(j=9;j>=0;j--)
    {
     l=pow(2,k);
     temp+=c[3][j]*l;
     k++;
    }
    sum[3]=temp;
    ct=0;ct1=0;ct2=0;

    if(temp==sum[0])
    ct++;
     if(temp==sum[1])
    ct1++;
    if(temp==sum[2])
    ct2++;

    }

    for(i=0;i<4;i++)
    {
    for(j=0;j<10;j++)
    printf("%d",c[i][j]);
    printf("\n");
    }

    for(i=0;i<4;i++)
    printf("%d\n",sum[i]);

    for(i=0;i<4;i++)
    {
       sum1[i]=(float)sum[i]/100;
        printf("%f\n",sum1[i]);
    }

  float y[4];

 for(i=0;i<4;i++)
 {
     y[i]=62.83*(2*sum1[i]+(0.91*pow(sum1[i],-0.2)));
     printf("%f\n",y[i]);
 }



}

void mating()
{
   int i,j,temp2[4][10];int ct1=0;

   for(i=0;i<2;i++)
    for(j=0;j<10;j++)
   temp2[i][j]=c[1][j];

   for(j=0;j<10;j++)
    temp2[2][j]=c[2][j];

    for(j=0;j<10;j++)
    temp2[3][j]=c[3][j];


     for(i=0;i<4;i++)
    {
    for(j=0;j<10;j++)
    printf("%d",temp2[i][j]);
    printf("\n");
    }
  crossover(temp2);

}
void crossover(int x[][10])
{
 int ran[2],i,j,ran2,pos1,pos2,temp3,ct=0,ct1=0,ct2=0,ct3=0,temp2[4][10];
 for(i=0;i<2;i++)
 {
  ran[i]=rand()%10;
 if(ran[i]==0)
 while(ran[i]==0)
 ran[i]=rand()%10;

 }

 ran2=rand()%2;
 if(ran2==0)
 {
  pos1=2;
  pos2=3;
  }
 else
 {
  pos1=3;
  pos2=2;
 }
printf("mate of element 1 is %d\t mate of element 2 is %d\n",pos1+1,pos2+1);

for(i=ran[0];i<10;i++)
 {
  temp3 =  x[0][i];
  x[0][i] = x[pos1][i];
  x[pos1][i] = temp3;
 }
  for(i=ran[1];i<10;i++)
 {
  temp3 =  x[1][i];
  x[1][i] = x[pos2][i];
  x[pos2][i] = temp3;
 }

 for(j=0;j<10;j++)
 {
     if(x[0][j]==0)
        ct++;
     if(x[pos1][j]==0)
        ct1++;
 }

 while(ct==10||ct1==10)
 {
 ran[0]=rand()%10;
 if(ran[0]==0)
 while(ran[0]==0)
 ran[0]=rand()%10;

 for(i=ran[0];i<10;i++)
 {
  temp3 =  x[0][i];
  x[0][i] = x[pos1][i];
  x[pos1][i] = temp3;
 }
 ct=0;ct1=0;

 for(j=0;j<10;j++)
 {
     if(x[0][j]==0)
        ct++;
     if(x[pos1][j]==0)
        ct1++;
 }

 }

  for(j=0;j<10;j++)
 {
     if(x[1][j]==0)
        ct2++;
     if(x[pos2][j]==0)
        ct3++;
 }

 while(ct2==10||ct3==10)
 {
 ran[1]=rand()%10;
 if(ran[1]==0)
 while(ran[1]==0)
 ran[1]=rand()%10;

 for(i=ran[1];i<10;i++)
 {
  temp3 =  x[1][i];
  x[1][i] = x[pos2][i];
  x[pos2][i] = temp3;
 }
ct2=0;ct3=0;

 for(j=0;j<10;j++)
 {
     if(x[1][j]==0)
        ct2++;
     if(x[pos1][j]==0)
        ct3++;
 }

 }

 for(i=0;i<2;i++)
 {
  printf("crossoversite for element %d is %d \n",i+1,ran[i]);
 }

   for(j=0;j<10;j++)
    temp2[0][j]=c[0][j];

    for(i=1;i<4;i++)
    for(j=0;j<10;j++)
    temp2[i][j]=x[i-1][j];

     for(i=0;i<4;i++)
    {
    for(j=0;j<10;j++)
    printf("%d",temp2[i][j]);
    printf("\n");
    }

    for(i=0;i<4;i++)
    for(j=0;j<10;j++)
    c[i][j]=temp2[i][j];

    stop();
    convert();

}


void stop()
{
    int i,j,k=0,l,m;
    int sum=0;float sum1,sum2;
    for(j=0;j<10;j++)
    {
        if(c[0][j]==c[1][j])
        k++;
        if(c[1][j]==c[2][j])
        k++;
        if(c[2][j]==c[3][j])
        k++;

    }
    if(k==30)
    {
        m=0;
        for(i=9;i>=0;i--)
        {
            l=pow(2,m);
            sum+=c[0][i]*l;
            m++;
        }
        sum1=(float)sum/100;

     sum2=62.83*(2*sum1+(0.91*pow(sum1,-0.2)));
     for(i=0;i<10;i++)
     {
         printf("%d",c[0][i]);
     }
     printf("\n");
     printf("%f\n",sum1);
     printf("%f\n",sum2);

     exit(0);

    }
}


int main()
{
 srand(time(0));
 char ch;
printf("do u want to generate y?");
scanf("%c",&ch);
    if(ch=='y')
    genran1();
    start();
    getch();
    return(0);
}


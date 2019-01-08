#include<stdio.h>

void main()

{

  char s[100],key[100];

  int i,j;
  
  printf("enter the text");

  scanf("%s",s);

  printf("%s\n",s);

  int a[4][4];

  int k=0;

  for(i=0;i<4;i++)

  {

   for(j=0;j<4;j++)

   {

    a[j][i]=s[k];
     k++;

   }

  }

   for(i=0;i<4;i++)

  {

    for(j=0;j<4;j++)

    {

     printf("%d\t",a[i][j]);

    }
 
     printf("\n");

  }

  
  printf("enter the text");

  scanf("%s",key);

  printf("%s\n",key);

  int b[4][4];

  int c=0;

  for(i=0;i<4;i++)

  {

   for(j=0;j<4;j++)

   {

    b[j][i]=key[c];
     c++;

   }

  }

   for(i=0;i<4;i++)

  {

    for(j=0;j<4;j++)

    {

     printf("%d\t",b[i][j]);

    }
 
     printf("\n");

  }


 int r[4][4];

 for(i=0;i<4;i++)

 {

  for(j=0;j<4;j++)

  {

   r[i][j]=(a[i][j])^(b[i][j]);

  }

 }

 printf("\n");

 printf("\n");


 for(i=0;i<4;i++)

  {

    for(j=0;j<4;j++)

    {

     printf("%d\t",r[i][j]);

    }
 
     printf("\n");

  }


}

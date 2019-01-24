#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
int main()
{
    int i,j,m=0,n=0,l,k,a[16]={0},b[16]={0};

    char text[100]="Two One Nine Two",am[6][6]={0},key[20]="Thats my Kung Fu",km[6][6]={0},x[6][6]={0};

   

    l=strlen(text);

    k=strlen(key);
  
    for(i=0;i<l;i++)
    {
       a[i]=text[i];
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)

        {

            am[j][i]=a[m];

            m++;

        }

    }
   
    for(i=0;i<k;i++)

    {

        b[i]=key[i];

    }

     for(i=0;i<4;i++)

    {

        for(j=0;j<4;j++)

        {

            km[j][i]=b[n];

            n++;

        }
    }
    

    

   struct timeval  tv1, tv2;
   gettimeofday(&tv1, NULL);
     
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            x[i][j]=(am[i][j])^(km[i][j]);
        }
    }

   gettimeofday(&tv2, NULL);

   

    printf ("Total time = %f seconds\n",
         (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
         (double) (tv2.tv_sec - tv1.tv_sec));
   

    printf("result of add round key is \n");
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("  %02X\t",x[i][j]);
        }
        printf("\n");
    }







    //subBytes

    

    char sp[16][16]=  {0x63,0X7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16};
        
    int su,y,y1,y2,op1[4][4],e;
    
    struct timeval  tv3, tv4;

    gettimeofday(&tv3, NULL);


    for(i=0;i<4;i++)
                {
                for(j=0;j<4;j++,e++)
                        {
                        su=x[i][j];
			y=su%16;
			su=su/16;
			y1=y;
			y2=su%16;
		
			op1[i][j]=(sp[y2][y1]&0xff);
                        }
                }

    gettimeofday(&tv4, NULL);

printf ("Total time = %f seconds\n",
         (double) (tv4.tv_usec - tv3.tv_usec) / 1000000 +
         (double) (tv4.tv_sec - tv3.tv_sec));

  

   printf("\nThe subBYte matrix is in HexaDecimal:\n");
   
   for(i=0;i<4;i++)
  
   { 
            
     for(j=0;j<4;j++,e++)

                        
     {

          printf("%02X\t",op1[i][j]&0xff);

      }

          printf("\n");

           
  }

  //ShiftRows

   

   int c[4][4];

   k=0;

  struct timeval  tv5, tv6;
  gettimeofday(&tv5, NULL);

   for(j=0;j<4;j++)

   {  
     i=0;

     c[i][j]=op1[i][j];

   }

   for(j=0;j<4;j++)

   {

    i=1;

    if(j!=3)    
 
     c[i][j]=op1[i][j+1];

    
    if(j==3)

     {
      c[i][j]=op1[i][j-3];
      continue;

     }
    

   
   }

   for(j=0;j<4;j++)

   {

    i=2;

    if(j<2)

    c[i][j]=op1[i][j+2];


    if(j>=2)

    c[i][j]=op1[i][j-2];

    
   }



   c[3][0]=op1[3][3];

   for(j=1;j<4;j++)

   {

    i=3;
    
    c[i][j]=op1[i][j-1];

   }

   

    










   
   gettimeofday(&tv6, NULL);

printf ("Total time = %f seconds\n",
         (double) (tv6.tv_usec - tv5.tv_usec) / 1000000 +
         (double) (tv6.tv_sec - tv5.tv_sec));




        printf("after shifting \n");
     for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
         printf(" %02X\t ",c[i][j]&0xff);
        }
        printf("\n");
    }



 //mix column

  
   
    int g[4];

    int v[4];

    int w;

    int h;

     int r[10];

    /* The array 'a' is simply a copy of the input array 'r'

     * The array 'b' is each element of the array 'a' multiplied by 2

     * in Rijndael's Galois field

     * a[n] ^ b[n] is element n multiplied by 3 in Rijndael's Galois field */ 



struct timeval  tv7, tv8;
gettimeofday(&tv7, NULL);

  for(j=0;j<4;j++)

  {



   for(i=0;i<4;i++)

   {
      r[i]=c[i][j];

   }
    

      for (w= 0; w < 4; w++) {

        g[w] = r[w];

        /* h is 0xff if the high bit of r[c] is set, 0 otherwise */

        h = (r[y] >> 7); /* arithmetic right shift, thus shifting in either zeros or ones */

        v[w] = r[w] << 1; /* implicitly removes high bit because b[c] is an 8-bit char, so we xor by 0x1b and not 0x11b in the next line */

        v[w] ^= 0x1B & h; /* Rijndael's Galois field */

    }

    r[0] = v[0] ^ g[3] ^ g[2] ^ (v[1] ^ g[1]); /* 2 * a0 + a3 + a2 + 3 * a1 */

    r[1] = v[1] ^ g[0] ^g[3] ^ (v[2] ^ g[2]); /* 2 * a1 + a0 + a3 + 3 * a2 */

    r[2] = v[2] ^ g[1] ^ g[0] ^ (v[3] ^ g[3]); /* 2 * a2 + a1 + a0 + 3 * a3 */

    r[3] = v[3] ^ g[2] ^ g[1] ^( v[0] ^ g[0]); /* 2 * a3 + a2 + a1 + 3 * a0 */


    for(i=0;i<4;i++)

     c[i][j]=r[i];

 

 }
gettimeofday(&tv8, NULL);

printf ("Total time = %f seconds\n",
         (double) (tv8.tv_usec - tv7.tv_usec) / 1000000 +
         (double) (tv8.tv_sec - tv7.tv_sec));


printf("after mix column\n");

   for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
         printf(" %02X\t ",c[i][j]&0xff);
        }
        printf("\n");
    }























}

  

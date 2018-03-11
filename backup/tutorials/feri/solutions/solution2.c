#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define for_x for (int x = 0; x < w; x++)
#define for_y for (int y = 0; y < h; y++)
#define for_xy for_x for_y
void show(int u[], int w, int h)
{
   int x,y;
   printf("\033[H");
   for (y=0; y<h; ++y){
     for (x=0; x<w; ++x){
       printf(u[y+x*h] ? "\033[107m\033[34m8\033[m" :" ");//"\033[07m  \033[m" : "  ");
     }
     printf("\033[E");
   }
   fflush(stdout);
}
void evolve(int u[], int w, int h)
{
   unsigned new[h*w];
   int x,y;
   for (y=0; y<h; ++y)
     for (x=0; x<w; ++x){
       int n = 0;
/*     for (int y1 = y - 1; y1 <= y + 1; y1++)
         for (int x1 = x - 1; x1 <= x + 1; x1++)
           if (u[(y1 + h) % h + ((x1 + w) % w)*h])
             n++;
       if (u[x*h+y]) n--;
*/
       if (u[(y-1+h)%h+((x+0+w)%w)*h])
         n++;
       if (u[(y-1+h)%h+((x-1+w)%w)*h])
         n++;
       if (u[(y-1+h)%h+((x+1+w)%w)*h])
         n++;
       if (u[(y+0+h)%h+((x-1+w)%w)*h]) 
         n++;
       if (u[(y+0+h)%h+((x+1+w)%w)*h])
         n++;
       if (u[(y+1+h)%h+((x+0+w)%w)*h])
         n++;
       if (u[(y+1+h)%h+((x-1+w)%w)*h])
         n++;
       if (u[(y+1+h)%h+((x+1+w)%w)*h])
         n++;

       new[y+x*h] = (n == 3 || (n == 2 && u[y+x*h]));
     }
   for (x=0; x<w; x++)
     for (y=0; y<h; ++y) 
       u[y+h*x] = new[y+h*x];
}
void game(int w, int h)
{
   int x,y;
   unsigned popul[h*w];
   printf("\033[1;1H\033[2J");
   for (x=0;x<w;++x)
     for (y=0; y<h; ++y)
       popul[x*h+y] = rand() < RAND_MAX / 4 ? 1 : 0; 
   while (1) {
     show(popul, w, h);
     evolve(popul, w, h);
     usleep(200000);
   }
}
 
int main(int c, char **v)
{
   int w = 0, h = 0;
   if (c > 1) w = atoi(v[1]);
   if (c > 2) h = atoi(v[2]);
   if (w <= 0) w = 30;
   if (h <= 0) h = 30;
   game(w, h);
}

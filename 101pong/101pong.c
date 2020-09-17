/*
** 101pong.c for 101pong in /home/bourhi_a/rendu/math/101pong
** 
** Made by 
** Login   <bourhi_a@epitech.net>
** 
** Started on  Sun Nov 17 03:54:52 2013 
** Last update Tue Nov 19 17:18:59 2013 
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "include.h"
#define pi 3.14159265

float		grad_to_degree(float f)
{
  return ((/* 90 -  */(f * 180 / pi)) * -1 );
}

int		put_incidence_angle(int sv[3])
{
  int		i;

  i = (sv[0] * sv[0] + sv[1] * sv[1] + sv[2] * sv[2]);
  printf("L’angle d’incidence est de ");
  printf("%0.2f", grad_to_degree(acos(-1/sqrt(i))));
  printf(" degrés.\n");
}

int		put_instant_n(int speed_vector[3], int array[7])
{
  my_putstr("A l’instant t+");
  my_put_nbr(array[6]);
  my_putstr(", les coordonnées de la balle seront (");
  my_put_nbr(array[0] + (array[6] + 1) * speed_vector[0]);
  my_putchar(';');
  my_put_nbr(array[1] + (array[6] + 1) * speed_vector[1]);
  my_putchar(';');
  my_put_nbr(array[2] + (array[6] + 1) * speed_vector[2]);
  my_putstr(")\n");
  put_incidence_angle(speed_vector);

}

int		put_speed_vector(int array[7])
{
  int		*speed_vector;

  speed_vector = malloc(sizeof(int) * 4);
  speed_vector[0] = array[3] - array[0];
  speed_vector[1] = array[4] - array[1];
  speed_vector[2] = array[5] - array[2];
  speed_vector[3] = '\0';
  my_putstr("Les coordonnées du vecteur vitesse sont (");
  my_put_nbr(speed_vector[0]);
  my_putchar(';');
  my_put_nbr(speed_vector[1]);
  my_putchar(';');
  my_put_nbr(speed_vector[2]);
  my_putstr(")\n");
  put_instant_n(speed_vector, array);
  return (0);
}

int		main(int ac, char **av)
{
  int		array[7];
  int		i;
  int		normal[3];
  int		sv[3];
  
  if (ac != 8)
    my_putstr("usage: ./101pong Xa Ya Za Xb Yb Zb n\n");
  else
    {
      while (i < 7)
      	{
      	  array[i] = my_getnbr(av[i + 1]);
      	  i++;
      	}
      put_speed_vector(array);
    }
  return (0);
}

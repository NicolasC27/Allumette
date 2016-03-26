/*
** my_rand.c for my_rand.c in /home/cheval_8/test/CPE_2015_Allum1/bonus
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Feb 21 14:44:50 2016 Chevalier Nicolas
** Last update Sun Feb 21 14:45:09 2016 Chevalier Nicolas
*/

#include "lib.h"

int		my_rand(int rand_max)
{
  srand(time(NULL));
  return (1 + (rand()  % rand_max));
}

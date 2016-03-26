/*
** choose.c for choose.c in /home/cheval_8/test/CPE_2015_Allum1
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Feb 21 01:25:57 2016 Chevalier Nicolas
** Last update Sun Feb 21 22:16:13 2016 Chevalier Nicolas
*/

#include	"allum.h"

int		read_options(int max, char *mode)
{
  char		*s;
  int		nb;

  nb = 0;
  if ((s = get_next_line(0)) == NULL)
    return (0);
  nb = ((s[0] == '\0') ? (1) : (my_getnbr(s)));
  if (nb <= 0 || nb == 0 || nb > max)
    return (error_allum1(mode));
  return (nb);
}

int		choose_options(t_player *player)
{
  player->a = 0;
  player->mode = 0;
  player->difficulty = 0;
  my_putstr(J_MODE);
  while ((player->mode = read_options(2, ERR_MODE)) <= 0)
    {
      if (player->mode == 0)
	return (-1);
      my_putstr(J_MODE);
    }
  if (player->mode == 1)
    {
      my_putstr(J_DIFFICULTY);
      while ((player->difficulty = read_options(3, ERR_DIFFICULTY)) <= 0)
	{
	  if (player->difficulty == 0)
	    return (-1);
	  my_putstr(J_DIFFICULTY);
	}
    }
  return (0);
}

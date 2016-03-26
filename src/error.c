/*
** error.c for error.c in /home/cheval_8/rendu/CPE_2015_Allum1
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Feb 16 20:36:50 2016 Chevalier Nicolas
** Last update Sun Feb 21 23:36:21 2016 Chevalier Nicolas
*/

#include	"allum.h"

int		error_allum1(char *str)
{
  my_putstr("Error: ");
  my_putstr(str);
  return (-1);
}

int		check_error(t_alum *list, int nb)
{
  if (nb > list->nb_matches || nb <= 0)
    return (error_allum1("\nLa ligne n'est pas correct\n"));
 if (check_line(list, nb) == -1)
    return (error_allum1("\nLa ligne est vide\n"));
  else if (nb < 0)
    return (error_allum1("\nMettez un nombre superieur a zero\n"));
  return (nb);
}

int	        init_game(t_player *player, int argc, char **argv)
{
  if (argc < 1 || argc > 2)
    return (exit_prog("USAGE: ./allum1 [matches]\n"));
  if (argv[1])
    {
      if ((player->nb_matches = my_getnbr(argv[1])) == 0)
	return (exit_prog("Error : tu dois au moins mettre une allumette(s)\n"));
      if (player->nb_matches > 100)
	return (exit_prog("Matches must be <= 100\n"));
    }
  else
    player->nb_matches = 4;
  return (0);
}

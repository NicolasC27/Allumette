/*
** main.c for main.c in /home/cheval_8/test/CPE_2015_Allum1/bonus
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Sun Feb 21 19:43:06 2016 Chevalier Nicolas
** Last update Sun Feb 21 23:40:06 2016 Chevalier Nicolas
*/

#include	"allum.h"

int		exit_prog(char *str)
{
  my_putstr(str);
  return (1);
}

int		loop_read(t_alum *list, int *line, int *matches)
{
  my_putstr(YELLOW);
  my_putstr("Quel ligne voulez vous choisir ? : ");
  my_putstr(DEFAULT);
  if (((*line) = read_line(list, -1)) <= 0)
    return ((!(*line)) ? (-1) : (0));
  my_putstr(YELLOW);
  my_putstr("Combien d'allumette voulez-vous retirer ? : ");
  my_putstr(DEFAULT);
  if (((*matches) = read_line(list, (*line))) <= 0)
    return ((!(*matches)) ? (-1) : (0));
  return (1);
}

char		check_end(t_alum *list, int cond, t_player *player)
{
  int		nb_line;

  nb_line = 0;
  count_list(list, &nb_line);
  my_putstr(GREEN);
  if (nb_line == 0 && cond == 1)
    return (exit_prog((player->mode == 1)
		      ? "\nJ'ai perdu.. snif.. mais je t'aurai la prochaine fois!!\n"
		      : "\nJoueur 2 a perdu\n"));
  if (nb_line == 0 && cond == 2)
    return (exit_prog((player->mode == 1)
		      ? "\nTu as perdu, too bad..\n"
		      : "\nJoueur 1 a perdu\n"));
  my_putstr(DEFAULT);
  return (0);
}

char		start_prog(t_alum *list, t_player *player)
{
  int		matches;
  int		line;
  int		nb;

  line = -1;
  display_matches(list);
  if (check_end(list, 1, player) != 0)
    return (0);
  my_putstr(RED);
  my_putstr("\nA toi de jouer:\n\n");
  my_putstr(DEFAULT);
  while ((nb = loop_read(list, &line, &matches)) != 1)
    if (nb == -1)
      return (0);
  display_message(line, matches, 1, player);
  display_matches(list);
  if (check_end(list, 2, player) != 0)
    return (0);
  my_putstr((player->mode == 1) ? "\nIA est entrain de jouer...\n"
	    : "\nPlayer 2 turn:\n");
  if (player->mode == 1)
    ia_level(list, player);
  if (player->mode == 2)
    while (loop_read(list, &line, &matches) == -1);
  return (1);
}

int		main(int argc, char **argv)
{
  t_alum	*list;
  t_player	player;
  int		len;

  system("clear");
  my_putstr(WELCOME);
  if (init_game(&player, argc, argv) == 1)
    return (0);
  if ((list = init_alum(player.nb_matches)) == NULL)
    return (0);
  if (choose_options(&player) == -1)
    return (0);
  while ((len = start_prog(list, &player)))
    if (len == 0)
      return (0);
  return (0);
}

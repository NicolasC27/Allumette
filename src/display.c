/*
** display.c for display.c in /home/cheval_8/rendu/CPE_2015_Allum1
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Tue Feb 16 20:17:18 2016 Chevalier Nicolas
** Last update Sun Feb 21 23:39:49 2016 Chevalier Nicolas
*/

#include	"allum.h"

void		display_lines(t_alum **tmp, int *nb_line, int *space)
{
  int		i;

  i = (*space);
  my_putstr(GREEN);
  my_put_nbr((*nb_line));
  my_putstr(DEFAULT);
  my_putchar('.');
  my_putchar(' ');
  while (i-- != 0)
    my_putchar(' ');
  i = -1;
  my_putstr(BLUE);
  while (++i < (*tmp)->nb_matches)
    my_putchar('|');
  my_putstr(DEFAULT);
  i = (*space) + ((*tmp)->max_matches - (*tmp)->nb_matches);
  while (i-- != 0)
    my_putchar(' ');
  my_putstr(RED);
  my_put_nbr((*tmp)->nb_matches);
  my_putstr(DEFAULT);
  my_putstr(" allumette(s)");
  (*space) -= 1;
  (*nb_line) += 1;
  (*tmp) = (*tmp)->next;
}

/*
** display matches
** void display_matches(t_struct LIST);
*/
void		display_matches(t_alum *list)
{
  t_alum	*tmp;
  int		nb_line;
  int		space;

  space = list->nb_matches;
  nb_line = 1;
  my_putchar('\n');
  tmp = list->next;
  while (tmp != NULL)
    {
      display_lines(&tmp, &nb_line, &space);
      my_putchar('\n');
    }
  my_putchar('\n');
}

/*
** display message at the end of round
*/
void		display_message(int line, int matches, int cond, t_player *player)
{
  my_putstr(RED);
  if (cond == 1)
    my_putstr("\nLe joueur a supprime ");
  else
    my_putstr((player->mode == 1) ? "\nIA a supprime "
	      : "\nLe joueur 2 a supprime" );
  my_put_nbr(matches);
  my_putstr(" allumette(s) a la ligne ");
  my_put_nbr(line);
  my_putstr(DEFAULT);
  my_putchar('\n');
}

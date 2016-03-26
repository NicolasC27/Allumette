/*
** allum.h for allum.h in /home/cheval_8/rendu/CPE_2015_Allum1/include
**
** Made by Chevalier Nicolas
** Login   <cheval_8@epitech.net>
**
** Started on  Fri Feb 19 14:08:13 2016 Chevalier Nicolas
// Last update Sun Feb 21 23:29:24 2016 Chevalier Nicolas
*/

#ifndef ALLUM_H_
# define ALLUM_H_

/*
** Includes
*/
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "gnl.h"
# include "lib.h"

/*
** Defines
*/
# define BUFFER_SIZE	128
# define J_DIFFICULTY	"\n\n"YELLOW"Difficulte du niveau"DEFAULT" \
: EASY("RED"1"DEFAULT") MEDIUM("RED"2"DEFAULT") HARD("RED"3"DEFAULT") : "
# define J_MODE		""YELLOW"Mode de jeu"DEFAULT" (Joueur vs IA \
taper"RED" 1"DEFAULT", Joueur vs Joueur taper"RED" 2"DEFAULT") : "
# define ERR_MODE	"You have to choose an IA\n"
# define ERR_DIFFICULTY	"You have to choose an difficulty\n"
# define HEADER		"*********************************************\n"
# define WELCOME	BLUE HEADER "BIENVENUE DANS LE JEU DES ALLUMETTES\
\n" HEADER "\n\n" DEFAULT

typedef struct		s_alum
{
  int			nb_matches;
  int			max_matches;
  struct s_alum		*next;
}			t_alum;

typedef struct		s_player
{
  int			nb_matches;
  int			difficulty;
  int			mode;
  int			a;
  int			col;
  int			win;
}			t_player;

/*
** FILE: main.c
*/
int			exit_prog(char *);

/*
** FILE: init.c
*/
t_alum			*init_node(int);
char			*convert_bin(int);
void			init_matches(t_alum **, int);
t_alum			*init_alum(int);

/*
**FILE: ia.c
*/
int			search_one(t_alum *);
int			choose_params(t_alum *, int *, int);
int			xor(t_alum *list);
int			xor_line(t_alum *list, int, int *);
void			ia(t_alum *list);

/*
**FILE: display.c
*/
void			display_lines(t_alum **, int *, int *);
void			display_matches(t_alum *);
void			display_message(int, int, int, t_player *);

/*
**FILE: utils_prog.c
*/
int			remove_matches(t_alum *, int, int);
int			count_list(t_alum *, int *);
int			read_line(t_alum *, int);
int			check_line(t_alum *, int);

/*
** error.c
*/
int			error_allum1(char *);
int			check_error(t_alum *, int);
int			init_game(t_player *, int, char **);

/*
** choose.c
*/
int			choose_options(t_player *);

/*
** ia.c
*/
int			ia_level(t_alum *, t_player *);

#endif /* !ALLUM_H_ */

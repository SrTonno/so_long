/*
void	find_path(t_game *game)
{
	char	**vector;
	int		col;
	int		fil;
	int		i;

	col = 0;
	vector = check_path(game);
	i = 0;
	//while (game->count > i)
		//ft_printf("%s\n", vector[i++]);
	while (game->count - 1> ++col)
	{
		fil = 0;
		while (game->len - 1 > ++fil)
		{
			if (game->map[col][fil] == 'E' && game->map[col][fil] == 'C')
			{
				if (vector[col][fil] == '0')
				{
					ft_printf ("Error\n Caminos no validos");
					exit (1);
				}
			}
		}
	}


	liberator_map(vector, game->count);

}
*/

#include <mlx.h>

#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		endian;
	void	*win;
	void	*mlx;
	void	*mlx_win;
}				t_data;



int	key_hook(int keycode, t_data *img)
{

	printf("Hello from %dkey_hook!\n", keycode);
	if (keycode == 13)
		return(1);
	return (0);
}

int	render_next_frame(t_data *img)
{
	int		img_width;
	int		img_height;
	int		a;
	img->img = mlx_xpm_file_to_image(img->mlx, "../img/emogi.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 430, 430);
	/* This function needs to exist, but it is useless for the moment */
	//printf("render\n");
	/*if (mlx_key_hook(img->win, key_hook, &img) == 1)
	{
		printf("Print new emogi");
		img->img = mlx_xpm_file_to_image(img->mlx, "../img/emogi.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->win, img->img, 430, 430);
	}*/
	//mlx_key_hook(img->win, key_hook, &img);
	//printf("%d", a);
	/*if (a == 1)
	{
		img->img = mlx_xpm_file_to_image(img->mlx, "../img/emogi.xpm", &img_width, &img_height);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 430, 430);
	}*/
	return (0);
}

int	main(void)
{
	//void	*mlx;
	//void	*mlx_win;
	t_data	img;
	t_vars	vars;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;


	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 1560, 784, "Prueba So_Long!");
	//backgraun
	img.img = mlx_xpm_file_to_image(img.mlx, "../img/old/ocean.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

	img.img = mlx_xpm_file_to_image(img.mlx, relative_path, &img_width, &img_height);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								//&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.img = mlx_xpm_file_to_image(img.mlx, "../img/old/emogi.xpm", &img_width, &img_height);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 30, 30);
	mlx_key_hook(img.win, key_hook, &img);
	//vars.win = img.win;
	//vars->mlx_win = img.mlx_win;
	/*mlx_loop_hook(img.mlx, &render_next_frame, &img);
	if (mlx_key_hook(img.win, key_hook, &img) == 1)
	{
		printf("Print new emogi");
		mlx_loop_hook(img.mlx, &render_next_frame, &img);
		//img.img = mlx_xpm_file_to_image(img.mlx, "../img/emogi.xpm", &img_width, &img_height);
		//mlx_put_image_to_window(img.mlx, img.win, img.img, 430, 430);
	}*/
	mlx_loop(img.mlx);


}

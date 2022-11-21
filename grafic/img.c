#include <mlx.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	//backgraun
	img.img = mlx_xpm_file_to_image(mlx, "../img/ocean.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								//&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	//img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.img = mlx_xpm_file_to_image(mlx, "../img/emogi.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 30, 30);
	img_width = 55;
	img_height = 555;
	img.img = mlx_xpm_file_to_image(mlx, "./cuadrado.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 500, 500);
	mlx_loop(mlx);
}

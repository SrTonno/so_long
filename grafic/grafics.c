#include <mlx.h>

int	render_next_frame(void *YourStruct);

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
	t_data	data;

	mlx = mlx_init();
	mlx_loop_hook(mlx, render_next_frame, data);
	mlx_loop(mlx);
}

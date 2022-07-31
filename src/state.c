#include "../minilibx/mlx.h"
#include <stdlib.h>

#include "../includes/state.h"
#include "../Libft/libft.h"

int	init_state(t_state *state)
{
	ft_memset(state, 1, sizeof(t_state));
	state->mlx = mlx_init();
	state->window = mlx_new_window(state->mlx, 1000, 1000, "so_long");
	return (1);
}

// mlx_destroy_image(state->mlx, state->img);
int	free_state(t_state *state)
{
	mlx_destroy_window(state->mlx, state->window);
	free(state->mlx);
	return (1);
}

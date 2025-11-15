/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:14:51 by liemi             #+#    #+#             */
/*   Updated: 2025/11/15 22:23:59 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*p;

	p = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(int *)p = color;
}

static int	mk_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_fill_demo(t_app *a)
{
	int	x;
	int	y;
	int	r;
	int	g;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			r = (x * 255) / WIN_W;
			g = (y * 255) / WIN_H;
			put_pixel(&a->img, x, y, mk_color(r, g, 128));
			x++;
		}
		y++;
	}
}

void	draw_present(t_app *a)
{
	mlx_put_image_to_window(a->mlx, a->win, a->img.img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:02:50 by liemi             #+#    #+#             */
/*   Updated: 2025/11/15 22:14:30 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	img_create(t_app *a, t_img *img, int w, int h)
{
	img->img = mlx_new_image(a->mlx, w, h);
	if (!img->img)
		die("mlx_new_image failed");
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->addr)
		die("mlx_get_data_addr faild");
}

void	img_destroy(t_app *a, t_img *img)
{
	if (img->img)
		mlx_destrory_image(a->mlx, img->img);
	img->img = NULL;
	img->addr = NULL;
}

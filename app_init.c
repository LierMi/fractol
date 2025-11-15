/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 05:12:54 by liemi             #+#    #+#             */
/*   Updated: 2025/11/15 21:43:49 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//初始化与清理、错误/用法
//打印一行错误到 stderr（文件描述符 2），然后 exit(1)。
void	die(const char *msg)
{
	if (msg)
	{
		write(2, msg, (int)strlen(msg));
		write(2, "\n", 1);
	}
	exit(1);
}

//打印 STEP 1 的用法：当前只支持“无参数启动”
void	printf_usage_and_exit(void)
{
	const char	*u;

	u = "Usage:\n"
		"  ./fractol\n"
		"(STEP 1: no args; later step add mandelbrot/julia)\n"
	write(1, u, (int)strlen(u));
	exit(0);
}

//若窗口存在，调用 mlx_destroy_window 清理。
void	app_destroy(t_app *a)
{
	if (a->win)
		mlx_destroy_window(a->mlx, a->win);
}
/*a->mlx = mlx_init();：创建图形上下文。失败就 die。

a->win = mlx_new_window(...);：按 WIN_W/H 创建窗口。失败也 die。

a->needs_redraw = 1;：标记初始需要绘制（后面步骤会用上）。

设计理由：把资源获取（init）和资源释放（destroy）放在同一文件，调用路径统一、好查漏。*/
void	app_init_mlx(t_app *a)
{
	a->mlx = mlx_init();
	if (!a->mlx)
		die("mlx_init failed");
	a->win = mlx_new_window(a->mlx, WIN_W, WIN_H, "fractol - step 1");
	if (!a->win)
		die("mlx_new_window failed");
	a->needs_redraw = 1;
}


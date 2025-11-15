/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 04:43:07 by liemi             #+#    #+#             */
/*   Updated: 2025/11/15 05:12:03 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_app	a;

	(void)av;
	if (ac != 1)
		print_usage_and_exit();//STEP 1 只接受零参数
	memset(&a, 0, sizeof(a));//把应用状态 a 清零，确保所有指针初始为 NULL，更安全
	app_init_mlx(&a);//创建图形上下文与窗口
	mlx_loop_hook(a.mlx, loop_hook, &a);//注册主循环钩子。MiniLibX 在每一帧都会调用 loop_hook(a)
	mlx_key_hook(a.win, on_key, &a);//注册键盘回调；我们只处理 ESC
	mlx_hook(a.win, 17, 0, on_close, &a);//注册窗口关闭（红叉）事件，事件号 17 是 X11 的 DestroyNotify
	mlx_loop(a.mlx);//进入事件循环；从此程序“活着”，等待事件并回调
	app_destroy(&a);//mlx_loop 正常返回时清理窗口（大多数情况下退出时不会走到这里，但写上更稳妥）
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liemi <liemi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:45:00 by liemi             #+#    #+#             */
/*   Updated: 2025/11/15 21:58:55 by liemi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//事件回调
int	on_key(int keycode, void *param)
{
	t_app	*a;
//若 keycode 是 ESC（X11 或 macOS）
	a = (t_app *)param;
	if (keycode == KEY_ESC_X11 || keycode == KEY_ESC_MAC)
	{
		app_destroy(a);
		exit(0);
	}
	return (0);//返回 0 表示事件已处理
}

int	on_close(void *param)
{//处理窗口右上角的关闭按钮
	t_app	*a;

	a = (t_app *)param;
	app_destroy(a);
	exit(0);
	return (0);
}

int	loop_hook(void *param)
{
	t_ap	*a;

	a = (t_app *)param;
	(void)a;
	return (0);
}

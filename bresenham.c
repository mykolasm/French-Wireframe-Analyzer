/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcink <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 10:22:00 by mmarcink          #+#    #+#             */
/*   Updated: 2018/06/19 10:22:00 by mmarcink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*

 function line(x0, y0, x1, y1)
     real deltax := x1 - x0
     real deltay := y1 - y0
     real deltaerr := abs(deltay / deltax)    // Assume deltax != 0 (line is not vertical),
           // note that this division needs to be done in a way that preserves the fractional part
     real error := 0.0 // No error at start
     int y := y0
     for x from x0 to x1 
         plot(x,y)    // is this just successive pixel putting?
         error := error + deltaerr
         while error ≥ 0.5 then
             y := y + sign(deltay) * 1 //sign func = sign(x) = {(-1 if x < 0), (0 if x = 0), (1 if x > 0)}
             error := error - 1.0

*/

int     sign(int x)
{
    if (x < 0)
        return (-1);
    else if (x = 0)
        return (0);
    else
        return (1);
}

int     draw_line(int x0, int y0, int x1, int y1)
{
    double delta_x = x1 - x0;
    double delta_y = y1 - y0;
    double delta_error = abs(delta_y / delta_x);   // assume (delta_x) true
    double error = 0.0;
    int y = y0;
    int x = x0; // idk so i guessed its the same? wont work in the other function...
    int i = 0;

    while (x0 <= x1)
    {
        mlx_pixel_put(mlx, window, x, y, test_color);  //void *mlx_ptr, void *win_ptr, int x, int y, int color)
        error += delta_error;
        while (error >= 0.5)
        {
            y += sign(delta_y) * 1;
            error -= 1.0;
        }
        //i++;   // wtf do i increment here??? hmm ask milan
    }
}
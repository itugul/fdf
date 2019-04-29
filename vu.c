/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vu.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbrekke <fbrekke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:16:29 by fbrekke           #+#    #+#             */
/*   Updated: 2019/04/11 14:24:10 by fbrekke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function plot(x, y, c) is
    // рисует точку с координатами (x, y)
    // и яркостью c (где 0 ≤ c ≤ 1)

function ipart(x) is
    return целая часть от x

function round(x) is
    return ipart(x + 0.5) // округление до ближайшего целого

function fpart(x) is
    return дробная часть x

function draw_line(x1,y1,x2,y2) is
   if x2 < x1 then
       swap(x1, x2)
       swap(y1, y2)
   end if
  
   dx := x2 - x1
   dy := y2 - y1
   gradient := dy ÷ dx
  
   // обработать начальную точку
   xend := round(x1) 
   yend := y1 + gradient × (xend - x1)
   xgap := 1 - fpart(x1 + 0.5)
   xpxl1 := xend  // будет использоваться в основном цикле
   ypxl1 := ipart(yend)
   plot(xpxl1, ypxl1, (1 - fpart(yend)) × xgap)
   plot(xpxl1, ypxl1 + 1, fpart(yend) × xgap)
   intery := yend + gradient // первое y-пересечение для цикла
        
   // обработать конечную точку
   xend := round(x2)
   yend := y2 + gradient × (xend - x2)
   xgap := fpart(x2 + 0.5)
   xpxl2 := xend  // будет использоваться в основном цикле
   ypxl2 := ipart(yend)
   plot(xpxl2, ypxl2, (1 - fpart(yend)) × xgap)
   plot(xpxl2, ypxl2 + 1, fpart(yend) × xgap)
     
   // основной цикл
   for x from xpxl1 + 1 to xpxl2 - 1 do
           plot(x, ipart(intery), 1 - fpart(intery))
           plot(x, ipart(intery) + 1, fpart(intery))
           intery := intery + gradient
   repeat
end function
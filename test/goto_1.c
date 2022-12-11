/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junoh <junoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:08:42 by junoh             #+#    #+#             */
/*   Updated: 2022/12/02 17:13:36 by junoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

long pcount_while(unsigned long x)
{
	long result = 0;
	while (x)
	{
		result = x & 0x1;
		x >>= 1;
	}
	return result;
}

long pcount_goto(unsigned long x)
{
	long result = 0;
	goto test;
	
	loop :
		result = x & 0x1;
		x >>= 1;
	test:
		 if (x)
			goto loop;
	return result;
}
	

int main(void)
{
	int go = pcount_goto(12345);
	int wh = pcount_while(12345);
	printf("go = %d\n", go);
	printf("wh = %d\n", wh);

	return (0);
}
	

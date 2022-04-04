/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:30:35 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/04/04 17:34:40 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing_folder/exec_test.h"
#include "../parsing_folder/minishell.h"

// char	*ft_strstr(char	*str, char	*to_find)
// {
// 	    int i=0;
// 	        int j=0;
// 		    int k=0;
// 		        if(to_find[0] == '\0'){
// 				          return (str);
// 				}
// 					          while(str[i] != '\0')
// 				     {
// 	     j=0;						      
// 		 if(str[i] == to_find[0])
// 			   {
// 				   k=i;
// 				 while(str[k] == to_find[j])
// 				   {
// 				if(to_find[j+1]=='\0'){
// 					return (&str[i]);
// 				  }
// 					 k++;
// 						   j++;
// 					}
// 					}
// 							    i++;
// 				   }        
// 			        return (0);
// }

// int get_equal_index(char *table)
// {
//     int i = 0;
//     while(table[i])
//     {
//         if(table[i] == '=')
//             return (i);
//         i++;
//     }
//     return (-1);
// }

// int main(void)
// {
// 	char *str = "ab=";
// 	int index = get_equal_index(str);
// 	//printf("index  %d || len %lu\n",index,strlen(str) - 1);
// 	if(index == (strlen(str) - 1))
// 	{
// 		printf("equal is in the end goo!\n");
// 	}
// }
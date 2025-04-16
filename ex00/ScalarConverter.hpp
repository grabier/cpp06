/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:25:23 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/16 18:23:02 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <limits>

class ScalarConverter{
	private:
		ScalarConverter(){}
	public:
		static void convert(std::string);
};

void putnan();
void putinf(int mode);
int is_special(std::string input);
int parse(std::string input);
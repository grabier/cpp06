/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:25:21 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/16 20:27:46 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void putnan(){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void putinf(int mode){
	if (mode == 0){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " <<  std::numeric_limits<float>::infinity() << std::endl;
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -" << std::numeric_limits<double>::infinity() << std::endl;
		std::cout << "double: -" << std::numeric_limits<double>::infinity() << std::endl;
	}
}

int is_special(std::string input){
	
	std::string a[6] = {"nan", "nanf", "inf", "-inf", "inff", "-inff"};
	for (int i = 0; i < 6; i++){
		if (input == a[i]){
			switch (i)
			{
			case 0:
				putnan();
				return (1);
			case 1:
				putnan();
				return (1);
			case 2:
				putinf(0);
				return (1);
			case 3:
				putinf(1);
				return (1);
			case 4:
				putinf(0);
				return (1);
			case 5:
				putinf(1);
				return (1);
			}
		}
	}
	return (0);
}

int parse(std::string input){
	//allowed characters: numbers, point.(only one), letras(solo una)
	//1. si hay letra, solo puede ser una al principio(displayable chars)
	//puede ser tb un signo menos seguido de un numero valido
	//2. que es un numero valido?
	//vamos a aceptar literales de int, double y float
	//es decir, valen el 2, el 2.0 y el 2.0f, asi como sus negativos
	std::string s;
	std::stringstream ss(input);
	s = ss.str();
	for (int i = 0; i < (s.size() - 1); i++){
		if (s[i] )
	}
}

void ScalarConverter::convert(std::string input){
	//comparamos primero con nan, inf y -inf, si no es ninguno de ellos:
	//comenzamos a parsear
	if (is_special(input))
		return ;
		
	//some parsing first of all:
	parse(input);

	//if (s.at(s.size() - 1) == 'f') ---> en algun punto nos servira para
	//detectar floats, primero hay que parsear

	
	
	//std::cout << "final de s vale: " << s.at(s.size() - 1) << std::endl;
	//std::cout << "s vale: " << s << std::endl;
}
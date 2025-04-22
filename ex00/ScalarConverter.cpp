/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:25:21 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/22 17:37:50 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

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

bool ft_check_dots(std::string input){//check there's only one dot if any
	int count = 0;
	for (unsigned long i = 0; i < (input.size() - 1); i++){
		if (input[i] == '.'){
			count ++;
		}
	}
	if (count > 1)
		return (false);
	return (true);
}

bool ft_check_chars(std::string input){
	if (!isdigit(input[0]) && input.size() > 1 && input[0] != '-')//check if alpha(except -), if there is anything behind, out
		return (false);
	if (isdigit(input[0]) && input.size() > 1){
		for (unsigned long i = 1; i < (input.size() - 2); i++){
			if (input[i] != '.' && !isdigit(input[i])){//check if there are mixed digits and non digits
				return (false);
			}
		}
	}
	if (input.size() > 1 && !isdigit(input[input.size() - 1]) && input[input.size() - 1] != 'f')
		return (false);
	return (true);
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
	if (!ft_check_chars(input) || !ft_check_dots(input)){
		std::cout << "Error: not convertible" << std::endl;
		return (0);
	}
	if (!isdigit(input[0]) && input[0] != '-')//1 for chars
		return (1);
	for (unsigned long i = 0; i < input.size() - 1; i++){
		if (input[i] == '.'){
			if (input[input.size() - 1 ] == 'f')//3 for floats
				return (3);
			else
				return (4);//4 for double
		}
	}
	return (2);//2 for ints
}

void ft_convert_char(std::string input){
	if (input[0] > 126 || input[0] < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << input[0] << std::endl;
	std::cout << "int: Impossible" << std::endl;
	std::cout << "float: Impossible" << std::endl;
	std::cout << "double: Impossible" << std::endl;
}

void ft_convert_int(std::string input){
	std::stringstream ss(input);
	char c;
	int n;
	double d;
	float f;
	
	ss >> n;
	c = static_cast<char>(n);
	d = static_cast<double>(n);
	f = static_cast<float>(n);
	if (n > 126 || n < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << c << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::setprecision(1) << std::fixed << f << "f" << std::endl;;
	std::cout << "double: " << d << std::endl;;
}

void ft_convert_float(std::string input){
	std::stringstream ss(input);
	char c;
	int n;
	double d;
	float f;
	
	ss >> f;
	c = static_cast<char>(f);
	n = static_cast<int>(f);
	d = static_cast<double>(f);
	if (n > 126 || n < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << f << "f" << std::endl;;
	std::cout << "double: " << d << std::endl;;
}

void ft_convert_double(std::string input){
	std::stringstream ss(input);
	char c;
	int n;
	double d;
	float f;
	
	ss >> d;
	c = static_cast<char>(d);
	n = static_cast<int>(d);
	f = static_cast<float>(d);
	if (n > 126 || n < 32)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << f << "f" << std::endl;;
	std::cout << "double: " << d << std::endl;;
}

void ScalarConverter::convert(std::string input){
	//comparamos primero con nan, inf y -inf, si no es ninguno de ellos:
	//comenzamos a parsear
	if (is_special(input))
		return ;
	//some parsing first of all:
	int type = parse(input);
	
	//std::cout << "parsing result : " << type << std::endl;
	
	switch(type){
		case 0:
			return ;
		case 1:
			ft_convert_char(input);
			return ;
		case 2:
			ft_convert_int(input);
			return ;
		case 3:
			ft_convert_float(input);
			return ;
		case 4:
			ft_convert_double(input);
			return ;
	}
	//if (s.at(s.size() - 1) == 'f') ---> en algun punto nos servira para
	//detectar floats, primero hay que parsear

	
	
	//std::cout << "final de s vale: " << s.at(s.size() - 1) << std::endl;
	//std::cout << "s vale: " << s << std::endl;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:06:29 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/22 19:15:10 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>


class CastingException:public std::exception{
	public:
		const char *what() const throw() {return ("CastingException: error\n");} 
};

Base *generate(void){
	srand(time(0));
	int r = rand() % 100;
	if (r < 33)
		return (new A);
	else if (r >33 && r < 66)
		return (new B);
	else
		return (new C);
}

void identify(Base &p){
	try{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "identify by reference: type A" << std::endl;
	}
	catch(...){
		try{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "identify by reference: type B" << std::endl;
		}
		catch(...)
		{
			C &c = dynamic_cast<C &>(p);
			(void)c;
			std::cout << "identify by reference: type C" << std::endl;
		}
	}
}

void identify(Base *p){
	if (dynamic_cast<A *>(p))
		std::cout << "identify by pointer: type A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "identify by pointer: type B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "identify by pointer: type C" << std::endl;
}

int main(void){
	
	Base *b1;
	Base b2;

	b1 = generate();
	identify(b1);
	identify(*b1);
	delete b1;
	
	return (0);
}
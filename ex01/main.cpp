/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:29:20 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/22 17:55:01 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

int main(){
	Data *p = new Data;
	p->d = 3.4;
	p->n = 8;
	p->f = 4.08f;
	p->s = "hola me iamo pako";
	std::cout << "Data initially: " << std::endl;
	std::cout << "address: " << p << std::endl;
	std::cout << "data->d: " << p->d << std::endl;
	std::cout << "data->n: " << p->n << std::endl;
	std::cout << "data->f: " << p->f << std::endl;
	std::cout << "data->s: " << p->s << std::endl;

	uintptr_t res = Serializer::serialize(p);
	Data *r = Serializer::deserialize(res);
	
	std::cout << "Data after serialization: " << std::endl;
	std::cout << "address: " << r << std::endl;
	std::cout << "res->d: " << r->d << std::endl;
	std::cout << "res->n: " << r->n << std::endl;
	std::cout << "res->f: " << r->f << std::endl;
	std::cout << "res->s: " << r->s << std::endl;
	delete p;
}
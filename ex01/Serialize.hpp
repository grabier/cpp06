/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:19:21 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/22 17:48:29 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP
#include <iostream>
#include <stdint.h>
#include <cstdlib>
#include "Data.h"

class Serializer{
	private:
		Serializer(){}
		Serializer(const Serializer &){}
		~Serializer(){}
		void operator=(const Serializer &){}
	public:
		static uintptr_t serialize(Data *);
		static Data *deserialize(uintptr_t);
};
#endif
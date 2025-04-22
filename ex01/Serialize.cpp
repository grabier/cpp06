/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontoro <gmontoro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:19:16 by gmontoro          #+#    #+#             */
/*   Updated: 2025/04/22 17:54:13 by gmontoro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t Serializer::serialize(Data *ptr){
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data *Serializer::deserialize(uintptr_t raw){
	Data *ret = reinterpret_cast<Data *>(raw);
	return (ret);
}
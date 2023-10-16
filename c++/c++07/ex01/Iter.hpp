#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
void	iter(T *array, int arraySize, void(*function)(const T&))
{
	for (int i = 0; i < arraySize; i++)
		function(array[i]);
}

#endif

#include <iostream>
#include <vector>
#include "timer.h"
#include "Array.h"
int main()
{
	timer timer;
	int arr_count = 100;
	Array<int,100000 >* arrs = new Array<int,100000 >[arr_count];
	std::cout << "Rozmiar tablicy:" << 100000 << std::endl;
	
	
	///wszystko losowe
	std::cout << "Wszystko losowe:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random();
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random();
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random();
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();	
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();

	///25% posortowane
	std::cout << "25% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(25);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(25);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(25);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();
	
	///50% posortowane
	std::cout << "50% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(50);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(50);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(50);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();
	
	///75% posortowane
	std::cout << "75% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(75);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(75);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(75);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();
	
	///95% posortowane
	std::cout << "95% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(95);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(95);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(95);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();

	///99% posortowane
	std::cout << "99% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();

	///99.7% posortowane
	std::cout << "99.7% posortowane:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99.7);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99.7);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(99.7);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();
	
	///posortowane w odwrotnej kolejnoœci 
	std::cout << "posortowane w odwrotnej kolejnosci:\n";
	//quicksort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(-1);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].quicksort();
	timer.stop();
	std::cout << "Quciksort:\n";
	timer.print_duration();
	//mergesort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(-1);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].mergesort();
	timer.stop();
	std::cout << "Mergesort:\n";
	timer.print_duration();
	//introsort
	for (int i = 0; i < arr_count; i++)
		arrs[i].random(-1);
	timer.start();
	for (int i = 0; i < arr_count; i++)
		arrs[i].introsort();
	timer.stop();
	std::cout << "Introsort:\n";
	timer.print_duration();

	std::cin.get();
	std::cin.get();
	delete[] arrs;
}




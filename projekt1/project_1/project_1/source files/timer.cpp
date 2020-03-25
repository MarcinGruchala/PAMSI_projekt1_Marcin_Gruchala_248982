#include "timer.h"
#include <iostream>

timer::timer()
{
}

void timer::start()
{
	m_start = std::chrono::high_resolution_clock::now();
}

void timer::stop()
{
	m_stop = std::chrono::high_resolution_clock::now();
	duration = m_stop - m_start;
}

void timer::print_duration()
{
	std::cout << "duration = " << duration.count() << "s\n";
}

timer::~timer()
{
}
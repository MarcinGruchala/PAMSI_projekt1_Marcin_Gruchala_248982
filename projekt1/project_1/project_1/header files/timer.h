#pragma once
#include <chrono>
class timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> m_start, m_stop;
	std::chrono::duration<float> duration;
public:

	timer();
	void start();
	void stop();
	void print_duration();
	~timer();

};
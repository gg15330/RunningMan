#pragma once

#include <SDL.h>

#include <cstdint>

class Timer {
public: 
	//Initializes variables 
	Timer(); 
	~Timer();
	//The various clock actions 
	void start(); 
	void stop(); 
	void pause(); 
	void unpause(); 
	//Gets the timer's time 
	std::uint32_t getTicks(); 
	//Checks the status of the timer 
	bool isStarted(); 
	bool isPaused(); 
private: 
	//The clock time when the timer started 
	std::uint32_t mStartTicks; 
	//The ticks stored when the timer was paused 
	std::uint32_t mPausedTicks; 
	//The timer status 
	bool mPaused; 
	bool mStarted; 
};


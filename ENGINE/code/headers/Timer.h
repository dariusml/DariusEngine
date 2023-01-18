#pragma once

#include <chrono>

namespace DariusEngine
{
	class Timer
	{
    private:
        std::chrono::time_point<std::chrono::system_clock> m_StartTime;
        std::chrono::time_point<std::chrono::system_clock> m_EndTime;
        bool m_bRunning = false;

    public:
        void start();

        void stop();

        double elapsedMilliseconds();

        double elapsedSeconds();
	};
}

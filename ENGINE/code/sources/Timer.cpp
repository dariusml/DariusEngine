#include "../headers/Timer.h"

#include <iostream>
#include <ctime>
#include <cmath>

namespace DariusEngine
{
    void Timer::start()
    {
        m_StartTime = std::chrono::system_clock::now();
        m_bRunning = true;
    }

    void Timer::stop()
    {
        m_EndTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }

    double Timer::elapsedMilliseconds()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if (m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    std::chrono::time_point<std::chrono::system_clock> Timer::currentTime()
    {
        std::chrono::time_point<std::chrono::system_clock> endTime;

        if (m_bRunning)
        {
            endTime = std::chrono::system_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return endTime;
    }

    double Timer::elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }
}
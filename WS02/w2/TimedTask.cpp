#include "TimedTask.h"
#include <iomanip>
namespace seneca {
	seneca::TimedTask::TimedTask()
	{

	}
	void TimedTask::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}

	void TimedTask::addTask(std::string taskName)
	{
		if (m_currentRecords < m_maxTasks)
		{
			m_taskArr[m_currentRecords].setName(taskName);
			m_taskArr[m_currentRecords].setUnit("nanoseconds");
			m_taskArr[m_currentRecords].setDuration(std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime));
			++m_currentRecords;
		}
	}
	std::ostream& operator<<(std::ostream& ostr, TimedTask t)
	{
		ostr << "--------------------------\nExecution Times:\n--------------------------\n";
		for (size_t i = 0; i < t.m_currentRecords; i++)
		{
			t.m_taskArr[i].display(ostr);
		}
		ostr << "--------------------------\n";
		return ostr;
	}
	// Task member functions
	void Task::setName(std::string name)
	{
		m_mame = name;
	}
	void Task::setUnit(std::string unit)
	{
		m_unit = unit;
	}
	void Task::setDuration(std::chrono::steady_clock::duration duration)
	{
		m_duration = duration;
	}
	std::ostream& Task::display(std::ostream& ostr) const
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_duration).count();
		ostr << std::left << std::setw(20) << m_mame;
		ostr << std::right << std::setw(13) << duration;
		ostr << std::setw(13) << m_unit << '\n';
		return ostr;
	}
}

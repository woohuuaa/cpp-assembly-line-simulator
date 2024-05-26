////////////////////////////////////////////////////////////////////////////
//	  																      //
// Name: Wan-Hua Wu |  Email: wwu104@myseneca.ca |  Student ID: 152921227 //
//							Date: 2024-05-23							  //
// ---------------------------------------------------------------------- //
// I declare that this submission is the result of my own work and only   //
// copied the code that my professor provided to complete my workshops	  //
// and assignments. This submitted piece of work has not been shared with //
// any other student or 3rd party content provider.						  //	 																      //
////////////////////////////////////////////////////////////////////////////
#ifndef _SENECA_TIMEDTASK_H
#define _SENECA_TIMEDTASK_H
#include <iostream>
#include <chrono>
namespace seneca {
	class Task
	{
		std::string m_mame{};
		std::string m_unit{};
		std::chrono::steady_clock::duration m_duration{};
	public:
		/// <summary>
		/// to set data member m_name
		/// </summary>
		/// <param name="name">a string to set name</param>
		void setName(std::string name);
		/// <summary>
		/// to set data member m_unit
		/// </summary>
		/// <param name="unit">a string to set unit</param>
		void setUnit(std::string unit);
		/// <summary>
		/// to set data member m_duration
		/// </summary>
		/// <param name="duration">a duration object to set duration</param>
		void setDuration(std::chrono::steady_clock::duration duration);
		/// <summary>
		/// to display Task object
		/// </summary>
		/// <param name="ostr"></param>
		/// <returns>ostream& object</returns>
		std::ostream& display(std::ostream& ostr) const;
	};
	class TimedTask
	{
		static constexpr size_t m_maxTasks{ 10 };
		size_t m_currentRecords{};
		std::chrono::steady_clock::time_point m_startTime{};
		std::chrono::steady_clock::time_point m_endTime{};
		Task m_taskArr[m_maxTasks];
	public:
		// rule of three
		// do not do copy in move, move is shallow
		TimedTask();
		/// <summary>
		/// a modifier that starts the timer for an event
		/// </summary>
		void startClock();
		/// <summary>
		/// a modifier that stops the timer for an event
		/// </summary>
		void stopClock();
		/// <summary>
		/// a modifier that receives the address of a C-style null-terminated string that holds the name of the task
		/// </summary>
		/// <param name="taskName"></param>
		/// <returns></returns>
		void addTask(std::string taskName);
		/// <summary>
		/// insert in the std::ostream object the records from the array in format
		/// </summary>
		/// <param name="istr"></param>
		/// <param name="t"></param>
		/// <returns>ostream object</returns>
		friend std::ostream& operator<<(std::ostream& ostr, TimedTask t);
	};
}
#endif // _SENECA_TIMEDTASK_H
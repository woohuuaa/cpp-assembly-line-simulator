// Name: Wan-Hua Wu
// Seneca Student ID: 152921227
// Seneca email: wwu104@myseneca.ca
// Date of completion: 2024-07-12
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SENECA_LINEMANAGER_H
#define SENECA_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
#include "CustomerOrder.h"
namespace seneca {
	class LineManager
	{
		std::vector<Workstation*> m_activeLine{};	// the collection of workstations for the current assembly line
		size_t m_cntCustomerOrder{};				// the total number of CustomerOrder objects
		Workstation* m_firstStation{};				// points to the first active station on the current line
	public:
		/// <summary>
		/// Constructor
		/// </summary>
		/// <param name="file">name of the file that identifies the active stations on the assembly line</param>
		/// <param name="stations">the collection of workstations available for configuring the assembly line</param>
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();					// reorders the workstations in m_activeLine and stores the reordered collection
		bool run(std::ostream& os);				// performs one iteration of operations on all of the workstations in the current assembly line
		void display(std::ostream& os) const;	// displays all active stations on the assembly line in their current order
	};
}
#endif // !SENECA_WORKSTATION_H


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
#ifndef _SENECA_PROTEINDATABASE_H
#define _SENECA_PROTEINDATABASE_H
#include <iostream>
#include <fstream>
#include <string>
namespace seneca {
	class ProteinDatabase
	{
		std::string* m_proteinSequence{};
		size_t m_size{};
	public:
		ProteinDatabase();
		/// <summary>
		/// 1-argument constructor that receives as parameter a string containing the name of a file 
		/// from which this member function populates the current object.
		/// </summary>
		/// <param name="filename"></param>
		ProteinDatabase(std::string filename);
		/// <summary>
		/// Copy Constructor
		/// </summary>
		/// <param name="src">ProteinDatabase objectcopy from</param>
		ProteinDatabase(const ProteinDatabase& src);
		/// <summary>
		/// copy assignment
		/// </summary>
		/// <param name="src">ProteinDatabase object copy from</param>
		/// <returns></returns>
		ProteinDatabase& operator=(const ProteinDatabase& src);
		/// <summary>
		/// destructor
		/// </summary>
		virtual ~ProteinDatabase();
		operator bool() const;
		/// <summary>
		/// a query that returns the number of protein sequences stored in the current object.
		/// </summary>
		/// <returns>the number of protein sequences stored in the current object</returns>
		size_t size() const;
		/// <summary>
		/// a query that returns a copy of the protein sequence at the index received as the function parameter. 
		/// If the index is invalid, this function should return an empty string.
		/// </summary>
		/// <param name="index">the index of protein sequence</param>
		/// <returns>
		/// a copy of the protein sequence at the index, 
		/// If the index is invalid, this function should return an empty string.
		/// </returns>
		std::string operator[](size_t index);
	};
}

#endif // _SENECA_PROTEINDATABASE_H

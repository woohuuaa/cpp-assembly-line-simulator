#include "Restaurant.h"
namespace seneca {
    void Restaurant::setEmpty()
    {
        if (m_pReservations) {
            for (size_t i = 0; i < m_numOfResv; ++i) {
                delete m_pReservations[i];
            }
            delete[] m_pReservations;
        }
        m_pReservations = nullptr;
        m_numOfResv = 0;
    }
    Restaurant::Restaurant() { }
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
    {
        if (reservations)
        {
            m_numOfResv = cnt;  
            m_pReservations = new Reservation*[cnt];
            for (size_t i = 0; i < cnt; ++i)
            {
                m_pReservations[i] = new Reservation(*reservations[i]);
            }
        }
    }
    // Copy Constructor
    Restaurant::Restaurant(const Restaurant& src)
    {
        *this = src;
    }
    // Copy Assignment
    Restaurant& Restaurant::operator=(const Restaurant& src)
    {
        if (this != &src)
        {
            setEmpty();
            if (src.m_pReservations)
            {
                m_numOfResv = src.m_numOfResv;
                m_pReservations = new Reservation*[src.m_numOfResv];
                for (size_t i = 0; i < src.m_numOfResv; ++i)
                {
                    m_pReservations[i] = new Reservation(*src.m_pReservations[i]);
                }
            }
        }
        return *this;
    }
    // Move Constructor
    Restaurant::Restaurant(Restaurant&& src)
    {
        *this = std::move(src);
    }
    // Move Assignment
    Restaurant& Restaurant::operator=(Restaurant&& src)
    {
        if (this != &src)
        {
            setEmpty();
            m_numOfResv = src.m_numOfResv;
            if (src.m_pReservations)
            {
                m_pReservations = src.m_pReservations;
                src.m_pReservations = nullptr;
            }
        }
        return *this;
    }
    Restaurant::~Restaurant()
    {
        setEmpty();
    }
    size_t seneca::Restaurant::size() const
    {
        return m_numOfResv;
    }
    std::ostream& operator<<(std::ostream& o, const Restaurant& rest)
    {
        static int CALL_CNT{};
        CALL_CNT++;
        o << "--------------------------\nFancy Restaurant ("
            << CALL_CNT << ")\n--------------------------\n";
        if (rest.m_pReservations)
        {
            for (size_t i = 0; i < rest.m_numOfResv; ++i)
            {
                o << *rest.m_pReservations[i];
            }
        }
        else
        {
            o << "This restaurant is empty!\n";
        }
        o << "--------------------------" << std::endl;
        return o;
    }
}
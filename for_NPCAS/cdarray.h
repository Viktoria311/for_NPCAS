#ifndef CDARRAY_H
#define CDARRAY_H

#include <iostream>

template<typename T>
class CDArray
{
    private:
        T * m_pData;
        int m_Number; // колич элементов
        int m_Size; // capasity
    public:
        CDArray() : m_Number(0), m_Size(1)
        {
            m_pData = nullptr;
        }

        CDArray(int size) : m_Number(0), m_Size(size)
        {
            m_pData = (T *)malloc(sizeof(T) * size);

            if (m_pData == NULL)
            {
                std::cout << "Memory Allocation Failed" << std::endl;
                exit(1);
            }
        }

        virtual ~CDArray()
        {
            free(m_pData);
        }

        int Add(const T & t)
        {
            *( m_pData + m_Number) = t;
            m_Number++;

            if (m_Number == m_Size)
            {
                T * new_ptr = (T *) realloc(m_pData, sizeof(T) * m_Size * 2);
                m_Size *= 2;

                if (new_ptr == NULL)
                {
                    std::cout << "Memory Reallocation Failed" << std::endl;
                    std::exit(1);
                }
                else
                {
                    m_pData = new_ptr;
                }
            }

            return m_Number;
        }

        int Delete(int number)
        {
            T * for_delete;

            int i = 0;

            for(; i < m_Number; ++i)
            {
                if (*(m_pData + i) == number) // если нашли нужный элемент
                {
                    // запомнить номер элемента для удаления
                    break;
                }
            }

            for(; i < m_Number - 1; ++i)
            {
                *(m_pData + i) = *(m_pData + i + 1);
            }

            --m_Number;

            return m_Number;
        }

        int Modify(int n, const T & t)
        {
            *(m_pData + n) = t;

            return 0;
        }

        int Resize(int size)
        {
            if (size == 0)
            {
                std::free(m_pData);
                m_pData = nullptr;
            }
            else
            {
                void * mem = std::realloc(m_pData, size);

                if (mem == NULL)
                {
                    std::cout << "Memory Reallocation Failed" << std::endl;
                    std::exit(1);
                }
                else
                {
                    m_pData = static_cast<T *>(mem);
                }
            }
        }

        void Clear()
        {
            m_Number = 0;
        }

        const T & operator[](int i) const
        {
            return *(m_pData + i);
        }
        T & operator[](int i)
        {
            return *(m_pData + i);
        }

        int Number() const
        {
            return m_Number;
        }

        int Size() const
        {
            return m_Size;
        }

        T * Ptr()
        {
            return m_pData;
        }

};

#endif




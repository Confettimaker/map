#ifndef MAP_ARRAY_H
#define MAP_ARRAY_H

#include <exception>

class OutOfBoundsException : public std::exception
{
  public:
    virtual const char * what() const throw()
    {
      return "Array out of bounds!";
    }
};

template <typename T>
class MapArray
{
  T * data;
  int m_size;
  int data_size;

  public:
    MapArray(const int size)
    {
      data = new T[size];
      m_size = size;
      data_size = 0;
    }
    ~MapArray()
    {
      delete [] data;
      data = nullptr;
    }

    void operator =(const MapArray<T> & rhs)
    {
      delete [] data;
      m_size = rhs.m_size;
      data = new T[m_size];
      data_size = rhs.data_size;
      for (int i = 0;i < data_size;i++)
      {
        data[i] = rhs.data[i];
      }
    }

    T & at(const int index)
    {
      if (index < data_size && index >= 0)
        return data[index];
      throw OutOfBoundsException();
    }

    T at(const int index) const
    {
      if (index < data_size && index >= 0)
        return data[index];
      throw OutOfBoundsException();
    }

    bool push(const T & val)
    {
      if (data_size < m_size)
      {
        data[data_size] = val;
        data_size ++;
        return true;
      }
      return false;
    }

    bool pop()
    {
      if (data_size > 0)
      {
        data_size --;
        return true;
      }
      return false;
    }

    int size() const
    {
      return data_size;
    }

    template <typename E>
    MapArray<T> map(E func) const
    {
      MapArray<T> temp(m_size);
      for (int i = 0;i < data_size;i++)
      {
        temp.push(func(data[i]));
      }
      return temp;
    }

};

#endif

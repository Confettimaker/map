#ifndef MAP_ARRAY_H
#define MAP_ARRAY_H

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

    template <typename E>
    void map(E func)
    {
      for (int i = 0;i < data_size;i++)
        func(data[i]);
    }

};

#endif
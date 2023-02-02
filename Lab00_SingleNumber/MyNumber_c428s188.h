#ifndef __MYNUMBER_H__
#define __MYNUMBER_H__

#include <algorithm>
#include <iostream>
using namespace std;

template <typename DataType>
class MyNumber
{
  public:
    explicit MyNumber(DataType rhs = 0) // default constructor
    {
        num = new DataType(rhs); //allocate memory for num and assign value of rhs to num
    }
    
    MyNumber(const MyNumber<DataType> & rhs)	// copy constructor with a MyNumber instance
    {
        num = new DataType(*rhs.num); //allocated memory for num and copy the value of rhs.num to num
    }
    
    MyNumber(MyNumber<DataType> && rhs)	// move constructor with a MyNumber instance
    {
        rhs.num = nullptr; //set the pointer to nullptr
    }
    
    MyNumber & operator= (const MyNumber<DataType> &rhs)	// copy assignment with a MyNumber instance
    {
        MyNumber copy = rhs; //copy the rhs to a temporary MyNumber instance
        swap(*this, copy); //swap the value of this and the temporary MyNumber instance
        return *this; //return value of this
    }

    MyNumber & operator= (MyNumber<DataType> && rhs)	// move assignment with a MyNumber instance 
    {
        swap(num, rhs.num); //swap the value of num and rhs.num
        return *this; //return value of this
    }

    ~MyNumber(void) // destructor
    {
        delete num; //delete the memory allocated for num
    }
    
    DataType read(void) const
    {   
        return *num; //return the value of num
    }

    void write(DataType rhs)
    {
        *num = rhs; //assign the value of rhs to num
    }

  private:
    /* data */
    DataType *num;
};


#endif // __MYVECTOR_H__
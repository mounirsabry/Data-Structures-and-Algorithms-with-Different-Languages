//The implementation file for the vector.h file.
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <cstdlib> //For NULL.
#include <iostream>
#include "../Headers/vector.h"
using namespace datastructures_mounir;

namespace datastructures_mounir
{
    template <typename T>
    Vector<T>::Vector()
        : array(NULL), capacity(0), length(0)
    {}

    template <typename T>
    Vector<T>::Vector(int initialCapacity)
        : array(NULL), capacity(initialCapacity), length(0)
    {
        if (initialCapacity < 0)
            capacity = 0;
        if (capacity == 0)
            return;
        try 
        {
            reserve(initialCapacity);
        }
        catch (std::bad_alloc e)
        {
            throw e;
        }
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T> &otherVector)
        : array(NULL), capacity(otherVector.capacity), length(otherVector.length)
    {
        if (capacity > 0)
            array = new T[capacity];
        if (length > 0)
        {
            copyArray(otherVector.array, array, length);
        }
    }

    template <typename T>
    Vector<T>::~Vector()
    {
        clear();
    }

    template <typename T>
    Vector<T> &Vector<T>::operator= (const Vector<T> &otherVector)
    {
        if (this == &otherVector)
            return *this;
        clear();
        capacity = otherVector.capacity;
        length = otherVector.length;
        if (capacity > 0)
            array = new T[capacity];
        if (length > 0)
        {
            copyArray(otherVector.array, array, length);
        }
        return *this;
    }

    template <typename T>
    void Vector<T>::reserve(int newCapacity)
    {
        if (newCapacity < 0)
            newCapacity = 0;
        if (newCapacity <= capacity)
            return;
        try 
        {
            if (length <= 0)
            {
                array = new T(newCapacity);
                capacity = newCapacity;
            }
            else
            {
                T *tempArray = new T(newCapacity);
                copyArray(array, tempArray, length);
                delete []array;
                array = tempArray;
                capacity = newCapacity;
            }
        }
        catch (std::bad_alloc e)
        {
            throw e;
        }
    }

    template <typename T>
    void Vector<T>::clear()
    {
        if (capacity > 0)
            delete []array;
        array = NULL;
        capacity = 0;
        length = 0;
    }

    template <typename T>
    int Vector<T>::getCapacity() const
    {
        return capacity;
    }

    template <typename T>
    int Vector<T>::getLength() const
    {
        return length;
    }

    template <typename T>
    bool Vector<T>::isEmpty() const
    {
        return (length <= 0);
    }

    template <typename T>
    T &Vector<T>::operator [](int index) const
    {
        return array[index];
    }

    template <typename T>
    T &Vector<T>::at(int index) const
    {
        if (index < 0 || index >= length)
            throw std::out_of_range("invalid index");
        return array[index];
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::find(const T &item) const
    {
        int itemIndex = -1;
        for (int i = 0; i < length; i++)
        {
            if (array[i] == item)
            {
                itemIndex = i;
                break;
            }
        }
        if (itemIndex == -1)
            return end();
        else
        {
            Vector<T>::Iterator iter(array, itemIndex);
            return iter;
        }
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::begin() const
    {
        if (length == 0)
            return end();
        Vector<T>::Iterator iter(array, 0);
        return iter;
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::last() const
    {
        if (length == 0)
            return end();
        Vector<T>::Iterator iter(array, length - 1);
        return iter;
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::end() const
    {
        Vector<T>::Iterator iter(array, length);
        return iter;
    }

    template <typename T>
    T &Vector<T>::front() const
    {
        return array[0];
    }

    template <typename T>
    T &Vector<T>::back() const
    {
        return array[length - 1];
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::insert(const typename Vector<T>::Iterator &location, const T &item)
    {
        if (location > end())
            return end();
        int index = location.getIndex();
        if (index < 0)
            return end();
        try 
        {
            if (capacity <= 0)
                reserve(DEFAULT_EMPTY_EXPAND_CAPACITY);
            else if (length >= capacity)
                reserve(capacity * 2);
        }
        catch (std::bad_alloc e)
        {
            return end();
        }
        //Shifing the element to insert the new element, relies on the
        //assignment operator of the vector datatype.
        for (int i = length; i > index; i--)
            array[i] = array[i - 1];
        array[index] = item;
        length++;
        Vector<T>::Iterator iter(array, index + 1);
        return iter;
    }

    template <typename T>
    typename Vector<T>::Iterator Vector<T>::pushBack(const T &item)
    {
        return insert(end(), item);
    }

    template <typename T>
    bool Vector<T>::popBack()
    {
        return erase(last());
    }

    template <typename T>
    bool Vector<T>::erase(const typename Vector<T>::Iterator &location)
    {
        if (location >= end())
            return false;
        int index = location.getIndex();
        if (index < 0)
            return false;
        for (int i = index; i < length - 1; i++)
        {
            array[i] = array[i + 1]; 
        }
        length--;
        return true;
    }

    template <typename T>
    void Vector<T>::copyArray(T *oldArray, T *newArray, int length) const
    {
        for (int i = 0; i < length; i++)
        {
            newArray[i] = oldArray[i];
        }
    }

    template <typename T>
    bool operator== (const Vector<T> &vector1, const Vector<T> &vector2)
    {
        if (vector1.length != vector2.length)
            return false;
        for (int i = 0; i < vector1.length; i++) //vector2.length should also work.
        {
            if (vector1[i] != vector2[i])
                return false;
        }
        return true;
    }

    template <typename T>
    std::ostream &operator<< (std::ostream& outStream, const Vector<T> &vector) 
    {
        if (vector.length > 0)
        {
            for (int i = 0; i < vector.length - 1; i++)
            {
                outStream << vector.at(i) << " ";
            }
            outStream << vector.at(vector.length - 1);
        }
        return outStream;
    }

    template <typename T>
    Vector<T>::Iterator::Iterator(T *arrayStartPointer, int index)
        : startPointer(arrayStartPointer), currentIndex(index)
    {}

    //Prefix operator.
    template <typename T>
    typename Vector<T>::Iterator &Vector<T>::Iterator::operator++ ()
    {
        currentIndex++;
        return *this;
    }

    //Postfix operator.
    template <typename T>
    typename Vector<T>::Iterator Vector<T>::Iterator::operator++ (int)
    {
        Vector<T>::Iterator temp = *this;
        currentIndex++;
        return temp;
    }

    //Prefix operator.
    template <typename T>
    typename Vector<T>::Iterator &Vector<T>::Iterator::operator-- ()
    {
        currentIndex--;
        return *this;
    }

    //Postfix template.
    template <typename T>
    typename Vector<T>::Iterator Vector<T>::Iterator::operator-- (int)
    {
        Vector<T>::Iterator temp = *this;
        currentIndex--;
        return temp;
    }

    template <typename T>
    typename Vector<T>::Iterator &Vector<T>::Iterator::operator+= (int offset)
    {
        currentIndex += offset;
        return *this;
    } 

    template <typename T>
    typename Vector<T>::Iterator &Vector<T>::Iterator::operator-= (int offset)
    {
        currentIndex -= offset;
        return *this;
    }

    template <typename T>
    T &Vector<T>::Iterator::operator* () const
    {
        return startPointer[currentIndex];
    }

    template <typename T>
    T &Vector<T>::Iterator::operator[] (int index) const
    {
        return startPointer[currentIndex + index];
    }

    template <typename T>
    int Vector<T>::Iterator::getIndex() const
    {
        return currentIndex;
    }
}

#endif
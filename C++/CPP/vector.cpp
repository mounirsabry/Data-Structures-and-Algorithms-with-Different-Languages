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
            for (int i = 0; i < length; i++)
                array[i] = otherVector[i];
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
            for (int i = 0; i < length; i++)
                array[i] = otherVector.array[i];
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
    int Vector<T>::insert(int index, const T &item)
    {
        if (index < 0 || index > length)
            return -1;
        try 
        {
            if (capacity <= 0)
                reserve(DEFAULT_EMPTY_EXPAND_CAPACITY);
            else if (length >= capacity)
                reserve(capacity * 2);
        }
        catch (std::bad_alloc e)
        {
            return -1;
        }
        //Shifing the element to insert the new element, relies on the
        //assignment operator of the vector datatype.
        for (int i = length; i > index; i--)
            array[i] = array[i - 1];
        array[index] = item;
        return length++;
    }

    template <typename T>
    int Vector<T>::pushBack(const T &item)
    {
        return insert(length, item);
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
    bool Vector<T>::erase(int index)
    {
        if (index < 0 || index >= length)
            return false;
        for (int i = index; i < length - 1; i++)
        {
            array[i] = array[i + 1]; 
        }
        length--;
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
}

#endif
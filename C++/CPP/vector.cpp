//The implementation file for the vector.h file.
#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <cstdlib> //For NULL.
#include <iostream>
#include <cmath>
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
        {
            try 
            {
                reserve(capacity);
            }
            catch (std::bad_alloc e)
            {
                throw e;
            }
        }
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
        {
            try 
            {
                reserve(capacity);
            }
            catch (std::bad_alloc e)
            {
                throw e;
            }
        }
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
                array = new T[newCapacity];
                capacity = newCapacity;
            }
            else
            {
                T *tempArray = new T[newCapacity];
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
    typename Vector<T>::Iterator Vector<T>::findSequential(const T &keyItem) const
    {
        int itemIndex = -1;
        for (int i = 0; i < length; i++)
        {
            if (array[i] == keyItem)
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
    typename Vector<T>::Iterator Vector<T>::findBinary(const T &keyItem) const
    {
        if (array == nullptr || length == 0)
            return end();
        if (length == 1)
        {
            if (array[0] == keyItem)
                return begin();
            else
                return end();
        }
        int minIndex = 0;
        int maxIndex = length - 1;
        while (minIndex <= maxIndex)
        {
            int midIndex = ceil(static_cast<double>(minIndex + maxIndex) / 2);
            if (array[midIndex] == keyItem)
            {
                Vector<T>::Iterator iter(array, midIndex);
                return iter;
            }
            else if (keyItem < array[midIndex])
                maxIndex = midIndex - 1;
            else
                minIndex = midIndex + 1;
        }
        return end();
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
    void Vector<T>::swap(const typename Vector<T>::Iterator &iter1,
                         const typename Vector<T>::Iterator &iter2)
    {
        int index1 = iter1.getIndex();
        int index2 = iter2.getIndex();

        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    template <typename T>
    void Vector<T>::sortSelectionSort()
    {
        if (array == nullptr || length == 0 || length == 1)
            return;
        for (int i = 0; i < length - 1; i++)
        {
            int smallestIndex = i;
            for (int j = i + 1; j < length; j++)
            {
                if (array[j] < array[smallestIndex])
                    smallestIndex = j;
            }
            if (smallestIndex != i)
                swap(array[i], array[smallestIndex]);
        }
    }

    template <typename T>
    void Vector<T>::sortInsertionSort()
    {
        if (array == nullptr || length == 0 || length == 1)
            return;
        for (int i = 1; i < length; i++)
        {
            int holeIndex = i;
            while ((array[holeIndex] < array[holeIndex - 1]) && (holeIndex >= 1))
            {
                swap(array[holeIndex], array[holeIndex - 1]);
                holeIndex--;
            }
        }
    }

    template <typename T>
    void Vector<T>::sortBubbleSort()
    {
        if (array == nullptr || length == 0 || length == 1)
            return;
        bool isSorted = false;
        while (!isSorted)
        {
            isSorted = true;
            for (int i = 0; i < length - 1; i++)
            {
                if (array[i] > array[i + 1])
                {
                    swap(array[i], array[i + 1]);
                    isSorted = false;
                }
            }
        }
    }

    template <typename T>
    void Vector<T>::sortQuickSort()
    {
        if (array == nullptr || length == 0 || length == 1)
        return;
        quickSortUtil(array, 0, length - 1);
    }

    template <typename T>
    void Vector<T>::sortMergeSort()
    {
        if (array == nullptr || length == 0 || length == 1)
            return;
        T *sortedArray = mergeSortUtil(array, 0, length - 1);
        for (int i = 0; i < length; i++)
            array[i] = sortedArray[i];
        delete []sortedArray;
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
    void Vector<T>::swap(T &element1, T &element2)
    {
        T temp = element1;
        element1 = element2;
        element2 = temp;
    }

    template <typename T>
    void Vector<T>::quickSortUtil(T *array, int minIndex, int maxIndex)
    {
        // == returns since a array with one element is already sorted.
        if (minIndex >= maxIndex) 
            return;

        int i = minIndex;
        int j = maxIndex;
        int pivotIndex = minIndex; 
        //could be changed to be any value within
        //the range [minIndex, maxIndex].
        while (i <= j)
        {
            while (array[i] <= array[pivotIndex])
                i++;
            while (array[j] > array[pivotIndex]) 
                j--;
            if (i <= j)
                swap(array[i], array[j]);
        }
        int sortedPosition = pivotIndex;
        if (j >= minIndex && j <= maxIndex && j != pivotIndex)
        {
            sortedPosition = j;
            swap(array[pivotIndex], array[sortedPosition]);
        }
        quickSortUtil(array, minIndex, sortedPosition - 1);
        quickSortUtil(array, sortedPosition + 1, maxIndex);
    }

    template <typename T>
    T *Vector<T>::mergeSortUtil(T *array, int minIndex, int maxIndex)
    {
        if (minIndex == maxIndex)
        {
            T *subList = nullptr;
            try
            {
                subList = new T[1];
            }
            catch(std::bad_alloc e)
            {
                throw e;
            }
            subList[0] = array[minIndex];
            return subList;
        }
        else
        {
            //The static cast to double is to force the mid element to be always
            //the first element in the second half similar to the binary search work.
            //Doing it the other way is fine but I prefered it this way for consistency.
            int midIndex = ceil(static_cast<double>(minIndex + maxIndex) / 2);
            //First half.
            //When length is even, it will be length / 2
            //When length is odd, it will be length /2 integer division
            //in other words, smaller than the second half by 1. 
            T *sortedArray1 = mergeSortUtil(array, minIndex, midIndex - 1);
            //Second half.
            //When length is even, it will be length / 2
            //When length is odd, it will be ceil (length / 2)
            //in other words, bigger than the first half by 1.
            T *sortedArray2 = mergeSortUtil(array, midIndex, maxIndex);
            int array1Length = midIndex - minIndex;
            int array2Length = maxIndex - midIndex + 1;
            T *sortedGroupArray = merge(sortedArray1, sortedArray2, array1Length, array2Length);
            delete []sortedArray1;
            delete []sortedArray2;
            return sortedGroupArray;
        }
    }

    template <typename T>
    T *Vector<T>::merge(T *array1, T *array2, int length1, int length2)
    {
        T *groupArray = nullptr;
        try
        {
            groupArray = new T[length1 + length2];
        }
        catch(std::bad_alloc e)
        {
            throw e;
        }
        int i = 0;
        int j = 0;
        int k = 0;
        while ((i < length1) && (j < length2))
        {
            if (array1[i] <= array2[j])
                groupArray[k++] = array1[i++];
            else
                groupArray[k++] = array2[j++];
        }

        while (i < length1)
            groupArray[k++] = array1[i++];
        while (j < length2)
            groupArray[k++] = array2[j++];
        return groupArray;
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
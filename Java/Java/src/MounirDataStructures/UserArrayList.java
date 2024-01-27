package MounirDataStructures;

import java.util.Comparator;

public class UserArrayList<T> implements UserList<T> {
    private int capacity;
    private int length;
    private Object[] array;
    private final int DEFAULT_INITIAL_CAPACITY = 10;

    public UserArrayList() {
        capacity = 0;
        grow(DEFAULT_INITIAL_CAPACITY);
        length = 0;
    }

    public UserArrayList(int initialCapacity) {
        capacity = 0;
        if (initialCapacity < 0)
            throw new IllegalArgumentException("initial capacity cannot be negative.");
        if (initialCapacity == 0)
            grow(DEFAULT_INITIAL_CAPACITY);
        else
            grow(initialCapacity);
        length = 0;
    }

    //Copy Constructor.
    public UserArrayList(UserArrayList<T> userArrayList) {
        capacity = 0;
        grow(userArrayList.capacity);
        copyArray(userArrayList.array, array, userArrayList.length);
        length = userArrayList.length;
    }

    public UserArrayList<T> copy() {
        UserArrayList<T> copy = new UserArrayList<>(this);
        return copy;
    }
    
    public void grow(int newCapacity) {
        if (newCapacity <= 0 || newCapacity <= capacity)
            return;

        if (capacity == 0) {
            array = new Object[newCapacity];
            capacity = newCapacity;
        } else {
            Object[] newArray = new Object[newCapacity];
            copyArray(array, newArray, length);
            array = newArray;
            capacity = newCapacity;
        }
    }

    private void copyArray(Object[] array, Object[] newArray, int length) {
        for (int i = 0; i < length; i++) {
            newArray[i] = array[i];
        }
    }

    @Override
    public void clear() {
        length = 0;
    }
    
    @Override
    public String toString() {
        String string = "[";
        for (int i = 0; i < length; i++) {
            if (i == length - 1)
                string += array[i].toString();
            else
                string += array[i].toString() + ", ";
        }
        string += "]";
        return string;
    }

    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object object) {
        UserArrayList<T> list;
        if (object instanceof UserArrayList)
            list = (UserArrayList<T>)object;
        else
            throw new ClassCastException("Object is not type of UserArrayList.");

        if (length != list.length)
            return false;
        for (int i = 0; i < length; i++) {
            if (!array[i].equals(list.array[i]))
                return false;
        }
        return true;
    }
    
    @Override
    public int getCapacity() {
        return capacity;
    }

    @Override
    public int getLength() {
        return length;
    }

    @Override
    public boolean isEmpty() {
        return (length == 0);
    }

    @Override
    @SuppressWarnings("unchecked")
    public T front() {
        return (T)(array[0]);
    }

    @Override
    @SuppressWarnings("unchecked")
    public T back() {
        return (T)(array[length - 1]);
    }

    @Override
    @SuppressWarnings("unchecked")
    public int getIndex(T key) {
        for (int i = 0; i < length; i++) {
            if ((T)array[i] == key)
                return i;
        }
        return -1;
    }

    private boolean isIndexValid(int index, boolean isLengthIndexAcceptable) {
        if (index < 0)
            return false;
        if (isLengthIndexAcceptable) {
            if (index > length)
                return false;
        } else {
            if (index >= length)
                return false;
        }
        return true;
    }

    @Override
    @SuppressWarnings("unchecked")
    public T get(int index) {
        if (!isIndexValid(index, false))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound.");
        return (T)(array[index]);
    }

    @Override
    public void set(int index, T newValue) {
        if (!isIndexValid(index, false))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound.");
        array[index] = newValue;
    }

    @Override
    public void add(T item) {
        if (length >= capacity)
            grow(capacity * 2);
        array[length] = item;
        length++;
    }

    @Override
    public void add(int index, T item) {
        if (!isIndexValid(index, true))
            return;
        if (length >= capacity)
            grow(capacity * 2);

        for (int i = length; i > index; i--)
            array[i] = array[i - 1];
        array[index] = item;
        length++;
    }

    @Override
    public void remove(int index) {
        if (!isIndexValid(index, false))
            return;
        
        for (int i = index; i < length - 1; i++)
            array[i] = array[i + 1];
        length--;
    }

    private void swap(T[] array, int index1, int index2) {
        T temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }

    @Override
    public void sort(Comparator<T> comp) {
        //Calls the default sorting algorithm.
        selectionSort(comp);
    }

    @SuppressWarnings("unchecked")
    public void selectionSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
        return;

        for (int i = 0; i < length - 1; i++) {
            int indexOfSmallest = i;
            for (int j = i + 1; j < length; j++) {
                if (comp.compare((T)array[j], (T)array[indexOfSmallest]) < 0)
                    indexOfSmallest = j;
            }
            if (indexOfSmallest != i) {
                swap((T[])array, i, indexOfSmallest);
            }
        }
    }

    @SuppressWarnings("unchecked")
    public void insertionSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        for (int i = 1; i < length; i++) {
            int holeIndex = i;
            while ((holeIndex >= 1) && (comp.compare((T)array[holeIndex], (T)array[holeIndex - 1]) < 0)) {
                swap((T[])array, holeIndex, holeIndex - 1);
                holeIndex--;
            }
        }
    }

    @SuppressWarnings("unchecked")
    public void bubbleSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        boolean isSorted = false;
        while (!isSorted) {
            isSorted = true;
            for (int i = 0; i < length - 1; i++) {
                if (comp.compare((T)array[i], (T)array[i + 1]) > 0) {
                    swap((T[])array, i, i + 1);
                    isSorted = false;
                }
            }
        }
    }

    @SuppressWarnings("unchecked")
    public void quickSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        quickSortUtil((T[])array, 0, length - 1, comp);
    }

    private void quickSortUtil(T[] array, int minIndex, int maxIndex, Comparator<T> comp) {
        if (minIndex >= maxIndex)
            return;

        int i = minIndex;
        int j = maxIndex;
        int pivotIndex = minIndex;

        while (i <= j) {
            while (i <= maxIndex && comp.compare((T)array[i], (T)array[pivotIndex]) <= 0)
                i++;
            while (j >= minIndex && comp.compare((T)array[j], (T)array[pivotIndex]) > 0)
                j--;
            if (i <= j)
                swap((T[])array, i, j);
        }
        int sortedPosition = pivotIndex;
        if (j != pivotIndex) {
            sortedPosition = j;
            swap((T[])array, pivotIndex, sortedPosition);
        }
        quickSortUtil(array, minIndex, sortedPosition - 1, comp);
        quickSortUtil(array, sortedPosition + 1, maxIndex, comp);
    }

    @SuppressWarnings("unchecked")
    public void mergeSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;
            
        T[] sortedArray = mergeSortUtil((T[])array, 0, length - 1, comp);
        for (int i = 0; i < length; i++)
            array[i] = sortedArray[i];
    }

    @SuppressWarnings("unchecked")
    private T[] mergeSortUtil(T[] array, int minIndex, int maxIndex, Comparator<T> comp) {
        if (minIndex == maxIndex) {
            T[] subList = (T[])new Object[1];
            subList[0] = array[minIndex];
            return subList;
        } else {
            int midIndex = (int)Math.ceil((double)(minIndex + maxIndex) / 2);
            T[] sortedArray1 = mergeSortUtil(array, minIndex, midIndex - 1, comp);
            T[] sortedArray2 = mergeSortUtil(array, midIndex, maxIndex, comp);
            
            T[] sortedGroupArray = merge(sortedArray1, sortedArray2, comp);
            return sortedGroupArray;
        }
    }

    @SuppressWarnings("unchecked")
    private T[] merge(T[] array1, T[] array2, Comparator<T> comp) {
        T[] groupArray = (T[])new Object[array1.length + array2.length];

        int i = 0;
        int j = 0;
        int k = 0;
        while ((i < array1.length) && (j < array2.length)) {
            if (comp.compare(array1[i], array2[j]) <= 0) 
                groupArray[k++] = array1[i++];
            else
                groupArray[k++] = array2[j++];
        }

        while (i < array1.length)
            groupArray[k++] = array1[i++];
        while (j < array2.length)
            groupArray[k++] = array2[j++];
        return groupArray;
    }

    public class UserArrayListIterator implements UserListIterator<T> {
        private int currentIndex;

        public UserArrayListIterator() {
            currentIndex = 0;
        }

        public UserArrayListIterator(int currentIndex) {
            this.currentIndex = currentIndex;
        }

        public UserArrayListIterator(UserArrayListIterator iter) {
            currentIndex = iter.currentIndex;
        }

        public UserArrayListIterator copy() {
            UserArrayListIterator copy = new UserArrayListIterator(this);
            return copy;
        }

        @Override
        public String toString() {
            return get(currentIndex).toString();
        }

        private UserArrayList<T> getOuterClassInstance() {
            return UserArrayList.this;
        }

        //I had to create getOuter function to get the outer class
        //of the UserArrayListIter of the parameter other.
        //Since I could get the outer UserArrayList instance of the calling object
        //through UserArrayList.this
        //But, I cannot get the outer UserArrayList instance of the other parameter
        //using other.UserArrayList.this
        //The solution was provided in the following thread.
        //https://stackoverflow.com/questions/1816458/getting-hold-of-the-outer-class-object-from-the-inner-class-object
        @Override
        @SuppressWarnings("unchecked")
        public boolean equals(Object object) {
            UserArrayListIterator castedIter;
            /*
                Here is had to use question mark or wildcard to solve the cannot
                be safely casted problem, it is fine since I do not depend on the parameter
                type on this function logic.
                The solution and the explanation were provided in the following threads.
                https://stackoverflow.com/questions/68808250/instanceof-check-throws-compiletimeerror-cannot-safely-cast

                https://www.geeksforgeeks.org/wildcards-in-java/
            */
            if (object instanceof UserArrayList<?>.UserArrayListIterator)
                castedIter = (UserArrayListIterator)object;
            else
                throw new ClassCastException("The object is not of type UserArrayListIterator.");

            if (getOuterClassInstance() != castedIter.getOuterClassInstance())
                return false;
            if (currentIndex != castedIter.currentIndex)
                return false;
            return true;
        }

        @Override
        public boolean hasNext() {
            return (currentIndex < length);
        }

        @Override
        public boolean hasPrevious() {
            return (currentIndex >= 0 && currentIndex < length);
        }

        @Override
        public void increment() {
            currentIndex++;
        }

        @Override
        public void decrement() {
            currentIndex--;
        }

        @Override
        public T getCurrent() {
            return get(currentIndex);
        }

        @Override
        public void setCurrent(T newValue) {
            set(currentIndex, newValue);
        }

        @Override
        public void addAtCurrent(T item) {
            add(currentIndex, item);
            currentIndex++;
        }

        @Override
        public void removeCurrent() {
            remove(currentIndex);
        }
    }

    //get Iterator function checks for the index to be valid, 
    //if the index is not valid then an exception is thrown.
    @Override
    public UserArrayListIterator getIterator(int index) {
        if (!isIndexValid(index, true))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound.");
        return new UserArrayListIterator(index);
    }

    @Override
    public UserArrayListIterator begin() {
        return new UserArrayListIterator(0);
    }

    @Override
    public UserArrayListIterator end() {
        return new UserArrayListIterator(length);
    }
}

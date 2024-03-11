using System.Text;

namespace Mounir_DataStructures
{
    public class UserArrayList<T> : IUserList<T>
    {
        private int length;
        private T?[] array;
        public int Capacity
        {
            get { return array.Length; }
        }
        public int Count
        {
            get { return length; }
        }
        private const int DEFAULT_CAPACITY = 10;
        private static readonly StringBuilder builder = new(100);

        public UserArrayList()
        {
            length = 0;
            array = [];
            GrowArray(DEFAULT_CAPACITY);
        }

        public UserArrayList(int initialCapacity)
        {
            length = 0;
            array = [];

            if (initialCapacity < 0)
                throw new InvalidDataException("Capacity is negative.");
            else if (initialCapacity == 0)
                GrowArray(DEFAULT_CAPACITY);
            else
                GrowArray(initialCapacity);
        }

        public UserArrayList(UserArrayList<T> otherArray)
        {
            array = [];
            GrowArray(otherArray.Capacity);
            length = otherArray.length;

            CopyArrayShallow(otherArray.array, array, length);
        }

        public UserArrayList(IUserList<T> otherList)
        {
            if (GetType() != otherList.GetType())
                throw new InvalidCastException("The list is not of type UserArrayList");
            UserArrayList<T> otherArray = (UserArrayList<T>)otherList;

            array = [];
            GrowArray(otherArray.Capacity);
            length = otherArray.length;

            CopyArrayShallow(otherArray.array, array, length);
        }

        private void GrowArray(int newCapacity)
        {
            if (newCapacity <= 0 || newCapacity <= Capacity)
                return;

            if (length == 0)
                array = new T[newCapacity];
            else
            {
                T[] newArray = new T[newCapacity];
                CopyArrayShallow(array, newArray, length);
                array = newArray;
            }
        }

        private static void CopyArrayShallow(T?[] array, T?[] newArray, int length)
        {
            for (int i = 0; i < length; i++)
            {
                newArray[i] = array[i];
            }
        }

        public object Clone()
        {
            UserArrayList<T> clone = new(this);
            return clone;
        }

        public override string? ToString()
        {
            builder.Clear();
            builder.Append('[');
            
            for (int i = 0; i < length; i++)
            {
                builder.Append(array[i]); //array[i] is either a value or null.
                if (i != length - 1)
                    builder.Append(", ");
            }

            builder.Append(']');
            return builder.ToString();
        }

        public override bool Equals(object? obj)
        {
            if (obj == null || GetType() != obj.GetType())
                return false;
            if (this == obj) //Same reference values.
                return true;

            UserArrayList<T> other = (UserArrayList<T>)obj;
            if (length != other.length)
                return false;
            
            for (int i = 0; i < length; i++)
            {
                if (array[i] != null && other.array[i] != null)
                {
                    //Here I had to use the null forgiving operator since the
                    //compiler does not pick up that I already checked array[i]
                    //and I am certain that it is not null.
                    if (array[i]!.Equals(other.array[i]) == false)
                        return false;
                }
                else if (array[i] == null && other.array[i] != null
                ||  array[i] != null && other.array[i] == null)
                {
                    return false;
                }
                //The fourth case it that both values are null, which makes them equal.
            }
            return true;
        }

        public override int GetHashCode()
        {
            int hashCodeSum = 0;
            foreach (T? element in array)
            {
                hashCodeSum += element?.GetHashCode() ?? 0;
            }
            return hashCodeSum;
        }

        public void Clear()
        {
            //Here I could have de-allocated the space
            //but I prefered not to, so that it saves the user
            //the performance of allocating the same space again
            //if the user continued to use the list after de-allocation.
            length = 0;
        }

        public bool IsEmpty()
        {
            return length == 0;
        }

        public T? this[int index]
        {
            get { return Get(index); }
            set { Set(index, value); }
        }

        public T? Front()
        {
            if (length == 0)
                throw new IndexOutOfRangeException("The array is empty.");
            
            return array[0];
        }

        public T? Back()
        {
            if (length == 0)
                throw new IndexOutOfRangeException("The array is empty.");

            return array[length - 1];
        }

        public int GetIndex(T? key)
        {
            for (int i = 0; i < length; i++)
            {
                if (array[i] == null && key == null)
                    return i;
                else if (array[i] != null && array[i]!.Equals(key))
                    return i;
            }
            return -1;
        }

        public T? Get(int index)
        {
            if (index < 0 || index >= length)
                throw new IndexOutOfRangeException($"Index is invalid, index was {index}.");

            return array[index];
        }

        public void Set(int index, T? newValue)
        {
            if (index < 0 || index >= length)
                throw new IndexOutOfRangeException($"Index is invalid, index was {index}.");

            array[index] = newValue;
        }

        public void Add(T? item)
        {
            if (length == Capacity)
                GrowArray(Capacity * 2);

            array[length++] = item;
        }

        public bool Insert(int index, T? item)
        {
            if (index < 0 || index > length) //length index could be used to add items at the end of the list.
                return false;

            if (length == Capacity)
                GrowArray(Capacity * 2);

            //Shift the array to the right to create a gap
            //to insert the new element.
            //The loop should be skiped if the index was length.
            for (int i = length; i > index; i--)
            {
                array[i] = array[i - 1];
            }

            array[index] = item;
            length++;
            return true;
        }

        public bool Remove(T? item)
        {
            int itemIndex = GetIndex(item);
            if (itemIndex == -1)
                return false;
            
            return RemoveAt(itemIndex);
        }

        public bool RemoveAt(int index)
        {
            if (index < 0 || index >= length)
                return false;
            
            //Shift the array to the left to fill the gap
            //created by deleting the element.
            for (int i = index; i < length - 1; i++)
            {
                array[i] = array[i + 1];
            }
            length--;
            return true;
        }

        public void Sort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;
            //Calls the default sorting algorithm.
            SortQuickSort(comparer);
        }

        public void SortSelectionSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            for (int i = 0; i < length - 1; i++)
            {
                int indexOfSmallest = i;
                for (int j = i + 1; j < length; j++)
                {
                    if (comparer.Compare(array[j], array[indexOfSmallest]) < 0)
                        indexOfSmallest = j;
                }
                if (indexOfSmallest != i)
                {
                    //Swap using tuples.
                    (array[i], array[indexOfSmallest]) = (array[indexOfSmallest], array[i]);
                }
            }
        }

        public void SortInsertionSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            for (int i = 1; i < length; i++)
            {
                int holeIndex = i;
                while ((holeIndex - 1) >= 0 && comparer.Compare(array[holeIndex], array[holeIndex - 1]) < 0)
                {
                    (array[holeIndex], array[holeIndex - 1]) = (array[holeIndex - 1], array[holeIndex]);
                    holeIndex--;
                }
            }
        }

        public void SortBubbleSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            bool isSorted = false;
            while (!isSorted)
            {
                isSorted = true;
                for (int i = 0; i < length - 1; i++)
                {
                    if (comparer.Compare(array[i], array[i + 1]) > 0)
                    {
                        (array[i], array[i + 1]) = (array[i + 1], array[i]);
                        isSorted = false;
                    }
                }
            }
        }

        public void SortQuickSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            QuickSortUtil(array, 0, length - 1, comparer);
        }

        private static void QuickSortUtil(T?[] array, int minIndex, int maxIndex, IComparer<T> comparer)
        {
            if (minIndex >= maxIndex)
                return;

            int i = minIndex;
            int j = maxIndex;
            int pivotIndex = minIndex; //Could be anyvalue.

            while (i <= j)
            {
                while (i <= maxIndex && comparer.Compare(array[i], array[pivotIndex]) <= 0)
                    i++;
                while (j >= minIndex && comparer.Compare(array[j], array[pivotIndex]) > 0)
                    j--;

                if (i <= j)
                {
                    (array[i], array[j]) = (array[j], array[i]);
                }
            }

            int sortedPosition = pivotIndex; //Initial value.
            if (j != pivotIndex)
            {
                sortedPosition = j;
                (array[pivotIndex], array[sortedPosition]) = (array[sortedPosition], array[pivotIndex]);
            }

            QuickSortUtil(array, minIndex, sortedPosition - 1, comparer);
            QuickSortUtil(array, sortedPosition + 1, maxIndex, comparer);
        }

        public void SortMergeSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            T?[] sortedArray = MergeSortUtil(array, 0, length - 1, comparer);
            for (int i = 0; i < length; i++)
                array[i] = sortedArray[i];
        }

        private static T?[] MergeSortUtil(T?[] array, int minIndex, int maxIndex, IComparer<T> comparer)
        {
            if (minIndex == maxIndex)
            {
                return [array[minIndex]];
            }
            else
            {
                int midIndex = (int)Math.Ceiling((double)(minIndex + maxIndex) / 2);
                var sortedArray1 = MergeSortUtil(array, minIndex, midIndex - 1, comparer);
                var sortedArray2 = MergeSortUtil(array, midIndex, maxIndex, comparer);

                var sortedGroupArray = Merge(sortedArray1, sortedArray2, comparer);
                return sortedGroupArray;
            }
        }

        private static T?[] Merge(T?[] array1, T?[] array2, IComparer<T> comparer)
        {
            var groupArray = new T?[array1.Length + array2.Length];

            int i = 0;
            int j = 0;
            int k = 0;
            while (i < array1.Length && j < array2.Length)
            {
                if (comparer.Compare(array1[i], array2[j]) <= 0)
                    groupArray[k++] = array1[i++];
                else
                    groupArray[k++] = array2[j++];
            }

            while (i < array1.Length)
                groupArray[k++] = array1[i++];
            while (j < array2.Length)
                groupArray[k++] = array2[j++];

            return groupArray;

        }
    }
}
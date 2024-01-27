using System.Text;

namespace Mounir_DataStructures
{
    public class UserList<T> : IUserList<T>
    {
        private class ListNode
        {
            public T? Value { get; set; }
            public ListNode? Previous { get; set; }
            public ListNode? Next { get; set; }

            public ListNode()
            {
                Value = default;
                Previous = null;
                Next = null;
            }

            public ListNode(T? value, ListNode? previous, ListNode? next)
            {
                Value = value;
                Previous = previous;
                Next = next;
            }

            public ListNode(ListNode otherNode)
            {
                Value = otherNode.Value;
                Previous = otherNode.Previous;
                Next = otherNode.Next;
            }

            public override string? ToString()
            {
                return Value?.ToString();
            }

            public override bool Equals(object? obj)
            {
                if (obj == null || GetType() != obj.GetType())
                    return false;
                if (this == obj) //Reference Comparsion.
                    return true;

                ListNode other = (ListNode)obj;
                if (Previous != other.Previous ||
                    Next != other.Next)
                {
                    return false;
                }
                if (Value == null && other.Value == null)
                {
                    return true;
                }
                else if (Value == null && other.Value != null
                ||  Value != null && other.Value == null)
                {
                    return false;
                }
                //Save Null Forgiving Operator since I already checked for null.
                else if (Value!.Equals(other.Value) == false)
                {
                    return false;
                }
                return true;
            }

            public override int GetHashCode()
            {
                //Shortend the code using the null coalescing operator
                //combined with the null conditional operator.
                return Value?.GetHashCode() ?? 0;
            }
        }
        private int length;
        private ListNode head;
        private ListNode tail;
        private readonly ListNode endNode;
        public int Capacity
        {
            get { return length; }
        }
        public int Count
        {
            get { return length; }
        }
        private readonly StringBuilder builder = new(100);

        public UserList()
        {
            endNode = new();
            head = endNode;
            tail = endNode;
            length = 0;
        }

        public UserList(UserList<T> otherList)
        : this() //Calls the default constructor to initiate the variables with default values.
        {
            //If the iter.Next is null, then iter is otherList.endNode, then the loop will stop
            //and the increment will not happen.
            //If the iter is not at the endNode yet, then iter.Next will never be null, 
            //This is why I safely added the Null forgiving operator.
            for (ListNode iter = otherList.head; iter != otherList.endNode; iter = iter.Next!)
            {
                Add(iter.Value);
            }
        }

        public UserList(IUserList<T> otherAbstractList)
        : this()
        {
            if (GetType() != otherAbstractList.GetType())
                throw new InvalidCastException();
            UserList<T> otherList = (UserList<T>)otherAbstractList;

            for (ListNode iter = otherList.head; iter != otherList.endNode; iter = iter.Next!)
            {
                Add(iter.Value);
            }
        }

        public override string? ToString()
        {
            builder.Clear();
            builder.Append('[');

            //Save null forgiving operator.
            for (ListNode iter = head; iter != endNode; iter = iter.Next!)
            {
                builder.Append(iter.Value); //Value is either some T or null.
                if (iter != tail)
                    builder.Append(", ");
            }

            builder.Append(']');
            return builder.ToString();
        }

        public override bool Equals(object? obj)
        {
            if (obj == null || GetType() != obj.GetType())
                return false;
            if (this == null) //Both points to the same object.
                return true;

            UserList<T> other = (UserList<T>)obj;
            if (length != other.length)
                return false;
            
            ListNode iter1 = head;
            ListNode iter2 = other.head;
            while (iter1 != endNode && iter1 is not null && iter2 is not null)
            {
                if (iter1.Value is null && iter2.Value is not null ||
                    iter1.Value is not null && iter2.Value is null)
                {
                    return false;
                }
                else if (iter1.Value?.Equals(iter2.Value) == false)
                {
                    return false;
                }

                iter1 = iter1.Next!;
                iter2 = iter2.Next!;
            }
            return true;
        }

        public override int GetHashCode()
        {
            int hashCodeSum = 0;
            for (ListNode iter1 = head; iter1 != endNode; iter1 = iter1.Next!)
            {
                hashCodeSum += iter1.Value?.GetHashCode() ?? 0;
            }
            return hashCodeSum;
        }

        public void Clear()
        {
            length = 0;
            head = endNode;
            tail = endNode;
            endNode.Previous = null;
        }

        public bool IsEmpty()
        {
            return length == 0;
        }

        public T? Front()
        {
            if (length == 0)
                throw new IndexOutOfRangeException("List is empty.");
            
            return head.Value;
        }

        public T? Back()
        {
            if (length == 0)
                throw new IndexOutOfRangeException("List is empty.");

            return tail.Value;
        }

        /*
            The user attempted to enhance the performance of the navigating by starting
            from the end that is closer to the index.
            Effectively dividing the average distance to reach the node by two.
        */
        private ListNode NavigateToNodeByIndex(int index)
        {
            if (index == length) //The caller wants the endNode.
                return endNode;

            //The function assumes that index is always valid since it is a private function.
            int midIndex = length / 2;
            ListNode desiredNode;
            if (index < midIndex) //Start navigation from the head.
            {
                int currentIndex = 0;
                desiredNode = head;
                while (currentIndex < index)
                {
                    desiredNode = desiredNode.Next!;
                    currentIndex++;
                }
            }
            else //Start navigation from the tail.
            {
                int currentIndex = length - 1;
                desiredNode = tail;
                while (currentIndex > index)
                {
                    desiredNode = desiredNode.Previous!;
                    currentIndex--;
                }
            }
            return desiredNode;
        }

        /*
            The function helps simplifies the code of any function 
            that searches for the node by value and wants the index
            or the actual node or both.
        */
        private (int, ListNode) NavigateToNodeByValue(T? item)
        {
            ListNode desiredNode = endNode;
            int nodeIndex = -1;

            int currentIndex = 0;
            for (ListNode iter = head; iter != endNode; iter = iter.Next!)
            {
                if (iter.Value is null && item is null ||
                    iter.Value is not null && iter.Value.Equals(item))
                {
                    desiredNode = iter;
                    nodeIndex = currentIndex;
                    break;
                }
                currentIndex++;
            }

            return (nodeIndex, desiredNode);
        }

        public int GetIndex(T? key)
        {
            (int index, _) = NavigateToNodeByValue(key);
            return index;
        }

        public T? Get(int index)
        {
            if (index < 0 || index >= length)
                throw new IndexOutOfRangeException($"Index is invalid, index was {index}");

            return NavigateToNodeByIndex(index).Value;
        }

        public void Set(int index, T? newValue)
        {
            if (index < 0 || index >= length)
                throw new IndexOutOfRangeException($"Index is invalid, index was {index}");

            NavigateToNodeByIndex(index).Value = newValue;
        }

        public void Add(T? item)
        {
            //Insertion at the end of the list.
            ListNode newNode = new(item, tail, endNode);

            endNode.Previous = newNode;
            tail = newNode;
            
            if (length == 0) //List was empty
                head = newNode;
            length++;
        }

        public bool Insert(int index, T? item)
        {
            if (index < 0 || index >= length)
                return false;

            ListNode indexNode = NavigateToNodeByIndex(index);
            ListNode newNode = new(item, indexNode.Previous, indexNode);

            //The function will always enter this condition if the list is empty.
            if (indexNode == head) //Insertion at start of the list, right before the indexNode
            {
                indexNode.Previous = newNode;
                head = newNode;
                if (length == 0) //List was empty.
                    tail = newNode;
            }
            else if (indexNode == tail) //Insertion at the end of the list, right before the indexNode.
            {
                //tail.Previous could never be null because if that is the case, then the control
                //would have entered the == head condition instead of this one.
                tail.Previous!.Next = newNode;
                tail.Previous = newNode;
            }
            else if (indexNode == endNode) //Insertion at the end of the list, after the indexNode.
            {
                //Save null forgiving operator.
                endNode.Previous!.Next = newNode;
                tail.Next = newNode;
                tail = newNode;
            }
            else //Insertion at the middle of the list.
            {
                //Save null forgiving operator.
                indexNode.Previous!.Next = newNode;
                indexNode.Previous = newNode;
            }
            length++;
            return true;
        }

        private void Remove(ListNode deletedNode)
        {
            //The function assumes that deletedNode is always valid node and it is not
            //the endNode (since you can't delete the endNode).
            if (deletedNode == head)
            {
                head.Next!.Previous = null;
                head = head.Next;
                if (length == 1) //The list will become empty.
                    tail = endNode;
            }
            else if (deletedNode == tail)
            {
                tail.Previous!.Next = endNode;
                endNode.Previous = tail.Previous;
                tail = tail.Previous;
            }
            else //Deletion at the middle of the list.
            {
                deletedNode.Previous!.Next = deletedNode.Next;
                deletedNode.Next!.Previous = deletedNode.Previous;
            }
            length--;
        }

        public bool Remove(T? item)
        {
            (_, ListNode desiredNode) = NavigateToNodeByValue(item);
            if (desiredNode == endNode)
                return false;

            Remove(desiredNode);
            return true;
        }

        public bool RemoveAt(int index)
        {
            if (index < 0 || index >= length)
                return false;

            ListNode desiredNode = NavigateToNodeByIndex(index);
            Remove(desiredNode);
            return true;
        }

        public void Sort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;
            //Calls the default sorting algorithm.
            SortSelectionSort(comparer);
        }

        public void SortSelectionSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            for (ListNode iter1 = head; iter1 != tail; iter1 = iter1.Next!)
            {
                ListNode smallestNode = iter1;
                for (ListNode iter2 = iter1.Next!; iter2 != endNode; iter2 = iter2.Next!)
                {
                    if (comparer.Compare(iter2.Value, smallestNode.Value) < 0)
                        smallestNode = iter2;
                }

                if (smallestNode != iter1)
                {
                    (smallestNode.Value, iter1.Value) = (iter1.Value, smallestNode.Value);
                }
            }
        }

        public void SortInsertionSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            for (ListNode iter1 = head.Next!; iter1 != endNode; iter1 = iter1.Next!)
            {
                ListNode holeNode = iter1;
                while (holeNode != head && comparer.Compare(holeNode.Previous!.Value, holeNode.Value) > 0)
                {
                    (holeNode.Previous.Value, holeNode.Value) = (holeNode.Value, holeNode.Previous.Value);
                    holeNode = holeNode.Previous;
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
                for (ListNode iter1 = head; iter1 != tail; iter1 = iter1.Next!)
                {
                    if (comparer.Compare(iter1.Value, iter1.Next!.Value) > 0)
                    {
                        (iter1.Value, iter1.Next.Value) = (iter1.Next.Value, iter1.Value);
                        isSorted = false;
                    }
                }
            }
        }

        public void SortQuickSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            QuickSortUtil(head, endNode, comparer);
        }

        private void QuickSortUtil(ListNode startNode, ListNode endNode, IComparer<T> comparer)
        {
            if (startNode == endNode || startNode.Next == endNode)
                return;

            ListNode iNode = startNode;
            ListNode jNode = endNode;
            ListNode pivotNode = startNode; //Could be any another value.

            while (iNode.Previous != jNode && iNode != jNode)
            {
                while (iNode!.Next != endNode && comparer.Compare(iNode.Value, pivotNode.Value) <= 0)
                    iNode = iNode.Next!;
                
                while (jNode.Previous != null && jNode.Previous != startNode &&
                       comparer.Compare(jNode.Value, pivotNode.Value) > 0)
                    jNode = jNode.Previous;

                if (iNode.Previous != jNode && iNode != jNode)
                    (iNode.Value, jNode.Value) = (jNode.Value, iNode.Value);
            }   

            ListNode sortedPositionNode = pivotNode;
            if (jNode != pivotNode)
            {
                sortedPositionNode = jNode;
                (pivotNode.Value, sortedPositionNode.Value) = (sortedPositionNode.Value, pivotNode.Value);
            }

            QuickSortUtil(startNode, sortedPositionNode, comparer);
            QuickSortUtil(sortedPositionNode.Next!, endNode, comparer);
        }

        public void SortMergeSort(IComparer<T> comparer)
        {
            if (length == 0 || length == 1)
                return;

            var sortedList = MergeSortUtil(head, endNode, 0, length - 1, comparer);
            head = sortedList.head;
            tail = sortedList.tail;
            endNode.Previous = sortedList.endNode.Previous;
        }

        private UserList<T> MergeSortUtil(ListNode startNode, ListNode endNode, int minIndex, int maxIndex, IComparer<T> comparer)
        {
            if (startNode == endNode)
            {
                UserList<T> subList = new();
                subList.Add(startNode.Value);
                return subList;
            }
            else
            {
                int midIndex = (int)Math.Ceiling((double)(minIndex + maxIndex) / 2);
                ListNode midNode = NavigateToNodeByIndex(midIndex);
                var sortedList1 = MergeSortUtil(startNode, midNode, minIndex, midIndex - 1, comparer);
                var sortedList2 = MergeSortUtil(midNode, endNode, midIndex, maxIndex, comparer);

                var sortedGroupList = Merge(sortedList1, sortedList2, comparer);
                return sortedGroupList;
            }
        }

        private static UserList<T> Merge(UserList<T> list1, UserList<T> list2, IComparer<T> comparer)
        {
            UserList<T> groupList = new();
            ListNode iter1 = list1.head;
            ListNode iter2 = list2.head;

            while (iter1 != list1.endNode && iter2 != list2.endNode)
            {
                if (comparer.Compare(iter1.Value, iter2.Value) <= 0)
                {
                    groupList.Add(iter1.Value);
                    iter1 = iter1.Next!;
                }
                else
                {
                    groupList.Add(iter2.Value);
                    iter2 = iter2.Next!;
                }
            }

            while (iter1 != list1.endNode)
            {
                groupList.Add(iter1.Value);
                iter1 = iter1.Next!;
            }
            while (iter1 != list2.endNode)
            {
                groupList.Add(iter2.Value);
                iter2 = iter2.Next!;
            }

            return groupList;
        }
    }
}
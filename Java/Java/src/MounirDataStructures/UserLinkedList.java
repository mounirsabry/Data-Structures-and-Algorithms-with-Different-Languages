package MounirDataStructures;

import java.util.Comparator;

public class UserLinkedList<T> implements UserList<T> {
    private class UserLinkedListNode {
        private T item;
        private UserLinkedListNode previous;
        private UserLinkedListNode next;

        public UserLinkedListNode() {
            item = null;
            previous = null;
            next = null;
        }

        public UserLinkedListNode(T item, UserLinkedListNode previous, UserLinkedListNode next) {
            this.item = item;
            this.previous = previous;
            this.next = next;
        }

        public UserLinkedListNode(UserLinkedListNode other) {
            item = other.item;
            previous = other.previous;
            next = other.next;
        }

        @SuppressWarnings("unused")
        public UserLinkedListNode copy() {
            UserLinkedListNode copy = new UserLinkedListNode(this);
            return copy;
        }

        public String toString() {
            return item.toString();
        }

        private UserLinkedList<T> getOuterClassInstance() {
            return UserLinkedList.this;
        }

        @SuppressWarnings("unchecked")
        public boolean equals(Object object) {
            UserLinkedListNode castedNode;
            if (object instanceof UserLinkedList<?>.UserLinkedListNode)
                castedNode = (UserLinkedListNode)object;
            else
                throw new ClassCastException("The object is not of type UserLinkedListNode.");
            
            if (getOuterClassInstance() != castedNode.getOuterClassInstance())
                return false;
            if (item != castedNode.item) 
                return false;
            if (previous != castedNode.previous || next != castedNode.next)
                return false;
            return true;
        }
    }

    private int length;
    private UserLinkedListNode head;
    private UserLinkedListNode tail;
    private UserLinkedListNode endNode;

    public UserLinkedList() {
        length = 0;
        endNode = new UserLinkedListNode(null, null, null);
        head = endNode;
        tail = endNode;
    }

    public UserLinkedList(UserLinkedList<T> other) {
        length = 0;
        endNode = new UserLinkedListNode(null, null, null);

        UserLinkedListNode currentNode = other.head;
        while (currentNode != other.endNode) {
            add(currentNode.item);
            currentNode = currentNode.next;
        }
    }

    public UserLinkedList<T> copy() {
        UserLinkedList<T> copy = new UserLinkedList<>(this);
        return copy;
    }

    @Override
    public void clear() {
        head = endNode;
        tail = endNode;
        endNode.previous = null;
        length = 0;
    }

    @Override
    public String toString() {
        String string = "[";
        UserLinkedListNode currentNode = head;
        for (int index = 0; index < length; index++) {
            string += currentNode.toString();
            if (index != length - 1)
                string += ", ";
            currentNode = currentNode.next;
        }
        string += "]";
        return string;
    }

    @Override
    @SuppressWarnings("unchecked")
    public boolean equals(Object object) {
        UserLinkedList<T> castedList;
        if (object instanceof UserLinkedList<?>)
            castedList = (UserLinkedList<T>)object;
        else
            throw new ClassCastException("The object is not of type UserLinkedList.");

        if (length != castedList.length)
            return false;
        
        UserLinkedListNode iter1 = head;
        UserLinkedListNode iter2 = castedList.head;
        while (iter1 != endNode) {
            //I did not use node.equals here since the nodes will not
            //belong to the same list.
            if (!iter1.item.equals(iter2.item))
                return false;
            iter1 = iter1.next;
            iter2 = iter2.next;
        }
        return true;
    }

    @Override
    public int getCapacity() {
        return getLength();
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
    public T front() {
        if (head == endNode) {
            throw new IndexOutOfBoundsException("List is empty.");
        }
        return head.item;
    }

    @Override
    public T back() {
        if (tail == endNode) {
            throw new IndexOutOfBoundsException("List is empty.");
        }
        return tail.item;
    }

    private UserLinkedListNode navigateToNodeByIndex(int index) {
        if (index == length)
            return endNode;
        else if (index > length) { //This is done for safety, but should never trigger since the function is private.
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound.");
        }
        UserLinkedListNode desiredNode;
        UserLinkedListNode currentNode;

        if (index < length / 2) { //navigate from the head.
            currentNode = head;
            for (int i = 0; i < index; i++) {
                currentNode = currentNode.next;
            }
            desiredNode = currentNode;
        } else { //navigate from the tail.
            currentNode = tail;
            for (int i = length - 1; i > index; i--) {
                currentNode = currentNode.previous;
            }
            desiredNode = currentNode;
        }
        return desiredNode;
    }

    @Override
    public int getIndex(T key) {
        UserLinkedListNode desiredNode = head;
        for (int i = 0; i < length; i++) {
            if (desiredNode.item.equals(key)) {
                return i;
            }
            desiredNode = desiredNode.next;
        }
        return -1;
    }

    private boolean isIndexValid(int index, boolean isLengthIndexAcceptable) {
        if (index < 0)
            return false;
        if (isLengthIndexAcceptable) {
            if (!(index <= length))
                return false;
        } else {
            if (!(index < length))
                return false;
        }
        return true;
    }

    @Override
    public T get(int index) {
        if (!isIndexValid(index, false))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound");
        return navigateToNodeByIndex(index).item;
    }

    @Override
    public void set(int index, T newValue) {
        if (!isIndexValid(index, false))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound");
        navigateToNodeByIndex(index).item = newValue;
    }

    @Override
    public void add(T item) {
        UserLinkedListNode newNode = new UserLinkedListNode();
        newNode.item = item;

        if (length == 0) { //The list is empty.
            newNode.next = endNode;
            endNode.previous = newNode;
            head = newNode;
            tail = newNode;
        } else {
            newNode.next = endNode;
            newNode.previous = tail;
            
            tail.next = newNode;
            endNode.previous = newNode;
            tail = newNode;
        }
        length++;
    }

    @Override
    public void add(int index, T item) {
        if (!isIndexValid(index, true))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound");
        if (index == length) { //insertion at the endNode.
            add(item);
            return;
        }

        UserLinkedListNode newNode = new UserLinkedListNode();
        newNode.item = item;

        UserLinkedListNode currentNode = navigateToNodeByIndex(index);
        
        if (currentNode == head) { //insertion at the start of the list.
            newNode.next = head;
            head.previous = newNode;
            head = newNode;
        } else if (currentNode == tail) { //insertion at the end of the list, right before the last element.
            newNode.next = tail;
            newNode.previous = tail.previous;
            //tail.previous cannot be null, because if it is, then then the currentNode is the
            //head node and the program will not enter this condition.
            tail.previous.next = newNode; 
            tail.previous = newNode;
        } else { //insertion at the middle.
            newNode.previous = currentNode.previous;
            newNode.next = currentNode;
            currentNode.previous.next = newNode;
            currentNode.previous = newNode;
        }
        length++;
    }

    @Override
    public void remove(int index) {
        if (!isIndexValid(index, false))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound");

        UserLinkedListNode deletedNode = navigateToNodeByIndex(index);
        if (deletedNode == head) { //Deletion at the start of the list.
            head.next.previous = null;
            head = head.next;
        } else if (deletedNode == tail) { //Deletion of the last element of the list.
            tail.previous.next = endNode;
            endNode.previous = tail.previous;
            tail = tail.previous;
        } else { //Deletion in the middle.
            deletedNode.previous.next = deletedNode.next;
            deletedNode.next.previous = deletedNode.previous;
        }
        length--;

        if (length == 0)  {
            tail = endNode;
        }
    }

    private void swapValues(UserLinkedListNode node1, UserLinkedListNode node2) {
        T temp = node1.item;
        node1.item = node2.item;
        node2.item = temp;
    }

    @Override
    public void sort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;
        selectionSort(comp);
    }

    public void selectionSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        for (var iter1 = head; iter1 != tail; iter1 = iter1.next) {
            UserLinkedListNode smallestNode = iter1;
            for (var iter2 = iter1.next; iter2 != endNode; iter2 = iter2.next) {
                if (comp.compare(iter2.item, smallestNode.item) < 0)
                    smallestNode = iter2;
            }
            if (!smallestNode.equals(iter1)) {
                swapValues(iter1, smallestNode);
            }
        }
    }

    public void insertionSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        for (var iter1 = head.next; iter1 != endNode; iter1 = iter1.next) {
            UserLinkedListNode holeNode = iter1;
            while ((holeNode.previous != null) && (comp.compare(holeNode.item, holeNode.previous.item) < 0)) {
                swapValues(holeNode, holeNode.previous);
                holeNode = holeNode.previous;
            }
        }
    }

    public void bubbleSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        boolean isSorted = false;
        while (!isSorted) {
            isSorted = true;
            for (var iter = head; iter != tail; iter = iter.next) {
                if (comp.compare(iter.item, iter.next.item) > 0) {
                    swapValues(iter, iter.next);
                    isSorted = false;
                }
            }
        }
    }

    public void quickSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        quickSortUtil(head, endNode, comp);
    }

    private void quickSortUtil(UserLinkedListNode startNode, UserLinkedListNode endNode, Comparator<T> comp) {
        if (startNode == endNode || startNode.next == endNode)
            return;

        UserLinkedListNode iNode = startNode;
        UserLinkedListNode jNode = endNode.previous;
        UserLinkedListNode pivotNode = startNode;
                                                                                                                                       
        while (iNode.previous != jNode && iNode != jNode) {
            while ((iNode.next != endNode) && (comp.compare(iNode.item, pivotNode.item) <= 0))
                iNode = iNode.next;
            while ((jNode.previous != null) && (jNode.next != startNode) &&
                    (comp.compare(jNode.item, pivotNode.item) > 0)) {
                jNode = jNode.previous;
            }

            if (iNode.previous != jNode && iNode != jNode)
                swapValues(iNode, jNode);
        }

        UserLinkedListNode sortedPositionNode = pivotNode;
        if (jNode != pivotNode) {
            sortedPositionNode = jNode;
            swapValues(pivotNode, sortedPositionNode);
        }
        quickSortUtil(startNode, sortedPositionNode, comp);
        quickSortUtil(sortedPositionNode.next, endNode, comp);
    }

    public void mergeSort(Comparator<T> comp) {
        if (length == 0 || length == 1)
            return;

        UserLinkedList<T> sortedList = mergeSortUtil(head, endNode, 0, length - 1, comp);
        this.head = sortedList.head;
        this.tail = sortedList.tail;
        this.endNode = sortedList.endNode;
    }

    private UserLinkedList<T> mergeSortUtil(UserLinkedListNode startNode, UserLinkedListNode endNode,
            int minIndex, int maxIndex, Comparator<T> comp) {
        if (startNode.next == endNode) {
            UserLinkedList<T> subList = new UserLinkedList<>();
            subList.add(startNode.item);
            return subList;
        } else {
            int midIndex = (int)Math.ceil((double)(minIndex + maxIndex) / 2);
            var midNode = navigateToNodeByIndex(midIndex);
            UserLinkedList<T> sortedList1 = mergeSortUtil(startNode, midNode, minIndex, midIndex - 1, comp);
            UserLinkedList<T> sortedList2 = mergeSortUtil(midNode, endNode, midIndex, maxIndex, comp);
            
            UserLinkedList<T> sortedGroupList = merge(sortedList1, sortedList2, comp);
            return sortedGroupList;
        }
    }

    private UserLinkedList<T> merge(UserLinkedList<T> list1, UserLinkedList<T> list2, Comparator<T> comp) {
        UserLinkedList<T> groupList = new UserLinkedList<>();
        var iter1 = list1.head;
        var iter2 = list2.head;

        while ((iter1 != list1.endNode) && (iter2 != list2.endNode)) {
            if (comp.compare(iter1.item, iter2.item) <= 0) {
                groupList.add(iter1.item);
                iter1 = iter1.next;
            }
            else {
                groupList.add(iter2.item);
                iter2 = iter2.next;
            }
        }

        while (iter1 != list1.endNode) {
            groupList.add(iter1.item);
            iter1 = iter1.next;
        }
        while (iter2 != list2.endNode) {
            groupList.add(iter2.item);
            iter2 = iter2.next;
        }
        return groupList;
    }

    public class UserLinkedListIterator implements UserListIterator<T> {
        private UserLinkedListNode currentNode;

        public UserLinkedListIterator() {
            currentNode = head;
        }

        public UserLinkedListIterator(UserLinkedListNode node) {
            currentNode = node;
        }

        public UserLinkedListIterator(UserLinkedListIterator other) {
            currentNode = other.currentNode;
        }

        public UserLinkedListIterator copy() {
            UserLinkedListIterator copy = new UserLinkedListIterator(this);
            return copy;
        }

        public String toString() {
            if (currentNode.item == null)
                return null;
            return currentNode.toString();
        }

        private UserLinkedList<T> getOuterClassInstance() {
            return UserLinkedList.this;
        }

        @Override
        @SuppressWarnings("unchecked")
        public boolean equals(Object object) {
            UserLinkedListIterator castedIter;
            if (object instanceof UserLinkedList<?>.UserLinkedListIterator)
                castedIter = (UserLinkedListIterator)object;
            else
                throw new ClassCastException("The object is not of type UserLinkedListIterator.");

            if (getOuterClassInstance() != castedIter.getOuterClassInstance())
                return false;
            else if (!currentNode.equals(castedIter.currentNode)) 
                return false;
            return true;
        }

        @Override
        public boolean hasNext() {
            if (currentNode == endNode || currentNode.next != endNode)
                return true;
            return false;
        }

        @Override
        public boolean hasPrevious() {
            if (currentNode.previous != null) 
                return true;
            return false;
        }

        @Override
        public void increment() {
            if (currentNode != endNode)
                currentNode = currentNode.next;
        }

        @Override
        public void decrement() {
            if (hasPrevious())
                currentNode = currentNode.previous;
        }

        @Override
        public T getCurrent() {
            return currentNode.item;
        }

        @Override
        public void setCurrent(T newValue) {
            currentNode.item = newValue;
        }

        @Override
        public void addAtCurrent(T item) {
            UserLinkedListNode newNode = new UserLinkedListNode();
            newNode.item = item;

            if (length == 0) { //Empty list.
                newNode.next = endNode;
                endNode.previous = newNode;
                head = newNode;
                tail = newNode;
            } else if (currentNode == head) { //Insertion at the start of the list.
                newNode.next = head;
                head.previous = newNode;
                head = newNode;
            } else if (currentNode == tail) { //Insertion at the end of the list, right before the last element.
                newNode.previous = tail.previous;
                newNode.next = tail;
                tail.previous.next = newNode;
                tail.previous = newNode;
            } else if (currentNode == endNode) { //Insertion at the endNode, after the last element.
                newNode.previous = tail;
                newNode.next = endNode;
                endNode.previous = newNode;
                tail.next = newNode;
                tail = newNode;
            } else { //Insertion at the middle of the list.
                newNode.previous = currentNode.previous;
                newNode.next = currentNode;
                currentNode.previous.next = newNode;
                currentNode.previous = newNode;
            }
            length++;
        }

        @Override
        public void removeCurrent() {
            if (currentNode == endNode) //The endNode cannot be deleted.
                return;

            if (currentNode == head) { //Deleting from the start of the list.
                head.next.previous = null;
                head = head.next;
                currentNode = head;
            } else if (currentNode == tail) { //Deleting from the end of the list.
                tail.previous.next = endNode;
                endNode.previous = tail.previous;
                tail = tail.previous;
                currentNode = endNode;
            } else { //Deleting from the middle of the list.
                currentNode.previous.next = currentNode.next;
                currentNode.next.previous = currentNode.previous;
                currentNode = currentNode.next;
            }
            length--;

            if (length == 0) {
                tail = endNode;
            }
        }

    }

    @Override
    public UserListIterator<T> getIterator(int index) {
        if (!isIndexValid(index, true))
            throw new IndexOutOfBoundsException("invalid index, index " + index + " is out of bound");
        return new UserLinkedListIterator(navigateToNodeByIndex(index));
    }

    @Override
    public UserListIterator<T> begin() {
        return new UserLinkedListIterator(head);
    }

    @Override
    public UserListIterator<T> end() {
        return new UserLinkedListIterator(endNode);
    }
}

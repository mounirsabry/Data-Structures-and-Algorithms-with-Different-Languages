import java.util.List;
import java.util.ArrayList;
import java.util.Comparator;

import MounirDataStructures.*;

public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        System.out.println(list);
        System.out.println(list.toString());
        System.out.println();

        //testUserArrayList1();
        //testUserArrayList1Iterators();

        /*
        String string1 = "Mounir";
        String string2 = string1;
        System.out.println("Setting string2 = string1.");
        if (string1 == string2) {
            System.out.println("== says: string1 equals string2.");
        }
        if (string1.equals(string2)) {
            System.out.println(".equals says: string1 equals string2.");
        }
        System.out.println();

        System.out.println("Setting string2 to have a value of its own.");
        string2 = new String("Mounir");
        //string2 = "Mounir";
        if (string1 == string2) {
            System.out.println("== says: string1 equals string2.");
        }
        if (string1.equals(string2)) {
            System.out.println(".equals says: string1 equals string2.");
        }
        System.out.println();

        System.out.println("Creating a third string and setting it up using string literal.");
        String string3 = "Mounir";
        if (string1 == string3) {
            System.out.println("== says: string1 equals string3.");
        }
        if (string1.equals(string3)) {
            System.out.println(".equals says: string1 equals string3.");
        }
        */

        testUserLinkedList1();
        //testUserLinkedListIterators1();
        //testUserStack1();
        //testUserQueue1();

        /*
        ArrayList<Integer> array1 = new ArrayList<>();
        array1.add(111);
        array1.add(54);
        array1.add(11);
        array1.add(543);
        System.out.println(array1);
        array1.sort(null);
        System.out.println(array1);
        */
    }

    public static Comparator<Integer> getComparatorInt() {
        return new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                if (o1 < o2) return -1;
                else if (o1 == o2) return 0;
                else return 1;
            }
        };
    }

    public static void testUserArrayList1() {

        System.out.println("Testing User Array List 1.0");
        UserList<Integer> list1 = new UserArrayList<>();
        System.out.println("List capacity :" + list1.getCapacity());
        System.out.println("List length :" + list1.getLength());
        System.out.println("List is empty :" + list1.isEmpty());
        list1.add(1);
        list1.add(2);
        list1.add(3);
        System.out.println(list1);
        System.out.println(list1.toString());

        System.out.println("List capacity :" + list1.getCapacity());
        System.out.println("List length :" + list1.getLength());
        System.out.println("List is empty :" + list1.isEmpty());

        UserArrayList<Integer>list2 = ((UserArrayList<Integer>)list1).copy();
        System.out.println(list1.equals(list2));
        System.out.println(list1 == list2);
        list2.add(4);
        System.out.println(list1.equals(list2));
        System.out.println(list1 == list2);

        System.out.println("After cloning the list and adding 4.");
        System.out.println("List1 :" + list1);
        System.out.println("List2 :" + list2);
        
        list1.clear();
        System.out.println("After clearing list1.");
        System.out.println("List1 capacity :" + list1.getCapacity());
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("List1 is empty :" + list1.isEmpty());

        list1.add(1);
        list1.add(3);
        list1.add(1, 2);
        list1.add(3, 4);
        list1.add(0, 10);
        list1.add(4, 40);
        System.out.println("Testing adding elements at different locations.");
        System.out.println("List1 :" + list1);
        System.out.println("List1 length :" + list1.getLength());

        list1.remove(0);
        list1.remove(2);
        //This did not work, since the last index was 3, the function
        //does not through exception.
        list1.remove(4); 
        list1.remove(3);
        System.out.println("Testing removing elements at different locations.");
        System.out.println("List1 :" + list1);
        System.out.println("List1 length :" + list1.getLength());

        System.out.println(list1.getIndex(1));
        System.out.println(list1.getIndex(2));
        System.out.println(list1.getIndex(40));
        System.out.println(list1.getIndex(3));
        System.out.println("List1 front :" + list1.front());
        System.out.println("List2 back :" + list2.back());

        System.out.println("list2 :" + list2);
        list2.add(123);
        list2.add(456);
        list2.add(987);
        System.out.println("After adding more elements to list2.");
        System.out.println("list2 :" + list2);
        System.out.println(list2.get(list2.getLength() - 1));
        System.out.println(list2.get(0));
        
        list2.set(list2.getLength() - 1, 1000);
        list2.set(0, 100);
        System.out.println("list2 :" + list2);

        System.out.println("adding more elements to list2 to test grow.");
        for (int i = 1; i < 5; i++)
            list2.add(i * i);
        System.out.println("List2 capacity :" + list2.getCapacity());
        System.out.println("List2 length :" + list2.getLength());

        UserList<Double> list3 = new UserArrayList<>(1);
        list3.add(1.0);
        list3.add(2.0);
        System.out.println("List3 :" + list3);
        System.out.println("List3 capacity :" + list3.getCapacity());
        System.out.println("List3 length :" + list3.getLength());

        list3.add(15.9);
        list3.add(38.4);
        list3.add(234.5);
        System.out.println("List3 :" + list3);
        System.out.println("List3 capacity :" + list3.getCapacity());
        System.out.println("List3 length :" + list3.getLength());

        UserList<Integer> testSort = new UserArrayList<>();
        testSort.add(187);
        testSort.add(54);
        testSort.add(30);
        testSort.add(11);
        testSort.add(22);
        UserArrayList<Integer> testArrayListSort1 = new UserArrayList<>((UserArrayList<Integer>)testSort);
        UserArrayList<Integer> testArrayListSort2 = new UserArrayList<>((UserArrayList<Integer>)testSort);
        UserArrayList<Integer> testArrayListSort3 = new UserArrayList<>((UserArrayList<Integer>)testSort);
        UserArrayList<Integer> testArrayListSort4 = new UserArrayList<>((UserArrayList<Integer>)testSort);

        System.out.println("List testSort Before: " + testSort);

        testSort.sort(getComparatorInt());
        System.out.println("List testSort After Selection: " + testSort);

        testArrayListSort1.insertionSort(getComparatorInt());
        System.out.println("List testSort After Insertion: " + testArrayListSort1);

        testArrayListSort2.bubbleSort(getComparatorInt());
        System.out.println("List testSort After Bubble: " + testArrayListSort2);

        testArrayListSort3.quickSort(getComparatorInt());
        System.out.println("List testSort After Quick: " + testArrayListSort3);

        testArrayListSort4.mergeSort(getComparatorInt());
        System.out.println("List testSort After Merge: " + testArrayListSort4);

    }

    public static void testUserArrayList1Iterators() {
        UserList<String> list1 = new UserArrayList<>();
        UserListIterator<String> iter1 = tryGetIterator(list1, 1);
        //The following two will throw an exception, IndexOutOfBoundsException: invalid index, index 0 is out of bound.
        //System.out.println(iter1.getItem());
        //System.out.println(iter1);
        iter1.addAtCurrent("Mounir");
        iter1.addAtCurrent("Sabry");
        iter1.addAtCurrent("Youssef");
        System.out.println("List1 :" + list1);
        iter1.removeCurrent();
        System.out.println("List1 after removing item: " + list1);
        //This will throw an exception, since after deleting the last item
        //in the list, the iter is pointing at the end of the list.
        //System.out.println(iter1);

        //To check this theory, let's compare it to the end().
        if (iter1.equals(list1.end()))
            System.out.println(".equals() says: iter1 is end.");
        
        if (iter1 == list1.end())
            System.out.println("== says: iter1 is end.");

        if (!iter1.hasNext())
            System.out.println("hasNext says: the iter does not have any elements remaining.");

        iter1.decrement();
        System.out.println(iter1);
        System.out.println(iter1.getCurrent());;

        UserListIterator<String> iter2 = list1.begin();
        iter2.removeCurrent();
        iter2.removeCurrent();
        System.out.println("List1 after removing two items from the start: " + list1);
    }

    private static <T> UserListIterator<T> tryGetIterator(UserList<T> list, int index) {
        UserListIterator<T> iter;
        try {
            iter = list.getIterator(index);
        } catch (IndexOutOfBoundsException e) {
            System.out.println("The function getIterator threw an exception, index " + index + " was not valid.");
            System.out.println("The iter is now end.");
            iter = list.end();
        } 
        return iter;
    }

    public static void testUserLinkedList1() {
        UserLinkedList<Integer> list1 = new UserLinkedList<>();

        System.out.println("List1 capacity :" + list1.getCapacity());
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("List1 is empty :" + list1.isEmpty());
        System.out.println(list1);
        list1.add(1);
        list1.add(2);
        list1.add(3);
        System.out.println("List1 capacity :" + list1.getCapacity());
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("List1 is empty :" + list1.isEmpty());
        System.out.println("List1 :" + list1);
        System.out.println("list1 front :" + list1.front());
        System.out.println("list1 back :" + list1.back());
        System.out.println("list1 get index(1) :" + list1.getIndex(1));
        System.out.println("List1 get index(2) :" + list1.getIndex(2));
        System.out.println("List1 get index(3) :" + list1.getIndex(3));
        System.out.println("List1 get index(19) :" + list1.getIndex(19));

        System.out.println("List1 get(0) :" + list1.get(0));
        System.out.println("List1 get(1) :" + list1.get(1));
        System.out.println("List1 get(2) :" + list1.get(2));
        //This will throw out of bound exception.
        //System.out.println("List1 get(3) :" + list1.get(3));
        list1.set(0, 10);
        list1.set(1, 20);
        list1.set(2, 30);
        System.out.println("After setting some values using set function.");
        System.out.println("list1 :" + list1);
        list1.add(1, 25);
        list1.add(0, 0);
        list1.add(4, 100);
        list1.add(3, 22);
        list1.add(7, 1000);
        //This will throw out of bound.
        //list1.add(9, 123);
        System.out.println("After inserting values at random indexes at list.");
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("list1 :" + list1);
        list1.remove(7);
        list1.remove(0);
        list1.remove(3);
        System.out.println("After removing some data from the list.");
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("list1 :" + list1);
        while (!list1.isEmpty())
            list1.remove(0);
        System.out.println("After emptying the list using remove.");
        System.out.println("List1 capacity :" + list1.getCapacity());
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("list1 :" + list1);
        list1.add(1);
        list1.add(2);
        list1.clear();
        System.out.println("List1 capacity :" + list1.getCapacity());
        System.out.println("List1 length :" + list1.getLength());
        System.out.println("list1 :" + list1);

        UserLinkedList<Integer> list2 = new UserLinkedList<>();
        System.out.println(list1.equals(list2));
        list1.add(1);
        list2.add(1);
        System.out.println(list1.equals(list2));
        list1.add(2);
        System.out.println(list1.equals(list2));

        UserLinkedList<Integer> list3 = new UserLinkedList<>();
        UserLinkedList<Double> list4 = new UserLinkedList<>();
        list3.add(1);
        list4.add(1.0);
        System.out.println(list3.equals(list4));
        //System.out.println(1 == 1.0);

        UserList<Integer> testSortList1 = new UserLinkedList<>();
        testSortList1.add(187);
        testSortList1.add(54);
        testSortList1.add(30);
        testSortList1.add(11);
        testSortList1.add(22);

        var testSortList2 = new UserLinkedList<>((UserLinkedList<Integer>)testSortList1);
        var testSortList3 = new UserLinkedList<>((UserLinkedList<Integer>)testSortList1);
        var testSortList4 = new UserLinkedList<>((UserLinkedList<Integer>)testSortList1);
        var testSortList5 = new UserLinkedList<>((UserLinkedList<Integer>)testSortList1);

        System.out.println("List testSort Before: " + testSortList1);

        testSortList1.sort(getComparatorInt());
        System.out.println("List testSort After selection: " + testSortList1);

        testSortList2.insertionSort(getComparatorInt());
        System.out.println("List testSort After insertion: " + testSortList2);

        testSortList3.bubbleSort(getComparatorInt());
        System.out.println("List testSort After bubble: " + testSortList3);

        testSortList4.quickSort(getComparatorInt());
        System.out.println("List testSort After quick: " + testSortList4);

        testSortList5.mergeSort(getComparatorInt());
        System.out.println("List testSort After merge: " + testSortList5);
    }

    public static void testUserLinkedListIterators1() {
        System.out.println("Testing User Linked List Iterators 1.");
        UserList<Double> list1 = new UserLinkedList<>();
        UserListIterator<Double> iter1 = tryGetIterator(list1, 0);
        System.out.println(iter1);
        System.out.println(iter1.getCurrent());
        
        iter1.addAtCurrent(1.0);
        iter1.addAtCurrent(2.0);
        iter1.addAtCurrent(3.0);
        System.out.println("List 1: " + list1);
        iter1.decrement();
        iter1.decrement();
        iter1.addAtCurrent(10.0);
        UserListIterator<Double> iter2 = tryGetIterator(list1, 0);
        iter2.addAtCurrent(100.0);
        iter2.setCurrent(22.0);
        System.out.println("List 1: " + list1);
        iter2 = list1.begin();
        iter2.removeCurrent();
        iter1.removeCurrent();
        iter1 = list1.end();
        iter1.decrement();
        iter1.removeCurrent();
        iter1 = list1.end();
        iter1.removeCurrent();
        System.out.println("List 1: " + list1);
        
        while (!list1.isEmpty())
            iter2.removeCurrent();
        System.out.println("List 1: " + list1);

        iter2.addAtCurrent(111.0);
        iter2.addAtCurrent(22.0);
        iter2.addAtCurrent(23.0);
        System.out.println("List 1: " + list1);

        iter1 = list1.begin();
        System.out.println("iter1: " + iter1);
        while (iter1.hasNext()) {
            iter1.increment();
            System.out.println("iter1: " + iter1);
        }
        iter2 = list1.end();
        while (iter2.hasPrevious()) {
            iter2.decrement();
            System.out.println("iter2: " + iter2);
        }

        for (var iter = list1.begin(); !iter.equals(list1.end()); iter.increment()) {
            System.out.println("iter :" + iter);
        }
    }

    public static void testUserStack1() {
        UserStack<Integer> stack1 = new UserStack<>();
        stack1.pushBack(1);
        stack1.pushBack(2);
        stack1.pushBack(3);

        System.out.println("Stack1 peek front: " + stack1.peekFront());
        System.out.println("Stack1 peek back: " + stack1.peekBack());
        System.out.println("Stack1: " + stack1);
        stack1.popBack();
        System.out.println("Stack1 length: " + stack1.getLength());
        System.out.println("Stack1 is empty: " + stack1.isEmpty());
        System.out.println("Stack1: " + stack1);
        
        stack1.clear();
        System.out.println("Stack1 length: " + stack1.getLength());
        System.out.println("Stack1 is empty: " + stack1.isEmpty());
        System.out.println("Stack1: " + stack1);

        var stack2 = new UserStack<>(stack1);
        System.out.println(stack1 == stack2);
        System.out.println(stack1.equals(stack2));

        stack1.pushBack(1);
        System.out.println(stack1.equals(stack2));
        stack2.pushBack(1);
        System.out.println(stack1.equals(stack2));
    }

    public static void testUserQueue1() {
        UserQueue<Integer> queue1 = new UserQueue<>();
        System.out.println("Queue1 is empty: " + queue1.isEmpty());
        System.out.println("Queue1 length: " + queue1.getLength());
        System.out.println("Queue1: " + queue1);

        queue1.pushBack(1);
        queue1.pushBack(2);
        queue1.pushBack(3);
        System.out.println("Queue1 is empty: " + queue1.isEmpty());
        System.out.println("Queue1 length: " + queue1.getLength());
        System.out.println("Queue1: " + queue1);

        System.out.println("Queue1 peek front: " + queue1.peekFront());
        System.out.println("Queue1 peek back: " + queue1.peekBack());
        queue1.popFront();
        System.out.println("Queue1: " + queue1.toString());
    }
}

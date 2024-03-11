using System.Collections;
using Mounir_DataStructures;

const int MIN_VALUE = 0;
const int MAX_VALUE = 50;
//TestUserArrayList1(MIN_VALUE, MAX_VALUE);
//TestUserList1(MIN_VALUE, MAX_VALUE);
IUserList<int> list = new UserArrayList<int>();
list.Add(1);
list.Add(2);
//The following requires the list to be IEnumerable.
// foreach (int integer in list)
// {

// }

#pragma warning disable CS8321 // Disables unused functions warnings for all functions.
void TestUserArrayList1(int minGeneratedValue, int maxGeneratedValue)
{
    IUserList<int> list1 = new UserArrayList<int>(2);
    Console.WriteLine("The list was created with 2 as the default capacity.");
    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);

    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);
    Console.WriteLine("list1 Front: " + list1.Front());
    Console.WriteLine("list1 Back: " + list1.Back());

    Console.WriteLine("list1 getindex of 1: " + list1.GetIndex(1));
    Console.WriteLine("list1 getindex of 10: " + list1.GetIndex(10));
    Console.WriteLine("list1 get 1: " + list1.Get(1));
    
    Console.WriteLine("Adding more data.");
    list1.Insert(0, 10); //At the start.
    list1.Insert(4, 101); //At the endNode.
    list1.Insert(4, 50); //At the tail.
    list1.Insert(2, 22); //At the middle.

    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);

    IUserList<int> list2 = new UserArrayList<int>(list1);
    Console.WriteLine("Is list1 == list2: " + (list1 == list2));
    Console.WriteLine("Is list1 Equals list2: " + list1.Equals(list2));
    Console.WriteLine("list1 hashcode: " + list1.GetHashCode());
    Console.WriteLine("list2 hashcode: " + list2.GetHashCode());
    list1.Set(0, 1);
    list1.Set(1, 2);
    Console.WriteLine("After setting some data in list1.");
    Console.WriteLine("Is list1 == list2: " + (list1 == list2));
    Console.WriteLine("Is list1 Equals list2: " + list1.Equals(list2));
    Console.WriteLine("list1 hashcode: " + list1.GetHashCode());
    Console.WriteLine("list2 hashcode: " + list2.GetHashCode());

    Console.WriteLine("Testing [] functions.");
    Console.WriteLine("list2[0]: " + list2[0]);
    Console.WriteLine("list2[5]: " + list2[5]);
    Console.WriteLine("Setting some values in list2.");
    list2[4] = 33;
    list2[5] = 55;
    Console.WriteLine("list2: " + list2);

    Console.WriteLine("Remvoing some data from list2.");
    list2.Remove(10);
    list2.Remove(22);
    list2.Remove(200); //data does not exist.
    list2.RemoveAt(4); //from the end.
    list2.RemoveAt(1); //from the mid.
    list2.RemoveAt(0); //from the start.
    list2.RemoveAt(10); //out of range index.
    Console.WriteLine("list2: " + list2);
    Console.WriteLine("list1 Capacity: " + list2.Capacity);
    Console.WriteLine("list1 Count: " + list2.Count);

    Console.WriteLine("Clearing list2.");
    list2.Clear();
    Console.WriteLine("list2: " + list2);
    Console.WriteLine("list2 Capacity: " + list2.Capacity);
    Console.WriteLine("list2 Count: " + list2.Count);

    UserArrayList<int> list3 = new();
    for (int i = 0; i < 6; i++)
    {
        Random rand = new();
        list3.Add(rand.Next(minGeneratedValue, maxGeneratedValue));
    }

    Console.WriteLine("List 3 is a random generated list.");
    Console.WriteLine("list3: " + list3);

    var list3Copy1 = (UserArrayList<int>)list3.Clone();
    var list3Copy2 = (UserArrayList<int>)list3.Clone();
    var list3Copy3 = (UserArrayList<int>)list3.Clone();
    var list3Copy4 = (UserArrayList<int>)list3.Clone();

    IComparer<int> comparer = new IntComparer();
    list3Copy1.SortSelectionSort(comparer);
    Console.WriteLine("Selection Sort: " + list3Copy1);

    list3Copy2.SortInsertionSort(comparer);
    Console.WriteLine("Insertion Sort: " + list3Copy2);

    list3Copy3.SortBubbleSort(comparer);
    Console.WriteLine("Bubble Sort: " + list3Copy3);

    list3.Sort(comparer); //Default sorting algorithm fro UserArrayList.
    Console.WriteLine("Quick Sort: " + list3);

    list3Copy4.SortMergeSort(comparer);
    Console.WriteLine("Merge Sort: " + list3Copy4);
}

void TestUserList1(int minGeneratedValue, int maxGeneratedValue)
{
    IUserList<int> list1 = new UserList<int>();
    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);

    list1.Add(1);
    list1.Add(2);
    list1.Add(3);

    Console.WriteLine("Is list empty: " + list1.IsEmpty());
    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);
    Console.WriteLine("list1 Front: " + list1.Front());
    Console.WriteLine("list1 Back: " + list1.Back());

    Console.WriteLine("list1 getindex of 1: " + list1.GetIndex(1));
    Console.WriteLine("list1 getindex of 10: " + list1.GetIndex(10));
    Console.WriteLine("list1 get 1: " + list1.Get(1));
    
    Console.WriteLine("Adding more data.");
    list1.Insert(0, 10); //At the start.
    list1.Insert(4, 101); //At the endNode.
    list1.Insert(4, 50); //At the tail.
    list1.Insert(2, 22); //At the middle.

    Console.WriteLine("list1: " + list1);
    Console.WriteLine("list1 Capacity: " + list1.Capacity);
    Console.WriteLine("list1 Count: " + list1.Count);
    
    IUserList<int> list2 = new UserList<int>(list1);
    Console.WriteLine("Is list1 == list2: " + (list1 == list2));
    Console.WriteLine("Is list1 Equals list2: " + list1.Equals(list2));
    Console.WriteLine("list1 hashcode: " + list1.GetHashCode());
    Console.WriteLine("list2 hashcode: " + list2.GetHashCode());
    list1.Set(0, 1);
    list1.Set(1, 2);
    Console.WriteLine("After setting some data in list1.");
    Console.WriteLine("Is list1 == list2: " + (list1 == list2));
    Console.WriteLine("Is list1 Equals list2: " + list1.Equals(list2));
    Console.WriteLine("list1 hashcode: " + list1.GetHashCode());
    Console.WriteLine("list2 hashcode: " + list2.GetHashCode());

    Console.WriteLine("Testing [] functions.");
    Console.WriteLine("list2[0]: " + list2[0]);
    Console.WriteLine("list2[5]: " + list2[5]);
    Console.WriteLine("Setting some values in list2.");
    list2[4] = 33;
    list2[5] = 55;
    Console.WriteLine("list2: " + list2);
    
    Console.WriteLine("Remvoing some data from list2.");
    list2.Remove(10);
    list2.Remove(22);
    list2.Remove(200); //data does not exist.
    list2.RemoveAt(4); //from the end.
    list2.RemoveAt(1); //from the mid.
    list2.RemoveAt(0); //from the start.
    list2.RemoveAt(10); //out of range index.
    Console.WriteLine("list2: " + list2);
    Console.WriteLine("list1 Capacity: " + list2.Capacity);
    Console.WriteLine("list1 Count: " + list2.Count);

    Console.WriteLine("Clearing list2.");
    list2.Clear();
    Console.WriteLine("list2: " + list2);
    Console.WriteLine("list2 Capacity: " + list2.Capacity);
    Console.WriteLine("list2 Count: " + list2.Count);
    
    UserList<int> list3 = new();
    for (int i = 0; i < 6; i++)
    {
        Random rand = new();
        list3.Add(rand.Next(minGeneratedValue, maxGeneratedValue));
    }

    Console.WriteLine("List 3 is a random generated list.");
    Console.WriteLine("list3: " + list3);
    
    var list3Copy1 = (UserList<int>)list3.Clone();
    var list3Copy2 = (UserList<int>)list3.Clone();
    var list3Copy3 = (UserList<int>)list3.Clone();
    var list3Copy4 = (UserList<int>)list3.Clone();

    IComparer<int> comparer = new IntComparer();
    list3Copy1.SortSelectionSort(comparer);
    Console.WriteLine("Selection Sort: " + list3Copy1);

    list3Copy2.SortInsertionSort(comparer);
    Console.WriteLine("Insertion Sort: " + list3Copy2);

    list3.Sort(comparer); //Default sorting algorithm fro UserArrayList.
    Console.WriteLine("Bubble Sort: " + list3);

    list3Copy3.SortQuickSort(comparer);
    Console.WriteLine("Quick Sort: " + list3Copy3);
    
    list3Copy4.SortMergeSort(comparer);
    Console.WriteLine("Merge Sort: " + list3Copy4);
}
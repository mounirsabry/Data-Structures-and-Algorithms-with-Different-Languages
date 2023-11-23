//Printing List Functions.
void printIntList(int *list, int length);
void printFloatList(float *list, int length);
void printDoubleList(double *list, int length);

//Fill a List with Random Numbers.
void fillRandomInt(int *list, int length);
void fillRandomFloat(float *list, int length);
void fillRandomDouble(double *list, int length);
void fillRandomIntLimit(int *list, int length, int start, int end);
void fillRandomFloatLimit(float *list, int length, int start, int end);
void fillRandomDoubleLimit(double *list, int length, int start, int end);

//Deep Copy a list into another list.
int * deepCopyListInt(int *list, int length);
float * deepCopyListFloat(float *list, int length);
double * deepCopyListDouble(double *list, int length);

//Search Algorithms.
int sequentialSearchUnsorted(int *list, int length, int key);
int sequentialSearchSorted(int *list, int length, int key);
int binarySearchRecV1(int *list, int length, int key);
int binarySearchRecV2(int *list, int length, int key);
int search(int *list, int minIndex, int maxIndex, int key);
int binarySearchIt(int *list, int length, int key);

//Sorting Algorithms.
void bubbleSort(int *list, int length);
void insertionSort(int *list, int length);
void selectionSort(int *list, int length);
//Arrays.
typedef struct UserArray UserArray;

UserArray *createUserArray(int initialCapacity);
void growUserArray(UserArray *array, int newCapacity);
int getValueUserArray(UserArray *array, int index);
int insertItemUserArray(UserArray *array, int index, int item);
int insertFirstUserArray(UserArray *array, int item);
int insertLastUserArray(UserArray *array, int item);
int updateItemUserArray(UserArray *array, int index, int newValue);
int deleteItemUserArray(UserArray *array, int index);
int deleteFirstUserArray(UserArray *array);
int deleteLastUserArray(UserArray *array);
UserArray *deallocateUserArray(UserArray *array);
int *getDeepListUserArray(UserArray *array);
int getCapacityUserArray(UserArray *array);
int getLengthUserArray(UserArray *array);
int findFirstUserArray(UserArray *array, int key);
void printUserArray(UserArray *array);

//Lists.
typedef struct UserLinkedList UserLinkedList;

UserLinkedList *createUserLinkedList();
int getValueUserLinkedList(UserLinkedList *list, int index);
int insertItemUserLinkedList(UserLinkedList *list, int index, int item);
int insertFirstUserLinkedList(UserLinkedList *list, int item);
int insertLastUserLinkedList(UserLinkedList *list, int item);
int updateItemUserLinkedList(UserLinkedList *list, int index, int newValue);
int deleteItemUserLinkedList(UserLinkedList *list, int index);
int deleteFirstUserLinkedList(UserLinkedList *list);
int deleteLastUserLinkedList(UserLinkedList *list);
UserLinkedList *deallocateUserLinkedList(UserLinkedList *list);
int *getDeepListUserLinkedList(UserLinkedList *list);
int getLengthUserLinkedList(UserLinkedList *list);
int findFirstUserLinkedList(UserLinkedList *list, int key);
void printUserLinkedList(UserLinkedList *linkedList);

//Stacks.
typedef struct UserStack UserStack;

UserStack *createUserStack(int initialCapacity);
void growUserStack(UserStack *stack, int newCapacity);
int peekUserStack(UserStack *stack);
int popUserStack(UserStack *stack);
int pushUserStack(UserStack *stack, int item);
int emptyUserStack(UserStack *stack);
UserStack *deallocateUserStack(UserStack *stack);
int *getDeepListUserStack(UserStack *stack);
int getCapacityUserStack(UserStack *stack);
int getLengthUserStack(UserStack *stack);

//Queues.
typedef struct UserQueue UserQueue;

UserQueue *createUserQueue();
int peekUserQueue(UserQueue *queue);
int popUserQueue(UserQueue *queue);
int pushUserQueue(UserQueue *queue, int item);
int emptyUserQueue(UserQueue *queue);
UserQueue *deallocateUserQueue(UserQueue *queue);
int *getDeepListUserQueue(UserQueue *queue);
int getCapacityUserQueue(UserQueue *queue);
int getLengthUserQueue(UserQueue *queue);
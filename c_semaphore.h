#ifndef SEM_DEAD
//--------------------
#define SEM_LIMIT  32
//--------------------
#define SEM_DEAD   0
#define SEM_ACTIVE 1
//--------------------
struct semaphore {
    int value, state;
    struct spinlock lock;
} 
#endif
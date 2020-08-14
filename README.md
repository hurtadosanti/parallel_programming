# ParallelProgramming
## Flynn's Taxonomy
- SIMD
- MIMD
- UMA vs NUMA

## Concurrency
Ability of a program to be broken into parts that can run independently of each other.

Usefull for I/O bound operations / they are good uses for threads
 
## Parallel hardware
CPU
GPU
Cluster

## Schedules
- Schedulers usually have different goals, handled by OS
- process life cycle
## Threads
- <thread>.join()
- <thread>.detach() -> daemon process

## Data Races

- Mutex / Lock (mutual exclusion)
- 
### Atomic
#include <atomic>

std::atomic<type> name(value);


- Reentrant locks
std::recursive_mutex 

nested functions will have issues when not used another option is to use an external function






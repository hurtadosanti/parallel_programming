# ParallelProgramming
## Flynn's Taxonomy

- SISD (Singe Instruction Single Data)
- SIMD (Singe Instruction Multiple Data) 
- MISD (Multiple Instruction Single Data) * Not common
- MIMD (Multiple Instruction Multiple Data)
    - Single Program, Multiple Data(SPMD) 
    - Multiple Program multiple data(MPMD) Manager and workers

## Memory
 - Shared Memory 
### UMA(Uniform memory access)    
#### Architecture:
    - Symmetric Multiprocessing(SMP))
#### Challenges
- Cache coherency

### NUMA(Non Uniform memory access)
Multiple processors sockets

### Distributed Memory Architecture
Best for using cheap software








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






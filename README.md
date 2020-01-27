This project is aimed so solve a typical synchronization plroblem in which several threads tend to modify the content of  variable.
To solve this problem metux locks scheme was used which ensures that one and only one thread is holding the lock(is in the critical section).

the problem is described below:
- City      : which is a directed graph representing a city
- Route     : which is any endge in the garph
- Car       : which represents threads
- Polution  : which represents the task that any thead does passing the edge

any car has a roadmap that act acording to it and doing so will produce some sort of polution. all the polutions will be stacked in the variable total_polution
the constraints are that any edge has the capacity of only one car and total_polution modification represents some kind of critical section challenge.
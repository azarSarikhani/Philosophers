# Philosophers
Philosophers with threads and mutexes


This is a solution to the classic dinning philosophers problem. With some modifications of course. There are n number of philos sitting around a tabble with each having one fork in fornt of them. They need 2 forks to be able to eat so they borrow one from their neighbour to be able to eat. They eat for the given miliseconds and go to sleep immidiately, for the given number of milisecods again. They will wake up and if they have access to forks they eat again otherwise they think as they wait, and this is what they always do when they wait. This program might not work well on slower computers. Don't try with bigger numbers than 200 philos or do if you have enough cores on your cpu.

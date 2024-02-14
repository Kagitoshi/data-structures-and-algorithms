Binary search is faster than linear search. Each time we double the amount of elements the max steps needed to search the 
entire sorted array is only increased by 1.

Elements = 3
Steps = 2

Elemtns = 7
Steps = 3

Elements = 15
Steps = 4

...and so on.

As for linear search the max amount of steps needed increase with each element added to the array.

Elements = 3
Steps = 3

Elements = 7 
Steps = 7

Elements = 15
Steps = 15

...and so on.

For small arrays binary and linear search won't show much of a difference but, let's look at arrays that are 10,000 and over in size.

For Linear Search:
Elements = 10,000
Steps = 10,000

Elements = 1,000,000
Steps = 1,000,000

For Binary Search:
Elements = 10,000
Steps = 13

Elements - 1,000,000
Steps = 20

Here is a graph for visualizion's sake:
https://www.edredo.com/sites/default/files/public/user_files/tud39880/linearSearch%20vs%20binary%20search%20diagram_0.jpg

Linear search is O(N) - Oh of N
Binary search is O(log N) - Oh of log N

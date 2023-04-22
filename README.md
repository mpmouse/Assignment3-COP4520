# Assignment3-COP4520

Assignment 3 COP 4520 Created by: Mari Peele Language: C++

Compile Instructions g++ -O2 *.cpp -o PresentParty.exe

NOTE:
  I was only able to partially complete this assignment. My coursework as been affected by preparations for a surgery coming up next week. I did not know about this surgery when I registered this semester. I will also be emailing the professor so they can be aware also.
  
  For this assignment, I was nearly able to complete part 1. While running without threads it completes but has an issue with less cards being written than presents processed. When run with threads it appears to enter an endless loop.
  
  The strategy I used was to create a vector list of 'presents', set their ids, and then shuffle them. This gave me an unorded list of presents.
  Then when a servant was tasked with sorting a present, then took it from the back of the vector, and removed it from the vector. This is most likely where my issue is since this action is not atomic. 
  When a servant is tasked with writing a card, they find an available present, lock it and its successor. Then the successor is used to make a card and the present is removed(links are updated in this process). After that, the predessor is unlocked.
  For the present search, the servant is given a random id and searches from the head of the list until either it is found, it finds a higher id, or reaches the end of the list. If either of the later two options happen, it was not in the stack.

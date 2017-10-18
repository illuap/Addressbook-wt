**You can use the make file**

-------------------------------------
COMPILING
-------------------------------------
(you might need to open up the make file and edit the CFlags to adjust it to the proper Include and Library locations depending on how your machine is setup for the wt files.)
1) open to the file directory through terminal
2) type "make"
3) should create a file called "app"

-------------------------------------
RUNNING
-------------------------------------
1) go to the same file directory as "app"
2) type "make run" or "./app --docroot ./ --http-address 127.0.0.1 --http-port 8080"
3) go to "localhost:8080" (I tested it with Firefox.)

-------------------------------------
PROVING THREADLOCKING IS FIXED
-------------------------------------
1) add the <thread> and <chrono> librarys (uncomment Lines 31 + 32 in main)
2) add a sleep method between the delete and create person vector (uncomment line 145)
3) compile and start the server
4) open 2 browsers side by side with the app loaded. (have localhost:8080 open on both browsers)
5) browser 1 generate a list wait till it's done
6) browser 2 load localhost:8080/people
7) browser 1 generate a new list 
8) browser 2 refresh the page (step 7 and 8 should be done under 10 seconds)
9) notice browser 2 loading is queued because it is waiting for browser 1 thread to finish.

Browser 2 was waiting for browser 1's thread to finish before it accessed the global vector addressBook!
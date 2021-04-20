/*Zachery Abbas
  1019463
  Assignment 3
*/
How to compile and Work Program: 
All you do is simply type in make to your prompt. Once the prorams are compiled you type in the prompt ./test
The program will have a greeting message asking you to press 1 for P11 and P12 or press 2 for P21 P22 P23. 
Then the results will show!!

Algorithms: 

P11.c: 
step one: is to find a signature that is searched by the user
step two: create a for loop that loops through all the signatures.
step three: if the signatures match print and add to count; 
step four: if they dont match do nothing. 

I used switch statments with cases becasue I though this would be the  easiest way to check each character. 

P12.c: 
I used three fucntions brute pre function which is basically the same algorithm as P11.c but implemnted 
with the struct I used. 
Then I used insertion sort 1 and insertion sort which are functions that basically orders them in decending order 
and deals with the numbers as strings. 
The in the last fucntion sortPre which is where I call the two fucntions and start the clock for brute force part of 
the program. 

P21.c:
In searchBrute I create two for loops thta correspond with the lengths of the file and array size
if they hay doesn't = needle than the program breaks off but the j == the length of needle then it is a matcher.

I used the Algorithm from text book. 

P22.c: 
I created a function that bascically compares the characters, if it is not contained in search string, you move till it shifts till it matches
I then call the function in the poolhors function. Then I do shift++ and counter++ when this stuf is happening "if (k != len2) {
           if (hay[i] >= 'a' && hay[i] <= 'z')
              i += table[(int)hay[i] - 97];
            else if (hay[i] >= 'A' && hay[i] <= 'Z')
              i += table[(int)hay[i] - 65];

P23.c: Although My progam doesnt work and isn't implemented in my main.c

I created three functions suffix, suffix table, and charTable 
char table checks the far right of the string to see  if it exist, if it doesnt exist will will move the 
full length. 
when it does exist it will keep moving till it matches 

suffix will not repeat the string,and will move the entire length but when it does exist again in search it will keep 
it going till it lines up again. 

Lastly suffix table basically checks oif the prefix is conatined in the suffix and will keep moving till they line up. 

2.4 TESTING/ analyze performance

Test 1: University
***********************************************
The Bruteforce matches found in the file is: 2345
Amount of Shifts: 3296581
Runtime for Brute Force 0.015101 seconds

Ratio: 0.0000000045808066

The amount of horspool found that are matches: 2345
Amount of Shifts: 435996
Runtime for Horspool is 0.005825 seconds

Ratio: 0.0000000133602143

Test 2: study
***********************************************
The Bruteforce matches found in the file is: 541
Amount of Shifts: 3296586
Runtime for Brute Force 0.017930 seconds

Ratio: 0.00000000543896018

The amount of horspool found that are matches: 541
Amount of Shifts: 717247
Runtime for Horspool is 0.007622 seconds

Ratio: 0.0000000106267436 

Test 3: year
***********************************************
The Bruteforce matches found in the file is: 1895
Amount of Shifts: 3296587
Runtime for Brute Force 0.032041 seconds

Ratio: 0.00000000097221839

The amount of horspool found that are matches: 1895
Amount of Shifts: 909158
Runtime for Horspool is 0.013607 seconds

Ratio: 0.0000000149665955

Test 4: Undergraduate Calendar
***********************************************
The Bruteforce matches found in the file is: 183
Amount of Shifts: 3296578
Runtime for Brute Force 0.017175 seconds

Ratio: 0.0000000149665955

The amount of horspool found that are matches: 183
Amount of Shifts: 332090
Runtime for Horspool is 0.004477 seconds

Ratio:0.0000000134812852

Test 5: Association
***********************************************
The Bruteforce matches found in the file is: 307
Amount of Shifts: 3296580
Runtime for Brute Force 0.015553 seconds

Ratio:0.00000000471791978 

The amount of horspool found that are matches: 307
Amount of Shifts: 382678
Runtime for Horspool is 0.005174 seconds

Ratio: 0.0000000135205055

Test 6: Privacy Act(FIPPA)
***********************************************
The Bruteforce matches found in the file is: 2
Amount of Shifts: 3296584
Runtime for Brute Force 0.014594 seconds

Ratio:0.00000000442579349

The amount of horspool found that are matches: 2
Amount of Shifts: 542738
Runtime for Horspool is 0.006741 seconds

Ratio:0.0000000124203575

Test 7:http://www.e-laws.gov.on.ca/index.html
***********************************************
The Bruteforce matches found in the file is: 1
Amount of Shifts: 3296553
Runtime for Brute Force 0.016168 seconds

Ratio: 0.00000000490454726

The amount of horspool found that are matches: 1
Amount of Shifts: 169644
Runtime for Horspool is 0.002320 seconds

Ratio:0.0000000136756973

Test 8:many
***********************************************
The Bruteforce matches found in the file is: 68
Amount of Shifts: 3296587
Runtime for Brute Force 0.014260 seconds

Ratio:0.0000000043256859

The amount of horspool found that are matches: 68
Amount of Shifts: 895702
Runtime for Horspool is 0.009159 seconds

Ratio:0.00000001065369

Test 9:Division
***********************************************
The Bruteforce matches found in the file is: 2
Amount of Shifts: 3296583
Runtime for Brute Force 0.015590 seconds

Ratio:0.00000000472913923

The amount of horspool found that are matches: 2
Amount of Shifts: 474704
Runtime for Horspool is 0.005714 seconds

Ratio:0.0000000120369746

Test 10: The University of Guelph
***********************************************
The Bruteforce matches found in the file is: 3221
Amount of Shifts: 3296588
Runtime for Brute Force 0.015607 seconds

Ratio: 0.00000000473428891

The amount of horspool found that are matches: 3221
Amount of Shifts: 1143647
Runtime for Horspool is 0.014301 seconds

Ratio:0.00000000125947327

Brief Analysis
***********************************************

Average for Brute Force: 0.0000000053795524 

Average for horspool:0.000000001.1600153677

When looking at the numbers you can see they horspool is average is greater thans brute force. but according to te runtime and 
amount of shifts horsepool is faster and less shifts compared to bruteforce. The reason why the ratios are like this is because 
horsepool is dividing it into a much smaller number compared to bruteforce which is dividing it into a bigger number. 



# project-a-day
Implement one real world project a day

# Day 1 [5/1/2015]
Created a prime number grabber in c++ (my weakest language, which is why I chose it^^) that gets the next prime number starting at the smallest prime 2. Efficiency was key in this program so that the user is not waiting when a number is requested. When prime numbers get very large, there can be long run times. In order to combat this, a few things were done. First, the expensive prime getter is not called everytime the user requests a prime number. It is called to grab the next 10 prime numbers in
succession and stored in a buffer using a queue. Additionally, each prime checker starts at the previous prime number, so the prime checker doesn't start from the bottom up every time. Lastly, the prime checker itself increments every 2 values (because only odd numbers are prime) and only checks until the floor of the square root of the number. This is because divisors beyond the square root of a number have already been checked. Take 100 for example:
2 x 50 [check 2 and 50]
4 x 25 [check 4 and 25]
5 x 20 [check 5 and 20]
10 x 10 [check 10]
20 x 5 [repeat check of both 20 and 5!!!]

# Day 2 [5/2/2015]
Had a late start today due to.. the Google Games!! It was a fun event put on by google and needless to say, I still have a lot more to learn about programming (and building towers with straws but thats a story for another day). Wow, this is turning into a blog now? I don't know how I feel about it.. Anyway! I tried to build a change giver that returns change from a given price and amount of money given. However, I've run into quite a bit of problems and less-than-ideal hard-coding
approach to the change giving. I still need to work out the kinks but it's almost done.

# Day 3 [5/4/2015]
YES I KNOW I MISSED A DAY. Oh wells, it was bound to happen. I still have to work on the change-giver from 5/2, but today I finished working on a credit card accepter. Basically, it accepts all valid credit cards by using Luhn's algorithm to determine if it valid. It's also interactive so you can try it out! (No, I am not saving this data and trying to steal your credit card information .. xD) But, it was fun! Definitely getting better at C++, which was one of the main goals of
this project--to practice and get comfortable creating easy projects that test a wide range of knowledge using languages I would otherwise be uncomfortable with. Enjoy! :)

# Day 4 [5/6/2015]
OK, daily projects is a much higher toll than I expected, so I'm not gonna be able to keep up.. Maybe MAYBE I could make up the debt some day by doing an insane amount of projects in one day, but for now.. oh wells. Anyway--I created a very simple fibonacci 'nth' digit finder. Fibonacci is interesting to me because it is so common and contains one of the biggest traps, but is still asked today by many companies (including the company that hired me for this summer). Let me start by
explaining what the Fibonacci sequence is. It is a mathematical sequence of numbers where each consecutive number is derived by summing the previous 2 numbers. For example: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ... (note: the first 2 numbers are the only exception to the rule where both numbers are 1). Recursion is probably the first thing that comes to your mind when you see this because it seems like it suits the problem so well.. just return the summation of the previous two terms
with a base case of num equal to 1. In fact, many people would opt for recursion in an interview setting, thinking that by showing knowledge and implementation of a recursive function they are impressing the interviewer, but this is the exact opposite! TWO recursive calls for every function call is horrid runtime and space usage! The smart interviewee would mention the recursive version of the fibonacci sequence to the interviewer and discuss the tradeoffs between
recursive and iterative implementations. Of course, the best way is to use iteration with a dynamic programming style to hold on to the current values at every point in the sequence. I love how my README went from my projects to a blog to interview prep 101. Hehe.

# Day 5 [5/7/2015]
For all you coffeelovers out there, I created a french press coffee program that has timers for many different aspects of the brewing process. For example, a timer that is in charge of the water boiling cooldown, to time how long it takes for the boiling water to reach 95-100 degree fahrenheit. It also accounts for the total time it takes for the water to infuse with the beans, along with 2 30 second incremental stirring reminders so you can stir at the most ideal times. Oh, and it
also comes with voice activated reminders, so you can turn your volume up and focus on other things while your fresh pot of coffee is being made! :)

# Day 6 [5/8/2015]
Today, I created a pretty simply program: a coin flipper which flips a coin at each user request and displays the total number of flips. It wasn't too hard to implement, but I did it in python (a language I am very foreign in). Part of this simple project was inspired by a race my roommate and I had where he had to build a coin flipper in Java and I had to build it using an Arduino, and my roommate ultimately won (by the power of stack overflow). Anyways, it was fun and I
encourage you to try my coin flipper!

**Testing Different MarkDown features..**
* Testing more MarkDown Features.. *
_CoolBeans_

# Day 7 [5/9/2015]
Created a simple string reverser in C++. It was actually much easier than I thought, as the pointer walking seemed to just make sense. This is a pretty common question asked in interviews (if I recall correctly, it's one of the first in CTCI) so I thought it'd be a good idea to knock it down. As usual, this program is interactive, so it loops and asks for user input repeatedly. Planning to learn either bash scripting or python scripting in order to create unit tests for my programs to
practice testing & scripting. We'll see..



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

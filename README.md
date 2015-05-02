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

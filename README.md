# project-a-day
Implement one real world project a day

# Day 1
Created a prime number grabber in c++ (my weakest language, which is why I chose it) that gets the next prime number starting at the smallest prime 2. Efficiency was key in this program so that the user is not waiting when a number is requested. When prime numbers get very large, there can be long run times. In order to combat this, two things were done: 1) The prime getter is not called everytime the user requests a prime number, it is called to grab the next 8 prime numbers in
succession and stored in a buffer using a queue. 2) Each prime checker starts at the previous prime number, so the prime checker doesn't start from the bottom up every time.

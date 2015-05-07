import time
import os

print 'In how many seconds would you like the alarm to go off?'

seconds = input()

while ( seconds > 0 ):
    print seconds, ' seconds until Alarm!'
    time.sleep(1)
    seconds -= 1

os.system('say "BEEP BEEP BEE BEEP BEEP BEEP BEEP"')

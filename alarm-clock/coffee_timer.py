import os
import time

print 'Enter water cooling time:  [format: MIN or MIN:SEC]'
boil_input = raw_input()
if ':' in boil_input:
    boil_time = boil_input.split(':')
    boil_min = int( boil_time[0] )
    boil_sec = int( boil_time[1] )
else:
    boil_min = int( boil_input )
    boil_sec = 0

print 'Enter steeping time: [format: MIN or MIN:SEC]'
steep_input = raw_input()
if ':' in steep_input:
    steep_time = steep_input.split(':')
    steep_min = int( steep_time[0] )
    steep_sec = int( steep_time[1] )
else:
    steep_min = int( steep_input )
    steep_sec = 0

total_boil_time = ( boil_min * 60 ) + boil_sec
total_steep_time = ( steep_min * 60 ) + steep_sec

print 'Starting the Coffee Timer..'
print 'Current Date/Time:', time.ctime()

os.system( ' say "STARTING COFFEE TIMER WITH GRIND THIRTY TWO!" ' )

while ( total_boil_time > 0 ):
    print 'Time left until done boiling:', total_boil_time
    time.sleep(1)
    total_boil_time -= 1

os.system( ' say "YOUR WATER IS READY FOR POURING " ' )

steep_time_passed = 0
while ( total_steep_time > 0 ):
    print 'Time left until done steeping:', total_steep_time
    time.sleep(1)
    total_steep_time -= 1
    steep_time_passed += 1
    if ( steep_time_passed == 60 ):
        os.system( ' say "POUR THE FUCKING WATER AND STIR THE COFFEE!" ' )
    if ( steep_time_passed == 270 ):
        os.system( ' say "THIRTY SECONDS LEFT. PREPARE THE CUPS!" ' )

    if ( steep_time_passed == 290 ):
        os.system( ' say "TEN SECONDS REMAINING." ' )

os.system( ' say "PRESS THE COFFEE AND ENJOY!" ' )

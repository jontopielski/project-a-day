import random
heads_count = 0
tails_count = 0

while ( True ):
    print 'Type "q" to quit'
    print 'Type anything else to continue and FLIP A COIN!'
    any_input = raw_input()
    flip_result = random.randint(0, 1)
    if ( flip_result == 0 ):
        print 'YOU GOT HEADS!'
        heads_count += 1

    else:
        print 'YOU GOT TAILS!'
        tails_count += 1

    print 'Total Heads:', heads_count, 'Total Tails:', tails_count


import sys
def hanoi(height, fro='left', to='right', through='middle'):
        if height:
                hanoi(height - 1, fro, through, to )
                print ('%-7s => %s' % (fro, to))
                hanoi(height -1, through, to, fro)

if __name__ == '__main__':
	hanoi( int(sys.argv[1]) )

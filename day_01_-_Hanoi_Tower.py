def hanoi(height, fro='left', to='right', through='middle'):
	if height:
		hanoi(height - 1, fro, through, to )
		print fro, ' => ', to
		hanoi(height -1, through, to, fro)

if __name__ == '__main__':
	hanoi(5)

def hanoi(height, from='left', to='right', through='middle'):
	if height:
		hanoi(height - 1)

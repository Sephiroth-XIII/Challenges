import random

def check_mywin(mr,board):
	#check for the rows
	for i in range(0,3):
		countX=0
		count_=0
		for j in range(0,3):
			if board[i][j]==mr:
				countX+=1
			if board[i][j]=='_':
				count_+=1
				x=i
				y=j
		if countX==2 and count_==1:
			win = str(x)+" "+str(y)
			return win
	#check for the columns
	for i in range(0,3):
		countX=0
		count_=0
		for j in range(0,3):
			if board[j][i]==mr:
				countX+=1
			if board[j][i]=='_':
				count_+=1
				x=j
				y=i
		if countX==2 and count_==1:
			win = str(x)+" "+str(y)
			return win
	#check for diagonal 1
	countX=0
	count_=0
	for i in range(0,3):
		if board[i][i]==mr:
			countX+=1
		if board[i][i]=='_':
			count_+=1
			x=i
			y=i
	if countX==2 and count_==1:
		win = str(x)+" "+str(y)
		return win	
		
	#check for diagonal 2
	countX=0
	count_=0
	for i in range(0,3):
		if board[i][2-i]==mr:
			countX+=1
		if board[i][2-i]=='_':
			count_+=1
			x=i
			y=2-i
	if countX==2 and count_==1:
		win = str(x)+" "+str(y)
		return win
			
						
def nextMove(player,board):
	#PLAYER CHECK
	if player=='X':
		me='X'
		opp='O'
	else:
		me='O'
		opp='X'
		
	#OPENING CALCULATION
	count1=0
	row = []
	col = []
	for i in range(0,3):
		for j in range(0,3):
			if board[i][j]=='_':
				count1+=1
				row.append(i)
				col.append(j)

	if count1==9:
		print "0 0"
	elif count1==8:
		if board[1][1]=='_':
			print "1 1"
		else:
			print "0 0"
	#MID GAME START NOW
	else:		
		#CHECK IF I AM WINNING
		SEQ = check_mywin(me,board)
		#BLOCK IF OPPONENTS WINNING
		SEQ1 = check_mywin(opp,board)
		if SEQ!=None:
			print SEQ
		elif SEQ1!=None:
			print SEQ1
		else:
			if me=='X':
				if count1==7:
					if board[0][1]=='O' or board[0][2]=='O' or board[1][2]=='O':
						print "2 0"
					elif board[1][0]=='O' or board[2][0]=='O':	
						print "0 2"
					elif board[2][1]=='O' or board[2][2]=='O':
						print "0 2"
					elif board[1][1]=='O':
						print "2 2"
				elif count1==5:
					if board[0][1]=='O' and board[1][0]=='O':
						print "2 2"
					elif board[0][2]=='O' and board[1][0]=='O':
						print "2 2"
					elif board[0][1]=='O' and board[2][0]=='O':
						print "2 2"
					elif board[0][1]=='O' and board[2][2]=='O':
						print "2 0"
				else:
					SEQ3=random.randrange(0,len(row))
					print row[SEQ3],col[SEQ3]
			elif me=='O':
				if count1==6:
					if board[1][1]=='X' and board[2][2]=='X':
						print "0 2"
					elif board[0][0]=='X' and board[2][1]=='X':
						print "2 0"
					elif board[0][0]=='X' and board[1][2]=='X':
						print "0 2"
					elif board[0][2]=='X' and board[2][1]=='X':
						print "2 2"
					elif board[0][2]=='X' and board[1][0]=='X':
						print "0 0"
					elif board[2][0]=='X' and board[0][1]=='X':
						print "0 0"
					elif board[2][0]=='X' and board[1][2]=='X':
						print "2 2"
					elif board[2][2]=='X' and board[1][0]=='X':
						print "2 0"
					elif board[2][2]=='X' and board[0][1]=='X':
						print "0 2"
					elif board[0][1]=='X' and board[1][2]=='X':
						print "0 2"
					elif board[0][1]=='X' and board[1][0]=='X':
						print "0 0"
					elif board[2][1]=='X' and board[1][0]=='X':
						print "2 0"
					elif board[2][1]=='X' and board[1][2]=='X':
						print "2 2"
					elif board[0][1]=='_':
						print "0 1"
					elif board[1][0]=='_':
						print "1 0"
					elif board[1][2]=='_':
						print "1 2"
					elif board[2][1]=='_':
						print "2 1"
					
				else:
					SEQ3=random.randrange(0,len(row))
					print row[SEQ3],col[SEQ3]
#player Input X,0
player = raw_input()
#Read the board now. The board is  3x3 array filled with X,0 or _
board = []
board1 = []
for i in xrange(0,3):
	board1.append(raw_input())
for i in range(0,3):
	board.append(list(board1[i]))

nextMove(player,board)

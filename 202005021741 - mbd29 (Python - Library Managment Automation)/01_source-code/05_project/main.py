#python3
import sys

fileBooks = "books.txt"
fileUsers = "users.txt"
fileBorroweds = "borroweds.txt"

users = []
books = []
borroweds = []

loginUser = []

def Login():

	name = input("Id: ")
	password = input("Password: ")
	for user in users:
		if(name == user[1] and password == user[2]):
			print("Seccessfully logged in!")
			if(user[0] == "admin"):			
				AdminMenu()
				return
			elif(user[0] == "student"):
				loginUser.append(user)
				StudentMenu()
				return
	print("Invalid id or password please try again")
	Login()
	return

def ReadFile():
	users.clear()
	books.clear()
	borroweds.clear()
	fileU = open(fileUsers,"r")
	for lineU in fileU:
		try:
			lineU = lineU.split(':')
			lineU[2] = lineU[2].split('\n')[0]
			users.append(lineU)
		except:
			pass
	fileB = open(fileBooks,"r")
	for lineB in fileB:
		try:
			lineB = lineB.split(':')
			lineB[3] = lineB[3].split('\n')[0]
			if(lineB[2].find(',') > -1):
				lineB[2] = lineB[2].split(',')
			books.append(lineB)
		except:
			pass
	fileBr = open(fileBorroweds,"r")
	for lineBr in fileBr:
		try:
			lineBr = lineBr.split(':')
			lineBr[1] = lineBr[1].split('\n')[0]
			borroweds.append(lineBr)
		except:
			pass
	return

def WriteFileUser():
	file = open(fileUsers,"w")
	for user in users:
		file.write(user[0]+":"+user[1]+":"+user[2]+"\n")
	return

def WriteFileBook():
	file = open(fileBooks,"w")
	for book in books:
		file.write(book[0]+":"+book[1]+":"+str(book[2])+":"+book[3]+"\n")
	return

def WriteFileBorrowed():
	file = open(fileBorroweds,"w")
	for borrowed in borroweds:
		#book id:student name
		file.write(borrowed[0]+":"+borrowed[1]+"\n")
	return

def AdminMenu():
	ReadFile()
	print("""
	Welcome Admin! What do you want to do?
	1-List books
	2-Create a book
	3-Clean a book
	4-Search for a book
	5-Change number of copies of book by id
	6-Show students borrowed a book by id
	7-List Users by id
	8-Create User
	9-Delete User
	10-Exit
	""")
	choice = input("Your choice: ")

	if(choice == "1"):#+
		ListBooks()
	elif(choice == "2"):#+
		CreateBook()
	elif(choice == "3"):#+
		CleanBook()
	elif(choice == "4"):#+
		SearchBook()
	elif(choice == "5"):#+
		ChangeNumOfCopy()
	elif(choice == "6"):#+
		ShowStudentsBorrowed()
	elif(choice == "7"):#+
		ListUsers()
	elif(choice == "8"):#+
		CreateUser()
	elif(choice == "9"):#+
		DeleteUser()
	elif(choice == "10"):#+
		Exit()
	else:#+
		print("Wrong choice !!!")
		
	AdminMenu()

def ListBooks():
	print("*** List of Books ***")
	for book in books:
		PrintBook(book)
	return

def CreateBook():
	name = input("What is the name of the book that you want to add?: ")
	bid = input("What is the id that you want to give for "+name+" book?: ")
	author = input("What is/are the author(s) of "+name+" book?: ")
	authors = author.split(",")
	copies = input("How many copies you have for "+name+" book?: ")
	ques = input("Are you sure?[Y/N] ")
	if(ques == "Y"):
		print("The fallowing book has been added to your collection:")
		PrintBook([bid,name,author,copies])
		books.append([bid,name,author,copies])
		WriteFileBook()
		return
	return

def CleanBook():
	ListBooks()
	print("\n\n")
	bid = input("What is the id of the book that you want to delete,(Enter 0 to go to main menu)?: ")
	if(bid == "0"):
		return
	print("The following book has been deleted:")
	for book in books:
		if(bid == book[0]):
			PrintBook(book)
			books.remove(book)
			WriteFileBook()
			return
	return

def SearchBook():
	bookValue = input("Enter book name or author name to search ,(Enter 0 to go to main menu)?: ")
	if(bookValue == "0"):
		return
	for book in books:
		if(bookValue == book[1] or book[2] in bookValue):
			PrintBook(book)
			return
	return

def ChangeNumOfCopy():
	ListBooks()
	print("\n\n")
	bid = input("What is the id of the book for the change ?(Enter 0 to go to main menu): ")
	if(bid == "0"):
		return
	i=0
	for book in books:
		if(bid == book[0]):
			break
		i+=1
	cpuser = int(books[i][3]) - CalcBookBorrowNum(book)
	while(True):
		copies = input("Enter the new value for the no of copies: ")
		if(cpuser > int(copies)):
			print(str(cpuser)+" user(s) is/are holding the book, try a larger number!")
		else:
			break
	books[i][3] = copies
	print("The following book has been updated:")
	WriteFileBook()
	return

def ShowStudentsBorrowed():
	bid = input("What is the id of the book that you want to show, (Enter 0 to go to main menu)?: ")
	if(bid == "0"):
		return
	print("Students that borrowed the book:")
	for borrowed in borroweds:
		if(borrowed[0] == bid):
			print("-"+borrowed[1])

	return

def ListUsers():
	print("*** Current Users ***")
	i = 1
	for user in users:
		if(user[0] != "admin"):
			print(str(i)+"-"+user[1])
		i+=1
	return

def CreateUser():
	name = input("What is the name of the user that you want to create? ")
	password = input("What is password for the new account? ")
	users.append(["student",name,password])
	for value in users:
		print("Name: "+value[1]+", Password: "+value[2])
	WriteFileUser()
	return

def DeleteUser():
	ListUsers()
	name = input("Which user do you want to delete: ")
	
	for user in users:
		if(user[1] == name):
			users.remove(user)
			WriteFileUser()
			print(name+" is deleted!")
			return

def Exit():
	print("Exiting the program...")
	sys.exit()

def StudentMenu():
	print("""
		1-Search for a book
		2-Add a book to my book list
		3-Delete a book from my book list
		4-Show my borrowed books
		5-Exit
		""")
	choice = input("Your choice: ")

	if(choice == "1"):#+
		StSearchBook()
	elif(choice == "2"):#+
		StAddBook()
	elif(choice == "3"):#+
		StDeleteBook()
	elif(choice == "4"):#+
		StShowBorrowed()
	elif(choice == "5"):#+
		Exit()
	else:
		print("Wrong choice !!!")
	StudentMenu()	

def StSearchBook():
	SearchBook()
	return

def StAddBook():

	ListBooks()
	print("\n\n")
	bid = input("What is the id of a book that you want to add (Enter 0 to go to main menu)?: ")
	if(bid == "0"):
		return
	for book in books:
		if(book[0] == bid):
			#kontrol edilecek
			if not(CalcBookBorrowNum(book) > 0):
				print("No copy available!!!")
				return
			book[3] = str(int(book[3])-1)
			borroweds.append([bid,loginUser[0][1]])
			WriteFileBorrowed()
			print("The following book has been added to your profile:")
			return
	print("Not found book!!!")
	StAddBook()
	return

def StDeleteBook():
	StShowBorrowed()
	print("\n\n")
	bid = input("What is the id of a book that you want to return (Enter 0 to go to main menu)?: ")
	if(bid == "0"):
		return
	for borrowed in borroweds:
		if(borrowed[0] == bid and borrowed[1] == loginUser[0][1]):
			print("The following book has been selected:")
			for book in books:
				if(book[0] == borrowed[0]):
					PrintBook(book)
			ques = input("Are you sure that you want to return this book ? [Y/N]")
			if(ques == "Y"):
				borroweds.remove(borrowed)
				print("The book has been returned.")
				WriteFileBorrowed()
				return
			else:
				return
	print("Book not found!!!")
	return

def StShowBorrowed():
	print("\n\nYour Books:\n")
	for borrowed in borroweds:
		if(borrowed[1] == loginUser[0][1]):
			for book in books:
				if(book[0] == borrowed[0]):
					PrintBook(book)
	return		

def CalcBookBorrowNum(book):
	num = 0
	for borrowed in borroweds:
		if(borrowed[0] == book[0]):
			num+=1
	return int(book[3])-num

def PrintBook(book):
	i=1
	for inbook in books:
		if(book == inbook):
			break
		i+=1
	print(str(i)+". Book id: "+book[0]+", Book Name:"+book[1]+", Book Authors: "+str(book[2])+", Number of Copies: "+book[3])
	return

print("****Welcome to Library Managment System****")
ReadFile()
#Login()
Login()

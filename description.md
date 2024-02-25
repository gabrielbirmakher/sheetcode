Simple leetcode tracker

"Global" variables
-Total number of questions (just have a text file that stores globals like this)

Interface when opened app:
	Number of completed leetcodes
	Last leetcode completed (number and title and possibly the date completed)
	Prompt does the user want to look at a leetcode question or add one to the list
	Menu (button that if you press it, will show you other options)
		percentages
		difficulty breakdown (how many easy, how many medium, how many hard (amount of that type/total amount))
		time since the last leetcode completion		

		could print out small chart of questions (number|title|difficulty|solved)
		this could be printed in order of difficulty or number (picked by user)
		user chooses which difficulty/difficulties, in what order to display 
			those, and they could also be in order by leetcode number
		user can also pick to print out all numbers, or up until a certian
			number from the top down, so if user picks 20, it will print the
			top 20 in numberical order, for exampleif the user picks the number
			4 then an output could include leetcode questions 4,654,and 1455.

Add new question to the list:
	Int for question number
	Text for title
	Int for difficulty (1 easy, 2 medium, 3 hard)
	Text/Blob for description 
After added to the list, will print out what was added

Print function():
	Params: input value from the user (which leetcode question)
		bool (false for short description or true for full description)
		one for each of the large text types
		will reset after after going back to menu

	Takes prompt from user (int) to see what leetcode question he wants to print out
	Prints out all data in half decent format

	The large text file parts will be shrunken down.
		Driver code will store the whole text in the column, but will only display 
		part of the code as a preview.

	Have another menu screen that will ask the user if he wants to see more of the text
	Will also have a prompt to go back to the main screen
	If user wants to see more, another menu will ask which text he would like to see
		full description
		what i learned
		extra section

	Will then call print function again with different parameters


Remove from the list:
	Quite simple, but ask for leetcode number and delete that one

Structure of our database:
	Leetcode number
	Leetcode title
	difficulty
	Leetcode quick/full description (clickable link, google if possible/doable)		
	Solved checker
	Solved if with help from google 	
		(possible link{implement a way to shorten text in this box so that you 
		can ask for the specifics of any box. In the same way for the text for 
		the column of describing what the mistake was, what were the better 
		solution(s), what to watch out for} or text preview)
	What I learned/Have to learn
	Extra (If this extra section contains a null value then it wont be shown)
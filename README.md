crazy-house
======

# Purpose
The purpose of this project is to create an artificial intelligence that can play the crazy-house variant of chess (this variant allows for dropping of captured pieces back onto the board.)

# Implementation
My first attempt at this problem involved inheritance. I created a Piece class, from which I derived classes Pawn, Bishop, etc. My thought was to use an array of polymorhpic \*Piece pointers. While this would have worked in principle, it soon became apparent (with some help from Brent Edmunds) that this was not the most efficent way to go. Instead, I created an array of std::pair<Piece, Color>\* pointers, where Piece and Color are strongly enumerated types. This allowed me to call functions regardless of piece type, for instance by using switch statements on Piece or Color. 

Almost all functionality was contained in member functions of a class called Board (a Board contains the pointer array, a score denoting who is better among white and black and a bool called white2move.) Such functions include toggle_move_color(), get_score() and set_score(), in_check() and checkmate() (which return true if these conditions are met), and solver().

The solver function uses the minimax iterative strategy for finding moves. It searches to a certain depth, and assumes that, in response to any move the AI will make, the user will choose the optimal response (optimal in the sense of score as computed by the set_score() function.) For my test trials, I have been sticking to a depth of four. 
The view() function prints the board to the console, along with a grid to allow the user to make moves.

# Deficiencies
I was unsuccessful in creating an AI to play crazy-house against. My working version allows a user to play standard chess (only as white) against the computer. Here is a list of things that, given more time, I would hope to implement for this project:
1. Allow the user to play as black
2. Create a GUI for more intuitive play
3. Allow for moves to be made using algebraic notation (e.g. 1. Nf3 ...) 
4. Save games using PGN
5. Allow for castling and en passant
6. Improve my set_score() function by taking piece mobility into account
7. Have the AI calculate forced mating attacks when possible
8. Implement alpha-beta pruning to improve speed (eliminate separate calculations for branches that merge)
9. Allow for captured pieces to be returned to play under the opposite color (essentially allowing this program to play the chess variant I initially intended

### RAII
One major area in which my program does not adhere to the idioms of PIC 10C is RAII. While I do have a correctly implemented Big 4, there are several areas in which I could possibly have memory leaks. These potential leaks all stem from the same problem: the desire not to have to create many copies of a Board in order to calculate possible moves. Because copying a Board is more expensive that simply moving one piece (by exchanging pointers in the board[][]), I performed calculations on the same board by moving pieces and then undoing these moves when necessary. Unless my program crashes, these calls to new and delete should ensure memory leaks do not occur; however, if I were to start this project again from scratch I would consider ways in which this strategy could be handled while adhering to RAII.

# Final Thoughts
Although I was not able to achieve all the functionality I intended for this project, it was a good learning experience for me. This was the first time in the PIC series that memory management had a noticeable affect on performance, and it was interesting to see certain moves cause the program to run slower (likely because of an abundance of possible moves in that position.) It was also interesting to work on a project in which there will likely remain room for improvement regardless of how much work goes into it. I'm happy with what I was able to accomplish, but I'm also glad to look back and see several ways I could have improved my design.

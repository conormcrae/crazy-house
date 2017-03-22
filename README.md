crazy-house
======

## Purpose
The purpose of this project is to create an artificial intelligence that can play the crazy-house variant of chess (this variant allows for dropping of captured pieces back onto the board.)

## Implementation
My first attempt at this problem involved inheritance. I created a Piece class, from which I derived classes Pawn, Bishop, etc. My thought was to use an array of polymorhpic \*Piece pointers. While this would have worked in principle, it soon became apparent (with some help from Brent Edmunds) that this was not the most efficent way to go. Instead, I created an array of std::pair<Piece, Color>\* pointers, where Piece and Color are strongly enumerated types. This allowed me to call functions regardless of piece type, for instance by using switch statements on Piece or Color. 
Almost all functionality was contained in member functions of a class called Board (a Board contains the pointer array, a score denoting who is better among white and black and a bool called white2move.) Such functions include toggle_move_color(), get_score() and set_score(), in_check() and checkmate() (which return true if these conditions are met), and solver().
The solver function uses the minimax iterative strategy for finding moves. It searches to a certain depth, and assumes that, in response to any move the AI will make, the user will choose the optimal response (optimal in the sense of score as computed by the set_score() function.) For my test trials, I have been sticking to a depth of four. 
The view() function prints the board to the console, along with a grid to allow the user to make moves.

## Deficiencies
I was unsuccessful in creating an AI to play crazy-house against.

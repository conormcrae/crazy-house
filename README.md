crazy-house
======

## Purpose
The purpose of this project is to create an artificial intelligence that can play the crazy-house variant of chess (this variant allows for dropping of captured pieces back onto the board.)

## Implementation
My first attempt at this problem involved inheritance. I created a Piece class, from which I derived classes Pawn, Bishop, etc. My thought was to use an array of polymorhpic *Piece pointers. While this would have worked in principle, it soon became apparent (with some help from Brent Edmunds) that this was not the most efficent way to go. Instead, I created an array of std::pair<Piece, Color>\* pnters, where Piece and Color are strongly enumerated types. This allowed me to call functions regardless of piece type, for instance by using switch statements on Piece or Color.

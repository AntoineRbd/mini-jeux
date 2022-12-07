# mini-jeux

# Table of Contents
I. [Mastermind](#mastermind)
    1. [Rule](#rule)
    2. [How to Play](#how_to_play)

## Mastermind 
### Rules
The object of MASTERMIND is to guess a secret code consisting of a series of 4
colored pegs. Each guest results in feedback narrowing down the possibilities of the
code. The winner is the player who solves his opponent's secret code with fewer
guesses

The codebreaker tries to guess the pattern, in both order and color, within twelve turns. Each guess is made by placing a row of code pegs on the decoding board. Once placed, the codemaker provides feedback by placing from zero to four key pegs in the small holes of the row with the guess. A colored or black key peg is placed for each code peg from the guess which is correct in both color and position. A white key peg indicates the existence of a correct color code peg placed in the wrong position

If there are duplicate colors in the guess, they cannot all be awarded a key peg unless they correspond to the same number of duplicate colors in the hidden code. For example, if the hidden code is red-red-blue-blue and the player guesses red-red-red-blue, the codemaker will award two colored key pegs for the two correct reds, nothing for the third red as there is not a third red in the code, and a colored key peg for the blue. No indication is given of the fact that the code also includes a second blue

Once feedback is provided, another guess is made; guesses and feedback continue to alternate until either the codebreaker guesses correctly, or all rows on the decoding board are full.

Traditionally, players can only earn points when playing as the codemaker. The codemaker gets one point for each guess the codebreaker makes

### How to play
To play mastermind, go to `mastermind/src`.
Then run 
```
make
./mastermind
```

The programm will ask you to put you first combination with this following format :
```
####
```

Where each **#** represent a color number 
```
RED     0
BLUE    1
GREEN   2
YELLOW  3
```

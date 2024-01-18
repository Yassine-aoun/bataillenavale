# bataillenavale
![Bataille Navale](https://www.logicieleducatif.fr/vignette/bataille-navale/815624-vignette_600.jpg)
##  Overview of the "Battleship" Game
### General Rules of the Game
The game of "Battleship" is a two-player board game in which players must place their ships on a "secret" grid. They then aim to sink all opponent ships by hitting all ship squares in turn. The winner is the one who manages to sink all the opponent's ships before their own ships are all sunk. A ship is considered sunk if each of its squares has been hit by the opponent's shots. Each player has a 10x10 grid where their ships are placed without overlapping or touching. There are two possible ship arrangements:

Standard Arrangement:

1 Aircraft Carrier (5 squares)
1 Cruiser (4 squares)
2 Destroyers (3 squares)
1 Submarine (2 squares)
Belgium Arrangement:

1 Battleship (4 squares)
2 Cruisers (3 squares)
3 Destroyers (2 squares)
4 Submarines (1 square)
For the shooting phase, each player must, one after the other, choose coordinates for a shot, consisting of a row index and a column index. The effects of the shot can either be "miss" if the shot did not hit any ship or "hit" if the shot hit a ship square. When all squares of a ship are hit, the ship is "sunk."
## Console Version

### Game Mechanism:

Upon launching the game, the program will present you with a list of choices:

If you want to play with another human player, type 1. If you type 2, you will play against the computer.

### Mechanism of the 1 vs. 1 Game:

First, the names of the two players will be requested.

Then, the program will ask you which arrangement you want to adopt for this game:

For the rest of this explanation, we will continue with arrangement 1.

After choosing the arrangement, the game will prompt the first player to start filling the board.

Each time, the game will specify which ship to place and how many squares the ship will occupy.
The player is supposed to specify the first row of the square (between 0 and 9) and the column of the square (letter between A and J) during placement and the direction of the ship: horizontal or vertical.

In this example, the ship will be in line 3 starting from column C.
The ship is represented by "#" on the board.

These actions will be repeated for each ship for each of the two players.
Once the placements are done, the shooting phase can begin.

In each turn, each player must enter the coordinates for a shot.

When all the ships of a player are sunk...

The end of the game is then announced along with the name of the winner.

### Mechanism of the Robot Game:

Now let's run a game against a robot.

The program will ask you for the player's name and which arrangement you want to adopt for this game:

For this example, we will try the 2nd arrangement (Belgium Arrangement).

The robot fills its board automatically and randomly using a script that we have implemented.

Then the attack phase is the same as explained earlier for the player. But the attack function is an intelligent version. The robot will attack randomly, but when its attack intersects with a square of an opponent's ship, it will try to destroy it by attacking the squares near the one attacked.


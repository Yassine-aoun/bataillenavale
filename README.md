# bataillenavale
<img src="https://www.logicieleducatif.fr/vignette/bataille-navale/815624-vignette_600.jpg" alt="Bataille Navale" width="300"/>
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
![Game Mechanism](https://img.genial.ly/603573c0d5d0c10a0b2726e2/162e7f0e-8a92-47fd-8f80-44cb5abd34cf.png)


### Mechanism of the 1 vs. 1 Game:

First, the names of the two players will be requested.
![Game Mechanism](https://scontent.ftun1-2.fna.fbcdn.net/v/t1.15752-9/416659535_1540818896694988_8304059225903432454_n.png?_nc_cat=107&ccb=1-7&_nc_sid=8cd0a2&_nc_ohc=5Z_PocAioHEAX9_hRJg&_nc_ht=scontent.ftun1-2.fna&oh=03_AdTeZuGLe1QZyOcyY6AHwNveD2an9Zq7Th3H2jgO-PYMtw&oe=65D0C8B0)

Then, the program will ask you which arrangement you want to adopt for this game:
![Game Mechanism](https://scontent.ftun1-2.fna.fbcdn.net/v/t1.15752-9/417967766_755269156000344_892879428463829971_n.png?_nc_cat=100&ccb=1-7&_nc_sid=8cd0a2&_nc_aid=0&_nc_ohc=o6nBWncOE6MAX8cSfid&_nc_ht=scontent.ftun1-2.fna&oh=03_AdQs7y9R44MeEUoYS4Z7XFaqyamXaTdA9NeQutupBaeOnA&oe=65D0CD13)

For the rest of this explanation, we will continue with arrangement 1.

After choosing the arrangement, the game will prompt the first player to start filling the board.

Each time, the game will specify which ship to place and how many squares the ship will occupy.
The player is supposed to specify the first row of the square (between 0 and 9) and the column of the square (letter between A and J) during placement and the direction of the ship: horizontal or vertical.
![Game Mechanism](https://scontent.ftun1-2.fna.fbcdn.net/v/t1.15752-9/416659535_1540818896694988_8304059225903432454_n.png?_nc_cat=107&ccb=1-7&_nc_sid=8cd0a2&_nc_ohc=5Z_PocAioHEAX9_hRJg&_nc_ht=scontent.ftun1-2.fna&oh=03_AdTeZuGLe1QZyOcyY6AHwNveD2an9Zq7Th3H2jgO-PYMtw&oe=65D0C8B0 | width=300)



## Graphical User Interface Version

### Tools Used:
- Language: C++
- Environment: Visual Studio
- Library: wxWidgets

wxWidgets (formerly wxWindows) is a widget toolkit and tool library for creating graphical user interfaces (GUI) for multi-platform applications. wxWidgets allows GUI code of a program to compile and run on multiple computing platforms with minimal or no code modifications.

### Used Classes:
- wxBackgroundBitmap
- Cfill
- Cmain
- CMenu
- CApp

### Other Used Libraries:
- Wx/bitmap.h: Insert an image.
- Wx/event.h: Trigger actions, for example, to switch from one window to another.

### Home Screen:
![Game Mechanism](https://scontent.ftun1-2.fna.fbcdn.net/v/t1.15752-9/417330664_394692739733357_3211872291128444284_n.png?_nc_cat=111&ccb=1-7&_nc_sid=8cd0a2&_nc_ohc=JfKC7M9S4kkAX90LGp5&_nc_ht=scontent.ftun1-2.fna&oh=03_AdTAcTV-9wrB7P83kBCijX_0f0zE9wKbKjshb4WKx5eEGA&oe=65D09D08 | width=300)


### Filling Screen:

![Game Mechanism](https://scontent.ftun1-2.fna.fbcdn.net/v/t1.15752-9/417732775_397136352888291_233989163788955952_n.png?_nc_cat=111&ccb=1-7&_nc_sid=8cd0a2&_nc_ohc=qPfV9Sl9ZeoAX8gqVNV&_nc_ht=scontent.ftun1-2.fna&oh=03_AdS2XLspThMihH5YR0iH7nOF62WbxrEhwvr01h3yg2kV3g&oe=65D0AC9E | width=300)


### Battle Screen After Attack:

![Game Mechanism](https://scontent.xx.fbcdn.net/v/t1.15752-9/417379294_279264838186135_2575092385583889252_n.png?stp=dst-png_p206x206&_nc_cat=107&ccb=1-7&_nc_sid=510075&_nc_ohc=GllbVYOA0AQAX8vQ_iQ&_nc_ad=z-m&_nc_cid=0&_nc_ht=scontent.xx&oh=03_AdQCI0DXFCdyjuiv7DeKUuSHN_c6zK69BgodYgJCX0n0gw&oe=65D09CDD | width=300)


# cub3D

cub3D is a project of 42 school about creating a basic 3D game with the *minilibx* using the **raycasting** technique. 
Similar to the **Wolfenstein 3D** game.

## How to Run

To run the program, navigate to the project directory and run the following command:

```
make
./cub3D maps/map.cub
```
In cub3D you can move with **W**, **A**, **S**, **D** and turn around with the **mouse** or with **left** and **right** arrow. 

## Map Rules

Two maps are already on the *maps* folder but you can make your own **.cub** !

* **NO**, **SO**, **WE**, **EA** are the textures of the nothern, southern, western and eastern walls. (must be **64x64** and **.xpm**)

* The floor color is **F** while **C** is for the ceiling, these values are RGB. (between 0 and 255)

* 1 is a wall, 0 is an empty space, the map needs to be closed and the player is represented with N, S, E or W, to know his initial direction (north, south, east, west)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm


F 35,40,41
C 117,115,108

         11111111
111111111111100111111111111
11100000000000W00000000111111
1100000011101010110000111100111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

## Preview

*Welcome to the raycasted world !* 

![Screenshot from 2023-04-07 21-55-43](https://user-images.githubusercontent.com/31923839/230671432-970fe804-78c5-4115-85fa-371048b413aa.png)


## Ressources 

* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html)
* [Lodev raycasting tutorial](https://lodev.org/cgtutor/raycasting.html)
* [Play Wolfenstein 3D](http://users.atw.hu/wolf3d/)

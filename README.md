# Tower Defense
Simple 2D game written in C++ using SFML graphic library.

### Dependencies
* [SFML] graphic library

### Installation
From the root directory of this repository run:
```sh
$ mkdir build; cd build
$ cmake ..
$ make
```
And to run the game:
```sh
$ cd ..
$ ./tower_defense
```
`./tower_defense` must be executed from root directory.

### Experimental

##### Frame rate
Game is limited to 30fps. To limit frame-rate to 60fps press key **F**.

##### Level map
Level map is saved in `data/map.1` you can freely edit it as long as start is in the
first column and size of a level is 20x20 chars.
```
...........
#########..
........#..
..#######..
..#........
..#...#####
..#...#....
..#.. ###..
..#.....#..
..#######..
...........
```

##### Waves
Enemy waves are saved in `data/waves.1` file. Lowercase letters are used to spawn enemies.
```
aaaaaaaaaaaaaaaaaaaa
bbbbbbbbbbbbbbbbbbbb
cccccccccccccccccccc
bcbcbcbcbcbcbcbcbcbcbcbcbcbcbcbcb
```

   [SFML]: http://www.sfml-dev.org/

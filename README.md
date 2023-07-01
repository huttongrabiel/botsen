# Botsen

A collision simulator. The collisions are simple. Two balls moving towards
each other will collide according to their properties and the settings of the user.

In classical mechanics there are three types of collisions: elastic, inelastic,
and totally inelastic.

# Runnning the Code

First install [raylib](https://github.com/raysan5/raylib)

Then within the directory for Botsen
```bash
mkdir build && cd build
cmake ../src
make -j
./Botsen
```

# TODO
- [X] Add support for elastic collisions
- [X] Add support for inelastic collisions
- [X] Add support for totally inelastic collisions
- [X] Allow user to specify collision type before beginning collision
- [ ] Allow user to 'throw', using mouse, balls at one another to cause collision
- [X] Keep balls within the frame and have them bounce of the sides

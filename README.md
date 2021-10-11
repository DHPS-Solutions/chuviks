# Rubik's Cube solver in C
![size](https://img.shields.io/github/repo-size/dhps-solutions/chuviks)
![lines](https://img.shields.io/tokei/lines/github/dhps-solutions/chuviks)
![commits](https://img.shields.io/github/commit-activity/w/dhps-solutions/chuviks)

Spits out a sequence of moves that eventually will be sent to a microcontroller to control servos and actually solve a physical Rubik's Cube.
## Motivation
- Learning C
- Create an interesting and visual project for our portofolios
- Having fun!
## How it's going to work
- Use camera's to determine a physical cube's starting position
- Run the solving program with the starting position as it's input
- Solving program returns a sequence of moves into a text file that can be read by a microcontroller and translated into moves in servo motors. F.ex. the sequence necessairy to get to a solved state might be R, F2, L, U. This would be translated into: move right servo motor, move front servo motor x 2, and so on.

### See directory 'helpers/' for demystification of the notation being used and how the Rubik'S Cube is represented in C code.

Logo: https://www.freelogodesign.org/manager/showcase/9a507fc0bd3742859223c8b157ff9db9

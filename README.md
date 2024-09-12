# 3D on the GameBoy

> An attempt at using the GBDK to run minimal 3D graphical renderings on GameBoy hardware

![square rotation](./img/sqrot.gif)

So far, I've implemented
- Basic fixed-point math functionality
- Linear-algebraic primitives, and
- 3D graphics primitives.

I used these to generate the above animation in which a 2D square is rotated about the origin on the screen.

Looking forward, I plan to implement
- A perspective transformation matrix for 3D rendering
- A cube that is rendered in 3D using the perspective matrix
- A 3D rotation matrix to rotate the cube about the origin
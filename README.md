# 3D on the GameBoy

> An attempt at using the GBDK to run minimal 3D graphical renderings on GameBoy hardware

# Cube rotation

![cube rotation](./img/curot.gif)

This is my latest proof-of-concept.  I made a first attempt at implementing a perspective projection transform.  It succeeds at projecting my cube onto the screen, albeit could use some work still to refine the field of view, as the cube looks a little too extended.

In this animation, I attempt to also apply a rotation transformation in which I rotate the cube about the z-axis.  This led to a bit of glitchiness, so I'll likely need to improve upon this by spending a bit of time refining the underlying fixed-point math.

In the process, I also dealt with my first instance in which my ROM size grew too large for the GameBoy to handle.  I ultimately needed to cut corners on memory usage as much as possible to enable this rotation to be executed in the first place.

# Square rotation

![square rotation](./img/sqrot.gif)

This was my initial proof-of-concept.  I implemented basic fixed-point math and 3D linear algebra.  I had not attempted to implement a perspective projection transform at this stage, hence why my two squares are perfectly overlapping despite the difference in their z-coordinates.  I used this functionality to generate the above animation in which a 2D square is rotated about the origin on the screen.
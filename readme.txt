=== Discription: CS606 Assignment 1 ===

Bezier curve are parametric curves, which are plotted on a given control points. Two methods to compute Bezier curve are using bernstein polynomian and other is De Castljau's algorithm.

=== Installation ===

On your linux machine, one needs to install free-glut libraries. To do the same, at terminal punch in

$apt-get install freeglut3-dev

=== List of files ===

main.cpp
BezierCurve.cpp
BezierCurve.h
Bernstein.cpp
Bernstein.h
Decastljau.cpp
Decastljau.h
Utility.cpp
Utility.h

=== How to run ===

1. Open your termial. 
2. Move into the src dirctory.
3. Type: make

:~/MT2013152_Assignemnt01/src$ make

4. Type: ./paintcurve to fire up the window
:~/MT2013152_Assignemnt01/src$ ./paintcurve
(for Better visual description view Beziercurve-image01.png in screenshots folder )

5. On the window opened, hover your mouse curser and click on the window screen.

6. User can pick random points on the screen using mouse.
(for Better visual description view Beziercurve-image02.png in screenshots folder )

7. Use right click to pop up the menu.
(for Better visual description view Beziercurve-image03.png in screenshots folder )

8. Pop up menu has options to the draw curve using two mentioned algorithm.

9. Pick your algorithm to plot the graph. One should be able to see a curve being draw with change colour all along its path, also notice the name of algorithm being selection appearing at the bottom left of the screen.
(for Better visual description view Beziercurve-image04.png in screenshots folder )

10. User can successivley add points the existing plot and paint curve.

11. Use option in the menu to clear the screen.

12. In addition we have following features:

Scaling

Scaling is done using following keys   -

i – to scale up the scene
o – to  scale down the scene

Translation

Translation is done using following keys   -

w – to translate upward
s  – to  asd to to translate downward
a – to translate to left side
d – to translate to ride side 

Rotation

Rotation is done using following keys   -

r – to rotate the scene anti-clock wise direction
t – to rotate the scene in clock wise direction


=== ScreenShots ===

ScreenShots are avaliable in the screenshots folder.

=== References/help ===

1. Interactive Computer Graphics - A Top-Down Approach Using OpenGL by Edward Angel
2. www.stackoverflow.com
3. www.opengl.org
4. Tutorials of openGL on www.youtube.com



 

# Cubic Bezier Curve

Given 4 control points p0,p1,p2,p3

![Bezier Curve](Bezier_curve.svg)

Generate a polynomial for both x and y for each point
and a parameter $t$ that ranges from 0 to 1, define an equation
so that when $t=0, (x,y) = p1$ and when $t=0, (x,y) = p3.
The other two points control the derivatives.

$x(t) = ((ax * t + bx) * t + cx) * t + dx$

$y(t) = ((ay * t + by) * t + cy) * t + dy$

$@t = 0, dx =p0.x, dy = p0.y$
$@t = 1, ax+bx+cx = p3.x - p0.x$

$x'(t) = 3ax t^2 + 2bx t + cx$
$y'(t) = 3ay t^2 + 2by t + cy$

$@t = 0, cx = p1.x - p0.x$

$@t = 1, 3ax + 2bx = p3.x - p2.x$

[a stackoverflow article showing solution](https://math.stackexchange.com/questions/2190728/how-to-calculate-the-cubic-b%C3%A9zier-spline-points)

$ax = p3.x + 3*(p1.x - p2.x) - 1$

$bx = 3*(p2.x - 2*p1.x + p0.x)$

$cx = 3*(p1.x - p0.x)$

$dx = p0.x$

same for y


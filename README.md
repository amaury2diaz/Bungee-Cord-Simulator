# Bungee Cord Simulator

While the user wishes to continue, the application will ask the user to select whether to run the simulation one more time.
The simulation uses Euler’s method, as explained in lectures and the course book to solve a differential equation for acceleration with an additional elastic restoring force term B so as to simulate stepping off the top of a 400 meter high building with a bungee cord tied to your ankle. The task is to reach the ground at low speed (<1.0 metres/sec at a height < 1.0 metres) so you can safely slip off the bungee and walk away.

The differential equation you are solving is the acceleration for falling under gravity with wind resistance and a bungee rope tied to your ankle:  
<br/><br/><b>dv/dt = g –(c/m)*(v + a*(v/vmax)2) – B</b><br/><br/>

v is velocity down, with values of the constants g = 9.8, c(initially) = 10.0, m = 68, a = 8.0, vmax = 46.
.
The forces on the right-hand side are:
1.	first term: g – the acceleration of gravity pulling you down,
2.	second term is the wind drag of the air slowing you down. It can be increased (w) or decreased (e) from the keyboard to simulate holding your arms out or keeping them close to your side while you fall, 
3.	third term B =  k(h0-h) is the elastic restoring force of the bungee cord pulling you up. k = 0.04 is the constant of the bungee cord and h0 = 400 is the initial height. For a heavy guy falling, reduce k.

If you have maximum wind drag (c = 10) then you burn up your speed and never reach the ground – you oscillate up and down for a while and are left dangling around 155 metres above the ground. If you have minimum wind drag (c = 1.0) you hit the ground too fast (v>1.0) and crash (you’re dead). So you need to adjust wind drag continuously so you just reach the ground (h<1.0) with a small speed (v<1.0) and so hover long enough to slip off the bungee cord. You start the simulation at time t = 0 with height h = h0 = 400 and velocity down = 0. Thereafter the differential equation determines both v and h with your input for c. 
 
The differential equation can be solved in an iterative algorithm, using Euler’s method, to calculate (and output) the velocity of descent at any step i+1 by correcting the previous value from step i from the iterative equation 
                                                                 <br/><b>vi+1 = vi + accni*time_elapsed</b><br/>

Also the current height hi+1 is calculated from the previous height iteratively using the average velocity over the interval:
                                                              <br/><b>hi+1 = hi-((vi +vi+1)/2) *time_elapsed.</b><br/>

When the simulation starts, you are 400 meters up on the top of the building. Then you fall to the ground under the control of the differential equation. As already stated, the purpose of the simulation is to get a soft landing that is a speed of < 1metre/sec at a distance above the surface of <1 metre. Hitting the surface any faster is a crash. The simulation continuously outputs the velocity and distance above the ground.  At the same time the overall duration of the jump is recorded.

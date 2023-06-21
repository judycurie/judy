# **Week16.** Applications and Implications

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |    - |
| *individual*      |        Propose a final project masterpiece that integrates the range of units covered, answering: What will it do? Who's done what beforehand? What will you design? What materials and components will be used? Where will come from? How much will they cost? What parts and systems will be made? What processes will be used? What questions need to be answered? How will it be evaluated? Your project should incorporate 2D and 3D design, additive and subtractive fabrication processes, electronics design and production, embedded microcontroller interfacing and programming, system integration and packaging. Where possible, you should make rather than buy the parts of your project. Projects can be separate or joint, but need to show individual mastery of the skills, and be independently operable |


## Photo of the week

![](../images/week16/photo-of-the-week16.png)


## Lecture Notes

![](../images/week16/week16.png)
![](../images/week16/week162.png)
![](../images/week16/week163.png)

## Checkpoints
- [ ] what it will do?
    * [ ] logic diagram
- [ ] state of art - who did what in this topic?
    * [ ] how you expand it?
- [ ] inventory of Components and where they come From
- [ ] questions to be answered
- [ ] *how should we evaluate it?*
- [ ] detailed schedule

**what it will do?** - it will be a device for controlling the assembly stage (measuring height), which could be attached to the top of a structure both in the model and real scale. The device will be remotely through Bluetooth communicating with the host device reading the height (and alternatively controlling the assembly device e.g. pumped membrane).


 **inventory of Components and where they come From**

 | Component   |                          |
 | ----------- | ------------------------------------ |
 | 2 x nRFN5240     |   China |
 | 1 x Plywood 0.6mm flex 1220x1220 | Finland|
 | 1 x Plywood 0.8mm flex 1220x1220 | Finland|

 **questions to be answered**

- Should I get plywood from Europe or design the inflatable membrane?

- Device should monitor the height from the acetometer (difficult to calibrate) or should I use ultrasonic sensor?

- How to add the sensing of the presence under the pavilion?

 **state of art**

 - [Sam Calish inflatables](http://fab.cba.mit.edu/classes/863.12/people/calisch/inflate/inflate.html)
 - [how to make inflatables](https://www.instructables.com/Giant-Inflatable-Robot/)
 - (https://www.softrobotics.io/)

## Inflatable
1. Finding a simulation model where the lengths of the disassembled and assembled are almost identical. It required finding the same topology of the points from the simulation model.
![](../images/week16/week164.png)
2. Finding planes (panels) which could be inflated.
![](../images/week16/week165.png)
3. The main asymptotic curves have the same length, therefore let's try to find lengths of the diagonals in the disassembled and assembled state.
![](../images/week16/week166.png)
![](../images/week16/week167.png)
4. Projecting of the diagonals lengths in the disassembled and assembled state. Their lengths stand for the bottom and top layer of the fabric to be inflated.
![](../images/week16/week168.png)
5. Visualization of the inflated panels. It doesn't seem to be feasible to inflate panels.
![](../images/week16/week169.png)
6. Let's check which diagonals shorten the most. Left: black shorten, white-extend. Right: Diagonals shortening more than 15cm on the segment.
![](../images/week16/week1610.png)
7. Making inflatable stipes makes it perfect.
![](../images/week16/week1611.png)
8. The inflated stripes with exact height calculated from the disassembled state (fit loft).
![](../images/week16/week1612.png)
9. Now only I need to figure out how to fabricate such a membrane :).
![](../images/week16/untitled.92.jpg)
![](../images/week16/untitled.93.jpg)

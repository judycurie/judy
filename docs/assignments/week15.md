# **Week15.** Wild Card

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |    - |
| *individual*      |        Design and produce something with a digital fabrication process (incorporating computer-aided design and manufacturing) not covered in another assignment, documenting the requirements that your assignment meets, and including everything necessary to reproduce it.|


## Photo of the week

![](../images/week14/photo-of-the-week14.png)


## Lecture Notes

![](../images/week15/week15.png)
![](../images/week15/week152.png)


## Idea
![](../images/week15/week153.png)

To design support holders for the final project scaled gridshell in scale 1:5.  The holders were desinged to be possible to fit the structure legs into them or (for some unknown reasons occuring duting physical assembly) if this would be not possible, they can keep the structure from unfolding staying on the outside.

## First Print
![](../images/week15/week154.png)
**Grasshopper file**: [gh -file](../files/week15/230516-print1.gh){: print1 }
**Robot Path**: [src-file](../files/week15/230516-print1.src){: print1 }
![](../images/week15/week155.png)
![](../images/week15/week156.png)

## Bottom Design

![](../images/week15/week157.png)
![](../images/week15/week158.png)
![](../images/week15/week159.png)
![](../images/week15/week1510.png)
![](../images/week15/week1511.png)

**Path generation trials**: [gh-file](../files/week15/codigos bancos y espiral-JC-bottom-master.gh){: path generation trials }
```
__author__ = "judyt"
__version__ = "2023.05.15"

import rhinoscriptsyntax as rs
import ghpythonlib.components as gh
import math
import clr
from Grasshopper.Kernel.Data import GH_Path
from Grasshopper import DataTree

def nestedListToDataTree(nestedlist):
    dataTree = DataTree[object]()
    for i,item_list in enumerate (nestedlist):
        path = GH_Path(i)
        dataTree.AddRange(item_list,path)
    return dataTree

height = math.sqrt(d**2 - offset**2)
print height
xpoints = []
points = x
pointsX = xx
for i in range (y):
    newpointsX = []
    newpoints = []
    center = gh.Average(points)
    for j in range(len(points)):
        #vecXYdir = gh.Vector2Pt(points[j], center, True)
        vecXYdir = rs.VectorUnitize(rs.VectorCreate(pointsX[j],points[j]))


        vecXY = gh.Amplitude(vecXYdir, offset)
        vecZ = gh.UnitZ(height)
        vec = rs.VectorAdd(vecXY,vecZ)

        newpoint = gh.Move(points[j],vec)['geometry']
        newpointX = gh.Move(pointsX[j],vecZ)['geometry']
        print newpointX
        newpoints.append(newpoint)
        newpointsX.append(newpointX)
    xpoints.append(newpoints)
    points = newpoints
    pointsX = newpointsX

xpoints = nestedListToDataTree(xpoints)

```
## Final Design

![](../images/week15/week1515.png)
![](../images/week15/week1517.png)

## Final Video
<video width="960"  controls>
  <source src="../../images/week15/WhatsApp Video 2023-05-16 at 23.12.38.mp4" type="video/mp4">
</video>

![](../images/week15/WhatsApp Image 2023-05-16 at 23.18.11.jpeg)

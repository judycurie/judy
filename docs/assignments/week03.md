# **Week03.** Computer-Controlled Cutting


|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |  characterize your lasercutter's focus, power, speed, rate, kerf, joint clearance and types 
| *individual*      | cut something on the vinylcutter; design, lasercut, and document a parametric construction kit, accounting for the lasercutter kerf,which can be assembled in multiple ways, and for extra credit include elements that aren't flat |


# Define the available joint types and their dimensions
joint_types = {
    'Butt Joint': {
        'thickness': [10, 20, 30],
        'length': [30, 40, 50],
    },
    'Lap Joint': {
        'thickness': [10, 20],
        'length': [20, 30],
        'lap_depth': [5, 10],
    },
    'Mortise and Tenon Joint': {
        'thickness': [20, 30, 40],
        'length': [40, 50, 60],
        'mortise_depth': [10, 15, 20],
        'tenon_length': [10, 15, 20],
    },
    'Dovetail Joint': {
        'thickness': [20, 30, 40],
        'length': [40, 50, 60],
        'dovetail_angle': [10, 15, 20],
    },
}

# Define the material thickness
material_thickness = 30

# Iterate over the joint types and find the appropriate joint based on the material thickness
for joint_type, joint_details in joint_types.items():
    if material_thickness in joint_details['thickness']:
        print(f"{joint_type} is suitable for material thickness {material_thickness} mm")
        print(f"Joint dimensions: {joint_details}")
        break
else:
    print(f"No joint type is available for material thickness {material_thickness} mm")



## Photo of the week

![](../images/week03/photo-of-the-week3.png)

## Simulation & Reality

<iframe width="960" height="315" src="https://youtube.com/embed/Mqb7dUGRLO0" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

<iframe width="960" height="315" src="https://youtube.com/embed/Y_U2DWwXKLk" frameborder="0" allow="autoplay; encrypted-media" allowfullscreen></iframe>

## Design & Fabrication

The beauty of asymptotic gridhshell lies in the ease of fabrication. The 3D laths unroll to  flat straigh strips which can be manufactured by laser, milling or even by hand.

![](../images/week03/w03-layoutbw.jpg)

To produce below fabrication layout, I prepered a custom Python script for unrolling and labaling of the elements and joints. The code produces layout for the bottom layer of the assymptotics. 

![](../images/week03/Screenshot 2023-02-13 205314x.png)
The scipt accounts for the laser beam size (kerf), material thickness, width of the material and tolerances. 
![](../images/week03/Screenshot 2023-02-13 211725x.png)
The joint connection shape can be rectacngular or defined by custom draw curve. 

![](../images/week03/Screenshot 2023-02-13 210750x.png)
![](../images/week03/Screenshot 2023-02-13 210841x.png)

## Material Tests
The material tests were conducted on 2 machines: Spirit GLS 12-100W CO2 (1) and Cromak LC5070Z (2,3,4).
The sample were cut with constant speed and varying power. The chosen speed is the fastest speed for which with 100% power the material was cut. 
![](../images/week03/w0309.jpeg)

The model was produces from the 0.8mm Birch Plywod. Based on the sample test the power of 40% was enought to cut the materia. As 5% power does nothing, for engraving the power of 7% was chosen.


## Model Assembly
The cut pieces were placed in assebmly order divided into Series A- bottom and Series B- top. The assembly was flat and the elements had to be carefully put into the right slots. The assebmled flat model was erected genetly with hands.
![](../images/week03/week03x3.jpg)


## Vinyl Cutter 
I followed the classy Vinyl cut sticker for my laptop. The vector drawing was prepared in Rhino and scaled to 50mm. After cutting, the trnasculent background needs to be covered with the additional layer. 

![](../images/week03/week03x.jpg)



## Group assignment

A few materials were considered and their thickness  measured: PET: 1.15mm, proipropylen 0.51mm, and cardboarf 1.45mm. The sameple test was cut on the PET sample (1).
![](../images/week03/week03x2.jpg)

A laser cutter's beam usually has a diameter between 0.1 and 0.3 mm. For the Spirit GLS 12-100W CO2 tested in the FabLab CDMX is 0.1mm (Laser Source, 10.6µm). 

## Python script

I prepered a custom Python script for the unrolling of the asymotitic laths and labaling the elements and the connection points. The cutting outlines account for the laser beam and thickness of the material.


```
import rhinoscriptsyntax as rs
import ghpythonlib.components as gh
from Grasshopper.Kernel.Data import GH_Path
from Grasshopper import DataTree
import Rhino


def nestedListToDataTree(nestedlist):
    dataTree = DataTree[object]()
    for i, item_list in enumerate (nestedlist):
        path = GH_Path(i)
        dataTree.AddRange(item_list, path)
    return dataTree

namesA = []
namesB = []
for i in range(len(curvesA)):
    namesA.append("A"+str(i))
    namesB.append("B"+str(i))

paramA = []
indexB = []
for a in curvesA:
    tA = []
    iB = []
    for b in curvesB:
        t = gh.CurveXCurve(a, b)['params_a']
        if t != None:
            tA.append(t)
            i=curvesB.index(b)
            iB.append(namesB[i])
            
    paramA.append(tA)
    indexB.append(iB)
    
paramA = nestedListToDataTree(paramA)
indexB = nestedListToDataTree(indexB)

_curves = []
_points = []
_pointsX = []
_names = []
_tags = []
_tagsCrvs = []
_outlines = []
_cutlines = []

for i in xrange(paramA.BranchCount):
    #create lines
    s = (step+width)*i
    startPt = gh.ConstructPoint(s,0,0)
    lg = gh.Length(curvesA[i])
    if lg == None:
        lg = 0.00
    endPt = gh.ConstructPoint(s, lg, 0)
    line = gh.Line(startPt,endPt)
    pt1 = gh.ConstructPoint(s-0.5*width,0,0)
    pt2 = gh.ConstructPoint(s-0.5*width, lg, 0)
    pt3 = gh.ConstructPoint(s+0.5*width, lg, 0)
    pt4 = gh.ConstructPoint(s+0.5*width,0,0)
    outline = gh.PolyLine([pt1,pt2,pt3,pt4], True)
    
    #create element name
    name = namesA[i] 
    midPt = gh.ConstructPoint(s, lg/2, 0)

    points = []
    pointsX = []
    cutlines = []
    tags = []
    tagsCrvs = []
    
    # create intersection points with tags
    for j in range(len(paramA.Branch(i))):
        pt = gh.EvaluateCurve(line,paramA.Branch(i)[j])['point']
        ptX = gh.EvaluateCurve(curvesA[i],paramA.Branch(i)[j])['point']
        txt =  str(indexB.Branch(i)[j])
        
        #create the cut outline
        cutaxis = gh.LineSDL(pt, gh.UnitX(1),0.5*width)
        cpt1 = gh.Move(pt, gh.ConstructPoint(0,0.5*thickness + 0.5*beamsize,0))['geometry']
        cutline1 = gh.LineSDL(cpt1, gh.UnitX(1),0.5*width+beamsize)
        cutline2 = gh.Mirror(cutline1, gh.XZPlane(pt))['geometry']
        cpt2 = gh.EndPoints(cutline1)['end']
        cpt3 = gh.EndPoints(cutline2)['end']
        cpt4 = gh.EndPoints(cutline2)['start']
        cutline = gh.PolyLine([cpt1,cpt2,cpt3,cpt4], True)
      
        #add instances to the lists
        points.append(pt)
        pointsX.append(ptX)
        tags.append(txt)
        cutlines.append(cutline)
 

    _curves.append(line)
    _points.append(points)
    _pointsX.append(pointsX)
    _cutlines.append(cutlines)
    _outlines.append(outline)
    _names.append(name)
    _tags.append(tags)
    _tagsCrvs.append(tagsCrvs)


_points = nestedListToDataTree(_points)
_pointsX = nestedListToDataTree(_pointsX)
_cutlines = nestedListToDataTree(_cutlines)
_tags = nestedListToDataTree(_tags)
_tagsCrvs = nestedListToDataTree(_tagsCrvs )
```
## Further work

![](../images/week03/page32.png)



## Conclusions/Problems/Questions/Dilemas


Scale and Tolerance problem

I tried add custom shape of the joints, however there was a problem with the units and tolerances. In [m] model the assymptotic cross sections worked correctl, while the cutout line for joints was not planar accrodingly to the software and couldnt be subtructued from the lath outline. While I scaled the model x10 the geometry operation on cutting out from the laths outlines the custom joint outlines worked.
![](../images/week03/w03s02.png)

Jumping out stripes

While the laths were placed on the board directly to each other, they started to stick out from the bed while being cut. Not recommended layout for the stip cutting. 


![](../images/week03/w03-layoutbwno.jpg)
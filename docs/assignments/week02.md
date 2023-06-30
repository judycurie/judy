# **Week02.** Computer-aided design

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |  na
| *individual*      | model (raster, vector, 2D, 3D, render, animate, simulate, ...) a possible final project, compress your images and videos, and post a description with your design files on your class page |

## Photo of the week
![](../images/week02/photo-of-the-week2.png)

## 2D Initial Design
Some Ideas of the shape and sensing:
![](../images/final-project/final8.png)
**Fig.** Shape and sensing ideas.

![](../images/week02/week2.png)
**Fig.** 2D design in plan: 1. Two carpark places, 2. The outline for the supports, 3. Placing support lines, so that 2 cars can access the space under the structure. 

Taking into consideration the geometric requirements, 2 subsurfaces were cut out of the minimal surface Enneper 3. The asymptotic curves were found with the custom-scripted component for Grasshopper.


![](../images/week02/V1V2-drawings2D.jpg)
**Fig.** Geometric comparison of the V1 and V2 proposals - top view.

Two proposal V1 and V2 can be built as a stand-alone structures. However for the modular assembly is important for the possibilities to cover large spaces. Some modular arrangements are presented below.

![](../images/week02/V1V2-modularity.jpg)
**Fig.** Modular arrangements - top view.

## Model
I wanted to find geometry concept, that is a cut out of the minimal surface which can be a roofing for 2 cars or a little garden party.

![](../images/week02/V1V2-drawingsx.jpg)

*“if surface is completely minimal, the asymptotics in the gridshell will coincide perfectly perpendicular, which result in torsion-free nodes and straight strips”* (Eike Schling, 2018)

The beauty of these structure lies in their simplicity. Not only they can constructed from the simple flat element but also assembled from flat. Below I made active-bending simulation with Kangaroo2, showing how the flat assembly will look like.

<video width="960"  controls>
  <source src="../../files/week02/SimulationTD500.mp4" type="video/mp4">
</video>

**Video.** Assembly simulation.


To model asymptotic gridshell composed of straight laths and with perpendicular intersection joints, the surface needs to be minimal. I selected Enneper 3 minimal surface, as has promising structurally and geometrically shape for the roof canopy. Below I present in short the workflow for the V1 and V2 versions.

## V1

![](../images/week02/Screenshot 2023-02-11 214846x.png)

The Enneper 3  surface was split with the plane and dome.

![](../images/week02/Screenshot 2023-02-11 214920x.png)

The network of asymptotics was created using a custom script.

![](../images/week02/Screenshot 2023-02-11 214949x.png)

I cutout the selected part of the Enneper surface.

![](../images/week02/Screenshot 2023-02-11 215028x.png)
The surface itself and the network of asymptotics were cut to the define outline. On the part of the surface where is starts the asymptotic network starts to get some problems with the direction as the surface is locally not continous/smooth. Therefore I cut 1/3 of the network and make the polar array and connect back with each other.

![](../images/week02/Screenshot 2023-02-11 215102x.png)
![](../images/week02/Screenshot 2023-02-11 215131x.png)
![](../images/week02/Screenshot 2023-02-11 215220x.png)

## V2
The Enneper 3 surface created.

![](../images/week02/Screenshot 2023-02-11 221301x.png)
The Enneper 3 surface was split with the plane and 3 geodesic curves.
![](../images/week02/Screenshot 2023-02-11 221413x.png)
![](../images/week02/Screenshot 2023-02-11 221439x.png)
The network of asymptotics was created using a custom script. The surface itself and the network of asymptotics were cut to the define outline. On the part of the surface where is starts the asymptotic network starts to get some problems with the direction as the surface is locally not continous/smooth. Therefore I cut 1/3 of the network and make the polar array and connect back with each other.

![](../images/week02/Screenshot 2023-02-11 221502x.png)
![](../images/week02/Screenshot 2023-02-11 221543x.png)
![](../images/week02/Screenshot 2023-02-11 221620x.png)
__________________________________________
## Files
**design files**: [Rhino/GH](../files/week02/230206_V.gh){: 230206_V}

# **Week18.** Project Development

|Assignment    |                          |
| ----------- | ------------------------------------ |
| *group*       |    - |
| *individual*      |      Complete your final project, tracking your progress:what tasks have been completed, and what tasks remain? what's working? what's not? what questions need to be resolved? what will happen when? what have you learned?|


## Photo of the week

![](../images/week16/photo-of-the-week16.png)


## Lecture Notes

![](../images/week18/week18.png)

## PET model 1:10

|Material|  thickness|  50| 60  |70  |**75**  | 80 |90  |   
|--------| ----------|----| ----|----|--------|----|----|  
|PET 20  | 0.55mm    |1.18| 0.95|0.79|**0.72**|0.66|0.55|  
|PET 30  | 0.74mm    |1.59| 1.28|1.06|**0.96**|0.88|0.74|
|PET 40  | 1.18mm    |2.53| 2.04|1.69|**1.54**|1.41|1.18|

## Final Project
**what tasks have been completed?**
- fabrication script for unrolling and taging the laths
- pcb host and slave remote communication
- design for 3D printed supports

**and what tasks remain?**

 - finding plywood material replacement & fabrication of structure model
 - desiging the middle part with attached board (some flex material?)
 - calibration of the IMU reading and sending it remotely to the host and/or signalling physically
 - optionally sensing occupancy

**what's working?**

- fabrication script for unrolling and taging the laths
- pcb host and slave remote communication
- slave pcb working on battery

**what's not?**

- measuring the height from the IMU sensor (calibration)
- printing supports with large 3D plastic extrudered failed

**what questions need to be resolved?**

- which material will be working for 1:5 model if not plywood
- how to read the height from IMU sensor
- how to communicate physically when certain height was reached
- how to send it through BLE to the host

**what will happen when?**

- by 01/06 struture fabricated
- by 03/06 reading height
- by 05/06 signaling the height: physically and remote BLE communication with HOST
- by 08/06 integration of the slave board in the Model
- by 10/06 integration of the design, additional sensor for presense?
- by 13/06 video

**what have you learned?**

- the Key Take aways are listened on the [final project website](../projects/final-project.md) at the end of each week section

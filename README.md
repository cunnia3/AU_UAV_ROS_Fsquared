Auburn University UAV ATTRACT project

This project is intended to create an environment for both simulation and testing of collision avoidance
algorithms on UAVs.


Features:

-Simulator - there is a basic point to point simulator for the Easy Star airplane running in UAV mode.

-Coordinator - monitors and coordinates all of the UAVs

-Collision avoidance - there is a collision avoidance file located in src that can be used as a shell
for writing your own avoidance algorithm

-XBeeIO - Integrates real UAVs using a X-Bee module

-KMLCreator - this program monitors all telemetry data and will output to a KML file when told to do so.  This will allow someone to load a visual representation of points into Google Earth.

-Launch files - inherited from ROS, you can create files to launch all or parts of the system

-Path files - a basic system for creating a path before running the program

-Course files - a basic system for creating a course and loading that into the program



ROS INSTALL

This is intended to be run on an Ubuntu device (Versions 11.10 – 12.0.4 have been verified).  However, you may be able to operate it on a Windows or Mac through a virtual machine.  The suggested VB is provided at http://nootrix.com/downloads/ (The ROS Fuerte Version). Step by step instructions are provided here: http://nootrix.com/2012/09/virtualizing-ros/.  Once the NOOTRIX virtual box is installed, the ROS environment comes preconfigured.  After the ROS environment is configured and the AU_UAV_stack is in the ros_workplace, you are ready for ROS compilation and execution.


ROS COMPILE / EXECUTION

To compile type "rosmake AU_UAV_stack"

To run type "roslaunch AU_UAV_ROS <launchfile>"
	-launchfiles are provided in AU_UAV_ROS/launch




GUI INSTALL / COMPILE

1. To get started with the GUI subset of the project, you will need to start with a Ubuntu Linux machine that has the ROS system installed (See Above) and the AU UAV package loaded.
2. Next, navigate to http://qt-project.org/downloads and click on “Qt libraries 4.8.4 for Linux/X11 (225 MB)”. This will start a fairly large download that might take some time. If prompted on where to save it, just pick a folder with a path that you can easily remember. (Note: Please ensure that the correct version is downloaded. Portions of the file saving code are version-specific.)
3. Once the file has been downloaded, it must be extracted. This can be done by double clicking on the file and using the archive manager, or by using the terminal. If using the terminal, first change the directory to the path where you saved the file and then run “gunzip qt-everywhere-opensource-src-4.8.4.tar.gz” followed by “tar xvf qt-everywhere-opensource-src-4.8.4.tar”.
4. Now open terminal (if it is not already open) and change the directory to the extracted folder labeled “qt-everywhere-opensource-src-4.8.4” and then run “sudo ./configure”. When prompted type ‘o’ for open source edition and “yes” to accept the license. This may take a little while to run (~30 mins).
5. After that is finished, run “sudo make”. This step will take several hours (up to 10 if using a virtual machine).
6. Once make is finished, run “sudo make install”. This will also take several hours, but less than required for “make”
7. Next, we need to install QT Creator. This allows for the user interface files to be edited and provides a very good IDE for the QT system. Once again we need to visit http://qt-project.org/downloads. From there, we will click on “QT Creator 2.7.0 for Linux/X11 32-bit (60 MB)”. 
8. Once the file has downloaded, open terminal and navigate to the directory where it is saved. After this, run “sudo chmod +x qt-creator-linux-x86-opensource-2.7.0.bin”
9. Next, run “./qt-creator-linux-x86-opensource-2.7.0.bin”. This will open an installer. Follow the on screen steps to complete the installation (Next, Next, Agree, Install, Finish). On the last screen, be sure to uncheck the box that labeled start QT Creator. We will need to run it from the terminal instead. If you forget, simply close the instance of QT Creator that appears.
10. We now need to install qt-ros, an intermediate between QT and ROS. This can be done through the terminal with “sudo apt-get install ros-fuerte-qt-ros”.  Type “y” at the appropriate prompt. Note: you may have to run “sudo apt-get update” first if you receive an error.
11. Obtain the “AU_UAV_GUI” folder from the CD.
12. Move it to your ROS workspace folder.
13. Open the “AU_UAV_GUI” folder and delete the “build” folder.
14. Navigate to your ROS workspace and then to the “AU_UAV_GUI” folder.
15. Next type “mkdir build” and navigate to the new build folder.
16. Now type “cmake ..”.
17. Once that has completed, type “rosmake AU_UAV_GUI”. 

GUI EXECUTION

The GUI is executed using a specific launch file.  To Execute the GUI comple the GUI and the ROS environments.  Then, launch the system by typing "roslaunch AU_UAV_ROS guiDriven.launch".  

The GUI can be launch seperatly after compliling by navigating to the ros_workspace/AU_UAV_GUI/ folder and typing "./bin/AU_UAV_GUI"

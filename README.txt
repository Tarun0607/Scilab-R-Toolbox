/********************************
Copyright © 2020 

Authors: Venkat Ragavan S, Garima Dave, Akash Manish Lad, Tarun A H, Dr.Mohana N
Organization: VIT Chennai
Email: mail2venkat21@gmail.com, garimadave628@gmail.com, akashlad4000@gmail.com, tarun.ambili123@gmail.com, mohana.n@vit.ac.in

This toolbox integrates the functionalities of R with Scilab. 

License: BSD-3-Clause
https://opensource.org/licenses/BSD-3-Clause

********************************/



Name of the toolbox: Scilab-R Toolbox

Purpose of the toolbox: To serve the statistical testing purpose by integrating R-Studio functions in Scilab via C libraries

Target Operating systems: Linux

External Software used: R Studio

External library that toolbox used : C libraries to integrate with Scilab software

Wikipedia link of the software integrated: https://en.wikipedia.org/wiki/RStudio

Step-by-step build instructions to compile the source code of the RStudio functions using C libraries:

STEP 1: 	Running the run.sh file using the command ./run.sh in terminal. Copying the header in thirdparty/linux/include along with '.so' file in thirdparty/linux/lib/x64 into thirdparty folder in the toolbox. 
	Initialising R environment in terminal in linux using "export R_HOME = /usr/lib/R"
STEP 2: 	Launching Scilab by calling "./scilab" 	
STEP 3:    Executing the command 'exec builder.sce' in scilab console inside the toolbox directory
STEP 4:	Executing the command 'exec loader.sce' in scilab console inside the toolbox directory
STEP 5:    Calling the implemented RStudio methods by declaring it to a variable. For example considering kruskal_wallis() method, declaring as: a = kruskal_wallis()


Directory structure of the Toolbox:
				etc: The .start and .quit present in this directory which helps in loading and unloading the toolbox.
				examples: This directory has sample example programs with the functions implemented in scilab.
				gateway: The sci_gateway files are present inside this directory which has gateway files for each C code written. 
					This acts as a bridge between scilab and C code.
				help: The .xml file present inside this directory is designed for each RStudio function  implemented in the toolbox.
					This inturn helps in showing the help inside the scilab.				
				macros: The macros directory is used to integrate the functions written in scilab itself saved as .sci inside the toolbox.
				third-party: The .c and .h present inside this has the C code of the functions implemented, this is integrated in scilab through gateways.

Version: 1.0.0

Licence : BSD-3-Clause

Last updated: 20-08-2020

Prerequisite for the Scilab-R toolbox in Linux: gcc installed in linux (sudo apt-get install gcc) and R installed in linux (sudo apt-get install r-base)

Building the toolbox: executing the command 'exec builder.sce' in scilab console inside the toolbox directory.

Loading the toolbox: executing the command 'exec loader.sce' in scilab console inside the toolbox directory.

Authors : 
1. Venkat Ragavan S (mail2venkat21@gmail.com)
2. Garima Dave (garimadave628@gmail.com)
3. Akash Manish Lad (akashlad4000@gmail.com)
4. Tarun A H (tarun.ambili123@gmail.com)
5. Mohana N (mohana.n@vit.ac.in)

Other important source links:

1. Detailed documentation of Scilab-R-Toolbox: https://bit.ly/31jHbzf

2. Integration of R using C libraries: http://sebastian-mader.net/programming/using-r-from-c-c/

3. Statistical/Algebraic R functions called through integrating C libraries to Scilab: https://www.rdocumentation.org/

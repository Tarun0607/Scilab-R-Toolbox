/********************************
Copyright © 2020 

Authors: Venkat Ragavan S, Garima Dave, Akash Manish Lad, Tarun A H, Dr.Mohana N
Organization: VIT Chennai
Email: mail2venkat21@gmail.com, garimadave628@gmail.com, akashlad4000@gmail.com, tarun.ambili123@gmail.com, mohana.n@vit.ac.in

This toolbox integrates the functionalities of R with Scilab. 

This file must be used under the terms of CeCILL. This source file is licensed as described in the 
file LICENSE, which you should have received as part of this distribution. The terms are also 
available at
https://cecill.info/licences/Licence_CeCILL_V2-en.txt 

This software is governed by the CeCILL  license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
********************************/



extern "C"
{
#include<Scierror.h>
#include<api_scilab.h>
#include <stdio.h>
#include "localization.h"
#include "r_dunif.h"




static const char fname[] = "dunif";
int sci_dunif(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{
	double *in1 ;
	double *in2 ;
	double *in3 ;
	double *in4 ;
	double *out1;
	double ar[1];
  
if (nin != 4)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 4);
        return 1;
    }

if (nout != 1)
    {
        Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
        return 1;
    }
    
    scilab_getDoubleArray(env, in[0],&in1);
    scilab_getDoubleArray(env, in[1],&in2);
    scilab_getDoubleArray(env, in[2],&in3);
    scilab_getDoubleArray(env, in[3],&in4);
    double *ret1 = r_dunif(in1[0],in2,in3[0],in4[0]);
   
    
    
    
    //if(ret1 == -1){
    
    	//Scierror(77,_("%s: Syntax error in the command\n"), fname);
    	//return 1;
    	
    //}

	//out[0] = scilab_createDoubleMatrix2d(env, 1, 1, 0);
   	out[0]=scilab_createDoubleMatrix2d(env, 1,in1[0], 0);
   	scilab_getDoubleArray(env, out[0],&out1);
	        for(int i=0;i<in1[0];i++)
			out1[i] = ret1[i];
    return 0;
}
}

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
#include "r_kruskalc.h"




static const char fname[] = "kruskal_wallis_vector";
int sci_kruskal_vector(scilabEnv env, int nin, scilabVar* in, int nopt, scilabOpt* opt, int nout, scilabVar* out)

{	double *in1;
	double *in2;
	double *in3;
	wchar_t** out1;
	
  
if (nin != 3)
    {
        Scierror(77, _("%s: Wrong number of input argument(s): %d expected.\n"), fname, 3);
        return 1;
    }

if (nout != 1)
    {
        Scierror(77, _("%s: Wrong number of output argument(s): %d expected.\n"), fname, 1);
        return 1;
    }
    
    scilab_getDoubleArray(env, in[0],&in1);
    //Scierror(77,_("Hi"));
    //in[0] = scilab_createDoubleMatrix2d(env, 1, 4);
    scilab_getDoubleArray(env,  in[1],&in2);
    scilab_getDoubleArray(env,  in[2],&in3);
    
    
    char *ans[5];
    
    int ret1 = r_kruskalc(in1[0],in2,in3,ans);
    
    
    const size_t cSize0 = strlen(ans[0])+1;
    wchar_t *temp0 = new wchar_t[cSize0];
    mbstowcs (temp0,ans[0],cSize0);
    
    const size_t cSize1 = strlen(ans[1])+1;
    wchar_t *temp1 = new wchar_t[cSize1];
    mbstowcs (temp1,ans[1],cSize1);
    
    const size_t cSize2 = strlen(ans[2])+1;
    wchar_t *temp2 = new wchar_t[cSize2];
    mbstowcs (temp2,ans[2],cSize2);
    
    const size_t cSize3 = strlen(ans[3])+1;
    wchar_t *temp3 = new wchar_t[cSize3];
    mbstowcs (temp3,ans[3],cSize3);
    
    
    
    
    if(ret1 == -1){
    
    	Scierror(77,_("%s: Syntax error in the command\n"), fname);
    	return 1;
    	
    }

	out[0] = scilab_createStringMatrix2d(env, 1, 4);
   	scilab_getStringArray(env, out[0],&out1);

		out1[0] = temp0;
		out1[1] = temp1;
		out1[2] = temp2;
		out1[3] = temp3;
		//out[0]=scilab_createString(env,temp);
    return 0;
}
}

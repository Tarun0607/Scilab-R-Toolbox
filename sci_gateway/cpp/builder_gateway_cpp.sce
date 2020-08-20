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



mode(-1)
lines(0)

toolbox_title = "test_toolbox";

Build_64Bits = %t;

path_builder = get_absolute_file_path('builder_gateway_cpp.sce');

Function_Names = [
        
        "kruskal_wallis","sci_kruskal_wallis_m", "csci6";
        "kruskal_wallis_vector","sci_kruskal_vector_m","csci6";
        "dpois","sci_dpois","csci6";
        "dnorm","sci_dnorm","csci6";
        "qnorm","sci_qnorm","csci6";
        "rnorm","sci_rnorm","csci6";
        "dunif","sci_dunif","csci6";
        "seq","sci_seq","csci6";
        "qunif","sci_qunif","csci6";
        "runif","sci_runif","csci6";
        "dbinom","sci_dbinom","csci6";
        "qbinom","sci_qbinom","csci6";
        "rbinom","sci_rbinom","csci6";
        "rpois","sci_rpois","csci6";
        "qpois","sci_qpois","csci6";
    ];

//Name of all the files to be compiled
Files = [
				"sci_kruskal_wallis_m.cpp";
				"sci_kruskal_vector_m.cpp";
				"sci_dpois.cpp";
				"sci_dnorm.cpp";
				"sci_qnorm.cpp";
				"sci_rnorm.cpp";
				"sci_dunif.cpp";
				"sci_seq.cpp";
				"sci_qunif.cpp";
				"sci_runif.cpp";
				"sci_dbinom.cpp";
				"sci_qbinom.cpp";
				"sci_rbinom.cpp";
				"sci_rpois.cpp" ;
				"sci_qpois.cpp" ;
				]



[a, opt] = getversion();
Version = opt(2);

//Build_64Bits = %f;

if getos()=="Windows" then
    third_dir = path_builder+filesep()+'..'+filesep()+'..'+filesep()+'thirdparty';
    lib_base_dir = third_dir + filesep() + 'windows' + filesep() + 'lib' + filesep() + Version + filesep();
    inc_base_dir = third_dir + filesep() + 'windows' + filesep() + 'include';
    C_Flags=['-D__USE_DEPRECATED_STACK_FUNCTIONS__  -I -w '+path_builder+' '+ '-I '+inc_base_dir+' ']   
    Linker_Flag  = [lib_base_dir+"libraryname.lib "]

elseif getos()=="Darwin" then //Mac
	third_dir = path_builder+filesep()+'..'+filesep()+'..'+filesep()+'thirdparty';
    	lib_base_dir = third_dir + filesep() + 'Mac' + filesep() + 'lib' + filesep() + Version + filesep();
    	inc_base_dir = third_dir + filesep() + 'Mac' + filesep() + 'include' ;
    	C_Flags=["-D__USE_DEPRECATED_STACK_FUNCTIONS__ -w -fpermissive -I"+path_builder+" -I"+inc_base_dir+" -Wl,-rpath "+lib_base_dir+" "]
    	Linker_Flag = ["-L"+lib_base_dir+" -lr_kruskal1 -Wl,-rpath="+lib_base_dir]

else//LINUX

    third_dir = path_builder+filesep()+'..'+filesep()+'..'+filesep()+'thirdparty';
    lib_base_dir = third_dir + filesep() + 'linux' + filesep() + 'lib' + filesep() + Version + filesep();

    inc_base_dir = third_dir + filesep() + 'linux' + filesep() + 'include';

    C_Flags = ["-I"+inc_base_dir];

		Linker_Flag = ["-L" + lib_base_dir + " -lr_kruskalt -lr_kruskalc -lr_dpois -lr_dnorm -lr_qnorm -lr_rnorm -lr_dunif -lr_seq -lr_qunif -lr_runif -lr_dbinom -lr_qbinom -lr_rbinom -lr_rpois -lr_qpois -Wl,-rpath="+lib_base_dir]

end

tbx_build_gateway(toolbox_title,Function_Names,Files,get_absolute_file_path("builder_gateway_cpp.sce"), [], Linker_Flag, C_Flags,[]);

clear toolbox_title Function_Names Files Linker_Flag C_Flags;

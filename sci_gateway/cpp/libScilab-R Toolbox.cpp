#include <wchar.h>
#include "libScilab-R Toolbox.hxx"
extern "C"
{
#include "libScilab-R Toolbox.h"
#include "addfunction.h"
}

#define MODULE_NAME L"libScilab-R Toolbox"

int libScilab-R Toolbox(wchar_t* _pwstFuncName)
{
    if(wcscmp(_pwstFuncName, L"kruskal_wallis") == 0){ addCFunction(L"kruskal_wallis", &sci_kruskal_wallis_m, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"kruskal_wallis_vector") == 0){ addCFunction(L"kruskal_wallis_vector", &sci_kruskal_vector_m, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"dpois") == 0){ addCFunction(L"dpois", &sci_dpois, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"dnorm") == 0){ addCFunction(L"dnorm", &sci_dnorm, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"qnorm") == 0){ addCFunction(L"qnorm", &sci_qnorm, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"rnorm") == 0){ addCFunction(L"rnorm", &sci_rnorm, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"dunif") == 0){ addCFunction(L"dunif", &sci_dunif, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"seq") == 0){ addCFunction(L"seq", &sci_seq, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"qunif") == 0){ addCFunction(L"qunif", &sci_qunif, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"runif") == 0){ addCFunction(L"runif", &sci_runif, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"dbinom") == 0){ addCFunction(L"dbinom", &sci_dbinom, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"qbinom") == 0){ addCFunction(L"qbinom", &sci_qbinom, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"rbinom") == 0){ addCFunction(L"rbinom", &sci_rbinom, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"rpois") == 0){ addCFunction(L"rpois", &sci_rpois, MODULE_NAME); }
    if(wcscmp(_pwstFuncName, L"qpois") == 0){ addCFunction(L"qpois", &sci_qpois, MODULE_NAME); }

    return 1;
}

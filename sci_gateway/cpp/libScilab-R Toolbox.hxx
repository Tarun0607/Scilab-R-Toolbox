#ifndef __LIBSCILAB-R TOOLBOX_GW_HXX__
#define __LIBSCILAB-R TOOLBOX_GW_HXX__

#ifdef _MSC_VER
#ifdef LIBSCILAB-R TOOLBOX_GW_EXPORTS
#define LIBSCILAB-R TOOLBOX_GW_IMPEXP __declspec(dllexport)
#else
#define LIBSCILAB-R TOOLBOX_GW_IMPEXP __declspec(dllimport)
#endif
#else
#define LIBSCILAB-R TOOLBOX_GW_IMPEXP
#endif

extern "C" LIBSCILAB-R TOOLBOX_GW_IMPEXP int libScilab-R Toolbox(wchar_t* _pwstFuncName);



#endif /* __LIBSCILAB-R TOOLBOX_GW_HXX__ */

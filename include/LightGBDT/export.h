#ifndef LIGHTGBDT_EXPORT_H_
#define LIGHTGBDT_EXPORT_H_

/** Macros for exporting symbols in MSVC/GCC/CLANG **/

#ifdef __cplusplus
#define LIGHTGBDT_EXTERN_C extern "C"
#else
#define LIGHTGBDT_EXTERN_C
#endif


#ifdef _MSC_VER
#define LIGHTGBDT_EXPORT __declspec(dllexport)
#define LIGHTGBDT_C_EXPORT LIGHTGBDT_EXTERN_C __declspec(dllexport)
#else
#define LIGHTGBDT_EXPORT 
#define LIGHTGBDT_C_EXPORT LIGHTGBDT_EXTERN_C
#endif

#endif /** LIGHTGBDT_EXPORT_H_ **/
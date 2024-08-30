/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-67a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sinks: cat
 *    BadSink : Copy data to string using wcscat
 * Flow Variant: 67 Data flow: data passed in a struct from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

typedef struct _CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType
{
    wchar_t * structFirst;
} CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType;


#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType myStruct);

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_bad()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType myStruct;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FLAW: Initialize data as a large buffer that is larger than the small buffer used in the sink */
    wmemset(data, L'A', 100-1); /* fill with L'A's */
    data[100-1] = L'\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67b_badSink(myStruct);
}

#endif
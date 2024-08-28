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


#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67b_goodG2BSink(CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType myStruct);

static void goodG2B()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_structType myStruct;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67b_goodG2BSink(myStruct);
}

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_67_good()
{
    goodG2B();
}

#endif
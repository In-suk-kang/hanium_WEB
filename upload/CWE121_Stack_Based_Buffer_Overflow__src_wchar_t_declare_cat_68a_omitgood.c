/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__src.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource:  Initialize data as a large string
 * GoodSource: Initialize data as a small string
 * Sink: cat
 *    BadSink : Copy data to string using wcscat
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <wchar.h>

wchar_t * CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68_badData;
wchar_t * CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68_goodG2BData;


#ifndef OMITGOOD

/* good function declarations */
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    /* FIX: Initialize data as a small buffer that as small or smaller than the small buffer used in the sink */
    wmemset(data, L'A', 50-1); /* fill with L'A's */
    data[50-1] = L'\0'; /* null terminate */
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68_goodG2BData = data;
    CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68b_goodG2BSink();
}

void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_68_good()
{
    goodG2B();
}

#endif
/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68a.c
Label Definition File: CWE121_Stack_Based_Buffer_Overflow__CWE129.label.xml
Template File: sources-sinks-68a.tmpl.c
*/
/*
 * @description
 * CWE: 121 Stack Based Buffer Overflow
 * BadSource: large Large index value that is greater than 10-1
 * GoodSource: Larger than zero but less than 10
 * Sinks:
 *    GoodSink: Ensure the array index is valid
 *    BadSink : Improperly check the array index by not checking the upper bound
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68_badData;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68_goodG2BData;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68_goodB2GData;


#ifndef OMITBAD

/* bad function declaration */
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68b_badSink();

void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Use an invalid index */
    data = 10;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68_badData = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_68b_badSink();
}

#endif /* OMITBAD */

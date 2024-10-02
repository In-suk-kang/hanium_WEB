/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE190_Integer_Overflow__char_fscanf_add_44.c
Label Definition File: CWE190_Integer_Overflow.label.xml
Template File: sources-sinks-44.tmpl.c
*/
/*
 * @description
 * CWE: 190 Integer Overflow
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Set data to a small, non-zero number (two)
 * Sinks: add
 *    GoodSink: Ensure there will not be an overflow before adding 1 to data
 *    BadSink : Add 1 to data, which can cause an overflow
 * Flow Variant: 44 Data/control flow: data passed as an argument from one function to a function in the same source file called via a function pointer
 *
 * */

#include "std_testcase.h"


#ifndef OMITBAD

static void badSink(char data)
{
    {
        /* POTENTIAL FLAW: Adding 1 to data could cause an overflow */
        char result = data + 1;
        printHexCharLine(result);
    }
}

void CWE190_Integer_Overflow__char_fscanf_add_44_bad()
{
    char data;
    /* define a function pointer */
    void (*funcPtr) (char) = badSink;
    data = ' ';
    /* POTENTIAL FLAW: Use a value input from the console */
    fscanf (stdin, "%c", &data);
    /* use the function pointer */
    funcPtr(data);
}

#endif